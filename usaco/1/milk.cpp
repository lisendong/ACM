/*
 ID:lisendo1
 PROG:milk
 LANG:C++
*/
#include <iostream>
#include <string>
#include "string.h"
#include "stdlib.h"
#include <fstream>
#include <vector>
#include "math.h"
using namespace std;
typedef struct farm {
    int p;
    int a;
}FARM;
int compare(const void *a, const void *b) {
    FARM *farm1 = (FARM*) a;
    FARM *farm2 = (FARM*) b;
    if (farm1->p < farm2->p) return -1;
    if (farm1->p > farm2->p) return 1;
    return 0;
}
int main() {
    ifstream in("milk.in");
    ofstream out("milk.out");
    int N;
    int M;
    FARM f[6000];
    in >> N >> M;
    for (int i = 0 ; i < M; i++) {
        in >> f[i].p >> f[i].a;
    }
    int prize = 0;
    qsort(f, M, sizeof(f[0]), compare);
    for (int i = 0; N > 0; i++) {
        if (f[i].a < N) {
            N -= f[i].a;
            prize += f[i].a * f[i].p;
        }
        else {
            prize += N * f[i].p;
            N = 0;
        }
    }
    out << prize << endl;
    return 0;

}

