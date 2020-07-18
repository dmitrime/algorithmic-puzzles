class WordDictionary:
    def __init__(self):
        self.children = dict()
        self.end = False
        
    def addWord(self, word: str) -> None:
        p = self
        for ch in word:
            if ch not in p.children:
                p.children[ch] = WordDictionary()
            p = p.children[ch]
        p.end = True
        
    def helper(self, word, root):
        if not word:
            return root.end
        for idx, ch in enumerate(word):
            if ch != '.' and ch not in root.children:
                return False
            elif ch != '.' and ch in root.children:
                root = root.children[ch]
            elif ch == '.':
                found = False
                for child in root.children.values():
                    found = found or self.helper(word[idx+1:], child)
                return found
        return root.end

    def search(self, word: str) -> bool:
        return self.helper(word, self)
        


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
