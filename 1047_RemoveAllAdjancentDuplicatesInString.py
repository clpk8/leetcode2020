class Solution(object):
    def removeDuplicates(self, S):
        """
        :type S: str
        :rtype: str
        """
        dq = collections.deque()
        for c in S:
            if dq and dq[-1] == c:
                dq.pop()
            else:
                dq.append(c)
        return ''.join(dq)