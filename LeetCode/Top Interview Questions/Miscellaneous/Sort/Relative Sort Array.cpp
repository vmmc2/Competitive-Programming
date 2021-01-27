class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> elemsArr1;
        map<int,int> elemsArr2;
        vector<int> arr1Final;
        vector<int> notInArr2;
        for(auto x : arr1){
            elemsArr1[x]++;    
        }
        for(auto x : arr2){
            elemsArr2[x]++;
        }
        for(map<int,int>::iterator it = elemsArr1.begin(); it != elemsArr1.end(); it++){
            if(elemsArr2.find(it->first) == elemsArr2.end()){
                for(int i = 0; i < it->second; i++){
                    notInArr2.push_back(it->first);    
                }
            }
        }
        for(int i = 0; i < (int)arr2.size(); i++){
            int curr = arr2[i];
            for(int j = 0; j < elemsArr1[curr]; j++){
                arr1Final.push_back(curr);
            }
        }
        for(auto x : notInArr2){
            arr1Final.push_back(x);
        }
        
        return arr1Final;
    }
};
