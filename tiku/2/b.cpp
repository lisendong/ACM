#include<cstdio>
#include<algorithm>
using namespace std;
int x[1000005];
int main()
{
    int n,a,p,q,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1; i<=n; i++)
            scanf("%d",&x[i]);
        sort(x+1,x+n+1);
        i=j=n/2;
        if(n%2==1)
        {
            a=x[++i];
            p=q=1;
            i--;
            //j++;
            j += 2;
            while(i>0&&x[i--]==a)
                p++;
            while(j<=n&&x[j++]==a)
                p++;
        }
        else
        {
            a=x[i];
            int b=x[++j];
            p = 2;
            q=b-a+1;
            i--;
            j++;
            while(i>0&&x[i--]==a)
                p++;
            while(j<=n&&x[j++]==a)
                p++;
        }
        printf("%d %d %d\n",a,p,q);
    }
}
