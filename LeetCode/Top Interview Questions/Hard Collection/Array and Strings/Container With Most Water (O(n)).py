class Solution:
    def maxArea(self, height: List[int]) -> int:
        # Approach 1: Naive - O(n^2)
        # Corner case:
        if len(height) == 0:
            return 0
        # General case:
        answer = -1
        left = 0
        right = len(height) - 1
        while left < right:
            answer = max(answer, (right - left)*(min(height[left],height[right])))
            if height[left] < height[right]:
                left += 1
            elif height[left] > height[right]:
                right -= 1
            else:
                left += 1
        return answer
        
