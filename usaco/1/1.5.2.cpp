/*
ID: lisendo1
PROG: pprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream in("pprime.in");
ofstream out("pprime.out");
int a[100] = {0};
int min_num , max_num;
bool is_prim(int length) {
	int sum = 0, e = length - 1;
	if (length % 2 == 0) {
		int i;
		for (i = 0; i < length / 2 ; i++) {
			sum += a[i] * pow(10, e--);
		}
		for (i = i - 1; i >= 0; i--) {
			sum += a[i] * pow(10, e--);
		}
	}
	else {
		int i;
		for (i = 0; i <= length / 2; i++) {
			sum += a[i] * pow(10, e--);
		}
		for (i = i - 2; i >= 0; i--) {
			sum += a[i] * pow(10, e--);
		}
	}
	if(sum > max_num || sum < min_num) return 0;
	//cout << sum << endl;
	int j;
	if (sum % 2 == 0) return 0;
	for(j = 3; j <= sqrt(sum) + 1; j+=2) {
		if (sum % j == 0) return 0;
	}
	out << sum << endl;
	return 1;
}
void dfs(int step, int length) {
	if (step == length / 2 + length % 2) {
		is_prim(length);
		return;
	}
	if (step == 0) {
		for (int i = 1; i <= 9; i+= 2) {
			a[step] = i;
			dfs(step + 1, length);
		}
	}
	else {
		for (int i = 0; i <= 9; i++) {
			a[step] = i;
			dfs(step + 1, length);
		}
	}
}
int main() {
	in >> min_num >> max_num;
	for (int i = 1; pow(10, i - 1) <= max_num; i++) {
		dfs(0, i);
	}
	return 0;
}