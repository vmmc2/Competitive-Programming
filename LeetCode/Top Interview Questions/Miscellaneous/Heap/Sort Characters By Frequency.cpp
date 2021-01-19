bool compare(pair<char,int> p1, pair<char,int> p2){
    if(p1.second <= p2.second){
        return true;
    }else{
        return false;
    }
}

class Solution {
public:
    string frequencySort(string s) {
        string answer = "";
        unordered_map<char,int> freq;
        priority_queue<pair<char,int>, vector<pair<char,int>>, function<bool(pair<char,int>, pair<char,int>)>> maxHeap(compare);
        for(int i = 0; i < (int)s.size(); i++){
            freq[s[i]]++;
        }
        for(unordered_map<char,int>::iterator it = freq.begin(); it != freq.end(); it++){
            maxHeap.push({it->first, it->second});
        }
        while(!maxHeap.empty()){
            pair<char,int> aux = maxHeap.top();
            maxHeap.pop();
            for(int i = 0; i < aux.second; i++){
                answer += aux.first;
            }
        }
        return answer;
    }
};
