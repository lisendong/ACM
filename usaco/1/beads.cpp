/*
 ID:lisendo1
 PROG:beads
 LANG:C++
*/
#include <iostream>
#include <fstream>
using namespace std;
char a[400];
int N;
int count(char b, int pos, int dir);
int count(char b, int pos, int dir) {
    int result = 0;
    int temp = pos;
    while (true) {
        if((a[pos] != 'w' && a[pos] != b) || (pos == temp && result != 0)) break;
        result++;
        if (dir == -1) pos = (pos == 0 ? N - 1 : pos - 1);
        if (dir == 1) pos = (pos == N - 1 ? 0 : pos + 1);
    }
    return result;
}
int main() {
    ifstream in("beads.in");
    ofstream out("beads.out");
    in >> N;
    for (int i = 0; i < N; i++) {
        in >> a[i];
    }
    int left = N - 1, right = 0;
    int max = 0;
    for(right = 0; right < N; right ++) {
        left = (right == 0 ? N -1 : right - 1);
        int count_left = 0, count_right = 0;
        //cout << right;
        if (a[left] == 'r') {
            count_left = count('r', left, -1);
        }
        else if (a[left] == 'b') {
            count_left = count('b', left, -1);
        }
        else if(a[left] == 'w') {
            count_left = count('r', left, -1) > count('b', left, -1) ? count('r', left, -1) : count('b', left, -1);
        }
        if (count_left == N) {
            out << count_left << endl;
            return 0;
        }
        if (a[right] == 'r') {
            count_right = count('r', right, 1);
        }
        else if (a[right] == 'b') {
            count_right = count('b', right, 1);
        }
        else if(a[right] == 'w') {
            count_right= count('r', right, 1) > count('b', right, 1) ? count('r', right, 1) : count('b', right, 1);
        }
        //cout << count_left << count_right << endl;
        if (count_right + count_left > max) max = count_right + count_left;
    }
    if (max > N) max = N;
    out << max << endl;
    return 0;
}

