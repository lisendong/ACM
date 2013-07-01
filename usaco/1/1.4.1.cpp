/*
ID: lisendo1
PROG: packrec
LANG: C++
*/
#include <iostream>
#include "stdlib.h"
#include <cstdlib>
#include <algorithm>
#include <fstream>
using namespace std;
typedef struct sample {
	int w[4], h[4];
} Sample;
Sample s;
typedef struct rec {
	int w, h;
	int choosed;
} Rec;
Rec r[4];
int icount = 0;
typedef struct result {
	int w, h;
} Result;
Result result[2000];
int min(int a, int b);
int min(int a, int b)  
{   
	if(a<=b) return a;  
    else return b;  
}  
  
int max(int a,int b)  
{   if(a>=b) return a;  
    else return b;  
}  
  
int max(int a,int b,int c)  
{   if(a>=b&&a>=c) return a;  
    if(b>=a&&b>=c) return b;  
    if(c>=a&&c>=b) return c;  
}  
int cmp(const Result &a, const Result &b) {
	if (a.h * a.w > b.h * b.w) 
		return 1;
	else 
		return 0;
}
void main_cal() {
	
	//num1
	result[icount].w = s.w[1] + s.w[2] + s.w[3] + s.w[0];
	result[icount].h = max(max(s.h[1], s.h[0]), max(s.h[2], s.h[3]));
	icount ++;
	//num2
	result[icount].w = max(s.w[0] + s.w[1] + s.w[2], s.w[3]);
	result[icount].h = max(s.h[0], s.h[1], s.h[2]) + s.h[3];
	icount ++;
	//num3
	result[icount].w = max(s.w[0] + s.w[1], s.w[2]) + s.w[3];
	result[icount].h = max(max(s.h[0], s.h[1]) + s.h[2], s.h[3]);
	icount ++;
	//num4
	result[icount].w = s.w[0] + s.w[3] + max(s.w[1], s.w[2]);
	result[icount].h = max(s.h[0], s.h[1] + s.h[2], s.h[3]);
	icount ++ ;
	//num5
	result[icount].h = max(s.h[0] + s.h[2], s.h[1] + s.h[3]);
	//if (icount == 9) cout << result[icount].h;
	if (s.h[2] >= (s.h[1] + s.h[3])) {
		result[icount].w = max(s.w[0], s.w[2] + s.w[1], s.w[2] + s.w[3]);
	}
	else if(s.h[2] > s.h[3] && s.h[2] < (s.h[1] + s.h[3])) {
		result[icount].w = max(s.w[0] + s.w[1], s.w[1] + s.w[2], s.w[2] + s.w[3]);
	}
	else if(s.h[2] == s.h[3]) {
		result[icount].w = max(s.w[0] + s.w[1], s.w[2] + s.w[3]);
	}
	else if(s.h[3] > s.h[2] && s.h[3] < (s.h[0] + s.h[2])) {
		result[icount].w = max(s.w[0] + s.w[1], s.w[0] + s.w[3], s.w[2] + s.w[3]);
	}
	else if(s.h[3] >= (s.h[0] + s.h[2])) {
		result[icount].w = max(s.w[1], s.w[0] + s.w[3], s.w[2] + s.w[3]);
	}
	icount ++;
}
void dfs_wh(int num) {
	if (num == 4) {
		main_cal();
		//count += 1;
		return ;
	}
	dfs_wh(num + 1);
	int temp = s.w[num]; s.w[num] = s.h[num]; s.h[num] = temp;
	dfs_wh(num + 1);

}
void dfs_order(int num) {
	if (num == 4) {
		dfs_wh(0);
		return ;
	}
	for (int i = 0; i < 4; i++) {
		if (r[i].choosed == 0) {
			r[i].choosed = 1;
			s.w[num] = r[i].w;
			s.h[num] = r[i].h;
			dfs_order(num + 1);
		    r[i].choosed = 0;
		}	
	}
}

int main() {
	ifstream in("packrec.in");
	ofstream out("packrec.out");
	int i;
	for (i = 0; i < 4; i++) {
		in >> r[i].w >> r[i].h;
		r[i].choosed = 0;
	}
	dfs_order(0);
	int min = result[0].h * result[0].w;
	for (i = 0; i < icount; i++) {
		if (result[i].h * result[i].w < min) {
			min = result[i].h * result[i].w;
		}
	}
	int result_count = 0;
	int result_for_output[100][2] = {0};
	for (i = 0; i < icount; i++) {
		if (result[i].h * result[i].w == min) {
			//cout << i << result[i].h << result[i].w << endl;
			//cout << i << endl;
			int found = 0;
			int left;
			left = result[i].h < result[i].w ? result[i].h : result[i].w;
			int right;
	
			right = max(result[i].h, result[i].w);
			int j = 0;
			for (j = 0; j < result_count; j++) {
				if (result_for_output[j][0] == left) {
					found = 1;
					break;
				}
			}
			if (found == 0) {
				int k = 0, m = 0;
				for (k = 0; k < result_count; k++) {
					if (left < result_for_output[k][0]) break;
				}
				for (m = result_count - 1; m >= k; m--) {
					result_for_output[m + 1][0] = result_for_output[m][0];
					result_for_output[m + 1][1] = result_for_output[m][1];
				}
				result_for_output[k][0] = left;
				result_for_output[k][1] = right;
				result_count ++;
			}
		}
	}
	out << min << endl;
	for (i = 0; i < result_count; i++) {
		out << result_for_output[i][0] << " " << result_for_output[i][1] << endl;
	}
	//sort(result, result + icount * sizeof(Result), cmp);
	//cout << result[0].h * result[0].w;
	//cout << count << endl;
	return 0;
}
