#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <utility>
#include <cmath>


using namespace std;

bool rotate_matrix(vector<vector<int>> &matrix){
  if((int)matrix.size() == 0) return false;
  if((int)matrix[0].size() == 0) return false;
  int n = (int)matrix.size(); //pegando a qtd de row/columns da matriz fornecida
  for(int layer = 0; layer < n/2; layer++){
    int first = layer;
    int last = n - 1 - layer;
    for(int i = first; i < last; i++){
      int offset = i - first;
      int top = matrix[first][i];
      matrix[first][i] = matrix[last-offset][first];
      matrix[last-offset][first] = matrix[last][last - offset];
      matrix[last][last - offset] = matrix[i][last];
      matrix[i][last] = top;
    }
  }
  return true;
}

int main() {
  vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
  rotate_matrix(matrix);
  rotate_matrix(matrix);
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      cout << matrix[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
