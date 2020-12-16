class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> answer;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        int m = (int)mat.size();
        int n = (int)mat[0].size();
        
        for(int i = 0; i < m; i++){
            int low = 0;
            int high = n - 1;
            int qtdSoldiers = n; //Se eu nao achar nenhum 0, quer dizer que a linha inteira ta preenchida com '1'.
            while(low <= high){
                int mid = low + (high - low)/2;
                if(mat[i][mid] == 0){
                    qtdSoldiers = mid;
                    high = mid - 1;
                }else if(mat[i][mid] == 1){
                    low = mid + 1;
                }
            }
            cout << "i: " << i << " qtdSoldiers: " << qtdSoldiers << endl;
            minHeap.push({qtdSoldiers, i});
        }
        for(int i = 1; i <= k; i++){
            auto x = minHeap.top();
            minHeap.pop();
            answer.push_back(x.second);
        }
        return answer;
    }
};
