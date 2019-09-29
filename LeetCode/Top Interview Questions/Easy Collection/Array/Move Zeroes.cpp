class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //primeiro passo: calcular a quantidade de zeros no array;
        int qtd_zeros = 0;
        for(int i = 0; i < (int)nums.size(); i++){
            if(nums[i] == 0) qtd_zeros++;
        }
        int vacant = 0;
        int cursor = 0;
        //TWO POINTERS.....
        while(cursor < (int)nums.size()){
            if(nums[vacant] == 0 && nums[cursor] == 0){
                cursor++;
            }
            else if(nums[vacant] == 0 && nums[cursor] != 0){
                nums[vacant] = nums[cursor];
                cursor++;
                vacant++;
            }
            else if(nums[vacant] != 0 && nums[cursor] == 0){
                cursor++;
            }
            else if(nums[vacant] != 0 && nums[cursor] != 0){
                nums[vacant] = nums[cursor];
                cursor++;
                vacant++;
            }
        }
        int sentinela = (int)nums.size() - 1;
        while(qtd_zeros > 0){
            nums[sentinela] = 0;
            sentinela--;
            qtd_zeros--;
        }
        
        
    }
};
