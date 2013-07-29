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
int M;
bool cover[5010] = {0};
typedef struct _mypair{
    int left, right;
} mypair;
vector<mypair> v;
int cmp(mypair a, mypair b) {
    if (a.right > b.right) return 1;
    else return 0;
}
int rcmp(mypair a, mypair b) {
    if (a.left < b.left) return 1;
    else return 0;
}
int main()
{
    int T;
    cin >> T;
    while (T--) {
        v.clear();
        cin >> M;
        int i;
        for (i = 0; i <= M; i++) cover[i] = false;
        int a, b;
        int count = 0;
        while (cin >> a >> b) {
            if (a == 0 && b == 0) break;
            if (b <= 0 || a >= M) continue;
            mypair * tmpp = new mypair;
            tmpp->left = a; tmpp->right = b;
            v.push_back(*tmpp);
        }
        int l = 0;
        int sum = M;
        vector<mypair> result;
        count = 0;
        while (sum > 0 && l <= M) {
            vector<mypair> cur;
            for (i = 0; i < v.size(); i++) {
                if (v[i].left <= l && v[i].right > l) {
                    cur.push_back(v[i]);
                }
            }
            if (cur.size() == 0) break;
            sort(cur.begin(), cur.end(), cmp);
            sum -= (cur[0].right - l);
            l = cur[0].right;
            count++;
            result.push_back(cur[0]);
            //v.erase(v.begin() + cur[0].pos);
        }
        
        if (sum > 0) cout << "0" << endl;
        else {
            sort (result.begin(), result.end(), rcmp);
            cout << count << endl;
            for (i = 0; i < result.size(); i++) {
                cout << result[i].left << " " << result[i].right << endl;
            }
        }
        cout << endl;
    }
}



