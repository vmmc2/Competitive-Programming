input = "i     love     algorithms very       much"
output = "i 

  
output = "i love algorithms very much"


input = "                                 "
  
output = " "
  
string remove_extra_spaces(string input){
  string output = "";
  // output += c // o(1)
  // output += outra_str // o(len(outra_str));
  // output = output + outra_str  // o(len(output) + len(outra_str)) o(n)
  int cursor = 0;
  int flag = 0;
  int n = (int)input.size();
  cursor = n - 1;
  int lastindex = n;
  while(true){
    if(input[cursor] != ' '){
      lastindex = cursor + 1;
      break;
    }
    cursor--;
  }
  cursor = 0;
  while(cursor < n){
    if(cursor == lastindex) break;
    if(cursor == 0 && input[cursor] == ' '){
      flag = 1;
    }
    if(input[cursor] != ' '){
      output += input[cursor];
      flag = 0;
    }
    else if(input[cursor] == ' ' && flag == 0){
      output += ' ';
      flag = 1;
    }
    cursor++;
  }
  return output;
}

-----------------------------------
A = 1
B = 2
C = 3
Z = 26
AA = 27
AB = 28
AC = 29
CCC = 2109
  
C            C       C
(26*26*3)  (26*3)    (3*26^0)
    
result = 0
result = result(0) + (3) * (26^0)
result = (3*(26^0) + (3)*(26^1)
result = (3*(26^0)) + (3)*(26^1) + (3)*(26^2)

int calculate(string s){
  int n = (int) s.size();
  int result = 0;
  int exp = 1;
  for(int i = n - 1; i >= 0; i--, exp *= 26){
    result += (s[i] - 'A' + 1) * exp;
  }
  return result;
}
