/*
ID: lisendo1
PROG: subset
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#define MAX_LENGTH 160*160
using namespace std;
ifstream in("subset.in");
ofstream out("subset.out");
unsigned int f[40][8000] = {0};
int N;
int main() {
	in >> N;
	int i, j, num;
	num = (1 + N) * N / 2;
	if (num % 2 != 0) {
		out << 0 << endl;
		return 0;
	}
	num /= 2;
	f[1][1] = 1;
	for (i = 1; i <= N; i++) {
		f[i][0] = 1;
	}
	for (i = 2; i <= N; i++) {
		for (j = 1; j <= num; j++) {
			if (j < i) f[i][j] = f[i - 1][j];
			else f[i][j] = f[i - 1][j] + f[i - 1][j - i];
		}
	}
	out << f[N][num] / 2<< endl;
	return 0;
}