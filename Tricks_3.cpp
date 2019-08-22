#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define INF 9999999
#define pb push_back
#define pii pair<int,int>

using namespace std;

typedef long long ll;

int main(){
	//Sorting is a fundamental algorithm design problem. Many efficient algorithms
	//use sorting as a subroutine, because it is often easier to process data if the
	//elements are in a sorted order.

	//The efficient general sorting
	//algorithms work in O (n*log(n)) time, and many algorithms that use sorting as a
	//subroutine also have this time complexity.

	//Algoritmo de Ordenacao Bubble-Sort ----- TIME COMPLEXITY: O(n2)
	//Algoritmo de Ordenacao Selection-Sort -- TIME COMPLEXITY: O(n2)
	
	A useful concept when analyzing sorting algorithms is an inversion: a pair
	of array elements ( array [ a ], array [ b ]) such that a < b and array [ a ] > array [ b ], i.e.,
	the elements are in the wrong order. Usually, the number of inversions indicates how much work will
	have to be done in order to sort the array.
	If there are no inversions, then the array is already sorted. On the other hand, if the array is reversed,
	then the number of inversions is maximal.
	Swapping a pair of consecutive elements that are in the wrong order removes
	exactly one inversion from the array.
		
	//Algoritmo de Ordenacao Counting Sort ---- TIME COMPLEXITY: O(n)
	The lower bound n log n does not apply to algorithms that do not compare array
	elements but use some other information. An example of such an algorithm is
	counting sort that sorts an array in O ( n ) time assuming that every element in
	the array is an integer between 0 . . . c and c = O ( n ).
	The algorithm creates a bookkeeping array, whose indices are elements of the
	original array. The algorithm iterates through the original array and calculates
	how many times each element appears in the array.
	Construction of the bookkeeping array takes O ( n ) time. After this, the sorted
	array can be created in O ( n ) time because the number of occurrences of each
	element can be retrieved from the bookkeeping array. Thus, the total time
	complexity of counting sort is O ( n ).
	Counting sort is a very efficient algorithm but it can only be used when the
	constant c is small enough, so that the array elements can be used as indices in
	the bookkeeping array.
		
	//Sorting in C++
	//1. Usually, if we want to sort an array in increasing order we do as the following:
	vector<int> v = {23, 4534, 65, -76, 454, 65};
	sort(v.begin(), v.end());
	//2. But, what if we want to sort the array in decreasing order? What should we do?
	sort(v.rbegin(), v.rend());
	//3. An ordinary array can be sorted in the following way:
	sort(v, v + tamanho_de_v);
	//4. We can also sort strings:
	string s = "monkey"
	sort(s.begin(), s.end());
	After that, we have: s = "ekmnoy"
		
	//Sorting with User-Defined Structs
	User-defined structs do not have a comparison operator automatically. The
	operator should be defined inside the struct as a function operator< , whose
	parameter is another element of the same type. The operator should return true
	if the element is smaller than the parameter, and false otherwise.
	For example, the following struct P contains the x and y coordinates of a point.
	The comparison operator is defined so that the points are sorted primarily by the
	x coordinate and secondarily by the y coordinate.
		
	struct P {
		int x, y;
		bool operator<(const P &p) {
			if (x != p.x) return x < p.x;
			else return y < p.y;
		}
	};
	
	//LINEAR SEARCH ---- O(n)
	//BINARY SEARCH ---- O(log n)
	
	



	return 0;
}
