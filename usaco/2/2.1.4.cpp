/*
ID: lisendo1
PROG: holstein
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#define MAX_LENGTH 160*160
using namespace std;
ifstream in("holstein.in");
ofstream out("holstein.out");
int N, M;
int need[1200] = {0};
int have[1200] = {0};
int type[20][1200] = {0};
int min_result , min_num, min_sum;
int get_num(int num) {
	int count = 0;
	while (num > 0) {
		count += num & 1;
		num >>= 1;
	}
	return count;
}
int get_sum(int num) {
	int sum;
	for (int i = 1; num > 0; i++) {
		sum += (num & 1) * i;
		num >>= 1;
	}
	return sum;
}
void analyse(int result) {
	int i, j;
	for (i = 0; i < N; i++) {
		have[i] = 0;
	}
	for (i = 0; i < M; i++) {
		if (result & (int)pow(2, i)) {
			for (j = 0; j < N; j++) {
				have[j] += type[i][j];
			}
		}
	}
	for (j = 0; j < N; j++) {
		if (have[j] < need[j]) break;
	}
	if (j == N) {
		int num = get_num(result);
		int sum = get_sum(result);
		if (num < min_num || (num == min_num && sum < min_sum)) {
			min_result = result;
			min_num = num;
			min_sum = sum;
		}
	}
}
int main() {
	in >> N;
	int i, j;
	for (i = 0; i < N; i++) {
		in >> need[i];
	}
	in >> M;
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			in >> type[i][j];
		}
	}
	min_result = pow(2, 16); min_num = 20; min_sum = 300;
	int result = 1;
	for (result = 1; result <= pow(2, M + 1) - 1; result++) {
		analyse(result);
	}
	out << min_num;
	for (i = 0; min_result > 0; i++) {
		if (min_result & 1) {
			out << " " << i + 1;
		}
		min_result >>= 1;
	}
	out << endl;
	return 0;
}