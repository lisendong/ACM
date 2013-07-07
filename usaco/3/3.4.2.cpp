/*
ID: lisendo1
PROG: heritage
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
#define oo 0x7FFFFFF
#define MAXN 210
using namespace std;
ifstream in("heritage.in"); 
ofstream out("heritage.out");
struct point{
   // vector <char> v; 
    char root;
    point *left;
    point *right;
};
string in_order, pre_order;
point * get_tree(int left, int right) {
    //cout << left << ":" << right << endl;
    if (left > right) return NULL;
    int i, j;
    for (i = 0; i < pre_order.size(); i++) {
        for (j = left; j <= right; j++) {
            if (pre_order[i] == in_order[j]) {
                break;
            }
        }
        if (j <= right) break;
    }
    point * r = (point *)malloc(sizeof(point));
    r->root = in_order[j];
    r->left = get_tree(left, j - 1);
    r->right = get_tree(j+1, right);
    return r;
}
void post_order(point * r) {
    if (r == NULL) return;
    post_order(r->left);
    post_order(r->right);
    out << r->root;
}
int main()
{
    in >> in_order;
    in >> pre_order;
    //point *r = (point*)malloc(sizeof(point));
    //r->root = pre_order[0];
    point *r = get_tree(0, in_order.size() - 1);
    //cout <<"finish" << endl;
    post_order(r);
    out << endl;
    //cout << in_order.size();
    return 0;
}

