/*
ID: lisendo1
PROG: sort3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#define MAX_LENGTH 160*160
using namespace std;
ifstream in("sort3.in");
ofstream out("sort3.out");
int a[2000];
int n[4] = {0};
int n1 = 0, n2 = 0, n3 = 0;
int n12=0, n13=0, n21=0, n23=0, n31=0, n32=0;
int sum = 0;
int main() {
	int N, i;
	in >> N;
	for (i = 0; i < N; i++) {
		in >> a[i];
		n[a[i]] ++;
	}
	n1 = n[1]; n2 = n[2]; n3 = n[3];
	for (i = 0; i < n1; i++) {
		if (a[i] == 2) n12++;
		if (a[i] == 3) n13++;
	}
	for (i = n1; i < n1+n2; i++) {
		if (a[i] == 1) n21++;
		if (a[i] == 3) n23++;
	}
	for (i = n1+n2; i < n1+n2+n3; i++) {
		if (a[i] == 1) n31++;
		if (a[i] == 2) n32++;
	}
	int temp;
	temp = n12 < n21 ? n12 : n21;
	sum += temp; n12 -= temp; n21 -= temp;
	temp = n13 < n31 ? n13 : n31;
	sum += temp; n31 -= temp; n13 -= temp;
	temp = n23 < n32 ? n23 : n32;
	sum += temp; n23 -= temp; n32 -= temp;
	sum += (n12 + n21 + n13 + n31 + n23 + n32) / 3 * 2;
	out << sum << endl;
	return 0;
}