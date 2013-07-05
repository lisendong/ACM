/*
ID: lisendo1
PROG: kimbits
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
ifstream in("kimbits.in"); 
ofstream out("kimbits.out");
int N, L, I;
int check(int num, int last_one_num) {
    //cout << num << "-" << last_one_num << endl;
    if (num == 0) return 0;
    num--;
    int sum = 0;
    while (num != 0) {
        //cout << num << "&" << 1 << "=" <<(int)( num & 1 )<< endl;
        if (!(num&1)) break;
        //cout << sum << endl;
        sum ++;
        num >>= 1;
    }
    return last_one_num - sum + 1;
}
void output(int num) {
    bool result[33];
    int result_num = 0;
    while (num != 0) {
        result[result_num++] = num % 2;
        num /= 2;
    }
    for (int i = 0; i < N - result_num; i++) out << "0";
    for (result_num--; result_num >= 0; result_num--) {
        out << result[result_num];
    }
    out << endl;
}
int main()
{
    in >> N >> L >> I;
    unsigned int i;
    int count = 0;
    int one_num = 0;
    for (i = 0; i < pow(2, N); i++) {
        if (L >= (one_num = check(i, one_num))) {
            count++;
            //cout << i << ":" << one_num << endl;
        }
        if (count == I) {
            output(i);
            break;
        }
    }
    return 0;
}

