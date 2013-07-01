/*
 ID:lisendo1
 PROG:dualpal
 LANG:C++
*/
#include <iostream>
#include <string>
#include "string.h"
#include <fstream>
#include <vector>
#include "math.h"
using namespace std;
bool ispal(char *a) {
    for (int i = 0, j = strlen(a) - 1; i <j; i++, j--) {
        if (a[i] != a[j]) return 0;
    }
    return 1;
}
void convert(char *s, int num, int base) {
    int len;
    if (num == 0) {
        strcpy(s, "");
        return ;
    }
    convert(s, num / base, base);
    len = strlen(s);
    s[len] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[num % base];
    s[len+1] = '\0';
}
int main() {
    ifstream in("dualpal.in");
    ofstream out("dualpal.out");
    int N, S;
    char a[50];
    in >> N >> S;
    int i = 1;
    for (int j = S + 1; ; j++) {
        int count = 0;
        for (int base = 2; base <= 10; base ++) {
            convert(a, j , base);
            if (ispal(a)) count ++;
            if (count >= 2) {
                //cout << i << endl;
                i++;
                out << j << endl;
                break; 
            }
        }
        if (i > N) break;
    }
    return 0;

}
