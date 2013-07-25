/*
ID: lisendo1
PROG: fence6
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
#include<vector>
#define MAXN 10000
#define oo 255 * 100 * 100
using namespace std;
ifstream in("fence6.in"); 
ofstream out("fence6.out");
struct line {
    vector <int> lefts, rights;
    int flag;
    int length;
};
line l[110];
int min_num = oo;
void dfs(int last_line, int this_line, int cur_sum, int origin_line) {
    vector <int>::iterator it;
    if (this_line == -1) { // 初始化代码
        for (it = l[origin_line].rights.begin(); it != l[origin_line].rights.end(); it++) {
            dfs(origin_line, (*it), l[origin_line].length, origin_line);
        }
        l[this_line].flag = false;//复原为未访问状态
    }
    else if (this_line == origin_line) {
        //cout << "hello" << endl;
        for (it = l[origin_line].lefts.begin(); it != l[origin_line].lefts.end(); it++) {
            if ((*it) == last_line) {
                if (cur_sum < min_num) {
                    min_num = cur_sum;
                    //cout << min_num << endl;
                    return ;
                }
            }
        }
    }
    else {
        int flag = -1;
        for (it = l[this_line].lefts.begin(); it != l[this_line].lefts.end(); it++){
            if ((*it) == last_line) flag = 0; //上一个线段是从左面连过来的
        }
        if (flag == -1) { // 上一个是从右面连过来的
            for (it = l[this_line].lefts.begin(); it != l[this_line].lefts.end(); it++) {
                if (l[(*it)].flag == false) { // flag 标识在这里来做
                    l[(*it)].flag = true;
                    dfs(this_line, (*it), cur_sum + l[this_line].length, origin_line);
                    l[(*it)].flag = false;
                }
            }
        }
        if (flag == 0) { // 上一个是从左面连过来的
            for (it = l[this_line].rights.begin(); it != l[this_line].rights.end(); it++) {
                if (l[(*it)].flag == false) {
                    l[(*it)].flag = true;
                    dfs(this_line, (*it), cur_sum + l[this_line].length, origin_line);
                    l[(*it)].flag = false;
                }
            }
        }
    }
}
int main()
{
    int N;
    in >> N;
    int i, j;
    int line_arr[110];
    for (i = 1; i <= N; i++) {
        int line_num;
        in >> line_num;
        in >> l[line_num].length;
        int left_num, right_num;
        in >> left_num >> right_num;
        for (j = 0; j < left_num; j++) {
            int tmp;
            in >> tmp;
            l[line_num].lefts.push_back(tmp);
        }
        for (j = 0; j < right_num; j++) {
            int tmp;
            in >> tmp;
            l[line_num].rights.push_back(tmp);
        }
        l[line_num].flag = false;
        line_arr[i] = line_num;
    }
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            l[line_arr[j]].flag = false;
        }
        //cout << line_arr[i] << endl;
        dfs(-1, -1, 0, line_arr[i]);
    }
    out << min_num << endl;
}


