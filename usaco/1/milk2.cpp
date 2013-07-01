/*
 ID:lisendo1
 PROG:milk2
 LANG:C++
*/
#include <iostream>
#include <fstream>
using namespace std;
int N;
int a[6000][2];
int is_busy(int time) {
    int flag = 0;
    for (int i = 0; i < N; i++) {
        if (time >= a[i][0] && time < a[i][1]) {
            flag = 1;
            break;
        }
    }
    return flag;
}
int main() {
    ifstream in("milk2.in");
    ofstream out("milk2.out");
    in >> N;
    int min = 1000000, max = 0;
    for (int i = 0; i < N; i++) {
        in >> a[i][0] >> a[i][1]; 
        if (a[i][0] < min) min = a[i][0];
        if (a[i][1]  > max) max = a[i][1];
    }
    int max_busy = 0, max_free = 0;
    int busy_flag = 0, count = 0;
    for (int i = min; i <= max; i++) {
        int busy = is_busy(i); 
        if (i == min) busy_flag = busy;
        if (busy == busy_flag) {
            count += 1;
        }
        else {
            if (busy_flag == 0) {
                max_free = count > max_free ? count : max_free;
            }
            else {
                max_busy = count > max_busy ? count : max_busy;
            }
            count = 1;
            busy_flag = busy;
        }
        
    }
    out << max_busy << " " << max_free << endl;
    return 0;
}

