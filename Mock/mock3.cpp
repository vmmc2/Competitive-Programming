"abc" -> invalid

dict maps from char -> vector<string>

{
  "a": ["bb", "cc", "dd"]
  "b": ["rato"]
  "c": ["xab", "lau"]
}

["bbratoxab", "bbratolau", "ccratoxab", "ccratolau", "ddratoxab", "ddratolau"]


'a'             bb           cc           dd

'b'            rato         rato         rato

'c'        xab    lau      xab lau     xab lau


produtorio(dict[ch].size() p/ todo ch pertencente a password)


[bbratoxab, bbratolau, ccratoxab, ccratolau, ddratoxab, ddratolau]

0  2
1  2
2  2
3  2
  
  
void helper(string agr)
n caracteres

(1+2+3+4+...+n) ~ n*(n+1)/2 ~ n²

void helper(int cursor, int finale, vector<string> &answer, map<char,vector<string>> &dict, string &password, string agr){
  if(cursor > finale){
    answer.push_back(agr);
    return;
  }
  vector<string> now = dict[password[cursor]];
  for(int i = 0; i < (int)now.size(); i++){
      string cur = agr + now[i];
      helper(cursor + 1, finale, answer, dict, password, cur);
  }
  return;
}

vector<string> generate_valid_passwords(string& password, map<char,vector<string>> &dict){
  vector<string> answer;
  if(password.length() == 0) return answer;
  int cursor = 0;
  string agr = "";
  int n = (int) password.length();
  helper(cursor, n - 1, answer, dict, password, agr);
  return answer;
}


-----------------------------------------------------
bool checkCommitForBugs(Commit c);

0 -> we do not have a bug
1 -> we have a bug
       
[0,0,0,0,0]
       
int checkfirstbuggyversion(vector<Commit> &v){
  int n = (int)v.size();
  if(n == 0) return -1;
  int low = 0;
  int high = n - 1;
  int answer = -1;
  while(low <= high){
    int mid = low + (high - low)/2; // mid = (low + high)/2;
    if(checkCommitForBugs(v[mid]) == true){
      answer = mid;
      high = mid - 1;
    }else{
      low = mid + 1;
    }
  }
  return answer;
}
