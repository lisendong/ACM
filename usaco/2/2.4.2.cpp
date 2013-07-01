/*
ID: lisendo1
PROG: maze1
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
ifstream in("maze1.in"); 
ofstream out("maze1.out");
char wall[300][100];
int dis[150][40];
int H, W;
int dis1[5000], dis2[5000];
int num1 = -1, num2 = -1;
void bfs(int s, int a[]) {
	int queue[5000], q_start = 0, q_end = 0;
	int visited[5000] = {0};
	queue[q_end++] = s;
	visited[s] = 1;
	a[s] = 0;
	int cur;
	//cout << queue[0] << endl;
	while (q_start != q_end) {
		cur = queue[q_start++];
		//cout << cur << endl;
		int h = (cur - 1) / W + 1;
		int w = (cur - 1) % W + 1;
		if (h != 1 && wall[h * 2 - 1][w * 2] != '-') {
			if (!visited[cur-W]) {
				queue[q_end++] = cur - W;
				a[cur - W] = a[cur] + 1;
				visited[cur - W] = 1;
			}
		}
		if (h != H && wall[2*h+1][w*2] != '-') {
			if (!visited[cur+W]) {
				queue[q_end++] = cur + W;
				a[cur + W] = a[cur] + 1;
				visited[cur + W] = 1;
			}
		}
		if (w != 1 && wall[h * 2][2 * w - 1] != '|') {
			if (!visited[cur - 1]) {
				queue[q_end++] = cur - 1;
				a[cur - 1] = a[cur] + 1;
				visited[cur - 1] = 1;
			}
		}
		if (w != W && wall[h * 2][2*w+1] != '|') {
			if (!visited[cur + 1]) {
				queue[q_end++] = cur + 1;
				a[cur + 1] = a[cur] + 1;
				visited[cur + 1] = 1;
			}
		}
	}
}
int main() {
	in >> W >> H;
	int w, h;
	char ch;
	for (h = 1; h <= 2 * H + 1; h++) {
		for (w = 1; w <= 2 * W + 1; w++) {
			in.get(ch);
			if (ch == 10) in.get(ch);
			wall[h][w] = ch;
			if ((h == 1 || h == 2 * H + 1) && w % 2 == 0 && ch == ' ') {
				int num;
				if (h == 1) num = w / 2;
				else num = W * (H - 1) + w / 2;
				if (num1 == -1) num1 = num;
				else num2 = num;
			}
			if ((w == 1 || w == 2 * W + 1) && h % 2 == 0 && ch == ' ') {
				int num;
				if (w == 1) num = W * (h / 2 - 1) + 1;
				else num = W * (h / 2);
				if (num1 == -1) num1 = num;
				else num2 = num;
			}
		}
	}
	//cout << num1 << " " << num2 << endl;
	//analyse num1;
	bfs(num1, dis1);
	bfs(num2, dis2);
	int max = 0;
	for (int i = 1; i <= w * h; i++) {
		int temp = dis1[i] < dis2[i] ? dis1[i] : dis2[i];
		if (temp > max) max = temp;
	}
	out << max + 1 << endl;
}