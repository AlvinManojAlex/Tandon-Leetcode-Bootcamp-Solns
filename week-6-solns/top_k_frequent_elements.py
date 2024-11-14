class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """

        # Variable to store heap values
        heap = []
        counter = {}

        for x in nums:
            counter[x] = counter.get(x, 0) + 1

        # Creating min heap => store frequency as negative
        for key, value in counter.items():
            heapq.heappush(heap, (-value, key))

        ans = []

        while len(ans) < k:
            ans.append(heapq.heappop(heap)[1])

        return ans
        