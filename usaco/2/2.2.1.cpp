/*
ID: lisendo1
PROG: preface
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#define MAX_LENGTH 160*160
using namespace std;
ifstream in("preface.in");
ofstream out("preface.out");
int result[200] = {0};
char unit[10] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'}; // 7
char* cell[30] = {"I", "II", "III", "IV", "V", //21
				"IX", "X", "XX", "XXX", "XL",
				"L", "XC", "C", "CC", "CCC", 
				"CD", "D", "CM", "M", "MM", "MMM"};
int value[30] = {1, 2, 3, 4, 5, 9, 10, 20, 30, 40, 50, 90, 100, 200, 300, 400, 500, 900, 1000, 2000, 3000};
int main() {
	int N, i;
	in >> N;
	for (i = 1; i <= N; i++) {
		int temp = i;
		int j = 20;
		while (temp != 0) {
			for (; j >= 0; j--) {
				if (value[j] <= temp) break;
			}
			temp -= value[j];
			for (int k = 0; cell[j][k]; k++) {
				result[cell[j][k]] ++;
			}
		}
	}
	for (i = 0; i < 7; i++) {
		if (result[unit[i]] != 0) {
			out << unit[i] << " " << result[unit[i]] << endl;
		}
	}
}