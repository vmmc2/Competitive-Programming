class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        d = {}
        missingNumber = 1
        for i in range(0, len(nums)):
            if nums[i] <= 0:
                continue
            if nums[i] == missingNumber:
                missingNumber += 1
                d[nums[i]] = True
            else:
                d[nums[i]] = True
        ok = True
        while ok:
            if missingNumber in d:
                missingNumber += 1
            else:
                ok = False
        return missingNumber
