#include <bits/stdc++.h>
using namespace std;

bool isPow2(int n) {
	return (n && !(n & n-1));
}
/*
n-1 has all bits set before the right-most set bit of n
n = 8 = 1000         n = 6 = 0110
n-1 = 7 = 0111       n-1 = 5 = 0101

Now, any power of 2 in binary has only the leftmost bit set and if it is n then n-1 will have all bits set and the leftmost cleared
Hence the bitwise AND on n and n-1 should result in 0 if it is a power of 2
*/

int countSetBits(int n) {
	int c = 0;
	while(n) {
		c++;
		n &= n-1;
	}
	return c;
}

/*
Using the same logic, during the operation 1 bit is lost. We can repeat the operation till the number is 0 and count the times the operation was performed.
Giving us the number of set bits.
*/

void listSubsets() {
	char arr[] = {'a', 'b', 'c'};
	int n = 3;
	for(int i = 0; i < (1 << n); i++) {
		cout << "{";
		for(int j = 0; j < n; j++) {
			if(i & (1 << j))
				cout << arr[j] << ", ";
		}
		i? cout << "\b\b}" << endl: cout << "}" << endl;
	}
}

/*
Total number of subsets = 2**n as it is a choice for every subset whether or not to include a particular element
So for every iteration of i loop from 0 till 2**n-1 (1 << n = 2**n)
for every element in list, we get the jth bit of i
*/

int numPresentOnlyOnce() {
	// In a list where all elements exists twice, find one which doesn't
	int arr[] = {2, 6, 4, 3, 4, 6, 2};
	int l = 7;
	int n = 0;
	for(int i = 0; i < l; i++)
		n ^= arr[i];
	return n;
}
/*
XOR gives 0 for (0 XOR 0) and (1 XOR 1) else 1
So XOR of same numbers gives 0
*/

bool isBitSet(int n, int p) {
	// Gets bit at index
	return (n & (1 << p));
}

void numsPresentOnlyOnce() {
	// same for two such numbers
	int arr[] = {2, 4, 6, 7, 4, 5, 6, 2};
	int l = 8;
	int n = 0;
	for(int i = 0; i < l; i++)
		n ^= arr[i];
	// We have the difference of the numbers
	int rset = 0, pos = 0, cp = n;
	while(rset != 1) {
		rset = cp & 1;
		pos++;
		cp = cp >> 1;
	}
	pos--;
	// Find the right most set bit position
	int n1 = 0;
	for(int i = 0; i < l; i++) {
		if(isBitSet(arr[i], pos))
			n1 ^= arr[i];
	}
	// All elements with bit set at pos will be XORed, only 1 of the unique element will be found at end as all other elements will XOR 0
	cout << n1 << " " << (n^n1) << endl;
	// We have the first unique element and second can be found by XOR of the first and difference of the 2
}

int setBit(int n, int p) {
	return (n | (1 << p));
}

int numOnlyOnce() {
	// In a list containing elements which occur thrice, find the one that exists only once
	int arr[] = {1, 3, 2, 3, 4, 2, 1, 1, 3, 2};
	int n = 10, res = 0;
	for(int i = 0; i < 64; i++) { // assuming 64bit architecture, for each bit
		int s = 0;
		for(int j = 0; j < n; j++) { // in each element
			if(isBitSet(arr[j], i)) // check if current bit is set
				s++;
		}
		if((s % 3) != 0) // if the current bit does not exist thrice, it belongs to the unique number
			res = setBit(res, i);
	}
	return res;
}

int main() {
	int n;
	cin >> n;
	cout << isPow2(n) << endl;
	cout << countSetBits(n) << endl;
	listSubsets();
	cout << numPresentOnlyOnce() << endl;
	numsPresentOnlyOnce();
	cout << numOnlyOnce() << endl;
	return 0;
}