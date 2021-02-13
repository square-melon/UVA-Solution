#include <iostream>
#include <cstring>
#define M 20

float profit[M+1][M+1][M+1];
int mid[M][M][M];

void findnum(int s,int a,int b)
{
    if(s<=0)
        return;
    int sb=mid[s][a][b];
    findnum(s-1,a,sb);
    std::cout<<' '<<sb+1;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n,s,i,j,k;
    while(std::cin>>n)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i==j)
                    profit[0][i][j]=1.0;
                else
                    std::cin>>profit[0][i][j];
            }
        }
        for(s=1;s<=n;s++)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                    profit[s][i][j]=-100;
            }
            for(k=0;k<n;k++)
            {
                for(i=0;i<n;i++)
                {
                    for(j=0;j<n;j++)
                    {
                        if(profit[s-1][i][k]*profit[0][k][j]>profit[s][i][j])
                        {
                            profit[s][i][j]=profit[s-1][i][k]*profit[0][k][j];
                            mid[s][i][j]=k;
                        }
                    }
                }
            }
            for(i=0;i<n;i++)
            {
                if(profit[s][i][i]>1.01)
                    break;
            }
            if(i!=n)
                break;
        }
        if(s!=n+1)
        {
            std::cout<<i+1;
            findnum(s,i,i);
            std::cout<<' '<<i+1;
        }
        else
            std::cout<<"no arbitrage sequence exists";
        std::cout<<'\n';
    }
    return 0;
}
