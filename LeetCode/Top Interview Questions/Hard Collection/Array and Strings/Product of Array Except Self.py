class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # naive approach: O**2
        answer = [1 for i in range(0, len(nums))]
        preffixprod = [1 for i in range(0, len(nums))]
        suffixprod = [1 for i in range(0, len(nums))]
        
        product = 1
        for i in range(0, len(nums)):
            product *= nums[i]
            preffixprod[i] = product
        i = len(nums) - 1
        product = 1
        while i >= 0:
            product *= nums[i]
            suffixprod[i] = product
            i -=1
        for i in range(0, len(nums)):
            if i == 0:
                answer[i] = suffixprod[i + 1]
            elif i == len(nums) - 1:
                answer[i] = preffixprod[i - 1]
            else:
                answer[i] = preffixprod[i - 1] * suffixprod[i + 1]
        print(answer)
        return answer
