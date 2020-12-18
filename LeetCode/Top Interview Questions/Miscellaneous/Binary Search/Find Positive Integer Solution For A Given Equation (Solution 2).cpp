/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> answer;
        for(int i = 1; i <= 1000; i++){
            int low = 1;
            int high = 1000;
            while(low <= high){
                int mid = low + (high - low)/2;
                if(customfunction.f(i, mid) == z){
                    vector<int> pseudo;
                    pseudo.push_back(i);
                    pseudo.push_back(mid);
                    answer.push_back(pseudo);
                    break;
                }else if(customfunction.f(i, mid) > z){
                    high = mid - 1;
                }else if(customfunction.f(i, mid) < z){
                    low = mid + 1;
                }
            }
        }
        return answer;
    }
};
