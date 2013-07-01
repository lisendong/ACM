/*
ID: lisendo1
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream in("milk3.in");
ofstream out("milk3.out");
int state[30][30][30] = {0};
int ra, rb, rc;
int ca, cb, cc;
void lookup(int &a, int ca, int &b, int cb, int&c, int cc);
void dfs(void);
void lookup(int &a, int ca, int &b, int cb, int &c, int cc) {
	int tempa = a, tempb = b, tempc = c;
	if (a > 0) {
		if (a > cb - b) {
			a -= cb - b;
			b = cb;
			dfs();
		}
		else {
			b += a;
			a = 0;
			dfs();
		}	
		a = tempa; b = tempb; c = tempc;
		if (a > cc - c) {
			a -= cc - c;
			c = cc;
			dfs();
		}
		else {
			c += a;
			a = 0;
			dfs();
		}	
		a = tempa; b = tempb; c = tempc;
	}
}
void dfs() {
	if (state[ra][rb][rc] == 1) {
		return ;
	}
	state[ra][rb][rc] = 1;
	lookup(ra, ca, rb, cb, rc, cc);
	lookup(rb, cb, ra, ca, rc, cc);
	lookup(rc, cc, ra, ca, rb, cb);
}
int main() {
	in >> ca >> cb >> cc;
	rc = cc;
	ra = rb = 0;
	dfs();
	int flag = 0;
	for (int j = 0; j < 30; j++) {
		for (int k = 0; k < 30; k++) {
			if (state[0][k][j] == 1) {
				if (flag != 0) out << " ";
				flag = 1;
				out << j;
			}
		}
	}
	out << endl;
}
