/*
 ID:lisendo1
 PROG:namenum
 LANG:C++
*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
int main() {
    ifstream in("namenum.in");
    ifstream dictin("dict.txt");
    ofstream out("namenum.out");
    char a[10][3] = {{0, 0, 0}, {0, 0, 0}, {'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'}, {'J', 'K', 'L'}, {'M', 'N', 'O'}, {'P', 'R', 'S'}, {'T', 'U', 'V'}, {'W', 'X', 'Y'}};
    //vector<string> dictv;
    //string temp;
    //while(dictin >> temp) {
    //    dictv.push_back(temp);
    //}
    int input[15];
    char tempc;
    int N = 0;
    while (in >> tempc) {
        input[N] = tempc - '0';
        //cout << input[N] << endl;
        N++;
    }
    string one;
    int have = 0;
    while (dictin >> one) {
        if (N != one.length()) continue;
        int flag = 1;
        for (int j = 0; j < one.length(); j++) {
            if (a[input[j]][0] != one[j] && a[input[j]][1] != one[j] && a[input[j]][2] != one[j]) {
                flag = 0;
                break;
            }
            //else {
            //    cout << one[j];
            //    cout << input[j] << "\t" << a[input[j]][0] << "\t" << a[input[j]][1] << "\t" << a[input[j]][2] << endl;
            //}
        }
        if (flag == 0) continue;
        have = 1;
        out << one << endl;
    }
    if (have == 0) out << "NONE" << endl;
    return 0; 
}
