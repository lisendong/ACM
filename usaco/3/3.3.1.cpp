/*
ID: lisendo1
PROG: fence
LANG: C++
*/
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#define MAXN 510
using namespace std;
ifstream in("fence.in"); 
ofstream out("fence.out");
int N;
list <int> e[MAXN];
int result_num = 0;
int result[20000] = {0};
void insert_edge(int a, int b) {
    list <int>::iterator i;
    for (i = e[a].begin(); i != e[a].end(); i++) {
        if (b < *i) break;
    }
    e[a].insert(i, b);
}
//int pos = 0;
void delete_edge(int a, int b) {
    list <int>:: iterator i;
    for (i = e[a].begin(); i != e[a].end(); i++) {
        if (*i == b) {
            e[a].erase(i);
            break;
        }
    }
}
void eu(int node, int step) {
    //if (step > 1000) cout << step << endl;
    if (e[node].size() == 0){
        //out << node << endl;
        result[result_num++] = node;
    }
    else {
        while (!e[node].empty()) {
            //cout << e[node].size() << endl;
            int select = e[node].front();
            e[node].pop_front();
            delete_edge(select, node);
            eu(select, step+1);
        }
        result[result_num++] = node;
    }
}
int main()
{
    in >> N;
    int i;
    for (i = 0; i < N; i++) {
        int a, b;
        in >> a >> b;
        insert_edge(a, b);
        insert_edge(b, a);
    }
    int min = 0;
    for (i = 1; i <= 500; i++) {
        if (min == 0 && e[i].size() > 0) min = i;
        if (e[i].size() % 2 == 1) {
            min = i;
            break;
        }
    }
    eu(min, 0);
    //cout << result_num << endl;
    while (result_num--) {
        out << result[result_num] << endl;
    }
}

