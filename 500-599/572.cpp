#include <iostream>

int oil[100][100];
int L,W;
int ans;

void dfs(int m,int n)
{
    if(m<0||n<0||m>=L||n>=W||oil[m][n]==0)
        return;
    oil[m][n]=0;
    dfs(m-1,n-1);
    dfs(m-1,n);
    dfs(m-1,n+1);
    dfs(m,n-1);
    dfs(m,n+1);
    dfs(m+1,n-1);
    dfs(m+1,n);
    dfs(m+1,n+1);
    return;
}

int main()
{
    int i,j;
    char c;
    std::cin>>L>>W;
    while(L!=0&&W!=0)
    {
        ans=0;
        for(i=0;i<100;i++)
        {
            for(j=0;j<100;j++)
                oil[i][j]=0;
        }
        for(i=0;i<L;i++)
        {
            for(j=0;j<W;j++)
            {
                std::cin>>c;
                if(c=='@')
                    oil[i][j]=1;
                else
                    oil[i][j]=0;
            }
        }
        for(i=0;i<L;i++)
        {
            for(j=0;j<W;j++)
            {
                if(oil[i][j]==1)
                {
                    dfs(i,j);
                    ans++;
                }
            }
        }
        std::cout<<ans<<'\n';
        std::cin>>L>>W;
    }
    return 0;
}
