bool compare(pair<int,int> p1, pair<int,int> p2){
    if( (p1.first*p1.first) + (p1.second*p1.second) <= (p2.first*p2.first) + (p2.second*p2.second) ){
        return false;
    }else{
        return true;
    }
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, function<bool(pair<int,int>,pair<int,int>)>> minHeap(compare);
        vector<vector<int>> answer;
        for(int i = 0; i < (int)points.size(); i++){
            minHeap.push({points[i][0], points[i][1]});
        }
        for(int i = 0; i < K; i++){
            vector<int> curr;
            pair<int,int> aux = minHeap.top();
            minHeap.pop();
            curr.push_back(aux.first);
            curr.push_back(aux.second);
            answer.push_back(curr);
        }
        return answer;
    }
};
