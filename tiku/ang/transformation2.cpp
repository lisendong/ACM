#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include <algorithm>
using namespace std;
#define oo 10007
struct tree
{
   long long l;
   long long r;
   long long x1;
   long long x2;
   long long x3;
   long long c1;
   long long c2;
   long long c3;
}s[400040];
long long a[100010];
long long b[100010];
void or1(long long xl,long long xr,long long c,long long v);
void or2(long long xl,long long xr,long long c,long long v);
void or3(long long xl,long long xr,long long c,long long v);
void build(int xl,int xr,int v)
{
     s[v].l=xl;
     s[v].r=xr;
     s[v].x1=0;
     s[v].x2=0;
     s[v].x3=0;
     s[v].c1=0;
     s[v].c2=0;
     s[v].c3=0;
     if (xl==xr)
     {
        b[xl]=v;
        a[xl]=0;
        return;
     }
     int t=(xl+xr)/2;
     int rt=v<<1;
     build(xl,t,rt);
     build(t+1,xr,rt+1);
}
void or1(long long xl,long long xr,long long c,long long v)
{
    long long t=v<<1;
    if (s[v].l==s[v].r)
    {
       s[v].x1=s[v].x1+c;
       if (s[v].x1>=oo) s[v].x1=s[v].x1%oo;
       s[v].x2=s[v].x1*s[v].x1;
       if (s[v].x2>=oo) s[v].x2=s[v].x2%oo;
       s[v].x3=s[v].x2*s[v].x1;
       if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
       return;
    }
    if ((xl==s[v].l)&&(xr==s[v].r))
    {
       if (s[v].c3>0)
       {
          s[v].c3+=c;
          if (s[v].c3>=oo) s[v].c3=s[v].c3%oo;
          long long k=xr-xl+1;
          long long cc=s[v].c3%oo;
          s[v].x1=k*cc;
          if (s[v].x1>=oo) s[v].x1=s[v].x1%oo;
          s[v].x2=s[v].x1*cc;
          if (s[v].x2>=oo) s[v].x2=s[v].x2%oo;
          s[v].x3=s[v].x2*cc;
          if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
          return;
       }
       if (s[v].c2>0)
       {
          or2(xl,s[t].r,s[v].c2,t);
          or2(s[t].r+1,xr,s[v].c2,t+1);
          s[v].c2=0;
       }
       s[v].c1+=c;
       long long y1,y2,y3;
       long long k=xr-xl+1;
       c=c%oo;
       y1=s[v].x1;
       y2=s[v].x2;
       y3=s[v].x3;
       s[v].x1=y1+k*c;
       if (s[v].x1>=oo) s[v].x1=s[v].x1%oo;
       long long u=y1*c;
       if (u>=oo) u=u%oo;
       s[v].x2=y2+2*u;
       u=k*c;
       u=u%oo;
       u=u*c;
       if (u>=oo) u=u%oo;
       s[v].x2=s[v].x2+u;
       if (s[v].x2>=oo) s[v].x2=s[v].x2%oo;
       u=k*c;
       if (u>=oo) u=u%oo;
       u=u*c;
       if (u>=oo) u=u%oo;
       s[v].x3=3*y2+3*y1*c+u;
       if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
       s[v].x3=s[v].x3*c+y3;
       if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
       return;
    }
    if (s[v].c3>0)
       {
          or3(s[t].l,s[t].r,s[v].c3,t);
          or3(s[t+1].l,s[t+1].r,s[v].c3,t+1);
          s[v].x1=s[t].x1+s[t+1].x1;
          s[v].x2=s[t].x2+s[t+1].x2;
          s[v].x3=s[t].x3+s[t+1].x3;
          if (s[v].x1>=oo) s[v].x1=s[v].x1%oo;
          if (s[v].x2>=oo) s[v].x2=s[v].x2%oo;
          if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
          s[v].c3=0;
       }
    if (s[v].c2>0)
       {
          or2(s[t].l,s[t].r,s[v].c2,t);
          or2(s[t+1].l,s[t+1].r,s[v].c2,t+1);
          s[v].x1=s[t].x1+s[t+1].x1;
          s[v].x2=s[t].x2+s[t+1].x2;
          s[v].x3=s[t].x3+s[t+1].x3;
          if (s[v].x1>=oo) s[v].x1=s[v].x1%oo;
          if (s[v].x2>=oo) s[v].x2=s[v].x2%oo;
          if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
          s[v].c2=0;
       }
    if (s[v].c1>0)
       {
          or1(s[t].l,s[t].r,s[v].c1,t);
          or1(s[t+1].l,s[t+1].r,s[v].c1,t+1);
          s[v].x1=s[t].x1+s[t+1].x1;
          s[v].x2=s[t].x2+s[t+1].x2;
          s[v].x3=s[t].x3+s[t+1].x3;
          if (s[v].x1>=oo) s[v].x1=s[v].x1%oo;
          if (s[v].x2>=oo) s[v].x2=s[v].x2%oo;
          if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
          s[v].c1=0;
       }
    if (xl>s[t].r) 
    {
       or1(xl,xr,c,t+1);
       s[v].x1=s[t].x1+s[t+1].x1;
       s[v].x2=s[t].x2+s[t+1].x2;
       s[v].x3=s[t].x3+s[t+1].x3;
       if (s[v].x1>=oo) s[v].x1=s[v].x1%oo;
       if (s[v].x2>=oo) s[v].x2=s[v].x2%oo;
       if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
    }
    else
    {
       if (xr<=s[t].r)
       {
         or1(xl,xr,c,t);
         s[v].x1=s[t].x1+s[t+1].x1;
         s[v].x2=s[t].x2+s[t+1].x2;
         s[v].x3=s[t].x3+s[t+1].x3;
         if (s[v].x1>=oo) s[v].x1=s[v].x1%oo;
         if (s[v].x2>=oo) s[v].x2=s[v].x2%oo;
         if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
       }
       else
       {
           or1(xl,s[t].r,c,t);
           or1(s[t+1].l,xr,c,t+1);
           s[v].x1=s[t].x1+s[t+1].x1;
           s[v].x2=s[t].x2+s[t+1].x2;
           s[v].x3=s[t].x3+s[t+1].x3;
           if (s[v].x1>=oo) s[v].x1=s[v].x1%oo;
           if (s[v].x2>=oo) s[v].x2=s[v].x2%oo;
           if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
       }
    } 
}
void or2(long long xl,long long xr,long long c,long long v)
{
    long long t=v<<1;
    if (s[v].l==s[v].r)
    {
       s[v].x1=s[v].x1*c;
       if (s[v].x1>=oo) s[v].x1=s[v].x1%oo;
       s[v].x2=s[v].x1*s[v].x1;
       if (s[v].x2>=oo) s[v].x2=s[v].x2%oo;
       s[v].x3=s[v].x2*s[v].x1;
       if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
       return;
    }
    if ((xl==s[v].l)&&(xr==s[v].r))
    {
       if (s[v].c3>0)
       {
          s[v].c3*=c;
          if (s[v].c3>=oo) s[v].c3=s[v].c3%oo;
          long long k=xr-xl+1;
          long long cc=s[v].c3;
          s[v].x1=k*cc;
          if (s[v].x1>=oo) s[v].x1=s[v].x1%oo;
          s[v].x2=s[v].x1*cc;
          if (s[v].x2>=oo) s[v].x2=s[v].x2%oo;
          s[v].x3=s[v].x2*cc;
          if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
          return;
       }
       if (s[v].c1>0)
       {
          or1(xl,s[t].r,s[v].c1,t);
          or1(s[t].r+1,xr,s[v].c1,t+1);
          s[v].c1=0;
       }
       if (s[v].c2>0) s[v].c2=c*s[v].c2;
       else s[v].c2=c;
       s[v].x1=s[v].x1*c;
       if (s[v].x1>=oo) s[v].x1=s[v].x1%oo;
       s[v].x2=s[v].x2*c;
       if (s[v].x2>=oo) s[v].x2=s[v].x2%oo;
       s[v].x2=s[v].x2*c;
       if (s[v].x2>=oo) s[v].x2=s[v].x2%oo;
       s[v].x3=s[v].x3*c;
       if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
       s[v].x3=s[v].x3*c;
       if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
       s[v].x3=s[v].x3*c;
       if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
       return;
    }
    if (s[v].c3>0)
       {
          or3(s[t].l,s[t].r,s[v].c3,t);
          or3(s[t+1].l,s[t+1].r,s[v].c3,t+1);
          s[v].x1=s[t].x1+s[t+1].x1;
          s[v].x2=s[t].x2+s[t+1].x2;
          s[v].x3=s[t].x3+s[t+1].x3;
          if (s[v].x1>=oo) s[v].x1=s[v].x1%oo;
          if (s[v].x2>=oo) s[v].x2=s[v].x2%oo;
          if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
          s[v].c3=0;
       }
    if (s[v].c2>0)
       {
          or2(s[t].l,s[t].r,s[v].c2,t);
          or2(s[t+1].l,s[t+1].r,s[v].c2,t+1);
          s[v].x1=s[t].x1+s[t+1].x1;
          s[v].x2=s[t].x2+s[t+1].x2;
          s[v].x3=s[t].x3+s[t+1].x3;
          if (s[v].x1>=oo) s[v].x1=s[v].x1%oo;
          if (s[v].x2>=oo) s[v].x2=s[v].x2%oo;
          if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
          s[v].c2=0;
       }
    if (s[v].c1>0)
       {
          or1(s[t].l,s[t].r,s[v].c1,t);
          or1(s[t+1].l,s[t+1].r,s[v].c1,t+1);
          s[v].x1=s[t].x1+s[t+1].x1;
          s[v].x2=s[t].x2+s[t+1].x2;
          s[v].x3=s[t].x3+s[t+1].x3;
          if (s[v].x1>=oo) s[v].x1=s[v].x1%oo;
          if (s[v].x2>=oo) s[v].x2=s[v].x2%oo;
          if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
          s[v].c1=0;
       }
    if (xl>s[t].r) 
    {
       or2(xl,xr,c,t+1);
       s[v].x1=s[t].x1+s[t+1].x1;
       s[v].x2=s[t].x2+s[t+1].x2;
       s[v].x3=s[t].x3+s[t+1].x3;
       if (s[v].x1>=oo) s[v].x1=s[v].x1%oo;
       if (s[v].x2>=oo) s[v].x2=s[v].x2%oo;
       if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
    }
    else
    {
       if (xr<=s[t].r)
       {
         or2(xl,xr,c,t);
         s[v].x1=s[t].x1+s[t+1].x1;
         s[v].x2=s[t].x2+s[t+1].x2;
         s[v].x3=s[t].x3+s[t+1].x3;
         if (s[v].x1>=oo) s[v].x1=s[v].x1%oo;
         if (s[v].x2>=oo) s[v].x2=s[v].x2%oo;
         if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
       }
       else
       {
           or2(xl,s[t].r,c,t);
           or2(s[t+1].l,xr,c,t+1);
           s[v].x1=s[t].x1+s[t+1].x1;
           s[v].x2=s[t].x2+s[t+1].x2;
           s[v].x3=s[t].x3+s[t+1].x3;
           if (s[v].x1>=oo) s[v].x1=s[v].x1%oo;
           if (s[v].x2>=oo) s[v].x2=s[v].x2%oo;
           if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
       }
    } 
}
void or3(long long xl,long long xr,long long c,long long v)
{
    long long t=v<<1;
    if (s[v].l==s[v].r)
    {
       s[v].x1=c;
       if (s[v].x1>=oo) s[v].x1=s[v].x1%oo;
       s[v].x2=s[v].x1*s[v].x1;
       if (s[v].x2>=oo) s[v].x2=s[v].x2%oo;
       s[v].x3=s[v].x2*s[v].x1;
       if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
       return;
    }
    if ((xl==s[v].l)&&(xr==s[v].r))
    {
       s[v].c1=0;
       s[v].c2=0;
       s[v].c3=c;
       long long k=xr-xl+1;
       long long cc=s[v].c3;
       cc=cc%oo;
       s[v].x1=k*cc;
       if (s[v].x1>=oo) s[v].x1=s[v].x1%oo;
       s[v].x2=s[v].x1*cc;
       if (s[v].x2>=oo) s[v].x2=s[v].x2%oo;
       s[v].x3=s[v].x2*cc;
       if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
       return;
    }
    if (s[v].c3>0)
       {
          or3(s[t].l,s[t].r,s[v].c3,t);
          or3(s[t+1].l,s[t+1].r,s[v].c3,t+1);
          s[v].x1=s[t].x1+s[t+1].x1;
          s[v].x2=s[t].x2+s[t+1].x2;
          s[v].x3=s[t].x3+s[t+1].x3;
          if (s[v].x1>=oo) s[v].x1=s[v].x1%oo;
          if (s[v].x2>=oo) s[v].x2=s[v].x2%oo;
          if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
          s[v].c3=0;
       }
    if (s[v].c2>0)
       {
          or2(s[t].l,s[t].r,s[v].c2,t);
          or2(s[t+1].l,s[t+1].r,s[v].c2,t+1);
          s[v].x1=s[t].x1+s[t+1].x1;
          s[v].x2=s[t].x2+s[t+1].x2;
          s[v].x3=s[t].x3+s[t+1].x3;
          if (s[v].x1>=oo) s[v].x1=s[v].x1%oo;
          if (s[v].x2>=oo) s[v].x2=s[v].x2%oo;
          if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
          s[v].c2=0;
       }
    if (s[v].c1>0)
       {
          or1(s[t].l,s[t].r,s[v].c1,t);
          or1(s[t+1].l,s[t+1].r,s[v].c1,t+1);
          s[v].x1=s[t].x1+s[t+1].x1;
          s[v].x2=s[t].x2+s[t+1].x2;
          s[v].x3=s[t].x3+s[t+1].x3;
          if (s[v].x1>=oo) s[v].x1=s[v].x1%oo;
          if (s[v].x2>=oo) s[v].x2=s[v].x2%oo;
          if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
          s[v].c1=0;
       }
    if (xl>s[t].r) 
    {
       or3(xl,xr,c,t+1);
       s[v].x1=s[t].x1+s[t+1].x1;
       s[v].x2=s[t].x2+s[t+1].x2;
       s[v].x3=s[t].x3+s[t+1].x3;
       if (s[v].x1>=oo) s[v].x1=s[v].x1%oo;
       if (s[v].x2>=oo) s[v].x2=s[v].x2%oo;
       if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
    }
    else
    {
       if (xr<=s[t].r)
       {
         or3(xl,xr,c,t);
         s[v].x1=s[t].x1+s[t+1].x1;
         s[v].x2=s[t].x2+s[t+1].x2;
         s[v].x3=s[t].x3+s[t+1].x3;
         if (s[v].x1>=oo) s[v].x1=s[v].x1%oo;
         if (s[v].x2>=oo) s[v].x2=s[v].x2%oo;
         if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
       }
       else
       {
           or3(xl,s[t].r,c,t);
           or3(s[t+1].l,xr,c,t+1);
           s[v].x1=s[t].x1+s[t+1].x1;
           s[v].x2=s[t].x2+s[t+1].x2;
           s[v].x3=s[t].x3+s[t+1].x3;
           if (s[v].x1>=oo) s[v].x1=s[v].x1%oo;
           if (s[v].x2>=oo) s[v].x2=s[v].x2%oo;
           if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
       }
    } 
}
long long or4(long long xl,long long xr,long long c,long long v)
{
    long long t=v<<1;
    if ((xl==s[v].l)&&(xr==s[v].r))
    {
       switch (c)
       {
          case 1:return s[v].x1;
          case 2:return s[v].x2;
          case 3:return s[v].x3;
       }
    }
    if (s[v].c3>0)
       {
          or3(s[t].l,s[t].r,s[v].c3,t);
          or3(s[t+1].l,s[t+1].r,s[v].c3,t+1);
          s[v].x1=s[t].x1+s[t+1].x1;
          s[v].x2=s[t].x2+s[t+1].x2;
          s[v].x3=s[t].x3+s[t+1].x3;
          if (s[v].x1>=oo) s[v].x1=s[v].x1%oo;
          if (s[v].x2>=oo) s[v].x2=s[v].x2%oo;
          if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
          s[v].c3=0;
       }
    if (s[v].c2>0)
       {
          or2(s[t].l,s[t].r,s[v].c2,t);
          or2(s[t+1].l,s[t+1].r,s[v].c2,t+1);
          s[v].x1=s[t].x1+s[t+1].x1;
          s[v].x2=s[t].x2+s[t+1].x2;
          s[v].x3=s[t].x3+s[t+1].x3;
          if (s[v].x1>=oo) s[v].x1=s[v].x1%oo;
          if (s[v].x2>=oo) s[v].x2=s[v].x2%oo;
          if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
          s[v].c2=0;
       }
    if (s[v].c1>0)
       {
          or1(s[t].l,s[t].r,s[v].c1,t);
          or1(s[t+1].l,s[t+1].r,s[v].c1,t+1);
          s[v].x1=s[t].x1+s[t+1].x1;
          s[v].x2=s[t].x2+s[t+1].x2;
          s[v].x3=s[t].x3+s[t+1].x3;
          if (s[v].x1>=oo) s[v].x1=s[v].x1%oo;
          if (s[v].x2>=oo) s[v].x2=s[v].x2%oo;
          if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
          s[v].c1=0;
       }
    if (xl>s[t].r) 
    {
       long long yy=or4(xl,xr,c,t+1);
       s[v].x1=s[t].x1+s[t+1].x1;
       s[v].x2=s[t].x2+s[t+1].x2;
       s[v].x3=s[t].x3+s[t+1].x3;
       if (s[v].x1>=oo) s[v].x1=s[v].x1%oo;
       if (s[v].x2>=oo) s[v].x2=s[v].x2%oo;
       if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
       return yy;
    }
    else
    {
       if (xr<=s[t].r)
       {
         long long yy=or4(xl,xr,c,t);
         s[v].x1=s[t].x1+s[t+1].x1;
         s[v].x2=s[t].x2+s[t+1].x2;
         s[v].x3=s[t].x3+s[t+1].x3;
         if (s[v].x1>=oo) s[v].x1=s[v].x1%oo;
         if (s[v].x2>=oo) s[v].x2=s[v].x2%oo;
         if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
         return yy;
       }
       else
       {
           long long yy;
           yy=or4(xl,s[t].r,c,t);
           yy=yy+or4(s[t+1].l,xr,c,t+1);
           s[v].x1=s[t].x1+s[t+1].x1;
           s[v].x2=s[t].x2+s[t+1].x2;
           s[v].x3=s[t].x3+s[t+1].x3;
           if (s[v].x1>=oo) s[v].x1=s[v].x1%oo;
           if (s[v].x2>=oo) s[v].x2=s[v].x2%oo;
           if (s[v].x3>=oo) s[v].x3=s[v].x3%oo;
           if (yy>=oo) yy=yy%oo;
           return yy;
       }
    } 
}
int main()
{
    int n,m;
    while (1)
    {
       scanf("%d%d",&n,&m);
       if ((n==0)&&(m==0)) break;
       build(1,n,1);
       for (int i=0;i<m;++i)
       {
           int j,k,l,w;
           scanf("%d%d%d%d",&j,&k,&l,&w);
           switch(j)
           {
              case 1: or1(k,l,w,1);break;
              case 2: or2(k,l,w,1);break;
              case 3: or3(k,l,w,1);break;
              case 4: long long yx=or4(k,l,w,1);
                      printf("%lld\n",yx);
           }
       }
    }
    return 0;
}
