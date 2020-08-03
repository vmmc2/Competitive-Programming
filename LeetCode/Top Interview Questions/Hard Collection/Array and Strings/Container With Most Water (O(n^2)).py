class Solution:
    def maxArea(self, height: List[int]) -> int:
        # Approach 1: Naive - O(n^2)
        # Corner case:
        if len(height) == 0:
            return 0
        # General case:
        answer = -1
        for i in range(0, len(height) - 1):
            for j in range(i + 1, len(height)):
                answer = max(answer, (j - i)* min(height[i],height[j]))
        return answer
