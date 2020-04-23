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

      
      
