#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> A)
{
  int answer = 0;
  vector<vector<int>> v;
  for(int i = 0; i < (int)A.size(); i++){
    
    if((int)v.size() == 0){ //Primeiro elemento sendo colocado na fila.
      v.push_back(vector<int>());
      //v[0].push_back(A[i]); //Maior... v[0][0]
      v[0].push_back(A[i]); //Menor... v[0][0]
      v[0].push_back(A[i]);
      answer++;
    }
    
    else{
      bool foundARow = false;
      for(int j = 0; j < (int)v.size(); j++){ //Passando por todas as filas.
        if(A[i] < v[j][0]){
          v[j][0] = A[i];
          v[j].push_back(A[i]);
          foundARow = true;
        }
      }
      if(foundARow == false){
        v.push_back(vector<int>());
        v[(int)v.size() - 1].push_back(A[i]);
        v[(int)v.size() - 1].push_back(A[i]);
        answer++;
      }
    }      
  }
  return answer; 
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
  string AS;
  cin >> AS;
  vector<int> A = toIntVector(AS);
  cout << solution(A);
}
