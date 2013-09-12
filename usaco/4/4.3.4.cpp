/*
ID: lisendo1
PROG: lgame
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<assert.h>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<list>
#include<map>
#include<vector>
#define MAXN 200
#define nil -1
#define oo 100000000.0
using namespace std;
ifstream in("lgame.in"); 
ofstream out("lgame.out");
ifstream dictin("lgame.dict");
int lnum[30] = {0};
string s[40010];
int value[40010] = {0};
int l_v[26] = {2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5, 2, 3, 5, 7, 2, 1, 2, 4, 6, 6, 7, 5, 7};
int snum = 0;
struct result {
    int a, b;
};
int result_num = 0;
result r[40010];
int cmp(result x, result y) {
    for (int i = 0, j = 0; i < s[x.a].size(), j < s[y.a].size(); i++, j++) {
        if (s[x.a][i] < s[y.a][j]) return 1;
        else if (s[x.a][i] > s[y.a][j]) return 0;
    }
    return s[x.a].size() < s[y.a].size();
}
int main()
{
    char ch;
    while (in >> ch)  {
        if (ch >= 'a' && ch <= 'z') {
            lnum[ch-'a']++;
        }
        else break;
    }
    string str;
    int i, j;
    while (dictin >> str) {
        if (str[0] == '.') break;
        int flag = 1;
        int count[30] = {0};
        for (i = 0; i < str.size(); i++) {
            if (lnum[str[i]-'a'] == 0) {flag = 0; break;}
            count[str[i]-'a']++;
            if (count[str[i] - 'a'] > lnum[str[i] - 'a']) {
                flag = 0; break;
            }
        }
        if (flag == 1)  {
            s[snum] = str;
            for (i = 0; i < str.size(); i++) {
                value[snum] += l_v[str[i]-'a'];
            }
            snum++;
            //cout << str << endl;
        }
    }
    int max = 0;
    for (i = 0; i < snum; i++) {
        if (value[i] > max) {
            max = value[i];
            result_num = 0;
            r[result_num].a = i;
            r[result_num].b = -1;
            result_num++;
        }
        else if (value[i] == max) {
            r[result_num].a = i;
            r[result_num].b = -1;
            result_num++;
        }
    }
    int m, n;
    cout << snum << endl;
    for (i = 0; i < snum; i++) {
        for (j = i; j < snum; j++) {
            int count[30] = {0};
            for (m = 0; m < s[i].size(); m++) {
                count[s[i][m]-'a'] += 1;
            }
            for (n = 0; n < s[j].size(); n++) {
                count[s[j][n] - 'a'] += 1;
                if (count[s[j][n] - 'a'] > lnum[s[j][n]-'a']) {
                    break;
                }
            }
            if (n == s[j].size()) {
                if (value[i] + value[j] > max) {
                    max = value[i] + value[j];
                    result_num = 0;
                    r[result_num].a = i;
                    r[result_num].b = j;
                    result_num++;
                }
                else if (value[i] + value[j] == max) {
                    r[result_num].a = i;
                    r[result_num].b = j;
                    result_num++;
                }
            }
        }
    }
    sort(r, r+result_num, cmp);
    out << max << endl;
    for (i = 0; i < result_num; i++) {
        out << s[r[i].a];
        if (r[i].b != -1) out << " " << s[r[i].b];
        out << endl;
    }
}
