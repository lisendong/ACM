/*
 ID:lisendo1
 PROG:crypt1
 LANG:C++
*/
#include <iostream>
#include <string>
#include "string.h"
#include <fstream>
#include <vector>
#include "math.h"
#include <stdio.h>
#include <cstdlib>
using namespace std;
char num[15];
int N;
void itoa(int num, char * s) {
    if (num == 0) {
        strcpy(s, "");
        return ;
    }
    itoa(num / 10, s);
    int len = strlen(s);
    s[len] = '0' + num % 10;
    s[len+1] = '\0';
}
bool in_array(int a) {
    for (int i = 0; i < N; i++) {
        if ('0' + a == num[i]) return 1;
    }
    return 0;
}
int main() {

    ifstream in("crypt1.in");
    ofstream out("crypt1.out");
    in >> N;
    for (int i = 0; i < N; i++) {
        in >> num[i]; 
    }
    int count = 0;
    for (int a = 0; a < N; a++) {
    for (int b = 0; b < N; b++) {
    for (int c = 0; c < N; c++) {
    for (int d = 0; d < N; d++) {
    for (int e = 0; e < N; e++) {
        char num1[4] = {num[a], num[b], num[c], 0};
        char num2[3] = {num[d], num[e], 0};
        int value1 = atoi(num1);
        int value2 = atoi(num2);
        int value3 = value1 * value2;
        char num3[20];
        itoa(value3, num3);
        int flag = 1;
        if (value3 == 4884) {
        }
        int partial1 = value1 * (num2[1] - '0');
        if (partial1 >= 1000) {
            continue;
        }
        while (partial1 != 0) {
            if (!in_array(partial1 % 10)) flag = 0;
            partial1 /= 10;
        }
        int partial2 = value1 * (num2[0] - '0');
        if (partial2 >= 1000) {
            continue;
        }
        while (partial2 != 0) {
            if (!in_array(partial2 % 10)) flag = 0;
            partial2 /= 10;
        }
        
        
        for (int i = 0; i < strlen(num3); i++) {
            int found = 0;
            for (int j = 0; j < N; j++) {
                if (num[j] == num3[i]) found = 1;
            }
            if (found == 0) {
                flag = 0;
                break;
            }
        }
        if (flag == 1 && strlen(num3) == 4) {
            count ++;
            cout << value1 << "\t" << value2 << endl;
            cout << num3 << endl;
        }

    }
    }
    }
    }
    }
    out << count << endl;
    return 0;
}

