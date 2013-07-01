/*
ID: lisendo1
PROG: ttwo
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
ifstream in("ttwo.in"); 
ofstream out("ttwo.out");
char wall[20][20];
int fx, fy, cx, cy;
int dirf = 0, dirc = 0;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int main() {
	int i, j;
	for (i = 0; i <= 11; i++) {
		wall[i][0] = '*';
		wall[i][11] = '*';
		wall[0][i] = '*';
		wall[11][i] = '*';
	}
	for (i = 1; i <= 10; i++) {
		for (j = 1; j <= 10; j++) {
			in >> wall[i][j];
			if (wall[i][j] == 'F') {
				fx = i; fy = j;
			}
			if (wall[i][j] == 'C') {
				cx = i; cy = j;
			}
		}
	}
	for (i = 1; i <= 16000;i++) {
		if (wall[fx + dir[dirf][0]][fy + dir[dirf][1]] != '*') {
			fx = fx + dir[dirf][0];
			fy = fy + dir[dirf][1];
		}
		else {
			dirf = (dirf + 1) % 4;
		}
		if (wall[cx + dir[dirc][0]][cy + dir[dirc][1]] != '*') {
			cx = cx + dir[dirc][0];
			cy = cy + dir[dirc][1];
		}
		else {
			dirc = (dirc + 1) % 4;
		}
		if (fx == cx && fy == cy) {
			out << i << endl;
			return 0;
		}
	}
	out << 0 << endl;
	return 0;
}