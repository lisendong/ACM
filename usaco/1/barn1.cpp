/*
 ID:lisendo1
 PROG:barn1
 LANG:C++
*/
#include <iostream>
#include <string>
#include "string.h"
#include <fstream>
#include <vector>
#include "math.h"
using namespace std;
int main() {
    ifstream in("barn1.in");
    ofstream out("barn1.out");
    int M, S, C;
    in >> M >> S >> C;
    int a[400] = {0}, b[400] = {0};
    int min = 10000000 , max = 0;
    for (int i = 1; i <= C; i++) {
        int temp;
        in >> temp;
        a[temp] = 1;
        if (temp > max) max = temp;
        if (temp < min) min = temp;
    }
    //初始化全部都盖上
    for (int i = min; i <= max; i++) {
        b[i] = 1;
    }
    //迭代4步
    for (int i = 1; i < M; i++) {
        int max_freei = 1, max_free = 0;
        int count = 0;
        for (int j = 1; j <= S; j++) {
            if (a[j] == 0 && b[j] == 1) {
                count += 1;
            }
            else {
                if (count > max_free) {
                    max_free = count;
                    max_freei = j - 1;
                }
                count = 0;
            }
        }
        if (max_freei == 1) continue;
        for (int k = max_freei; a[k] == 0 && b[k] == 1; k--) {
            b[k] = 0;
        }
    }
    int num = 0;
    for (int i = 0; i <= S; i++) {
        num += b[i];
    }
    out << num << endl;
    return 0;
}
