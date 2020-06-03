class Solution(object):
    def subtractProductAndSum(self, n):
        """
        :type n: int
        :rtype: int
        """
        s, p = 0, 1
        for i in str(n):
            s += int(i)
            p *= int(i)
        return p - s