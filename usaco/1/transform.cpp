/*
 ID:lisendo1
 PROG:transform
 LANG:C++
*/
#include <iostream>
#include <fstream>
using namespace std;
char a[20][20], b[20][20], temp[20][20];
int N;
int equals(char a[20][20], char b[20][20]) {
    int flag = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (a[i][j] != b[i][j]) {
                flag = 0;
                break;
            }
        }
    }
    return flag;
}
int init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[i][j] = a[i][j];
        }
    }
}
void num1() {
    int temp1[20][20];
    for (int i = 0; i < N; i++) {
         for (int j = 0; j < N; j++) {
             temp1[j][N - 1 - i] = temp[i][j];
         }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[i][j] = temp1[i][j];
        }
    }
}
void num2() {
    int temp1[20][20];
    for (int i = 0; i < N; i++) {
         for (int j = 0; j < N; j++) {
             temp1[N - 1 - i][N - 1 - j] = temp[i][j];
         }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[i][j] = temp1[i][j];
        }
    }
}
void num3() {
    int temp1[20][20];
    for (int i = 0; i < N; i++) {
         for (int j = 0; j < N; j++) {
             temp1[N - 1 - j][i] = temp[i][j];
         }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[i][j] = temp1[i][j];
        }
    }
}
void num4() {
    int temp1[20][20];
    for (int i = 0; i < N; i++) {
         for (int j = 0; j < N; j++) {
             temp1[i][N - 1 - j] = temp[i][j];
         }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[i][j] = temp1[i][j];
        }
    }
}
int main() {
    ifstream in("transform.in");
    ofstream out("transform.out");
    in >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            in >> a[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            in >> b[i][j];
        }
    }
    init();
    num1();
    if (equals(b, temp)) {out << 1 << endl; return 0;}
    init();
    num2();
    if (equals(b, temp)) {out << 2 << endl; return 0;}
    init();
    num3();
    if (equals(b, temp)) {out << 3 << endl; return 0;}
    init();
    num4();
    if (equals(b, temp)) {out << 4 << endl; return 0;}
    init();
    num4();num1();
    if (equals(b, temp)) {out << 5 << endl; return 0;}
    init();
    num4();num2();
    if (equals(b, temp)) {out << 5 << endl; return 0;}
    init();
    num4();num3();
    if (equals(b, temp)) {out << 5 << endl; return 0;}
    init();
    if (equals(b, temp)) {out << 6 << endl; return 0;}
    out << 7 << endl; 
    return 0;
}

