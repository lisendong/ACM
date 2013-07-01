/*
ID: lisendo1
PROG: concom
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
ifstream in("concom.in"); 
ofstream out("concom.out");
int own[110][110] = {0};
bool control[110] = {0};
int main() {
	int N;
	in >> N;
	int n;
	for (n = 0; n < N; n++) {
		int i, j, p;
		in >> i >> j >> p;
		own[i][j] = p;
	}
	int a, b, c;
	for (a = 1; a <=100; a++) {
		for (b = 1; b <= 100; b++) control[b] = 0;
		for (b = 1; b <= 100; b++) {
			if (own[a][b] > 50) control[b] = 1;
		}
		control[a] = 1;
		while(true) {
			int flag = 0;
			for (b = 1; b <= 100; b++) {
				if (control[b] == 1) continue;
				int sum = 0;
				for (c = 1; c <= 100; c++) {
					if (control[c]) sum += own[c][b];
				}
				if (sum > 50) {
					//cout << b << endl;
					flag++;
					control[b] = 1;
				}
			}
			//cout << flag << endl;
			if (flag == 0) break;
		}
		for (b = 1; b <= 100; b++) {
			if(control[b] && a != b) out << a << " " << b << endl; 
		}
	}
	return 0;
}