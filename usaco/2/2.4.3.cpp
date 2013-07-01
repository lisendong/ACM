/*
ID: lisendo1
PROG: cowtour
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
#define oo 100000000
#define MAX_N 200//the range was wrong!!! my god!!! WA!!!!
using namespace std;
ifstream in("cowtour.in"); 
ofstream out("cowtour.out");
double point[MAX_N][2];
int N;
double dis[MAX_N][MAX_N];
int point_part[MAX_N];//judge the part # of a point
int part_num = 0;
double diameter[MAX_N], max_dis[MAX_N];
double getdis(double x, double y) {
	return sqrt(x * x + y * y);
}
void flood(int point, int part_n) {
	int i, j;
	for (i = 1; i <= N; i++) {
		if (dis[i][point] != oo && point_part[i] == -2) point_part[i] = part_n;
	}
	return ;
	/*while (true) {
		int flag = 0;
		for (i = 1; i <= N; i++) {
			if (point_part[i] == -1) {
				point_part[i] = part_num;
				flag ++;
				for (j = 1; j <= N; j++) {
					if (dis[i][j] != oo && point_part[j] == -2) point_part[j] = -1;
				}
			}
		}
		if (flag == 0) break;
	}*/
}
double max(double a, double b, double c) {
	double result;
	if (a>b) result = a;
	else result = b;
	if (result < c) result = c;
	return result;
}
int main() {
	in >> N;
	int i, j, m;
	for (i = 1; i <= N; i++) {
		in >> point[i][0] >> point[i][1];
	}
	char ch;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			in >> ch;
			if (ch == 10) in >> ch;
			if (ch == '0') dis[i][j] = oo;
			else dis[i][j] = getdis(point[i][0] - point[j][0], point[i][1] - point[j][1]);
			if (i == j) dis[i][j] = 0;
			//dis[j][i] = dis[i][j];
			//cout << dis[i][j] << endl;
		}
	}
	for (m = 1; m <= N; m++) {
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				if (dis[i][j] > dis[i][m] + dis[m][j]) {
					dis[i][j] = dis[i][m] + dis[m][j];
					dis[j][i] = dis[i][j];
				}
			}
		}
	}
	for (i = 1; i <= N; i++) {
		point_part[i] = -2;
	}
	for (i = 1; i <= N; i++) {
		if (point_part[i] == -2) {
			part_num ++;
			point_part[i] = part_num;
			flood(i, part_num);
		}
	}
	//part_num = 3;
	//calculate the diameter of each part.
	int part;
	//cout << part_num << ":";
	for (part = 1; part <= part_num; part++) {
		double max_dia = 0;
		for (i = 1;  i <= N; i++) {
			for (j = 1; j <= N; j++) {
				if (point_part[i] == part && point_part[j] == part) {
					if (dis[i][j] > max_dia) max_dia = dis[i][j];
				}
			}
		}
		diameter[part] = max_dia;
	}
	//calculate the max_distance of each point
	//cout << part_num << endl;
	for (i = 1; i <= N; i++) {
		double max_dia = 0;
		for (j = 1; j <= N; j++) {
			if (point_part[i] == point_part[j]) {
				if (dis[i][j] > max_dia) max_dia = dis[i][j];
			}
		}
		max_dis[i] = max_dia;
	}
	double min_new_dia = oo;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (point_part[i] != point_part[j]) {
				double ijdis = getdis(point[i][0] - point[j][0], point[i][1] - point[j][1]);
				//cout << ijdis << endl;
				double tmp_new_dia = max(diameter[point_part[i]], diameter[point_part[j]], max_dis[i] + max_dis[j] + ijdis);
				//cout << tmp_new_dia << endl;
				if (tmp_new_dia < min_new_dia) min_new_dia = tmp_new_dia;
			}
		}
	}
	//if (min_new_dia == 0) {cout << ".000000" << endl; return 0;}
	out<<setprecision(6)<<setiosflags(ios::fixed  | ios::showpoint)<<min_new_dia<<endl;
	//cout << min_new_dia << endl;
	return 0;
}