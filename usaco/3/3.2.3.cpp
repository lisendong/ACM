/*
ID: lisendo1
PROG: spin 
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#define oo 10000
#define MAXN 10000
using namespace std;
ifstream in("spin.in"); 
ofstream out("spin.out");
long long N, L, I;
class wheel {
    public:
        int speed, wnum, wp[20][2];
        void rotate(void) {
            int i;
            for (i = 0; i < wnum; i++) {
                wp[i][0] += speed;
                wp[i][0] %= 360;
            }
        }
};
class wheel w[5];
bool check() {
    int i, j;
    int degree;
    for (degree = 0; degree < 360; degree++) {
        int flag = 0;
        for (i = 0; i < 5; i++) {
            for (j = 0; j < w[i].wnum; j++) {
                int start = w[i].wp[j][0], finish = w[i].wp[j][0] + w[i].wp[j][1];
                if (finish < 360) {
                    if (degree >= start && degree <= finish) {
                        flag ++;
                        break;
                    }
                }
                else {
                    if (degree >= start && degree <= 359) {
                        flag ++;
                        break;
                    }
                    if (degree >= 0 && degree <= finish % 360) {
                        flag++;
                        break;
                    }
                }
            }
        }
        //cout << degree << ":" << flag << endl;
        if (flag == 5) return true;
    }
    return false;
}
int main()
{
    int i, j;
    for (i = 0; i < 5; i++) {
        in >> w[i].speed >> w[i].wnum;
        for (j = 0; j < w[i].wnum; j++) {
            in >> w[i].wp[j][0] >> w[i].wp[j][1];
        }
    }
    int time = 0;
    while(time <= 360) {
        //cout << check() << endl;
        if(check()) {
            out << time << endl;
            return 0;
        }
        for (i = 0; i < 5; i++) {
            w[i].rotate();
        }
        time++;
    }
    out << "none" << endl;
    return 0;
}

