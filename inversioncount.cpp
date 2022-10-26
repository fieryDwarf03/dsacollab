#include <bits/stdc++.h>
using namespace std;
/*
An inversion occurs when arr[i] > arr[j] and i < j
Count number of inversions
*/

int count(int arr[], int n) {
	// N**2
	int c = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++)
			if(arr[i] > arr[j])
				c++;
	}
	return c;
}

long long merge(int arr[], int l, int m, int r) {
	long long c = 0;
	int n1 = m-l+1, n2 = r-m;
	int a[n1], b[n2];
	for(int i = 0; i < n1; i++) a[i] = arr[l+i];
	for(int i = 0; i < n2; i++) b[i] = arr[m+1+i];
	int i = 0, j = 0, k = l;
	while(i < n1 && j < n2) {
		if(a[i] <= b[j]) {
			arr[k] = a[i];
			k++; i++;
		} else {
			arr[k] = b[j];
			k++; j++;
			c += (n1 - i);
		}
	}
	while(i < n1) {
		arr[k] = a[i];
		k++; i++;
	}
	while(j < n2) {
		arr[k] = b[j];
		j++; k++;
	}
	return c;
}

long long count(int arr[], int l, int r) {
	long long c = 0;
	if(l < r) {
		int m = (l+r)/2;
		c += count(arr, l, m);
		c += count(arr, m+1, r);
		c += merge(arr, l, m, r);
	}
	return c;
}

int main() {
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> n;
	cout << count(arr, n) << endl;
	cout << count(arr, 0, n-1) << endl;
	return 0;
}