from collections import Counter

class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        cs = Counter(s)
        ct = Counter(t)
        for k in cs:
            if ct[k] == cs[k]:
                del ct[k]
        return ct.popitem()[0] if ct else ''

