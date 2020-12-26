class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        present = [False]*4000
        answer = -1
        
        for i in range(0, len(arr)):
            present[arr[i]] = True
        curr = 1
        for i in range(1, len(present)):
            if present[i] == False and curr == k:
                answer = i
                break
            elif present[i] == False and curr < k:
                curr += 1
                
        return answer
