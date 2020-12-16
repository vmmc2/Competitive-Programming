class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> answer;
        vector<pair<int,int>> aux;
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
            aux.push_back({qtdSoldiers, i});
        }
        sort(aux.begin(), aux.end());
        for(int i = 0; i < k; i++){
            answer.push_back(aux[i].second);
        }
        return answer;
    }
};
