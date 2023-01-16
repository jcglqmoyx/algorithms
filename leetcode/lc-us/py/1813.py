class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        if sentence1 == sentence2:
            return True
        if len(sentence1) < len(sentence2):
            sentence1, sentence2 = sentence2, sentence1
        words1, words2 = sentence1.split(), sentence2.split()
        if len(words1) < len(words2):
            return False
        i = 0
        while i < len(words2) and words1[i] == words2[i]:
            i += 1
        j, k = len(words1) - 1, len(words2) - 1
        while k >= i:
            if words1[j] != words2[k]:
                return False
            j -= 1
            k -= 1
        return True
