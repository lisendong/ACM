/*
 ID:lisendo1
 PROG:palsquare
 LANG:C++
*/
#include <iostream>
#include <string>
#include "string.h"
#include <fstream>
#include <vector>
#include "math.h"
using namespace std;
class Num
{
    public:
        int value;
        char a[50];
//        Num(int num) {
//            this->value = num; 
//        }
        void setnum(int num) {
            this->value = num;
        }
        void convert(int base) {
            int i = 0;
            while (value != 0) {
                if(value % base < 10) {
                    a[i] = '0' + value % base;
                }
                else {
                    a[i] = 'A' + value % base - 10;
                }
                value /= base;
                i++;
            }
            a[i] = '\0';
        }
        bool ispal() {
            bool flag = 1;
            for (int i = 0; i <= (strlen(a) - 1) / 2; i++) {
                if (a[i] != a[strlen(a) - 1 - i]) flag = 0;
            }
            return flag;
        }
};
char *reverse(char * a) {
    for (int i = 0; i <= (strlen(a) - 1) / 2; i++) {
        int temp = a[i];
        a[i] = a[strlen(a) - 1 - i];
        a[strlen(a) - 1 - i] = temp;
    }
    return a;
}
int main() {
    ifstream in("palsquare.in");
    ofstream out("palsquare.out");
    int base;
    in >> base;
    Num thisa, thisb;
    for (int i = 1; i <=300; i++) {
        thisa.setnum(pow(i, 2));
        thisb.setnum(i);
        thisa.convert(base);
        thisb.convert(base);
        if (thisa.ispal()) out << reverse(thisb.a) << " " << thisa.a << endl;
    }
    return 0;
}

