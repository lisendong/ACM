/*
ID: lisendo1
PROG: prefix
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
ifstream in("prefix.in");
//fp=fopen("prefix.in","r"); 
ofstream out("prefix.out");
map <string, bool> m1;
map <string, bool>::iterator m1_iter;
char tmpstr[20], data[200010];
int str_len = 0;
bool dp[200010] = {0};
int main() {
	//string str;
	//char *a = "abc";
	//str.assign(a, 1);
	//cout << str << endl;
	//m1[str] = 1;
	char ch;
	string str;
	int max_len = 0, tmp_len = 0;
	while ('.' != (ch = in.get())) {
		if (ch == ' ' || ch == 10) {
			m1[str] = 1;
			if (tmp_len > max_len) max_len = tmp_len;
			str = "";tmp_len = 0;
			continue;
		}
		str.append(&ch, 1);
		tmp_len ++;
	}
	while(EOF != (ch = in.get())) {
		if (ch == 10) continue;
		data[str_len++] = ch;
	}
	int i;
	for (i = 0; i < str_len; i++) {
		int start;
		if (i == 0) start = 0;
		else if (dp[i - 1] == 1) start = i;
		else continue;
		int j;
		for (j = 0; j < max_len; j++) {
			string tmp_str;
			tmp_str.assign(data + start, j + 1);
			if (m1.find(tmp_str) != m1.end()) {
				dp[start + j] = 1;
			}
		}
	}
	//cout << str_len << endl;
	for (i = str_len - 1; i >= 0; i--) {
		if (dp[i] == 1) {
			out << i+1 << endl;
			return 0;
		}
	}
	out << 0 << endl;
	//cout << str << endl;
	//cout << m1[str] << endl;
	return 0;
}
