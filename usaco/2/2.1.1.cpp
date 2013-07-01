/*
ID: lisendo1
PROG: castle
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
ifstream in("castle.in");
ofstream out("castle.out");
typedef struct module {
	bool up, down, left, right;
	int room_num;
} Module;
Module m[60][60];
int M, N;
int area[3000] = {0}, area_num = 1;
typedef struct join_area {
	int row, col, flag, area;
} Join_area;
Join_area max_area;
void tag(int row, int col, int r_num) {
	//cout << r_num << endl;
	m[row][col].room_num = -1;
	while(true) {
		int tag_num = 0;
		for (int i = row; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (m[i][j].room_num == -1) {
					m[i][j].room_num = r_num;
					area[r_num] ++;
					//cout << i << " " << j << endl;
					if (m[i][j].up == 0 && m[i - 1][j].room_num == -2) {m[i - 1][j].room_num = -1;	tag_num ++;}
					if (m[i][j].right == 0 && m[i][j+1].room_num == -2) {m[i][j+1].room_num = -1; tag_num ++;}
					if (m[i][j].down == 0 && m[i+1][j].room_num == -2) {m[i+1][j].room_num = -1; tag_num ++;}
					if (m[i][j].left == 0 && m[i][j - 1].room_num == -2) {m[i][j-1].room_num = -1; tag_num ++;}
				}
			}
		}
		if (tag_num == 0) break;
	}
}
int main() {
	int i, j;
	in >> M >> N;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			int temp;
			in >> temp;
			if (temp >= 8) {
				m[i][j].down = 1;
				temp -= 8;
			}
			else m[i][j].down = 0;
			if (temp >= 4) {m[i][j].right = 1; temp -= 4;}
			else m[i][j].right = 0;
			if (temp >= 2) {m[i][j].up = 1; temp -= 2;}
			else m[i][j].up = 0;
			if (temp >= 1) {m[i][j].left = 1; temp -= 1;}
			else m[i][j].left = 0;
			m[i][j].room_num = -2;
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (m[i][j].room_num == -2) {//start to tag
				tag(i, j, area_num);
				area_num ++;
			}
		}
	}
	out << --area_num << endl;

	max_area.row = 0;
	max_area.col = 0;
	max_area.area = area[m[0][0].room_num];
	max_area.flag = 1;//north = 1
	for (j = 0; j < M; j++) {
		for (i = N - 1; i >= 0; i--) {
			if (i > 0 && m[i][j].up == 1 && m[i][j].room_num != m[i-1][j].room_num) {
				if (area[m[i][j].room_num] + area[m[i-1][j].room_num] > max_area.area) {
					max_area.row = i;
					max_area.col = j;
					max_area.area = area[m[i][j].room_num] + area[m[i-1][j].room_num];
					max_area.flag = 1;
				}
			}
			if (j < M - 1 && m[i][j].right == 1 && m[i][j].room_num != m[i][j + 1].room_num) {
				if (area[m[i][j].room_num] + area[m[i][j+1].room_num] > max_area.area) {
					max_area.row = i;
					max_area.col = j;
					max_area.area = area[m[i][j].room_num] + area[m[i][j+1].room_num];
					max_area.flag = 0;
				}
			}
		}
	}
	sort(area + 1, area + area_num + 1);
	out << area[area_num] << endl;
	out << max_area.area << endl;
	out << max_area.row + 1 << " " << max_area.col + 1;
	if (max_area.flag == 1) out << " N" << endl;
	else out << " E" << endl;
	return 0;
}