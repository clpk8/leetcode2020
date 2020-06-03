class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        map = {}
        for c in magazine:
            if c not in map:
                map[c] = 1
            else:
                map[c]+=1
        for c in ransomNote:
            if c in map and map[c] >= 1:
                map[c]-=1
            else:
                return False
        return True