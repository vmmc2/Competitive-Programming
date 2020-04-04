class Solution {
public:
    int binary_search(vector<int> &v, int target, int fl){
        int n = (int)v.size();
        int low = 0;
        int high = n - 1;
        int index = -1; //assumo q n vou achar.
        while(low <= high){
            int mid = low + (high - low)/2;
            if(v[mid] == target){
                if(fl == 0){ //primeira ocorrencia
                    index = mid;
                    high = mid - 1;
                }else{//ultima ocorrencia
                    index = mid;
                    low = mid + 1;
                }
            }else if(v[mid] < target){
                low = mid + 1;
            }else if(target < v[mid]){
                high = mid - 1;
            }
        }
        return index;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int first = binary_search(nums, target, 0);
        if(first == -1){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        ans.push_back(first);
        int last = binary_search(nums, target, 1);
        ans.push_back(last);
        return ans;
    }
};
