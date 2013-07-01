/*
ID: lisendo1
PROG: nocows
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <map>
#include <cstdio>
#define MAX_LENGTH 160*160
using namespace std;
ifstream in("nocows.in"); 
ofstream out("nocows.out");
int N, K;
int smaller[300][200] = {0};
int main() {
	in >> N >> K;
	int i, j, k;
	for (j = 1; j <= K; j++) {
		smaller[1][j] = 1;
	}
	for (i = 2; i <= N; i++) {
		for (j = 2; j <= K; j++) {
			for (k = 1; k <= i - 2; k++) {
				smaller[i][j] += smaller[k][j - 1]  * smaller[i - 1 - k][j - 1];
				smaller[i][j] %= 9901;
			}
		}
	}
	out << (smaller[N][K] - smaller[N][K - 1] + 9901) % 9901 << endl;
	return 0;
}
