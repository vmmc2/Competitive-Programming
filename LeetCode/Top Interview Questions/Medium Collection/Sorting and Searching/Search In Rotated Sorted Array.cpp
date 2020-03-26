class Solution {
public:
    int binary_search(vector<int> &nums, int left, int right, int index, int target){
        if(left > right) return index;
        int mid = left + (right - left)/2;
        if(nums[mid] == target){
            index = mid;
            return index;
        }else if(nums[mid] > target){
            return binary_search(nums, left, mid - 1, index, target);
        }else if(nums[mid] < target){
            return binary_search(nums, mid + 1, right, index, target);
        }
        return index;
    }
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1; //array vazio. tem nada ai
        int left, right;
        int l1, r1;
        int breakpoint;
        int tam = (int)nums.size();
        for(int i = 0; i < tam - 1; i++){
            if(nums[i] > nums[i + 1]){
                breakpoint = i;
                break;
            }
        }
        left = 0;
        right = breakpoint;
        l1 = breakpoint + 1;
        r1 = tam - 1;
        int ind1 = binary_search(nums, left, right, -1, target);
        int ind2 = binary_search(nums, l1, r1, -1, target);
        if(ind1 == -1 && ind2 == -1) return -1;
        return max(ind1, ind2);
    }
};
