/*
ID: lisendo1
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <fstream>
#define MAX_NUM 256 * 256 * 2
using namespace std;
ifstream in("ariprog.in");
ofstream out("ariprog.out");
int data[MAX_NUM] = {-1};
int exist[MAX_NUM] = {0};
int result[10010][2];
int result_num = 0;
int num = 0;
int main() {
	//cout << MAX_NUM << endl;
	int N, M;
	in >> N >> M;
	for (int p = 0; p <= M; p++) {
		for (int q = p; q <= M; q++) {
			int temp = p * p + q * q;
			exist[temp] = 1;
			int k;
			for (k = 0; k < num; k++) {
				if (temp <= data[k]) break;
			}
			if (temp == data[k]) continue;
			for (int j = num - 1; j >= k; j--) {
				data[j + 1] = data[j];
			}
			data[k] = temp;
			num++;
		}
	}
	sort(data, data + num);
	//for (p =0; p < num; p++) cout << data[p] << " ";
	//cout << endl;
	for (int a = 0; a <= num - N; a++) {
		for (int b = a + 1; b <= num - N + 1; b++) {
			if (data[a] + (data[b] - data[a]) * (N - 1) > 2 * M * M)  break;
			int flag = 1;
			for (int count = 1; count <= N - 2; count++) {
				if (exist[data[b] + (data[b] - data[a]) * count] == 0) {
					flag = 0;
					break;
				}
			}
			if (flag == 1) {
				//cout << "index:" << a << " " << b << endl;
				int k;
				for (k = 0; k < result_num; k++) {
					if ((data[b] - data[a] < result[k][1]) || (data[b] - data[a] == result[k][1] && data[a] < result[k][0])) break;
				}
				for (int j = result_num - 1; j >= k; j--) {
					result[j + 1][0]= result[j][0];
					result[j + 1][1] = result[j][1];
				}
				result[k][0] = data[a];
				result[k][1] = data[b] - data[a];
				result_num ++;
				//cout << data[a] << " " << data[b] - data[a] << endl;
			}
		}
	}
	if (result_num == 0) {
		out << "NONE" << endl;
		return 0;
	}
	for (int i = 0; i < result_num; i++) {
		out << result[i][0] << " " << result[i][1] << endl;
	}
	return 0;
}