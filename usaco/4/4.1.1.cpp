/*
ID: lisendo1
PROG: nuggets 
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
#define oo 2000000000
#define MAXN 10000
bool flag[2000020] = {0};
int box[20];
using namespace std;
ifstream in("nuggets.in"); 
ofstream out("nuggets.out");
int N;
int main()
{
   in >> N;
   unsigned int i;
   for (i = 0; i < N; i++) {
        in >> box[i];
   }
   sort(box, box+N);
   if (box[0] == 1) {
       out << 0 << endl;
       return 0;
   }
   for (i = 0; i < N; i++) {
       flag[box[i]] = 1;
   }
   unsigned int maxn = 0;
   for (i = 1; i <= 1000000; i++) {
       //if (i % 100000000 == 0) cout << i << endl;
       if (flag[i]) {
           int j;
           for (j = 0; j < N; j++) {
               flag[(i + box[j])] = 1;
           }
       }
       else {
           if (i > maxn) {maxn = i; }
       }
   }
   if (maxn > 100000) out << 0 << endl;
   else out << maxn << endl;
}

