/*
ID: lisendo1
PROG: hamming
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#define MAX_LENGTH 160*160
using namespace std;
ifstream in("hamming.in");
ofstream out("hamming.out");
int result[100];
int N, B, D;
int dis(int a, int b) {
	a = a ^ b;
	int count = 0;
	while (a != 0) {
		if (a & 1)
			count++;
		a >>= 1;
	}
	return count;
}
int check(int num, int step) {
	for (int i = 0; i < step; i++) {
		if (dis(num, result[i]) < D) return 0;
	}
	return 1;
}
int dfs(int step, int depth) {
	int i;
	if (step == depth) {
		for (i = 0; i < depth; i++) {
			if (i != 0 && i % 10 != 0) out << " ";
			out << result[i];
			if (i % 10 == 9 && i > 0) out << endl;
		}
		if (i % 10 != 0) out << endl;
		return 1;
	}
	for (i = result[step - 1] + 1; i <= pow(2, B) - 1; i++) {
		if (check(i, step)) {
			result[step] = i;
			if (dfs(step + 1, depth)) return 1;
		}
	}
	return 0;
}
int main() {
	in >> N >> B >> D;
	int i;
	for (i = 0; i <= pow(2, B) - 1; i++) {
		result[0] = i;
		if(dfs(1, N)) break;
	}
	return 0;
}