/*
ID: lisendo1
PROG: sprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
ifstream in("sprime.in");
ofstream out("sprime.out");
int a[10] = {0};
bool is_prim(int length) {
	int sum = 0, e = length - 1;
	for (int i = 0; i < length; i++) {
		sum += a[i] * pow(10, e--);
	}
	if (sum == 1) return 0;
	if (sum == 2 || sum == 3) return 1;
	if (sum % 2 == 0) return 0;
	int j;
	for (j = 3; j <= sqrt(sum) + 1; j+=2) {
		if (sum % j == 0) return 0;
	}
	return 1;
}
void dfs(int step, int length) {
	if (step == length) {
		int sum = 0, e = length - 1;
		for (int i = 0; i < length; i++) {
			sum += a[i] * pow(10, e--);
		}
		out << sum << endl;
		return;
	}
	int d;
	for (d = 1; d <= 9; d++) {
		a[step] = d;
		if (is_prim(step + 1)) {
			dfs(step + 1, length);
		}
	}
}

int main() {
	int N;
	in >> N;
	dfs(0, N);
	return 0;
}
