/*
ID: lisendo1
PROG: contact 
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#define oo 100000
#define MAXK 110
#define MAXN 100010
#define null 0
using namespace std;
ifstream in("contact.in"); 
ofstream out("contact.out");
int sta[5000][13] = {0};
char s[200000];
typedef struct result {
    int num, length, freq;
} Result;
Result r[70000];
void output_binary(int num, int length) {
    int count = 0;
    bool tmp[20];
    while (num != 0) {
        tmp[count++] = num % 2;
        num /= 2;
    }
    int i;
    for (i = 0; i < length - count; i++) {
        out << 0;
    }
    for (count = count - 1; count >= 0; count --) {
        out << tmp[count];
    }
}
int get_digit(char *s, int start, int str_len) {
    int sum = 0;
    for (int i = start; i < start+str_len; i++) {
        sum = sum * 2 + s[i] - '0';
    }
    return sum;
}
bool cmp(Result a, Result b) {
    if (a.freq != b.freq) return (a.freq > b.freq);
    if (a.length != b.length) return (a.length < b.length);
    return a.num < b.num;
}
int main()
{
    int A, B, N;
    in >> A >> B >> N;
    char ch;
    int S = 0;
    while (in >> ch) {
        if (ch == 10) continue;
        s[S++] = ch;
    }
    int str_len = 0;
    for (str_len = A; str_len <= B; str_len++) {
        int start;
        for (start = 0; start + str_len - 1 < S; start++) {
            int digit = get_digit(s, start, str_len);
            sta[digit][str_len] ++;
        }
    }
    int result_num = 0;
    int i, j;
    for (i = 0; i <5000; i++) {
        for (j = 1; j <=12; j++) {
            if (sta[i][j] > 0) {
                r[result_num].num = i;
                r[result_num].length = j;
                r[result_num].freq = sta[i][j];
                result_num++;
            }
        }
    }
    sort(r, r + result_num, cmp);
    j = 0;
    int last_freq = -1;
    int count = 0;
    for (i = 0; i < result_num; i++) {
        if (r[i].freq != last_freq) {
            j++;
            if (j > N) break;
            if (count != 0) out << endl;
            out << r[i].freq << endl; 
            count = 0;
        }
        if (count != 0) out << " ";
        output_binary(r[i].num, r[i].length);
        if (count == 5) {out << endl; count = 0;}
        else count++;
        last_freq = r[i].freq;
    }
    if (count != 0) out << endl;
    return 0;
}

