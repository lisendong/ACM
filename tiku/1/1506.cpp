#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
unsigned long long largestRectArea(vector<unsigned long long > &height) {  
    stack<unsigned long long > p;  
    int i = 0;
    unsigned long long  res = 0;  
    height.push_back(0);//作用：清空栈  
    while(i < height.size()) {  
        if(p.empty() || height[p.top()] <= height[i])  
            p.push(i++);  
        else {  
            //unsigned long long t = p.top();  
            //p.pop();  
            //res = max(res, height[t] * (p.empty() ? i : i -p.top() +1));  
            long long t = p.top();
            p.pop();
            res = max(res, height[t] * (p.empty() ? i : (i - t)));
                //res = max(res, height[t] * i);
        }  
    }  
    height.insert(height.begin(), 0);
    for (i = height.size() - 2; i >= 0; i--) {  
        if(p.empty() || height[p.top()] <= height[i])  
            p.push(i);  
        else {  
            //unsigned long long t = p.top();  
            //p.pop();  
            //res = max(res, height[t] * (p.empty() ? i : i -p.top() +1));  
            long long t = p.top();
            p.pop();
            res = max(res, height[t] * (p.empty() ? height.size() -  i : (t - i)));
                //res = max(res, height[t] * i);
        }  
    }  
    return res;  
} 
int main() {
    int n;
    while (scanf("%d", &n)){
        if (n == 0) break;
        int i;
        vector<unsigned long long > v;
        for (i = 1; i <= n; i++) {
            unsigned long long tmp;
            scanf("%lld", &tmp);
            v.push_back(tmp);
        }
        cout << largestRectArea(v) << endl;
    }
} 
