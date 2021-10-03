class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        N = len(s)
        # ending[i] contains the ending indices in `s` of
        # words in `wordDict` that are prefixes of s[i:]
        ending = [[] for i in range(N)]
        reachable = [False] * (N + 1)
        reachable[0] = True
        for i in range(N):
            if reachable[i]:
                substr = s[i:]
                for w in wordDict:
                    if substr.startswith(w):
                        ending[i].append(i + len(w))
                        reachable[i + len(w)] = True
        if not reachable[-1]:
            return []
        sentence = {}
        for i, E in enumerate(ending):
            sen = sentence.get(i, [])
            if sen:
                for j in E:
                    sentence.setdefault(j, []).extend(x + ' ' + s[i:j] for x in sen)
                del sentence[i]
            else:
                for j in E:
                    sentence.setdefault(j, []).append(s[i:j])
        return sentence.get(len(s), [])




from collections import OrderedDict

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        N = len(s)
        # ending[i] contains the ending indices in `s` of
        # words in `wordDict` that are prefixes of s[i:]
        ending = OrderedDict()
        reachable = [True] + [False] * N
        for i in range(N):
            if reachable[i]:
                substr = s[i:]
                for w in wordDict:
                    if substr.startswith(w):
                        ending.setdefault(i, []).append(i + len(w))
                        reachable[i + len(w)] = True
        if not reachable[-1]:
            return []
        # sentences[i] holds all possible sentences of
        # words in s[:i]
        sentences = {}
        for i, E in ending.items():
            sen = sentences.get(i, [])
            if sen:
                for j in E:
                    sentences.setdefault(j, []).extend(x + ' ' + s[i:j] for x in sen)
                sentences.pop(i)
            else:
                for j in E:
                    sentences.setdefault(j, []).append(s[i:j])
        return sentences.get(len(s), [])

