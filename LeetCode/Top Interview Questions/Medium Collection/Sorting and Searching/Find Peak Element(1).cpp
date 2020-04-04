class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if((int)nums.size() == 1) return 0;
        int n = (int)nums.size();
        //checando agr os conner case em que o peak element eh o primeiro ou o ultimo elemento do array.
        if(nums[0] > nums[1]) return 0;
        else if(nums[n - 1] > nums[n - 2]) return n - 1;
        //Se chegou aqui, eh porque o peak element ta pelo meio do array. tem que fazer binary search.
        int low = 0;
        int high = n - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            //checando se achei um peak element.
            if(nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) return mid;
            //se eu achei um valley, continuo buscando para a esquerda.
            if(nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1]){
                high = mid;
            }
            if(nums[mid - 1] > nums[mid] && nums[mid] > nums[mid + 1]){ //busco para a esquerda.
                high = mid;
            }
            if(nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1]){ //busco para a direita.
                low = mid;
            }
        }
        return high;
    }
};
