/*
ID: lisendo1
LANG: C
TASK: ratios
*/
#include<stdio.h>
int map[4][3];
void read()
{
    int i, j;
    for (i = 0; i <4; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
}
int isOk(int a, int b, int c, int d)
{
    int j, sum;
    for (j = 0; j < 3; j++)
    {
        sum = a * map[1][j] + b * map[2][j] + c * map[3][j];
        if (sum != d * map[0][j])
        {
            return 0;
        }
    }
    return 1;
}
void deal()
{
    int i, j, k, h;
    for (i = 0; i < 100; i++)
    {
        for (j = 0; j < 100; j++)
        {
            for (k = 0; k < 100; k++)
            {
                for (h = 1; h < 100; h++)
                {
                    if (isOk(i, j, k, h))
                    {
                        printf("%d %d %d %d\n",  i, j, k, h);
                        return;
                    }
                }
            }
        }
    }
    printf("NONE\n");
}
int main()
{
    freopen("ratios.in", "r", stdin), freopen("ratios.out","w", stdout);
    read();
    deal();
    fclose(stdin), fclose(stdout);
}
