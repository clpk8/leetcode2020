class Solution(object):
    def reverseWords(self, S):
        """
        :type s: str
        :rtype: str
        """
        result = ""
        s = S.split()
        for s1 in s:
            result += s1[::-1]
            result += " "
        return result.rstrip()