/*
ID: lisendo1
PROG: checker
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
ifstream in("checker.in");
ofstream out("checker.out");
int N;
int num = 0;
int result[20] = {0};
int place[20][20] = {0};
int col_busy[20] = {0};
int l2r[30] = {0}, r2l[30] = {0};
int w_l2r[20][20];
int w_r2l[20][20];
bool ok(int step, int j) {
	if (col_busy[j] == 1) return 0;
	if (r2l[w_r2l[step][j]] == 1) return 0;
	if (l2r[w_l2r[step][j]] == 1) return 0;
	//for (int m = -1; m <= 1; m+=2) {
	//	for (int n = -1; n <= 1; n+=2) {
	//		for (row = step, col = j; row >= 0 && row < N && col >= 0 && col < N; row +=m, col += n) {
	//			if (place[row][col] == 1) return 0;
	//		}
	//	}
	//}
	return 1;
}
void dfs(int step) {
	if (step == N) {
		if (num < 3) {
			for (int i = 0; i < N; i++) {
				if (i != 0) out << " ";
				out << result[i] + 1;
			}
			out << endl;
		}
		num ++;
		return ;
	}
	int j;
	for (j = 0; j < N; j++) {
		if (ok(step, j)) {
			col_busy[j] = 1;
			l2r[w_l2r[step][j]] = 1;
			r2l[w_r2l[step][j]] = 1;
			result[step] = j;
			place[step][j] = 1;
		}
		else continue;
		dfs(step + 1);
		place[step][j] = 0;
		col_busy[j] = 0;
		l2r[w_l2r[step][j]] = 0;
		r2l[w_r2l[step][j]] = 0;
	}
}
int main() {
	in >> N;
	int line = 0, i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			w_l2r[i][j] = line++;
		}
		line = line - N + 1;
	}
	line = 0;
	for (i = 0; i < N; i++) {
		for (j = N - 1; j >= 0; j--) {
			w_r2l[i][j] = line++;
		}
		line = line - N + 1;
	}
	dfs(0);
	out << num << endl;
	return 0;
}