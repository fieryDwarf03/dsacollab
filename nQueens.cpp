#include<bits/stdc++.h>
using namespace std;

void display(bool** arr, int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			cout << (arr[i][j]? "Q ": "_ ");
		cout << endl;
	}
	cout << endl;
}

bool isValidPos(bool** arr, int n, int x, int y) {
	for(int i = 0; i < x; i++) {
		if(arr[i][y]) return false;
	}
	int i = x, j = y;
	while( i >= 0 && j >= 0) {
		if(arr[i][j]) return false;
		i--; j--;
	}
	i = x; j = y;
	while(i >= 0 && j < n) {
		if(arr[i][j]) return false;
		i--; j++;
	}
	return true;
}

bool place(bool** arr, int n, int idx) {
	if(idx == n) { display(arr, n); return true; }
	for(int i = 0; i < n; i++) {
		if(isValidPos(arr, n, idx, i)) {
			arr[idx][i] = 1;
			place(arr, n, idx+1);
			arr[idx][i] = 0;
		}
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	bool** arr = new bool*[n];
	for(int i = 0; i < n; i++)
		arr[i] = new bool[n];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			arr[i][j] = 0;
	place(arr, n, 0);
	return 0;
}