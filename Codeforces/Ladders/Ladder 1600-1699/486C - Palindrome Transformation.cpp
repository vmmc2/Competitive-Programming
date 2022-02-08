#include <bits/stdc++.h>
#include <sstream>
 
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, initPos;
    string s;
    int middle, answer = 0;

    cin >> n >> initPos;
    cin >> s;

    initPos--;
    
    if(n % 2 == 0){
        middle = n/2 - 1;
        int leftmostL = 0, rightmostR = n - 1;
        int rightmostL = middle, leftmostR = middle + 1;
        while(s[leftmostL] == s[rightmostR] && leftmostL < rightmostR){
            leftmostL++;
            rightmostR--;
        }
        while(s[rightmostL] == s[leftmostR] && rightmostL >= 0 && leftmostR <= n - 1){
            rightmostL--;
            leftmostR++;
        }
        if(leftmostL >= rightmostR || (rightmostL < 0 && leftmostR > n - 1)){
            cout << 0 << endl;
            return 0;
        }
        if(initPos <= middle){
            int begin, end;
            if(initPos > rightmostL){
                answer += abs(leftmostL - rightmostL) + abs(initPos - rightmostL);
            }else if(initPos >= leftmostL && initPos <= rightmostL){
                answer += min(abs(leftmostL - initPos)*2 + abs(rightmostL - initPos), abs(leftmostL - initPos) + abs(rightmostL - initPos)*2);
            }else if(initPos < leftmostL){
                answer += abs(leftmostL - rightmostL) + abs(initPos - leftmostL);
            }
            begin = leftmostL, end = rightmostL;
            //answer += min(abs(0 - initPos)*2 + abs(middle - initPos), abs(0 - initPos) + abs(middle - initPos)*2);
            for(int i = begin; i <= end; i++){
                char minLetter = (char)min((int)s[i], (int)s[n - 1 - i]);
                char maxLetter = (char)max((int)s[i], (int)s[n - 1 - i]);
                answer += min((int)maxLetter - (int)minLetter, ((int)minLetter - (int)'a') + ((int)'z' - (int)maxLetter) + 1);
            }
        }else{
            int begin, end;
            //cout << "entrei" << endl;
            if(initPos > rightmostR){
                answer += abs(leftmostR - rightmostR) + abs(initPos - rightmostR);
            }else if(initPos >= leftmostR && initPos <= rightmostR){
                answer += min(abs(leftmostR - initPos)*2 + abs(rightmostR - initPos), abs(leftmostR - initPos) + abs(rightmostR - initPos)*2);
            }else if(initPos < leftmostR){
                answer += abs(leftmostR - rightmostR) + abs(initPos - leftmostR);
            }
            begin = leftmostR, end = rightmostR;
            //cout << "answer: " << answer << endl;
            //answer += min(abs(middle + 1 - initPos)*2 + abs(n - 1 - initPos), abs(middle + 1 - initPos) + abs(n - 1 - initPos)*2);
            for(int i = begin, j = rightmostL; i <= end; i++, j--){
                char minLetter = (char)min((int)s[i], (int)s[j]);
                char maxLetter = (char)max((int)s[i], (int)s[j]);
                //cout << "minLetter: " << minLetter << " --- maxLetter: " << maxLetter << endl;
                answer += min((int)maxLetter - (int)minLetter, ((int)minLetter - (int)'a') + ((int)'z' - (int)maxLetter) + 1);
                //cout << "answer: " << answer << endl;
            }
        }
    }else{
        middle = n/2;
        //cout << middle << " " << s[middle] << endl;
        int leftmostL = 0, rightmostR = n - 1;
        int rightmostL = middle - 1, leftmostR = middle + 1; 
        while(s[leftmostL] == s[rightmostR] && leftmostL <= middle - 1 && middle + 1 <= rightmostR){
            leftmostL++;
            rightmostR--;
        }
        while(s[rightmostL] == s[leftmostR] && rightmostL >= 0 && leftmostR <= n - 1){
            rightmostL--;
            leftmostR++;
        }
        if(leftmostL == rightmostR || (rightmostL < 0 && leftmostR > n - 1)){
            cout << 0 << endl;
            return 0;
        }
        //cout << rightmostL << " " << leftmostR << endl;
        
        if(initPos < middle){
            int begin, end;
            if(initPos > rightmostL){
                answer += abs(leftmostL - rightmostL) + abs(initPos - rightmostL);
            }else if(initPos >= leftmostL && initPos <= rightmostL){
                answer += min(abs(leftmostL - initPos)*2 + abs(rightmostL - initPos), abs(leftmostL - initPos) + abs(rightmostL - initPos)*2);
            }else if(initPos < leftmostL){
                answer += abs(leftmostL - rightmostL) + abs(initPos - leftmostL);
            }
            begin = leftmostL, end = rightmostL;
            for(int i = begin; i <= end; i++){
                char minLetter = (char)min((int)s[i], (int)s[n - 1 - i]);
                char maxLetter = (char)max((int)s[i], (int)s[n - 1 - i]);
                answer += min((int)maxLetter - (int)minLetter, ((int)minLetter - (int)'a') + ((int)'z' - (int)maxLetter) + 1);
            }
        }else if(initPos > middle){
            int begin, end;
            //cout << "entrei" << endl;
            if(initPos > rightmostR){
                answer += abs(leftmostR - rightmostR) + abs(initPos - rightmostR);
                //cout << "entrei2" << endl;
            }else if(initPos >= leftmostR && initPos <= rightmostR){
                //cout << "entrei3" << endl;
                answer += min(abs(leftmostR - initPos)*2 + abs(rightmostR - initPos), abs(leftmostR - initPos) + abs(rightmostR - initPos)*2);
            }else if(initPos < leftmostR){
                answer += abs(leftmostR - rightmostR) + abs(initPos - leftmostR);
                //cout << "entrei4" << endl;
            }
            //cout << "answer1: " << answer << endl;
            begin = leftmostR, end = rightmostR;
            //cout << "begin: " << begin << " --- end: " << end << endl;
            for(int i = begin, j = middle - abs(leftmostR - middle); i <= end; i++,  j--){
                char minLetter = (char)min((int)s[i], (int)s[j]);
                char maxLetter = (char)max((int)s[i], (int)s[j]);
                answer += min((int)maxLetter - (int)minLetter, ((int)minLetter - (int)'a') + ((int)'z' - (int)maxLetter) + 1);
                //cout << "answer2: " << answer << endl;
            }
        }else{
            int begin, end;
            answer += abs(middle - rightmostL) + abs(leftmostL - rightmostL);
            begin = leftmostL, end = rightmostL;
            for(int i = begin; i <= end; i++){
                char minLetter = (char)min((int)s[i], (int)s[n - 1 - i]);
                char maxLetter = (char)max((int)s[i], (int)s[n - 1 - i]);
                answer += min((int)maxLetter - (int)minLetter, ((int)minLetter - (int)'a') + ((int)'z' - (int)maxLetter) + 1);
            }
        }
    }

    cout << answer << endl;

    return 0;
}
