class Solution {
public:
    void sortColors(vector<int>& nums) {
        if((int)nums.size() == 0 || (int)nums.size() == 1) return;
        int start = 0;
        int end = (int)nums.size() - 1;
        int index = 0;
        int temp;
        while(start < end && index <= end){
            if(nums[index] == 0){
                temp = nums[start];
                nums[start] = nums[index];
                nums[index] = temp;
                start++;
                index++;
            }else if(nums[index] == 2){
                temp = nums[end];
                nums[end] = nums[index];
                nums[index] = temp;
                end--; 
                //eu n incremento o index aqui pq eu posso ter pego um '0' do final e ter colocado no meio do 
                //array. Por causa disso, eu mantenho o cursor, para que na proxima iteracao eu jogue o '0' para
                //o inicio do array.
            }else{
                index++;
            }
        }
    }
};
