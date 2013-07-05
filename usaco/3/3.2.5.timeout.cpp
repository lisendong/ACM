/*
ID: lisendo1
PROG: msquare
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
ifstream in("msquare.in"); 
ofstream out("msquare.out");
class Square {
    public:
        int num[8];
        void varya() {
            int newnum[8], i;
            for (i = 0; i <= 7; i++) {
                newnum[i] = num[7 - i]; 
            }
            for (i = 0; i < 8; i++) num[i] = newnum[i];
        }
        void varyb() {
            int newnum[8], i;
            for (i = 1; i <= 3; i++) {
                newnum[i] = num[i - 1];
            }
            newnum[0] = num[3];
            for (i = 4; i <= 6; i++) {
                newnum[i] = num[i+1];
            }
            newnum[7] = num[4];
            for (i = 0; i < 8; i++) num[i] = newnum[i];
        }
        void varyc() {
            int newnum[8], i;
            newnum[0] = num[0]; newnum[1] = num[6]; newnum[2] = num[1]; newnum[3] = num[3]; newnum[4] = num[4]; 
            newnum[5] = num[2]; newnum[6] = num[5]; newnum[7] = num[7];
            for (i = 0; i < 8; i++) num[i] = newnum[i];
        }
        Square(const Square& c) {
            for (int i = 0; i < 8; i++) num[i] = c.num[i];
        }
        Square() {
        }
        bool check(const Square &c) {
            for (int i = 0; i < 8; i++) {
                if (num[i] != c.num[i]) return false;
            }
            return true;
        }
        void output() {
            for (int i = 0; i < 8; i++) {
                out << num[i] << " ";
            }
            out << endl;
        }
};
class Square init, cur, target;
char result[100];
bool dfs(int step, int max) {
    if (step == max) {
        if (cur.check(target)) {return true;}
        else {return false;}
    }
    //cur.output();
    if (step < 1 || result[step - 1] != 'A') {
        cur.varya();
        result[step] = 'A';
        if (dfs(step + 1, max)) return true;
        cur.varya();
    }

    if (step < 3 || !('B' == result[step - 1] && 'B'==result[step-2] && 'B'==result[step-3])) {
        cur.varyb();
        result[step] = 'B';
        if (dfs(step + 1, max)) return true;
        cur.varyb(); cur.varyb(); cur.varyb();
    }

    if (step < 3 || !('C' == result[step - 1] && 'C'==result[step-2] && 'C'==result[step-3])) {
        cur.varyc();
        result[step] = 'C';
        if (dfs(step + 1, max)) return true;
        cur.varyc(); cur.varyc(); cur.varyc();
    }
    return false;
}
void output(int depth) {
    for (int i = 0; i < depth; i++) {
        out << result[i];
    }
}
int main()
{
    int i;
    for (i = 0; i < 8; i++) {
        init.num[i] = i+1;
    }
    for (i = 0; i < 8; i++) {
        in >> target.num[i];
    }
    int depth;
    for (depth = 0; ;depth++) {
        for (i = 0; i < 8; i++) {
            cur.num[i] = init.num[i];
        }
        if(dfs(0, depth)) {
            out << depth << endl;
            output(depth);
            out << endl;
            return 0;
        }
    }
    return 0;
}

