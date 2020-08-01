class Solution:
    def binSearch(self, target: int, cdSums: List[int]) -> bool:
        left = 0
        right = len(cdSums) - 1
        while left <= right:
            mid = (left + right)//2
            if cdSums[mid] == target:
                return True
            elif cdSums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return False
    def binSearch2(self, target: int, cdSums: List[int], esquerda: bool) -> int:
        left = 0
        right = len(cdSums) - 1
        index = -1
        while left <= right:
            mid = (left + right)//2
            if cdSums[mid] == target:
                index = mid
                if esquerda == True:
                    right = mid - 1
                else:
                    left = mid + 1
            elif cdSums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return index
        
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        # Approach 1: O(n^2)
        # Perceba que: A[i] + B[j] + C[k] + D[l] = 0 eh a mesma coisa que: A[i] + B[j] = -C[k] - D[l] = -(C[k] + D[l])
        # Com isso, a gente reduz a complexidade de O(n^4) para O(n^2)
        abSums = []
        cdSums = []
        answer = 0
        for i in range(0, len(A)):
            for j in range(0, len(B)):
                abSums.append(A[i] + B[j])
        for i in range(0, len(C)):
            for j in range(0, len(D)):
                cdSums.append(C[i] + D[j])
        cdSums.sort()
        for i in range(0, len(abSums)):
            if self.binSearch(abSums[i]*(-1), cdSums) == True:
                lindex = self.binSearch2(abSums[i]*(-1), cdSums, True)
                rindex = self.binSearch2(abSums[i]*(-1), cdSums, False)
                answer += (rindex - lindex + 1)
        return answer
                
