/*
ID: lisendo1
PROG: fence8
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
using namespace std;
ifstream in("fence8.in"); 
ofstream out("fence8.out");
int board[60];
int min_rail[60];
int rail[1100];
int N, R;
int sum_waste;
bool dfs(int step, int waste, int deep, int last_board) {
    //if (deep == 767) cout << step << endl;
    if (step == 0) return true;
    int i, j, new_waste =  waste, high;
    if (step != deep && rail[step - 1] == rail[step]) high = last_board;
    else high = N - 1;
    for (i = high; i >= 0; i--) {
        assert(board[i] >= 0 && rail[step - 1] >= 0);
        if (board[i] >= rail[step - 1]) {
            board[i] -= rail[step - 1];
            for (j = 0; j < deep - 1; j++) {
                if (board[i] >= rail[j]) break;
            }
            if (j == deep - 1) {
                 new_waste = waste + board[i];
                 if (new_waste > sum_waste) {
                     board[i] += rail[step - 1];
                     continue;
                } 
            }
            bool flag = dfs(step - 1, new_waste, deep, i);
            board[i] += rail[step - 1];
            if (flag == true) {  return true;}
        }
    }
    return false;
}
int main()
{
    in >> N;
    int i, j;
    for (i = 0; i < N; i++) {
        in >> board[i];
    }
    in >> R;
    for (i = 0; i < R; i++) {
        in >> rail[i];
    }
    sort(board, board+N);
    sort(rail, rail + R);
    int deep;
    int sum_board = 0;
    for (i = 0; i < N; i++) sum_board += board[i];
    for (deep = 1; deep <= R ; deep++) {
        int sum = 0;
        for (i = 0; i < deep; i++) sum += rail[i];        
        sum_waste = sum_board - sum;
        if (sum_waste < 0) break;
        if (!dfs(deep, 0, deep, 0)) break;
    }
    out << deep - 1 << endl;
}

