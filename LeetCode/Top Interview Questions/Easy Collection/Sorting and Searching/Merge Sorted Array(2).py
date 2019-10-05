class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        # Entao... a outra solucao apesar de ter complexidade O(n) usa uma memoria adicional com a 
        # seguinte complexidade: O(m + n)
        # Vamos fazer agr sem usar memoria extra e usando a tecnica de two pointers(Time Complexity: O(n)) 
        i = m - 1
        j = n - 1
        k = m + n - 1
        while i >= 0 and j >= 0:
            if nums1[i] <= nums2[j]:
                nums1[k] = nums2[j]
                k -= 1
                j -= 1
            elif nums1[i] > nums2[j]:
                nums1[k] = nums1[i]
                k -= 1
                i -= 1
        if i < 0:
            #Nesse caso, tem que retirar o resto do nums2
            while j >= 0:
                nums1[k] = nums2[j]
                k -= 1
                j -= 1
        elif j < 0:
            while i >= 0:
                nums1[k] = nums1[i]
                k -= 1
                i -= 1
