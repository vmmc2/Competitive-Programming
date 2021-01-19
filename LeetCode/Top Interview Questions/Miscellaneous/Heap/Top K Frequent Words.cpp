bool compare(pair<string,int> p1, pair<string,int> p2){
    if(p1.second < p2.second){
        return true;
    }else if(p1.second == p2.second){
        if(p1.first <= p2.first){
            return false;
        }else{
            return true;
        }
    }else{
        return false;
    }
}

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        vector<string> answer;
        priority_queue<pair<string,int>, vector<pair<string,int>>, function<bool(pair<string,int>, pair<string,int>)>> maxHeap(compare);
        
        for(int i = 0; i < (int)words.size(); i++){
            freq[words[i]]++;
        }
        for(unordered_map<string,int>::iterator it = freq.begin(); it != freq.end(); it++){
            maxHeap.push({it->first, it->second});
        }
        for(int i = 0; i < k; i++){
            pair<string,int> aux = maxHeap.top();
            maxHeap.pop();
            answer.push_back(aux.first);
        }
        return answer;
    }
};
