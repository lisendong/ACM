/*
 ID:lisendo1
 PROG:gift1
 LANG:C++
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main() {
    string a[20]; 
    int b[20] = {0};
    ifstream ifile("gift1.in");
    ofstream ofile("gift1.out");
    int NP = 0;
    ifile >> NP;
    for(int i = 0; i < NP; i++) {
        ifile >> a[i];
    }
    string temp;
    while(ifile >> temp) {
        int find;
        for (find = 0; find < NP; find++) {
            if (temp == a[find]) break;
        }
        int money, num;
        ifile >> money >> num;
        if (num == 0) continue;
        int money_per_gift = money / num;
        int money_total = money - money % num;
        for (int j = 0; j < num; j++) {
            string person;
            ifile >> person;
            for (int k = 0; k < NP; k++) {
                if (person == a[k]) {
                    b[k] += money_per_gift;
                }
            }
        }
        b[find] -= money_total;
    }
    for (int i = 0; i < NP; i++) {
        ofile << a[i] << " ";
        ofile << b[i] << endl;
    }
    return 0;
}
