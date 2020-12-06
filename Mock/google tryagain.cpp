////////////////////////////////////  QUESTION 1 ////////////////////////////////////////

#include <string>
#include <map>
#include <iostream>

using namespace std;

int solution(string S, string T) 
{
  // Your solution goes here.
  //Corner cases.
  if(S == T) return 1;
  map<char,int> freqS;
  map<char,int> freqT;
  for(int i = 0; i < (int)S.length(); i++){
    freqS[S[i]]++;
  }
  for(int i = 0; i < (int)T.length(); i++){
    freqT[T[i]]++;
  }
  for(int i = 0; i < (int)T.length(); i++){
    if(freqT[T[i]] > freqS[T[i]]) return 0;  
  }
  
  int pointerS = 0;
  int pointerT = 0;
  int counter = 0;
  
  while(pointerS < (int)S.length() && pointerT < (int)T.length()){
    if(S[pointerS] == T[pointerT]){
      pointerS++;
      pointerT++;
      counter++;
    }else{
      S[pointerS] = '-';
      pointerS++;
    }
  }
  if(counter == T.length()){
    return 1;
  }
  
  return 0;
}

int main()
{
  // Read from stdin, solve the problem, write answer to stdout.
  string S;
  string T;
  cin >> S >> T;
  cout << solution(S, T);
}

///////////////////////////// QUESTION 2 //////////////////////////////////
#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

int solution(int total_money, int total_damage, vector<int> costs, vector<int> damages)
{
  //Reminds a knapsack 0/1
  int n, W;
  n = (int)costs.size(); //qtd de cartas
  W = total_money; //dinheiro maximo
  int dp[n + 1][W + 1];
  
  for(int i = 0; i < n + 1; i++){
    for(int j = 0; j < W + 1; j++){
      if(i == 0 || j == 0) dp[i][j] = 0;
      else if(costs[i] <= j){
        dp[i][j] = max(dp[i - 1][j], damages[i] + dp[i - 1][j - costs[i]]);
      }else{
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  
  if(dp[n][W] >= total_damage){
    return 1;
  }
  
  return 0;
}

vector<int> toIntVector(string str)
{
  std::vector<int> out;
  std::string i;
  std::istringstream tokenStream(str);
  while (std::getline(tokenStream, i, ','))
  {
    out.push_back(atoi(i.c_str()));
  }
  return out;
}

int main()
{
  // Read in from stdin, solve the problem, and write answer to stdout.
  int total_money, total_damage; string costsS, damagesS;
  cin >> total_money >> total_damage >> costsS >> damagesS;
  vector<int> costs = toIntVector(costsS);
  vector<int> damages = toIntVector(damagesS);
  cout << solution(total_money, total_damage, costs, damages);
}
