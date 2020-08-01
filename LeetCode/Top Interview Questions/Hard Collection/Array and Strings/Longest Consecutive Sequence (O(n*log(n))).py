class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        # Corner case: Empty list
        if len(nums) == 0:
            return 0
        # Treating the general cases...
        nums.sort()
        print(nums)
        answer = -1
        length = 1
        lastSeen = None
        for i in range(0, len(nums)):
            if lastSeen == None:
                lastSeen = nums[i]
            else:
                if nums[i] == lastSeen:
                    continue
                if nums[i] == lastSeen + 1:
                    print("Nums[i]:", nums[i], " --- lastSeen:", lastSeen)
                    length += 1
                    lastSeen = nums[i]
                    print(length)
                else:
                    answer = max(answer, length)
                    length = 1
                    lastSeen = nums[i]
        answer = max(answer, length)
        return answer
