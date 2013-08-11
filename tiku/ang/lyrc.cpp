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
typedef unsigned long long ull;
using namespace std;
int nNodesCount = 0;
int mstrnum = 0;
int result[1000] = {0};
int belong[1000] = {0};
char all_str[1000][6000];
struct CNode {
    CNode *pChilds[100];
    CNode *pPrev;
    bool bBadNode;
    bool bStopNode;
    int strnum;
    int latenum;
    void Init() {
        memset(pChilds, 0, sizeof(pChilds));
        bBadNode = false;
        bStopNode = false;
        pPrev = NULL;
        strnum = 0;
        latenum = 0;
    }
};
CNode Tree[3000000];
int getnum(char a) {
    if (a >= 'a' && a <= 'z') return a - 'a';
    if (a >= 'A' && a <= 'Z') return a - 'A' + 26;
    if (a >= '0' && a <= '9') return a - '0' + 52;
    if (a == '-') return 62;
}
void Insert(CNode * pRoot, char *s, int j) {
    for (int i = 0; s[i]; i++) {
        int num = getnum(s[i]);
        if (pRoot->pChilds[num] == NULL) {
            pRoot->pChilds[num] = Tree + nNodesCount;
            nNodesCount++;
        }
        pRoot = pRoot->pChilds[num];
    }
    pRoot->bBadNode = true;
    pRoot->bStopNode = true;  
    pRoot->strnum = j;
}
void BuildDfa() {
    for (int i = 0; i < 63; i++) {
        Tree[0].pChilds[i] = Tree+1;
    }
    Tree[0].pPrev = NULL;
    Tree[1].pPrev = Tree;
    deque<CNode*>q;
    q.push_back(Tree+1);
    while (!q.empty()) {
        CNode *pRoot = q.front();
        q.pop_front();
        for (int i = 0; i < 63; i++) {
            CNode *p = pRoot->pChilds[i];
            if (p) {
                CNode *pPrev = pRoot->pPrev;
                while(pPrev) {
                    if (pPrev->pChilds[i]) {
                        p->pPrev = pPrev->pChilds[i];
                        if (p->pPrev->bBadNode) {
                            p->bBadNode = true;
                        }
                        break;
                    }
                    else {
                        pPrev = pPrev->pPrev;
                    }
                }
                q.push_back(p);
            }
        }
    }
}
void SearchDfa(char *s) {
    CNode *p = Tree + 1;
    for (int i = 0; s[i]; i++) {
        while (true) {
            int num = getnum(s[i]);
            if (p->pChilds[num]) {
                p = p->pChilds[num];
                if (p->bStopNode) {
                    result[p->strnum]++;
                }
                if (p->bBadNode) {
                    p->latenum++;
                    //CNode *prev = p->pPrev;
                    //while (prev->bBadNode) {
                    //    if (prev->bStopNode) {
                    //        result[prev->strnum]++;
                    //        //break;
                    //    }
                    //    prev = prev->pPrev;
                    //}
                }
                break;
            }
            else {
                p = p->pPrev;
            }
        }
    }
}
void lateDfa() {
    deque<CNode*>q;
    q.push_back(Tree+1);
    while (!q.empty()) {
        CNode *pRoot = q.front();
        q.pop_front();
        for (int i = 0; i < 63; i++) {
            CNode *p = pRoot->pChilds[i];
            if (p) {
                if (p->latenum > 0) {
                    CNode *prev = p->pPrev;
                    while (prev->bBadNode) {
                        if (prev->bStopNode) {
                            result[prev->strnum]+=p->latenum;
                        }
                        prev = prev->pPrev;
                    }
                }
                q.push_back(p);
            }
        }
    }
}
int main()
{
    nNodesCount = 2;
    int num_words;
    scanf("%d", &num_words);
    int i, j;
    char a[6000];
    for (i = 0; i < num_words; i++) {
        scanf("%s", a);
        for (j = 0; j < mstrnum; j++) {
            if (strcmp(a, all_str[j]) == 0) {
                break;
            }
        }
        belong[i] = j;
        if (j == mstrnum) {
            Insert(Tree+1, a, j);
        }
        if (j == mstrnum) {
            strcpy(all_str[j], a);
            mstrnum++;
        }
    }
    BuildDfa();
    int num_str;
    scanf("%d", &num_str);
    char b[100000];
    for (i = 0; i < num_str; i++) {
        scanf("%s", b);
        SearchDfa(b);
    }
    lateDfa();
    for (i = 0; i < num_words; i++) {
        printf("%d\n", result[belong[i]]);
    }
}



