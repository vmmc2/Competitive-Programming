#include <bits/stdc++.h>

using namespace std;

int rotated_array(vector<int> &v){ //tem que achar o index onde temos o ponto de vale ("valley point").
    int n = (int)v.size();
    int low = 0;
    int high = n - 1;
    while(low <= high){
        if(v[low] <= v[high]) return low;
        int mid = low + (high - low)/2;
        int prev = (mid + n - 1) % n;
        int next = (mid + 1) % n;
        //checagem para o ponto de vale.
        if(v[prev] >= v[mid] && v[mid] <= v[next]) return mid;
        if(v[low] <= v[mid]){
            low = mid + 1;
        }
        if(v[mid] <= v[high]){
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> v = {11,12,13,15,17,20,1};
    int how_many = rotated_array(v);
    if(how_many == -1){
        cout << "invalid array provided in the input." << "\n";
    }else{
        cout << "the array was rotated: " << how_many << " times." << "\n";
    }
    
    return 0;
}
