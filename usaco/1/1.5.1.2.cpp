/*
ID: lisendo1
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cmath>
#define MAX_NUM 600000
using namespace std;
ifstream in("numtri.in");
ofstream out("numtri.out");
int data[MAX_NUM] = {0};
int value[MAX_NUM] = {0};
int findlevel(int num) {
	//for (i = 1; ; i++) {
	//	if (i * (i + 1) / 2 >= num) break;
	//}
	float x = (-1 + pow(1 + 8 * num, 0.5)) / 2;
	int zheng = (int) x;
	if (x == zheng) return x;
	else return zheng + 1;
}
int max(int a, int b) {
	return a > b ? a : b;
}
int main() {
	int num, i;
	in >> num;
	int total = (1 + num) * num / 2;
	for (i = 1; i <= total; i++) {
		in >> data[i];
	}
	for (i = total; i >= 1; i--) {
		if (i >= total - num + 1) {
			value[i] = data[i];
		}
		else {
			value[i] = data[i] + max(value[i + findlevel(i)], value[i + findlevel(i) + 1]);
		}
	}
	out << value[1] << endl;
	return 0;
}