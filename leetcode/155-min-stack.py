class MinStack:
    def __init__(self):
        self.st = []
        self.mn = []

    def push(self, x: int) -> None:
        if self.mn and x > self.mn[-1][0]:
            self.mn[-1][1] += 1
        else:
            self.mn.append([x, 1])

        self.st.append(x)

    def pop(self) -> None:
        if self.st:
            self.st.pop()

        if self.mn:
            self.mn[-1][1] -= 1
            if self.mn[-1][1] <= 0:
                self.mn.pop()
        
    def top(self) -> int:
        if self.st:
            return self.st[-1]
        return None

    def getMin(self) -> int:
        print(self.mn)
        if self.mn:
            return self.mn[-1][0]
        return None
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
