/*
ID: lisendo1
PROG: comehome
LANG: C++
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <map>
#include <cstdio>
#define oo 1000000
#define MAX_N 10
using namespace std;
ifstream in("comehome.in"); 
ofstream out("comehome.out");
int dis[60][60] = {0};
int trans(char a) {
	if (a >= 'a') return a - 'a';
	else return 26 + a - 'A';
}
int main() {
	int N, i, j, m;
	in >> N;
	char a, b;
	int tmp_dis;
	int t_a, t_b;
	for (i = 0; i < 60; i++) {
		for (j = 0; j < 60; j++) {
			dis[i][j] = oo;
			if (i == j) dis[i][j] = 0;
		}
	}
	for (i = 0; i < N; i++) {
		in >> a >> b >> tmp_dis;
		t_a = trans(a);
		t_b = trans(b);
		//cout << t_a << " " << t_b << " " << tmp_dis << endl;
		if (tmp_dis < dis[t_a][t_b]) {
			dis[t_a][t_b] = tmp_dis;
			dis[t_b][t_a] = tmp_dis;
		}
	}
	for (m = 0; m < 52; m++) {
		for (i = 0; i < 52; i++) {
			for (j = 0; j < 52; j++) {
				if (dis[i][j] > dis[i][m] + dis[j][m]) {
					dis[i][j] = dis[i][m] + dis[j][m];
					dis[j][i] = dis[i][j];
				}
			}
		}
	}
	int min_dis = oo, min_num = 0;
	for (i = 26; i < 51; i++) {
		if (dis[i][51] < min_dis) {
			min_dis = dis[i][51];
			min_num = i;
		}
	}
	a = min_num - 26 + 'A';
	out << a << " " << min_dis << endl;
	return 0;
}