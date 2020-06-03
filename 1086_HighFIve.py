class Solution(object):
    def highFive(self, items):
        """
        :type items: List[List[int]]
        :rtype: List[List[int]]
        """
        items.sort(reverse=True)

        res = []
        curr = []
        idx = items[0][0]

        for i, val in items:
            if i == idx:
                if len(curr) < 5:
                    curr.append(val)
            else:
                res.append([idx, sum(curr) / len(curr)])
                curr = [val]
                idx = i
        res.append([idx, sum(curr) / len(curr)])

        res = res[::-1]
        return res;

##Priority queue
class Solution(object):
    def highFive(self, items):
        """
        :type items: List[List[int]]
        :rtype: List[List[int]]
        """
        d = collections.defaultdict(list)
        for idx, val in items:
            heapq.heappush(d[idx], val)

            if len(d[idx]) > 5:
                heapq.heappop(d[idx])

        res = [[i, sum(d[i]) / len(d[i])] for i in sorted(d)]
        return res;