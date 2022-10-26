#include <bits/stdc++.h>
using namespace std;

// 4 bit numbers

bool getBit(int n, int p) {
	return (n & (1 << p));
}

int setBit(int n, int p) {
	return (n | (1 << p));
}

int unsetBit(int n, int p) {
	return (n & ~(1 << p));
}

int updateBit(int n, int p, int bit) {
	int masked = (n & ~(1 << p));
	return (masked | (bit << p));
}

int main() {
	int n, p;
	cin >> n >> p;
	cout << (int)getBit(n, p) << endl;
	cout << setBit(n, p) << endl;
	cout << unsetBit(n, p) << endl;
	return 0;
}