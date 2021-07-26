class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int> position;
        for(int i = 0; i < (int)arr.size(); i++){
            if(arr[i] % 2 == 0){
                if(position.find(arr[i]/2) != position.end() && position[arr[i]/2] != i)
                    return true;
                if(position.find(arr[i]*2) != position.end() && position[arr[i]*2] != i)
                    return true;
            }else{
                if(position.find(arr[i]*2) != position.end() && position[arr[i]*2] != i)
                    return true;
            }
            position[arr[i]] = i;
        }
        return false;
    }
};
