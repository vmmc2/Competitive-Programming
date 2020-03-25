class Solution {
public:
    int binary_search_left(vector<int> &nums, int left, int right, int target, int index){
        if(left > right){
            return index;
        }
        int mid = left + (right - left)/2;
        if(nums[mid] == target){
            //achei, mas continuo procurando a esquerda pra achar a primeira ocorrencia
            index = mid;
            return binary_search_left(nums, left, mid - 1, target, index);
        }else if(nums[mid] > target){
            return binary_search_left(nums, left, mid - 1, target, index);
        }else{
            return binary_search_left(nums, mid + 1, right, target, index);
        }
        return index;
    }
    int binary_search_right(vector<int> &nums, int left, int right, int target, int index){
        if(left > right){
            return index;
        } 
        int mid = left + (right - left)/2;
        if(nums[mid] == target){
            //achei, mas continuo procurando a esquerda pra achar a primeira ocorrencia
            index = mid;
            return binary_search_right(nums, mid + 1, right, target, index);
        }else if(nums[mid] > target){
            return binary_search_right(nums, left, mid - 1, target, index);
        }else{
            return binary_search_right(nums, mid + 1, right, target, index);
        }
        return index;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = (int)nums.size() - 1;
        vector<int> ans;
        
        //Passo -1 como index pq eu suponho que nao vou conseguir encontra-lo no array.
        int firstoc = binary_search_left(nums, left, right, target, -1); 
        int lastoc = binary_search_right(nums, left, right, target, -1);
        ans.push_back(firstoc);
        ans.push_back(lastoc);
        return ans;
    }
};
