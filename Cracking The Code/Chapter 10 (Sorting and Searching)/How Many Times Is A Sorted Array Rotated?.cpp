#include <bits/stdc++.h>

using namespace std;

int find_rotation(vector<int> &v){
    int n = (int)v.size();
    int low = 0;
    int high = n - 1;
    while(low <= high){
        if(v[low] < v[high]) return low;
        int mid = low + (high - low)/2;
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) % n;
        if(v[prev] > v[mid] && v[mid] < v[next]) return mid;
        else if(v[low] <= v[mid]){
            low = mid + 1;
        }else if(v[mid] <= v[high]){
            high = mid - 1;
        }
    }
    return -1; //case of invalid input vector
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> v = {2,3,4,5,7};
    
    int num_rotations = find_rotation(v);
    cout << num_rotations << "\n";
    
    return 0;
}
