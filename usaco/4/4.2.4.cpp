/*
ID: lisendo1
PROG: cowcycle
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
#define MAXN 1000
#define nil -1
#define oo 100000000.0
using namespace std;
ifstream in("cowcycle.in"); 
ofstream out("cowcycle.out");
int F, R;
float fa, fb, ra, rb;
vector<double> resultf, resultr;
double ansf[100], ansr[100];
double mmin = oo;
void output(vector<double> a, int N) {
    int i;
    for (i = 0; i < N; i++) {
        if (i != 0) cout << " ";
        cout << a[i];
    }
    cout << endl;
}
double cal() {
    //if (resultf[0] == 39 && resultf[1] == 51 && resultr[0] == 12 && resultr[1] == 13 && resultr[2] == 14 && resultr[3] == 15 && resultr[4] == 28) {
        //cout << "hello" << endl;
    //}
    //if (resultr[0] == 6 && resultr[1] == 9 && resultr[2] == 18) {
    //    cout << "hello" << endl;
    //}
    double tmp[100]; 
    int result = 0;
    int i, j;
    for (i = 0; i < F; i++) {
        for (j = 0; j < R; j++) {
           tmp[result++] = resultf[i] / resultr[j];
        }
    }
    sort(tmp, tmp + F * R);
    if (tmp[F * R - 1] < 3 * tmp[0]) return -1;
    double diff[100];
    result = 0;
    double mean = 0;
    for (i = 0; i < F * R - 1; i++) {
        diff[i] = tmp[i+1] - tmp[i];
        mean += diff[i];
    }
    mean /= (F * R - 1);
    double variance = 0;
    for (i = 0; i < F * R - 1; i++) {
        variance += (diff[i] - mean) * (diff[i] - mean);
    }
    //variance /= (F * R - 1);
    return variance;
}
void dfsr(int step) {
    if (step == R) {
            double calvalue;
            calvalue = cal();
            //if (calvalue != -1) {
            //    cout << calvalue << endl;
            //        output(resultf, F);
            //        output(resultr, R);
            //}
            if (calvalue != -1 && calvalue < mmin) {
                mmin = calvalue;
                //cout << mmin << endl;
                int i;
                for (i = 0; i < F; i++) ansf[i] = resultf[i];
                for (i = 0; i < R; i++) ansr[i] = resultr[i];
            }
            return ;
    }
    int i;
    if (step == 0) i = ra;
    else i = resultr[step - 1] + 1;
    for (; i <= rb; i++) {
        resultr.push_back((double)i);
        dfsr(step + 1);
        resultr.pop_back();
    }
}
void dfsf(int step) {
    if (step == F) {
        dfsr(0);
        return ;
    }
    int i;
    if (step == 0) i = fa;
    else i = resultf[step - 1] + 1; 
    for (; i <= fb; i++) {
        //resultf[step+1] = i;
        resultf.push_back((double)i);
        dfsf(step+1);
        resultf.pop_back();
    }
}
int main()
{
    in >> F >> R;
    in >> fa >> fb >> ra >> rb;
    mmin = oo;
    dfsf(0);
    int i;
    for (i = 0; i < F; i++) {
        if (i != 0) out << " ";
        out << ansf[i];
        //cout << ansf[i];
    }
    out << endl;
    for (i = 0; i < R; i++) {
        if (i != 0) out << " ";
        out << ansr[i];
        //cout << ansr[i];
    }
    out << endl;
    return 0;
}


