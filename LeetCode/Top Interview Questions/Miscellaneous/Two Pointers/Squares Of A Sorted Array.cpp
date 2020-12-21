class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> answer;
        //Primeiro caso: O array possui apenas numeros nao-negativos. (>= 0)
        if(nums[0] >= 0){
            for(int i = 0; i < (int)nums.size(); i++){
                answer.push_back(nums[i]*nums[i]);
            }
        }else if(nums[(int)nums.size() - 1] < 0){ //O array so tem numeros negativos. Vou de tras para frente.
            for(int i = (int)nums.size() - 1; i >= 0; i--){
                answer.push_back(nums[i]*nums[i]);
            }
        }else{ //Quer dizer que eu tenho numeros negativos... Tenho que achar o index do primeiro numero nao-negativo.
            int low = 0;
            int high = (int)nums.size() - 1;
            int lPointer, rPointer;
            while(low <= high){
                int mid = low + (high - low)/2;
                if(nums[mid] >= 0){
                    rPointer = mid;
                    high = mid - 1;
                }else if(nums[mid] < 0){
                    low = mid + 1;
                }
            }
            lPointer = rPointer - 1;
            int l, r;
            while(lPointer >= 0 || rPointer < (int)nums.size()){
                if(lPointer >= 0) l = nums[lPointer]*nums[lPointer];
                if(rPointer < (int)nums.size()) r = nums[rPointer]*nums[rPointer];
                if(lPointer >= 0 && rPointer < (int)nums.size()){
                    if(l <= r){
                        answer.push_back(l);
                        lPointer--;
                    }else if(l > r){
                        answer.push_back(r);
                        rPointer++;
                    }
                }else if(lPointer < 0 && rPointer < (int)nums.size()){
                    answer.push_back(r);
                    rPointer++;
                }else if(lPointer >= 0 && rPointer >= (int)nums.size()){
                    answer.push_back(l);
                    lPointer--;
                }
            }
        }
        return answer;
    }
};
