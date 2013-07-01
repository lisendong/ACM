/*
ID: lisendo1
PROG: clocks
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream in("clocks.in");
ofstream out("clocks.out");
int clocks[9] = {3, 3, 0, 2, 2, 2, 2, 1, 2};
char *ways[10] = {"", "ABDE", "ABC", "BCEF", "ADG", "BDEFH", "CFI", "DEGH", "GHI", "EFHI"};
int result_seq[10];
int temp_seq[10];
int min_steps = 40;
void use(int way_num) {
	int i;
	for (i = 0; ways[way_num][i] != 0; i++) {
		clocks[ways[way_num][i] - 'A'] = (clocks[ways[way_num][i] - 'A'] + 1) % 4;
	}
}
void roll_back(int way_num) {
	int i;
	for (i = 0; ways[way_num][i] != 0; i++) {
		clocks[ways[way_num][i] - 'A'] = (clocks[ways[way_num][i] - 'A'] - 1) % 4;
	}
}
void dfs(int step) {
	int i = 0;
	if (step == 10) {
		int flag = 1;
		//cout << step << endl;
		for (i = 0; i < 9; i++) {
			if (clocks[i] != 0) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			int sum = 0;
			for (i = 1; i <= 9; i++) {
				sum += temp_seq[i];
			}
			if (sum < min_steps) {
				for (i = 1; i <= 9; i++) {
					result_seq[i] = temp_seq[i];
				}
				min_steps = sum;
			}
		}
		return ;
	}
	for (i = 0; i <= 3; i++) {
		int j = 0;
		for (j = 0; j < i; j++) use(step);
		temp_seq[step] = i;
		dfs(step + 1);
		for (j = 0; j < i; j++) roll_back(step);
	}

}
int main() {
	//cout << ways[1][0];
	int s;
	for (s = 0; s < 9; s++){
		int temp;
		in >> temp;
		clocks[s] = temp / 3 % 4;
	}
	dfs(1);
	int start = 0;
	for (s = 1; s <= 9; s++) {
		if (result_seq[s] != 0) {
			for (int k = 0; k < result_seq[s]; k++) {
				if (start != 0) out << " ";
				start = 1;
				out << s;
			}
		}
	}
	out << endl;
	return 0;
}