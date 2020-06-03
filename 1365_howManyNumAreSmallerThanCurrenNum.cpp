//
// Created by Chunbin lin on 6/1/20.
//

class Solution(object):
def smallerNumbersThanCurrent(self, nums):
"""
:type nums: List[int]
:rtype: List[int]
"""
sorted_nums = sorted(nums)
dict_pos = {}
number_of_smaller = 0
for e in sorted_nums:
if e not in dict_pos:
dict_pos[e] = number_of_smaller
        number_of_smaller += 1
res = []
for e in nums:
res.append(dict_pos[e])
return res;