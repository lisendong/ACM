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
#include<string>
#include<stack>
#include<queue>
using namespace std;
ifstream in("msquare.in"); 
ofstream out("msquare.out");
int k[50000][2] = {0};
int flag[50000] = {0};
string init = "12345678";
string target = init;
int cantor[]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800}; 
int kangtuo(string a) {
    int num = 0;
    for (int i = 0; i < a.size(); i++) {
        int tmp = 0;
        for (int j = i + 1; j < a.size(); j++) {
            if (a[j] < a[i]) tmp++;
        }
        num += tmp * cantor[a.size() - i - 1];
    }
    return num;
}
void bfs() {
    queue <string> q;
    q.push(init);
    while(!q.empty()) {
        int num, cur_num;
        string cur = q.front();
        q.pop();
        cur_num = kangtuo(cur);
        if (cur == target) break;
        flag[cur_num] = true;
        //A
        string n1 = cur;
        reverse(n1.begin(), n1.end());
        num = kangtuo(n1);
        if (!flag[num]) {
            flag[num] = 1;
            q.push(n1);
            k[num][0] = cur_num;
            k[num][1] = 1;
        }
        //B
        string n2 = cur;
        n2[0] = cur[3]; n2[1] = cur[0]; n2[2] = cur[1]; n2[3] = cur[2];
        n2[4] = cur[5]; n2[5] = cur[6]; n2[6] = cur[7]; n2[7] = cur[4];
        num = kangtuo(n2);
        if (!flag[num]) {
            flag[num] = 1;
            q.push(n2);
            k[num][0] = cur_num;
            k[num][1] = 2;
        }
        //C
        string n3 = cur;
        n3[1] = cur[6]; n3[2] = cur[1]; n3[5] = cur[2]; n3[6] = cur[5];
        num = kangtuo(n3);
        if (!flag[num]) {
            flag[num] = 1;
            q.push(n3);
            k[num][0] = cur_num;
            k[num][1] = 3;
        }
    }
}
int main()
{
    int i;
    for (i = 0; i < 8; i++) {
        in >> target[i];
    }
    bfs();
    stack <char> s;
    i = kangtuo(target);
    while (i != 0) {
        s.push((char)('A'+k[i][1] - 1));
        i = k[i][0];
    }
    out << s.size() << endl;
    while (!s.empty()) {
        char ch = s.top();
        s.pop();
        out << ch;
    }
    out << endl;
}

