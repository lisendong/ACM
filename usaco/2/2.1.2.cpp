/*
ID: lisendo1
PROG: frac1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#define MAX_LENGTH 160*160
using namespace std;
ifstream in("frac1.in");
ofstream out("frac1.out");
struct frac {
	int i, j;
} f[MAX_LENGTH];
int N = 0, num = 0;
bool check(int i, int j) {
	for (int count = 0; count < num; count++) {
		if (f[count].i * j == f[count].j * i) 
			return false;
	}
	return true;
}
int cmp(frac a, frac b) {
	return a.i * b.j < b.i * a.j;
}
int main() {
	in >> N;
	for (int j = 1; j <= N; j++) {
		for (int i = 0; i <j; i++) {
			if(check(i, j)) {
				f[num].i = i;f[num].j = j;
				num++;
			}
		}
	}
	sort(f, f + num, cmp);
	for (int k = 0; k < num; k++) {
		out << f[k].i << "/" << f[k].j << endl;
	}
	out << "1/1" << endl;
	return 0;
}
