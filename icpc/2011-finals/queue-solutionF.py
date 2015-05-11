#!/usr/bin/env python
# -*- coding: utf-8 -*-
import Queue
from collections import namedtuple

class Restructure(object):
    '''
    Breadth first search solution.
    Add all reachable states to the queue until an ending state is found.
    '''
    def __init__(self, N, D, machines):
        self.D = D
        self.N = N
        # sort by day
        self.machines = sorted(machines)
        # dummy machine at the end
        self.machines.append(Machine(self.D+1, 0, 0, 0))
        self.N += 1
        # builds a convenient map of
        # day -> first index of the next possible machine to buy from the sorted list of machines
        self.idx = {}
        d, i = 0, 0
        while i < self.N:
            day = self.machines[i].d
            if day != d:
                self.idx[d] = i
                d = day
            i += 1
        if day != d:
            self.idx[d] = i
        #print self.machines
        #print self.idx

    def maximize_money(self, C):
        max_money = C
        # state is a 4-tuple of (day, money, current machine, explanation for debugging)
        State = namedtuple('State', ['day', 'cash', 'machine_idx', 'explain'])
        q = Queue.Queue()
        q.put(State(0, C, None, 'start'))
        cache = {0: C}
        # still something left in the queue
        while not q.empty():
            state = q.get()
            if state.day < self.D+1:
                #print state
                for i in range(self.idx[state.day], self.N):
                    new_machine = self.machines[i]
                    new_day = new_machine.d
                    resell, old_g = 0, 0
                    # we have a machine working already
                    if state.machine_idx is not None:
                        old_machine = self.machines[state.machine_idx]
                        resell = old_machine.r
                        old_g = old_machine.g
                    # money we got from running old machine
                    gains = (new_day - state.day - 1) * old_g
                    # total money available at this point
                    funds = state.cash + resell + gains
                    # can we buy it? no use buying machine with gains lower or equal,
                    # except the special case for the last dummy-machine where g = 0.
                    if funds >= new_machine.p and (new_machine.g > old_g or new_machine.g == 0):
                        cash_left = funds - new_machine.p
                        # next possible day after choosing new machine
                        next_day = self.D+1 if new_day not in self.idx else self.machines[self.idx[new_day]].d
                        future_gains = (next_day - new_day - 1) * new_machine.g
                        future_resell = new_machine.r
                        total_expected = cash_left + future_gains + future_resell
                        # add only if it's the best expected for the future
                        if new_day not in cache or total_expected > cache[new_day]:
                            cache[new_day] = total_expected
                            # add new state
                            new_state = State(new_day, cash_left, i,
                                              state.explain + ' - ' + 'm[{}],c={}'.format(i, funds - new_machine.p))
                            #print '\tday = {}, i = {}, adding = {}'.format(state.day, i, new_state)
                            q.put(new_state)
            else:
                #print 'ENDING ', state
                max_money = max(max_money, state.cash)
        return max_money
             

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
