class Trie:
    def __init__(self):
        self.end = False
        self.children = dict() # char -> Trie obj
        
    def insert(self, word: str) -> None:
        if not word:
            return
        next = self
        for w in word:
            if w not in next.children:
                next.children[w] = Trie()
            next = next.children[w]
        next.end = True

    def search(self, word: str) -> bool:
        if not word:
            return False
        next = self
        for w in word:
            if w not in next.children:
                return False
            next = next.children[w]
        return next.end
        
    def startsWith(self, prefix: str) -> bool:
        if not prefix:
            return False
        next = self
        for w in prefix:
            if w not in next.children:
                return False
            next = next.children[w]
        return True
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
