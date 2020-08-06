class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # Treating the corner case first:
        if len(nums) == 0 or len(nums) == 1:
            return
        # Treating the general cases...
        counter = 0
        for i in range(0, len(nums)):
            if nums[i] == 0:
                counter += 1
        left = 0
        right = 0
        while right < len(nums):
            if nums[left] == 0 and nums[right] == 0:
                right += 1
            elif nums[left] == 0 and nums[right] != 0:
                nums[left] = nums[right]
                left += 1
                right += 1
            elif nums[left] != 0 and nums[right] == 0:
                right += 1
            else:
                nums[left] = nums[right]
                left += 1
                right += 1
        i = -1
        while counter > 0:
            nums[i] = 0
            counter -=1
            i -= 1
        return
            

            
