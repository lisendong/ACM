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
#include<map>
#include<deque>
#include<list>
#include<vector>
#define oo 0x7FFFFFF
#define MAXN 25
using namespace std;
vector <string> v;
map <string, int> m;
int main()
{
    int t;
    cin >> t;
    string s;
    getline(cin, s);
    getline(cin, s);
    while (t--) {
        int min_size = oo, max_size = 0;
        v.clear();
        m.clear();
        while (true) {
            getline(cin, s);
            if (s.empty()) {
                break;
            }
            if (s.size() > max_size) max_size = s.size();
            if (s.size() < min_size) min_size = s.size();
            v.push_back(s);
        }
        int L = min_size + max_size;
        int i, j;
        for (i = 0; i < v.size(); i++) {
            for (j = 0; j < v.size(); j++) {
                if (v[i].size() + v[j].size() == L) {
                    string a = v[i] + v[j];
                    string b = v[j] + v[i];
                    if (m.find(a) == m.end()) {
                        m[a] = 0;
                    }
                    if (m.find(b) == m.end()) {
                        m[b] = 0;
                    }
                    m[a] = m[a] + 1;
                    m[b] = m[b] + 1;
                }
            }
        }
        int max_count = 0;
        string result;
        for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
            if (it->second > max_count){
                 result = it->first;
                 max_count = it->second;
            }
        }
        cout << result << endl;
        if (t != 0) cout << endl; 
    }
}



