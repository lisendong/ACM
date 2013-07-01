/*
ID: lisendo1
PROG: zerosum
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
ifstream in("zerosum.in"); 
ofstream out("zerosum.out");
char result[10];
int N;
void dfs(int step, int sum, int last_num, char last_symbol) {
	if (step == N - 1) {
		if (sum == 0) {
			out << "1";
			for(int i = 0; i < N - 1; i++) {
				out << result[i] << i + 2;
			}
			out << endl;
		}
		return ;
	}
	int temp = sum;
	//‹óŠi
	result[step] = ' ';
	if(step == 0) {
		sum = sum * 10 + step + 2;
		dfs(step + 1, sum, sum, ' ');
	}
	else {
		if (last_symbol == '-') {
			sum += last_num;
			sum -= (last_num * 10 + step + 2);
			last_num = last_num * 10 + step + 2;
		}
		else if (last_symbol == '+') {
			sum -= last_num;
			sum += (last_num * 10 + step + 2);
			last_num = last_num * 10 + step + 2;
		}
		else {
			sum = sum * 10 + step + 2;
			last_num = sum;
		}
		dfs(step + 1, sum, last_num, last_symbol);
	}
	//"+"†
	sum = temp;
	result[step] = '+';
	dfs(step + 1, sum + (step + 2), step + 2, '+');
	//"-"†
	sum = temp;
	result[step] = '-';
	dfs(step + 1, sum - (step + 2), step + 2, '-');
}
int main() {
	in >> N;
	dfs(0, 1, 1, ' ');
	return 0;
}