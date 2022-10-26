#include <bits/stdc++.h>
using namespace std;

/*
Consider a board given by a matrix where 0 means obstruction and 1 means free.
Find the exit
*/

bool isFree(bool** arr, int i, int j, int n) {
	if( i < n && j < n && arr[i][j] == 1)
		return true;
	return false;
}

bool rat(bool** arr, int i, int j, int n, bool** res) {
	if(i == n-1 && j == n-1) {
		res[i][j] = 1;
		return true;
	}
	if(isFree(arr, i, j, n)) {
		res[i][j] = 1;
		if(rat(arr, i+1, j, n, res))
			return true;
		if(rat(arr, i, j+1, n, res))
			return true;
		res[i][j] = 0;
		return false;
	}
	return false;
}

int main() {
	int  n;
	cin >> n;
	bool** arr = new bool*[n];
	for(int i = 0; i < n; i++)
		arr[i] = new bool[n];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> arr[i][j];
	bool** res = new bool*[n];
	for(int i = 0; i < n; i++)
		res[i] = new bool[n];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			res[i][j] = 0;
	rat(arr, 0, 0, n, res);
	cout << endl;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}