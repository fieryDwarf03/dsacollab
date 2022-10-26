#include<bits/stdc++.h>
using namespace std;

/*
Given a board of 2xN and tiles of size 2x1. Count the number of ways to tile the board.
*/

int count(int n) {
	if(n == 0 || n == 1) return n;
	return (count(n-1)+count(n-2));
}

int main() {
	int n;
	cin >> n;
	count(n);
	return 0;
}