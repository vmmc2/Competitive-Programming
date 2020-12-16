class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char answer1;
        int answer;
        int n = (int)letters.size();
        int low = 0;
        int high = n - 1;
        
        //Basicamente, se o target estiver dps do ultimo char do vector, tem que retornar
        //o primeiro char do vector.
        if((int)target < (int)letters[0]) return letters[0];
        if((int)target >= (int)letters[n - 1]) return letters[0];
        while(low <= high){
            int mid = low + (high - low)/2;
            if((int)target == (int)letters[mid]){
                answer = (mid + 1)%n;
                answer1 = letters[(mid + 1)%n];
                low = mid + 1;
            }
            else if((int) target < (int)letters[mid]){
                answer = mid;
                answer1 = letters[mid];
                high = mid - 1;
            }else if((int)target > (int)letters[mid]){
                low = mid + 1;
            }
        }
        return answer1;
    }
};
