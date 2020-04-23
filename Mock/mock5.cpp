// classic problem
input = "cafeteria", "cafe"
  			"cafe"   answer = 0
  
// your problem
input = "maquina" "quma"
        "quma" answer = 0

"maqu" is an anagram of "quma", so answer = 0


  
mbquina

m -> 1
b -> 1


quma
size = 4
q -> 1
u -> 1
m -> 1
a -> 1
b -> 0
  
  
bool check_hashtable(unordered_map<char,int> &hashtable, unordered_map<char,int> &hs){
  for (auto [key, value] : hs) {
    //
  }
  
  for(auto it = hashtable.begin(); it != hashtable.end(); it++){
			if(hs.find(it->first) == hs.end()){
        return false;
      }else{
        if(it->second != hs[it->first]) return false;
      }
  }
  return true;
}

O(52) + (s.size() - anam.size())*O(52) = O(1)  
  
O((s.size() - anam.size()) * (anam.size()) = O(N * M) ~ O(N²)
  
int check_anagram(string s, string anam){
  //treating the corner cases
  if(anam == "" && s == "") return 0;
  
  int n = (int)anam.size();
  unordered_map<char,int> hashtable;
  for(int i = 0; i < n; i++){
    hashtable[anam[i]]++;
  }  
  int tam = (int)s.size();
  for(int cur = 0; cur <= tam - n ; cur++){
    unordered_map<char,int> hs;
    int c1 = cur;
    int s1 = 1;
    int flag = 1; // assuming that i can found an anagram starting at cur
    while(s1 <= n){
      hs[s[c1]]++; //building our hashtable
      if(hashtable[s[c1]] == 0  || hs[s[c1]] > hashtable[s[c1]]){
        flag = 0;
        break;
      }
      s1++;
      c1++;
    }
    if(flag == 0){
      continue;
    }else{
      if(check_hashtable(hashtable, hs)){
				return cur;
      }
    }
  }
  return -1;
}




===============================================================================================
input = [1, 5, 10, 9, 6, 21], 4

maxi = 21
answer = 0
loop i - 1 until 21 --> [1,21] -- > 11

  sum = 0
  1 -> 0
  5 -> 2
  10 -> 5
  9 -> 4
  6 -> 3
  21 -> 10
  sum >= 4
   answer = max(answer, i)

L[i] = length of a wood block

pieces of size 10
  
1 -> 0
5 -> 0
10 -> 1
9 -> 0
6 -> 0
21 -> 2
---------
      3 pieces
      


Space Complexity: O(1)
Time Complexity: O(n*log(largest_element_in_array))

long long int calculate(vector<long long int> &input, int k){
	int n = (int)input.size();
  long long int maxi = -1;
  long long int answer = 0;
  for(int i = 0; i < n; i++){
  	maxi = max(maxi, input[i]);
  }
  long long int left = 1;
  long long int right = maxi;
  while(left <= right){
  	long long int mid = left + (right - left)/2;
    long long int sum = 0;
    for(int i = 0; i < n; i++){
    	sum += (input[i]/mid)*1LL;
    }
    if(sum >= k){ //we have found an answer. we must continue our search to the right
    	answer = max(answer, mid);
      left = mid + 1;
    }else{
    	right = mid - 1;
    }
  }
	return answer;
}

      
      
