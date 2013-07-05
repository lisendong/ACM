/*
ID: lisendo1
PROG: fact4
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#define oo 100000
#define MAXN 10010
using namespace std;
ifstream in("fact4.in"); 
ofstream out("fact4.out");
int main()
{
    int N;
    cin >> N; 
    int i;
    int result = 1;
    for (i = 1; i <= N; i++) {
        int tmpi = i;
        while (0 == tmpi % 10) tmpi /= 10;
        result = result * (tmpi % 1000);
        while (0 == result % 10) result /= 10;
        result = result % 1000;
        out << i << ":" << result << endl;
    }
    out << result % 10 << endl;
}

