class Trie:

    def __init__(self):
        self.trie = {}

    def insert(self, word: str):
        d = self.trie

        for c in word:
            if c not in d:
                d[c] = {}
            d = d[c]

        d['.'] = '.'

    def search(self, word: str):
        d = self.trie

        for c in word:
            if c not in d:
                return False
            d = d[c]
        
        return '.' in d

    def startsWith(self, prefix: str):
        d = self.trie

        for c in prefix:
            if c not in d:
                return False
            d = d[c]

        return True


trie = Trie()

print(trie.insert("apple"))
print(trie.search("apple"))
print(trie.search("app"))
print(trie.startsWith("app"))
print(trie.insert("app"))
print(trie.search("app"))