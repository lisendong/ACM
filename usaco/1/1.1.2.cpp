/*
 ID:lisendo1
 PROG:ride
 LANG:C++
*/
#include <iostream>
#include <fstream>
using namespace std;
int main() {
    char a[10], b[10];
    ifstream file("ride.in");
    ofstream fout("ride.out");
    file >> a >> b;
    int num1= 1, num2 = 1;
    for (int i = 0; a[i] != 0; i++) {
        num1 *= a[i] - 'A' + 1;
        if (num1 > 47) {
           num1 %= 47;
        }
    } 
    for (int i = 0; b[i] != 0; i++) {
        num2 *= b[i] - 'A' + 1;
        if (num2 > 47) {
           num2 %= 47;
        }
    } 
    if (num1 == num2) {fout << "GO" << endl;}
    else {fout << "STAY" << endl;} 
    return 0;
}
