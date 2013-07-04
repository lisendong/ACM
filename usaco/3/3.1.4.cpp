/*
ID: lisendo1
PROG: rect1
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#define oo 100000
#define MAXK 110
#define MAXN 100010
#define null 0
using namespace std;
ifstream in("rect1.in"); 
ofstream out("rect1.out");
typedef struct rec {
    int x1, y1, x2, y2, color;
    struct rec *next;
} Rec;
int result[3000] = {0};
int main()
{
    int W, H, N;
    in >> W >> H >> N;
    int i;
    Rec r;
    Rec *head = &r;
    head->x1 = 0; head->y1 = 0; head->x2 = W; head->y2 = H;head->color = 1;
    head -> next = null;
    for (i = 0; i < N ; i++) {
        int x1, y1, x2, y2, color;
        int newx1, newy1, newx2, newy2;
        in >> x1 >> y1 >> x2 >> y2 >> color;
        Rec *cur = head, *pre = head;
        while (cur != null) {
            int flag = 0;
            if (x1 > cur->x1 && x1 < cur->x2 && y1 < cur->y2 && y2 > cur->y1) {
                flag ++;
                newx1 = cur->x1; newx2 = x1;
                newy1 = y1 > cur->y1 ? y1 : cur->y1;
                newy2 = y2 < cur->y2 ? y2 : cur->y2;
                Rec *newrect = (Rec*)malloc(sizeof(Rec));
                newrect->x1 = newx1; newrect->x2 = newx2; newrect->y1 = newy1; newrect->y2 = newy2;
                newrect->color = cur->color;
                newrect->next = head;
                head = newrect;
                if (flag == 1 && pre==cur) pre = head;
            }
            if (x2 < cur->x2 && x2 > cur->x1 && y1 < cur->y2 && y2 > cur->y1) {
                flag ++;
                newx1 = x2; newx2 = cur->x2;
                newy1 = y1 > cur->y1 ? y1 : cur->y1;
                newy2 = y2 < cur->y2 ? y2 : cur->y2;
                Rec *newrect = (Rec*)malloc(sizeof(Rec));
                newrect->x1 = newx1; newrect->x2 = newx2; newrect->y1 = newy1; newrect->y2 = newy2;
                newrect->color = cur->color;
                newrect->next = head;
                head = newrect;
                if (flag == 1 && pre==cur) pre = head;
            }
            if (y1 > cur->y1 && y1 < cur->y2 && x1 < cur->x2 && x2 > cur->x1) {
                flag ++;
                newx1 = cur->x1; newy1 = cur->y1;
                newx2 = cur->x2; newy2 = y1;
                Rec *newrect = (Rec*)malloc(sizeof(Rec));
                newrect->x1 = newx1; newrect->x2 = newx2; newrect->y1 = newy1; newrect->y2 = newy2;
                newrect->color = cur->color;
                newrect->next = head;
                head = newrect;
                if (flag == 1 && pre==cur) pre = head;
            }
            if (y2 > cur->y1 && y2 < cur->y2 && x1 < cur->x2 && x2 > cur->x1) {
                flag ++;
                newx1 = cur->x1; newy1 = y2;
                newx2 = cur->x2; newy2 = cur->y2;
                Rec *newrect = (Rec*)malloc(sizeof(Rec));
                newrect->x1 = newx1; newrect->x2 = newx2; newrect->y1 = newy1; newrect->y2 = newy2;
                newrect->color = cur->color;
                newrect->next = head;
                head = newrect;
                if (flag == 1 && pre==cur) pre = head;
            }
            if (flag != 0 || (x1 <= cur->x1 && x2 >= cur->x2 && y1 <= cur->y1 && y2 >=cur->y2)) {
                //cout << "hello" << endl;
                if (pre == cur) {
                    head = head -> next;
                    pre = cur = head;
                }
                else {
                    pre -> next = cur -> next;
                    cur = cur->next;
                }
                //cout << "delete" << cur -> color << endl;
            }
            else {
                if (cur != pre) pre = pre -> next;
                cur = cur -> next;
            }
        }
        Rec *newrect = (Rec*)malloc(sizeof(Rec));
        newrect->x1 = x1; newrect->x2 = x2; newrect->y1 = y1; newrect->y2 = y2;
        newrect->color = color;
        newrect->next = head;
        head = newrect;
    }
    while (head != null) {
        result[head->color] += (head->x2 - head->x1) * (head->y2 - head->y1);
        //cout << "color" << head->color << ":" << head->x1 << "," << head->y1 << " " << head->x2 << "," << head->y2 << endl;
        head = head->next;
    }
    for (i = 1; i <= 2500; i++) {
        if (result[i] > 0) {
            out << i << " " << result[i] << endl;
        }
    }
    return 0;
}

