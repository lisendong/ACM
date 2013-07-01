/*
ID: lisendo1
PROG: money
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
ifstream in("money.in"); 
ofstream out("money.out");
int v[30], V;
int N;
long long int n[30][10010] = {0};
int main() {
	in >> V >> N;
	int i, j;
	for (i = 1; i <= V; i++) {
		n[i][0] = 1;
	}
	for(i = 1; i <= V; i++) {
		in >> v[i];
	}
	for (j = 1; j <= N; j++) {
		for (i = 1;i <= V; i++) {
			if (v[i] <= j)
				n[i][j] = n[i][j - v[i]] + n[i-1][j];//ŠjSzhuanyiŒöŽ®
			else 
				n[i][j] = n[i - 1][j];
		}
	}
	out << n[V][N] << endl;
}
