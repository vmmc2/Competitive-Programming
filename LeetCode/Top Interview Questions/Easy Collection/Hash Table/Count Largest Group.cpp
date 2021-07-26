class Solution {
public:
    int getSumDigits(int n){
        int answer = 0;
        while(n != 0){
            answer += n % 10;
            n = n/10;
        }
        
        return answer;
    }
    int countLargestGroup(int n) {
        map<int,int> freq;
        int x = 1;
        int answer = 0;
        for(int i = 1; i <= n; i++){
            freq[getSumDigits(i)]++;
        }
        for(map<int,int>::iterator it = freq.begin(); it != freq.end(); it++){
            x = max(x, it->second);
        }
        for(map<int,int>::iterator it = freq.begin(); it != freq.end(); it++){
            if(it->second == x) answer++;
        }
        return answer;
    }
};
