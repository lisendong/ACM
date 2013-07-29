#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
struct node
{
    int x,y;
}a[100001],b[100001];
int cmp(node a,node b)
{
    return a.x<b.x;
}
int main()
{
    int max,pos,i,begin,end,m,n,sum,f,posmax,t;
    scanf("%d",&t);
    while (t--) 
    {
        scanf("%d",&m);
        n=0;
        while (scanf("%d%d",&begin,&end))
        {
            if (begin==0&&end==0) break;
            if (end>=0)
            {
                a[n].x=begin;
                a[n].y=end;
                ++n;
            }
        }
        sort(a,a+n,cmp);
        if (a[0].x>0) printf("0\n");//开始漏了没判断第一条线段就不能覆盖到0，wrongY-Y；
        else
        {
            pos=0; max=0; sum=1;
            while (pos+1<n&&a[pos+1].x<=0)//pos+1<N防止数组越界，还真有所有数据都从小于0开始的，re Y-Y；
            {
                ++pos;
                if (a[pos].y>a[max].y) max=pos;
            }
            pos=max; b[1].x=a[pos].x; b[1].y=a[pos].y;
            while (pos<n && b[sum].y<m) 
            {
                f=1; posmax=max;
                while (pos+1<n && a[pos+1].x<=a[max].y)
                {
                    f=0;
                    ++pos;
                    if (a[pos].y>a[posmax].y) posmax=pos;
                }
                if (f) break;
                max=posmax;
                ++sum;
                b[sum].x=a[max].x;
                b[sum].y=a[max].y;
            }
            if (b[sum].y>=m) 
            {
                printf("%d\n",sum);
                for (i=1;i<=sum;i++)
                    printf("%d %d\n",b[i].x,b[i].y);
            }else printf("0\n");
        }
        if (t) printf("\n");
    }
    return 0;
}
