class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int i = 0;
        int n = (int)arr.size();
        
        while(i < n){
            int x = i;
            int increment = 0;
            bool notFound = false;
            for(auto vec : pieces){
                if(arr[x] == vec[0]){
                    bool ok = true;
                    for(auto ele : vec){
                        if(arr[x] != ele) ok = false;
                        x++;
                    }
                    if(ok == true){
                        notFound = true;
                        increment += (int)vec.size();
                        break;    
                    }
                }
            }
            if(notFound == false) return false;
            i += increment;
        }
        return true;
    }
};
