class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3;
        for(int i = 0; i < (int)nums1.size(); i++){
            nums3.push_back(nums1[i]);
        }
        int i = 0;
        int j = 0;
        int k = 0;
        while(i < m && j < n){//i referente ao nums3 e j referente ao nums2
            //k eh referente ao nums1
            if(nums3[i] <= nums2[j]){
                nums1[k] = nums3[i];
                k++;
                i++;
            }else if(nums3[i] > nums2[j]){
                nums1[k] = nums2[j];
                k++;
                j++;
            }
        }
        if(i == m){//exauri o vetor nums3. tenho que tirar do nums2
            while(j < n){
                nums1[k] = nums2[j];
                k++;
                j++;
            }
        }
        else if(j == n){//exauri o vetor nums2. tenho que tirar do nums3
            while(i < m){
                nums1[k] = nums3[i];
                i++;
                k++;
            }
        }
    }
};
