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
#include<deque>
#include<list>
#include<vector>
#define oo 0x7FFFFFF
#define MAXN 25
using namespace std;
int main()
{
    int two_num;
    int year;
    while (cin >> year) {
        if (year == 0) {
            break;
        }
        two_num = 4; 
        two_num <<= (year-1960) / 10;
        double used_two_num = 0;
        int n = 1;
        while (true) {
            used_two_num += log(n) / log(2);
            if (used_two_num > two_num) {
                n--;
                break;
            }
            n++;
        }
        cout << n << endl;
    }
}



