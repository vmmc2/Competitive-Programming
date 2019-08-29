#include <map>
#define pb push_back
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> hashtable1;
        map<int,int> hashtable2;
        vector<int> answer;
        for(int i = 0; i < (int)nums1.size(); i++){
            hashtable1[nums1[i]]++;
        }
        for(int i = 0; i < (int)nums2.size(); i++){
            hashtable2[nums2[i]]++;
        }
        if((int)hashtable1.size() >= (int)hashtable2.size()){
            for(auto it = hashtable1.begin(); it != hashtable1.end(); ++it){
                if(it->second >= 1 && hashtable2[it->first] >= 1){
                    int minimo = min(it->second, hashtable2[it->first]);
                    for(int i = 1; i <= minimo; i++){
                        answer.pb(it->first);
                    }
                }
            }
        }else{
            for(auto it = hashtable2.begin(); it != hashtable2.end(); ++it){
                if(it->second >= 1 && hashtable1[it->first] >= 1){
                    int minimo = min(it->second, hashtable1[it->first]);
                    for(int i = 1; i <= minimo; i++){
                        answer.pb(it->first);
                    }
                }
            }
        }
        return answer;
    }
};
