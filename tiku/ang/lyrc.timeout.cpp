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
#include <map>
#include<deque>
#include<list>
#include<vector>
#define oo 0x7FFFFFF
#define MAXN 25
using namespace std;
map<string, int> m;
vector<string> word;
vector<int> wl;
vector<string> str;
int main()
{
    int num_words;
    cin >> num_words;
    int i;
    string a;
    for (i = 0; i < num_words; i++) {
        cin >> a;
        word.push_back(a);
        m[a] = 0;
        if (find(wl.begin(), wl.end(), a.size()) == wl.end()) {
            wl.push_back(a.size());
        }
    }
    sort(wl.begin(), wl.end());
    int num_str;
    cin >> num_str;
    for (i = 0; i < num_str; i++) {
        cin >> a;
        str.push_back(a);
    }
    int j, k;
    for (i = 0; i < str.size(); i++) {
        for (j = 0; j < str[i].size(); j++) {
            int found = 0;
            for (k = 0; k < wl.size(); k++) {
                if (j + wl[k] - 1 >= str[i].size()) break;
                found++;
                string substr = str[i].substr(j, wl[k]);
                if (m.find(substr) != m.end()) {
                    m[substr] += 1;
                }
            }
            if (found == 0) continue;
        }
    }
    for (i = 0; i < word.size(); i++) {
        cout << m[word[i]] << endl;
    }
}



