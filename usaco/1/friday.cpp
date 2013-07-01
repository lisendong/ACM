/*
 ID:lisendo1
 PROG:friday
 LANG:C++
*/
#include <iostream>
#include <fstream>
using namespace std;
int get_day(int month, int year) {
    int a[13] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(month == 2) {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
            return 29;
        }
        else {
            return 28;
        }
    }
    else {
        return a[month];
    }
}

int main() {
    ifstream in("friday.in");
    ofstream out("friday.out");
    int N;
    in >> N;
    int start_year = 1900, start_month = 1, start_day = 1;
    int week = 1;
    int count[8] = {0};
    while (true) {
        if (start_month == 12 && start_day == 31 && start_year == 1900 + N - 1) {
            break;
        }
        if(start_day == 13) {
            count[week] += 1;
        }
        week += 1;
        if (week > 7) week = 1;
        if (start_day == get_day(start_month, start_year)) {
            start_day = 1;
            if (start_month == 12) {
                start_month = 1;
                start_year += 1;
            }
            else {
                start_month += 1;
            }
        }
        else {
            start_day += 1;
        }
    }
    out << count[6] << " " << count[7] << " ";
    for (int i = 1; i <=5; i++) {
        out << count[i];
        if( i != 5) out << " ";
    }
    out << endl;
}
