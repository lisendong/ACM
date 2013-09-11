/*
ID: lisendo1
PROG: prime3
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
#include<map>
#include<vector>
#define MAXN 200
#define nil -1
#define oo 100000000.0
using namespace std;
ifstream in("prime3.in"); 
ofstream out("prime3.out");
bool primeflag[100010] = {0};
int one, sum;
bool isprime(int num) {
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}
struct first{
    int  b, c, d, e;
    struct first * next;
};
first * firstlist = NULL;
struct second{
    int b, c, d;
    struct second * next;
};
second * secondlist[20][20] = {NULL};
struct third {
    int b, d, e;
    struct third * next;
};
third * thirdlist[20][20] = {NULL};
//struct forth {
//    int a, c, e;
//    struct forth * next;
//};
//forst * forthlist[20][20] = {NULL};
struct result {
    int data[6][6];
};
int r[6][6];
result total_r[2000];
int result_num = 0;
bool check1(int num) {
    int tmpnum = num;
    int tail = num % 10;
    //if (tail != 1 && tail != 3 && tail != 7 && tail != 9) return false;
    while (num) {
        tail = num % 10;
        num /= 10;
        if (tail == 0) return false;
    }
    int tmpsum = 0;
    num = tmpnum;
    while (num) {
        tmpsum += num % 10;
        num /= 10;
    }
    if (tmpsum != sum) return false;
    return true;
}
bool check2(int i, int mid, int j) {
    int tmpsum = i + j;
    while (mid) {
        tmpsum += mid % 10;
        mid /= 10;
    }
    if (tmpsum == sum) return true;
    else return false;
}
void init() {
    for (int num = 10000; num <= 99999; num++) {
        if (isprime(num)) primeflag[num] = true;
    }
    cout << "prime flag finish!" << endl;
    for (int num = one * 10000; num <= one * 10000 + 9999; num++) {
        if (primeflag[num] && check1(num)) {
            first * tmp1 = (first*)malloc(sizeof(first));
            tmp1->b = num / 1000 % 10;
            tmp1->c = num / 100 % 10;
            tmp1->d = num / 10 % 10;
            tmp1->e = num % 10;
            tmp1->next = firstlist;
            firstlist = tmp1;
        }
    }
    cout << "list 1 finish!" << endl;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            for (int mid = 0; mid<= 999; mid++) {
                int num = mid * 10 + j + i * 10000;
                if (primeflag[num] && check2(i, mid, j)) {
                    second * tmp2 = (second*)malloc(sizeof(second));
                    tmp2->b = mid / 100 % 10;
                    tmp2->c = mid / 10 % 10;
                    tmp2->d = mid % 10;
                    tmp2->next = secondlist[i][j];
                    secondlist[i][j] = tmp2;
                }
            }
        }
    }
    cout << "list 2 finish!" << endl;
    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int mid = 0; mid <= 999; mid++) {
                    int num = i * 10000;
                    num += (mid / 100 % 10) * 1000;
                    num += j * 100;
                    num += (mid / 10 % 10) * 10;
                    num += (mid % 10);
                    if (primeflag[num] && check2(i, mid, j)) {
                        third * tmp3 = (third*) malloc (sizeof(third));
                        tmp3->b = mid / 100 % 10;
                        tmp3->d = mid / 10 % 10;
                        tmp3->e = mid % 10;
                        tmp3->next = thirdlist[i][j];
                        thirdlist[i][j] = tmp3;
                    }
            }
        }
    }
    cout << "list 3 finish!" << endl;
    //for (int i = 0; i <= 9; i++) {
    //    for (int j = 0; j <= 9; j++) {
    //        for(int mid = 100; mid <= 999; mid ++) {
    //            int num = (mid / 100) * 10000;
    //            num += i * 1000;
    //            num += (mid / 10 % 10) * 100;
    //            num += j * 10;
    //            num += (mid % 10);
    //            if (primeflag(num)) {
    //                forth * tmp4 = (forth*) malloc(sizeof(forth));
    //                tmp4->a = mid / 100;
    //                tmp4->c = mid / 10 % 10;
    //                tmp4->e = mid % 10;
    //                tmp4->next = forthlist[i][j];
    //                forthlist[i][j] = tmp4;
    //            }
    //        }
    //    }
    //}
}
bool check_result() {
    r[2][5] = sum - r[2][1] - r[2][2] - r[2][3] - r[2][4];
    if (r[2][5] < 0 || r[2][5] > 9) return false;
    int num1 = r[2][1] * 10000 + r[2][2] * 1000 + r[2][3] * 100 + r[2][4] * 10 + r[2][5];
    if (!primeflag[num1]) return false;
    
    r[4][5] = sum - r[4][1] - r[4][2] - r[4][3] - r[4][4];
    if (r[4][5] < 0 || r[4][5] > 9) return false;
    num1 = r[4][1] * 10000 + r[4][2] * 1000 + r[4][3] * 100 + r[4][4] * 10 + r[4][5];
    if (!primeflag[num1]) return false;

    //r[5][2] = sum - r[1][2] - r[2][2] - r[3][2] - r[4][2];
    //if (r[5][2] < 0 || r[5][2] > 9) return false;
    //num1 = r[1][2] * 10000 + r[2][2] * 1000 + r[3][2] * 100 + r[4][2] * 10 + r[5][2];
    //if (!primeflag[num1]) return false;

    //r[5][4] = sum - r[1][4] - r[2][4] - r[3][4] - r[4][4];
    //if (r[5][4] < 0 || r[5][4] > 9) return false;
    //num1 = r[1][4] * 10000 + r[2][4] * 1000 + r[3][4] * 100 + r[4][4] * 10 + r[5][4];
    //if (!primeflag[num1]) return false;

    if (sum != (r[5][1] + r[5][2] + r[5][3] + r[5][4] + r[5][5])) return false;
    if (sum != (r[1][5] + r[2][5] + r[3][5] + r[4][5] + r[5][5])) return false;

    num1 = r[1][5] * 10000 + r[2][5] * 1000 + r[3][5] * 100 + r[4][5] * 10 + r[5][5];
    if (!primeflag[num1]) return false;

    num1 = r[5][1] * 10000 + r[5][2] * 1000 + r[5][3] * 100 + r[5][4] * 10 + r[5][5];
    if (!primeflag[num1]) return false;
    //int i, j;
    //bool flag[10] = {0};
    //for (i = 1; i <= 5; i++) {
    //    for (j = 1; j <= 5; j++) {
    //        if (r[i][j] != 0 && r[i][j] != 1 && r[i][j] != 2 && r[i][j] != 3 && r[i][j] != 5 && r[i][j] != 7) {
    //            if (flag[r[i][j]] != 0) return false;
    //            flag[r[i][j]]++;
    //        }
    //    }
    //}
    return true;
}
void dfs6(void) {
    third * cur;
    for (cur = thirdlist[r[1][3]][r[3][3]]; cur != NULL; cur = cur->next) {
        r[2][3] = cur->b; r[4][3] = cur->d; r[5][3] = cur->e;
        if (check_result()) {
            memcpy(total_r[result_num].data, r, sizeof(r));
            result_num++;
        }
    }
}
void dfs5(void) {
    third * cur;
    for (cur = thirdlist[r[3][1]][r[3][3]]; cur != NULL; cur = cur->next) {
        r[3][2] = cur->b; r[3][4] = cur->d; r[3][5] = cur->e;
        //delete branch
        r[5][2] = sum - r[1][2] - r[2][2] - r[3][2] - r[4][2];
        if (r[5][2] < 0 || r[5][2] > 9) continue;
        int num1 = r[1][2] * 10000 + r[2][2] * 1000 + r[3][2] * 100 + r[4][2] * 10 + r[5][2];
        if (!primeflag[num1]) continue;

        r[5][4] = sum - r[1][4] - r[2][4] - r[3][4] - r[4][4];
        if (r[5][4] < 0 || r[5][4] > 9) continue;
        num1 = r[1][4] * 10000 + r[2][4] * 1000 + r[3][4] * 100 + r[4][4] * 10 + r[5][4];
        if (!primeflag[num1]) continue;

        //if (sum != (r[5][1] + r[5][2] + r[5][3] + r[5][4] + r[5][5])) continue;

        //num1 = r[5][1] * 10000 + r[5][2] * 1000 + r[5][3] * 100 + r[5][4] * 10 + r[5][5];
        //if (!primeflag[num1]) continue;
        dfs6();
    }
}
void dfs4(void) {
    third * cur;
    for (cur = thirdlist[r[1][1]][r[3][3]]; cur != NULL; cur = cur->next) {
        r[2][2] = cur->b; r[4][4] = cur->d; r[5][5] = cur->e;
        dfs5();
    }
}
void dfs3(void) {
    second * cur;
    for (cur = secondlist[r[5][1]][r[1][5]]; cur != NULL; cur = cur->next) {
        r[4][2] = cur->b; r[3][3] = cur->c; r[2][4] = cur->d;
        dfs4();
    }
}
void dfs2(void) {
    first * cur;
    for (cur = firstlist; cur != NULL; cur = cur->next) {
        r[2][1] = cur->b; r[3][1] = cur -> c; r[4][1] = cur->d; r[5][1] = cur->e;
        dfs3();
    }
}
void dfs1(void) {
    first * cur;
    for (cur = firstlist; cur != NULL; cur = cur->next) {
        r[1][1] = one;
        r[1][2] = cur->b; r[1][3] = cur->c; r[1][4] = cur->d; r[1][5] = cur->e;
        dfs2();
    }
}
int cmp(result a, result b) {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            if (a.data[i][j] < b.data[i][j]) return 1;
            else if (a.data[i][j] > b.data[i][j]) return 0;
        }
    }
}
int main()
{
    in >> sum >> one;
    init();
    cout << "init finish!" << endl;
    dfs1();
    sort(total_r, total_r + result_num, cmp);
    cout << "The above example has " << result_num <<" solutions.\n\n";
    //printf("The above example has %d solutions.\n\n", result_num);
    for (int i = 0; i < result_num; i++) {
        for (int j = 1; j <= 5; j++) {
            for (int k = 1; k <= 5; k++) {
                out << total_r[i].data[j][k];
//                printf("%d", total_r[i].data[j][k]);
            }
                out << endl;
 //           printf("\n");
        }
        if (i != result_num - 1)
            out << endl;
//        printf("\n");
    }
}
