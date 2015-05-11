#!/usr/bin/env python
# -*- coding: utf-8 -*-
import Queue
from collections import namedtuple

class Restructure(object):
    '''
    Dynamic programming solution.
    To find the best solution for day D_i, look at the best days from D_0 to D_i-1.
    '''
    def __init__(self, N, D, machines):
        self.D = D
        self.N = N
        # sort by day
        self.machines = sorted(machines)
        # dummy machine at the end
        self.machines.append(Machine(self.D+1, 0, 0, 0))
        self.N += 1
        #print self.machines
        # map of which day comes after current day
        self.days = {0: self.machines[0].d}
        for i in range(len(self.machines)-1):
            m = self.machines[i]
            self.days[m.d] = self.machines[i+1].d

    def maximize_money(self, C):
        # state is a 5-tuple of (day, money, expected money in the next day or end,
        #                        current machine index, explanation used for debugging)
        State = namedtuple('State', ['day', 'cash', 'expected', 'machine_idx', 'explain'])
        # start at day 0
        best = {0: State(0, C, C, None, 'start')}
        for i, new_machine in enumerate(self.machines):
            for day, state in sorted(best.items()):
                new_day = new_machine.d
                # consider only states which are older than new_machine
                if day >= new_day:
                    break

                resell, old_g = 0, 0
                if state.machine_idx is not None:
                    old_machine = self.machines[state.machine_idx]
                    resell = old_machine.r
                    old_g = old_machine.g
                gains = (new_day - state.day - 1) * old_g
                # what we have if left we sell the old machine (one in the state)
                funds = state.cash + resell + gains
                # can we buy it? no use buying machine with gains lower or equal,
                # except the special case for the last dummy-machine where g = 0.
                if funds >= new_machine.p and (new_machine.g > old_g or new_machine.g == 0):
                    cash_left = funds - new_machine.p

                    # day that follows new_day in self.days of last day
                    next_day = self.D+1 if new_day not in self.days else self.days[new_day]
                    future_gains = (next_day - new_day - 1) * new_machine.g
                    future_resell = new_machine.r
                    # what we expect to have if we buy this machine and use it
                    total_expected = cash_left + future_gains + future_resell
                    # is it the best one we can get for this day?
                    if new_day not in best or best[new_day].expected < total_expected:
                        new_state = State(new_day, cash_left, total_expected, i,
                                state.explain + ' - ' + 'm[{}],c={}'.format(i, funds - new_machine.p))
                        best[new_day] = new_state

        # return what we have at the end of the last day
        return best[self.D+1].cash
             

if __name__ == '__main__':
    # machine is a 4-tuple of (day available, price, resell proce, gains per day)
    Machine = namedtuple('Machine', ['d', 'p', 'r', 'g'])
    with open('input.txt') as f:
        case = 1
        while True:
            N, C, D = [int(x) for x in f.next().split()]
            if N == 0 and C == 0 and D == 0:
                break

            machines = []
            for _ in range(N):
                d, p, r, g = [int(x) for x in f.next().split()]
                machines.append(Machine(d, p, r, g))

            result = Restructure(N, D, machines).maximize_money(C) if len(machines) > 0 else C

            print 'Case {}: {}'.format(case, result)
            case += 1
