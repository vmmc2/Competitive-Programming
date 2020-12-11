# Notes and tips about some of the problems that I've solved

## 01) Longest Palindrome.
* This is a tricky one because you must pay attention to all possible cases of palindromes. Basically, there are 3 cases:
  * All unique letters in the palindrome appear an even amount of times. __In this case, you should return the length of the palindrome as the answer.__
  * All unique letters in the palindrome appear an odd amount of times. __In this case, you should find the letter that appears the most. Save its number of appearances and then iterate through all the other letters summing this first value to (numberOfApperances - 1).__
  * There is a mix of unique letters that appear an odd number of times and unique letters that appear an even number of times. __In this case, you should save the number of occurences of letters that appear an even number of times and sum this to the value described in the second case.__
