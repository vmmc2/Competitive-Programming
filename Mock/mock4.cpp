input = 
[
 [1,5,7],
 [2,3,10],
 [4,6,9]
]

[1,5,7]
[2,3,10]
[4,6,9]

output = [1,2,3,4,5,6,7,9,10]


[1,2,5,6,7]
[23,45]
[34,56]


pointers = [1,1];
sizeOfEachVec = [2,2];

[2,2,3]



template<typename T>
class MyIterator<T> {
public:
    MyIterator(vector<vector<T>>& _input) {
        input = _input;
        n = (int) input.size();
        pointers.resize(n, 0);
        for(int i = 0; i < n; i++){
            pair<T, int> elemento = make_pair(input[i][pointers[i]];
            min_heap.push(elemento);    
        }
    }
        T next2() {
        T value;
        int row;
        tie(value, row) = min_heap.top();
        // value = min_heap.top().first;
        // row   = min_heap.top().second;
        min_heap.pop();
        pointers[row]++;
        if (pointers[row] < input[row].size()) {
            pair<T, int> element = make_pair(input[row][pointers[row]], row);
            min_heap.push(element);
        }
        return value;
    }
    T next() {
        T value = min_heap.top();
        min_heap.pop();
        for(int i = 0; i < n; i++){
            // this condition below
            if(pointers[i] < sizeOfEachVec[i]){
                T value2 = min_heap.top();
                min_heap.push(input[i][pointers[i]]);
                pointers[i]++;
                if(input[i][pointers]] <= value2) break;
            }
        }
        return value;
    }
    bool hasNext() {
        if(min_heap.empty()){
            return false;
        }
        return true;
    }
private:
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>> min_heap; // O(log(N * M)), O(N * M)
    vector<int> pointers;
    vector<vector<T>>& input;
    int n;
};


vector<int> helperFunction(vector<vector<int>>& input) {
    MyIterator<int> it(input);
    vector<int> answer;
    while (it.hasNext()) {
        answer.push_back(it.next());
    }
    return answer;
}
