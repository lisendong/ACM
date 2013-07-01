/*
ID: lisendo1
PROG: runround
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
ifstream in("runround.in");
ofstream out("runround.out");
char a[20] = {0};
bool check(unsigned int m) {
	int i = 0, flag = 0;
	bool visited[20] = {0};
	bool targeted[20] = {0};
	char temp[20] = {0};
	while (m != 0) {
		temp[i++] = m % 10 + '0';
		m /= 10;
	}
	int len = i;
	for (i = 0; i < len; i++) {
		a[i] = temp[len - 1 - i];
	}
	i = 0;
	for (flag = 0; flag < len; flag++) {
		i = (i + a[i] - '0') % len;
		if (targeted[a[i] - '0']) return 0;
		if (visited[i]) return 0;
		targeted[a[i] - '0'] = 1;
		visited[i] = 1;
	}
	return 1;
}
int main() {
	unsigned int  M;
	in >> M;
	while (true) {
		M++;
		if (check(M)) {
			out << M << endl;
			break;
		}
	}
	return 0;
}