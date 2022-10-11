#include <bits/stdc++.h>
using namespace std;

/*
Calculate the maximum possible sum of subarray
*/

int bruteforce(int arr[], int n) {
	int mx = INT_MIN;
	for(int i = 0; i < n; i++) {
		int s = 0;
		for(int j = i; j < n; j++) {
			s += arr[j];
			if(s > mx)
				mx = s;
		}
	}
	return mx;
}

int kadanes(int arr[], int n) {
	int mx = INT_MIN, s = 0;
	for(int i = 0; i < n; i++) {
		s += arr[i];
		if(mx < s)
			mx = s;
		if(s < 0)
			s = 0;
	}
	return mx;
}

int main() {
	int n;
	cout << "Input n: ";
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++) 
		cin >> arr[i];
	cout << bruteforce(arr, n) << endl;
	cout << kadanes(arr, n) << endl;
	return 0;
}