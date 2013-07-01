/*
ID: lisendo1
PROG: lamps
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <string>
#define MAX_LENGTH 160*160
using namespace std;
ifstream in("lamps.in");
ofstream out("lamps.out");
char a = 63;
struct table {
	int num;
	int a[10];
} t[5];
int get_one_num(int a) {
	int num = 0;
	while(a != 0) {
		if (a & 1) num++;
		a >>= 1;
	}
	return num;
}
int N, C, on[100], off[100], on_num = 0, off_num = 0;
int result[20], result_num = 0;
void add_result(int new_num) {
	int i, k;
	for (i = 0; i < result_num; i++) {
		if (result[i] == new_num) return;
		if (result[i] > new_num) break;
	}
	for (k = result_num - 1; k >= i; k--) {
		result[k + 1] = result[k];
	}
	result[i] = new_num;
	result_num++;
}
bool check(int one_result) {
	int i;
	for (i = 0; i < on_num; i++) {
		if (0 == (one_result & (int)pow(2, 5 - ((on[i] - 1) % 6)))) return 0;
	}
	for (i = 0; i < off_num; i++) {
		if (0 < (one_result & (int)pow(2, 5-((off[i] - 1) % 6)))) return 0;
	}
	return 1;
}
void output(int one_result) {
	int i, j = 5;
	for (i = 0; i < N; i++) {
		out << (int)((one_result & (int)pow(2, j)) > 0);
		j--;
		if (j == -1) j = 5;
	}
}
int main() {
	int i, j, k, m;
	for (i = 1; i <= 4; i++) {
		t[i].num = 0;
	}
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 2; k++) {
				for (m = 0; m < 2; m++) {
					a = 63;
					if (i) a ^= 63;
					if (j) a ^= 42;
					if (k) a ^= 21;
					if (m) a ^= 36;
					int one_num = i + j + k + m;
					t[one_num].a[t[one_num].num++] = a;
					//cout << i << j << k << m << ":";
					//for (int x = 32; x >= 1; x /= 2) {
					//	cout << ((int)(a&x) > 0);
					//}
					//cout << endl;
				}
			}
		}
	}
	in >> N >> C;
	int on_light, off_light;
	in >> on_light;
	while(on_light != -1) {
		on[on_num++] = on_light;
		in >> on_light;
	}
	in >> off_light;
	while(off_light != -1) {
		off[off_num++] = off_light;
		in >> off_light;
	}
	if (C % 2 == 0) {
		for (i = 0; i <= (C < 4 ? C : 4); i += 2) {
			for (j = 0; j < t[i].num; j++) {
				add_result(t[i].a[j]);
			}
		}
	}
	else {
		for (i = 1; i <= (C < 3 ? C : 3); i += 2) {
			for (j = 0; j < t[i].num; j++) {
				add_result(t[i].a[j]);
			}
		}
	}
	int real_count = 0;
	for (i = 0; i < result_num; i++) {
		if (check(result[i])) {
			real_count ++;
			output(result[i]);
			out << endl;
		}
	}
	if (real_count == 0) out << "IMPOSSIBLE" << endl;
	return 0;
}