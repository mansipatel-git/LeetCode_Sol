class Solution(object):
    def twoSum(self, arr, target):
        seen = {}

        for i, x in enumerate(arr):
            if target - x in seen:
                return [seen[target - x], i]

            seen[x] = i

        return []