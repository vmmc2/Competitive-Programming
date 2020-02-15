class Solution:

    def __init__(self, nums: List[int]):
        self.original = list(nums)
        self.array = list(nums)
        

    def reset(self) -> List[int]:
        self.array = self.original
        self.original = list(self.original)
        return self.array
     
    def shuffle(self) -> List[int]:
        #para fazer a operacao de shuffle, vamos trabalhar em cima da list array.
        tam = len(self.array)
        for i in range(0, tam):
            swap_ind = random.randrange(i, tam)
            temp = self.array[swap_ind]
            self.array[swap_ind] = self.array[i]
            self.array[i] = temp
        return self.array
        
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
