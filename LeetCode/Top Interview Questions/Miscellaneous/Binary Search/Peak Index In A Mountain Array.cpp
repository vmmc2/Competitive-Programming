class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int answer = 0;
        int low = 0;
        int high = (int)arr.size() - 1;
        
        //Treating corner cases first.
        if(arr[0] > arr[1]) return 0;
        if(arr[high] > arr[high - 1]) return high;
        
        while(low < high){
            int mid = low + (high - low)/2;
            if(arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]){
                answer = mid;
                break;
            }else if(arr[mid - 1] <= arr[mid] && arr[mid] <= arr[mid + 1]){
                low = mid;
            }else if(arr[mid - 1] >= arr[mid] && arr[mid] >= arr[mid + 1]){
                high = mid;
            }else if(arr[mid - 1] >= arr[mid] && arr[mid] <= arr[mid + 1]){
                high = mid;
            }
        }
        return answer;
    }
};
