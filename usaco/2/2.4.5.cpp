/*
ID: lisendo1
PROG: fracdec
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
#define oo 100010
#define MAX_N 10
using namespace std;
ifstream in("fracdec.in"); 
ofstream out("fracdec.out");
int yushu_hash[oo] = {0};
int result[oo]= {0};
int result_num = 0;
int main() {
	int N, D, i, count = 0;
	in >> N >> D;
	out << N / D << ".";
	for (count = 1; pow(10, count) <= N / D; count++) {
		;
	}
	count++;
	if (N % D == 0) {out << 0 << endl; return 0;}
	N = (N % D);
	int flag = -2;
	for (i = 0; i < oo; i++) yushu_hash[i] = -2;
	yushu_hash[N] = -1;
	N = N * 10;
	//cout << N << "/" << D << endl; return 0;
	while (true) {
		if (N % D == 0) {
			result[result_num++] = N / D;
			break;
		}
		if (N > D) {
			result[result_num++] = N / D;
			N = N % D;
			if (yushu_hash[N] != -2) {
				flag = yushu_hash[N];
				break;
			}
			yushu_hash[N] = result_num - 1;
			N = N * 10;
			continue;
		}
		else {
			result[result_num++] = 0;
			if (yushu_hash[N] != -2) {
				flag = yushu_hash[N];
				break;
			}
			N = N * 10;
			continue;
		}
	}
	if (flag == -2) {
		for (i = 0; i < result_num; i++) {
			if (count % 76 == 0) out << endl;
			count ++;
			out << result[i];
		}
		out << endl;
		return 0;
	}
	for (i = 0; i <= flag; i++) {
		if (count % 76 == 0) out << endl;
		count ++;
		out << result[i];
	}
	out << "(";
	count ++;
	for (i = flag + 1; i < result_num; i++) {
		if (count % 76 == 0) out << endl;
		count++;
		out << result[i];
	}
	out << ")";
	out << endl;
	return 0;
}
