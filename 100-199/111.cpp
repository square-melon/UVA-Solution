#include <iostream>
#include <cstring>
#define M 20
//LCS

int main()
{
    int n,i,j;
    int ans[M],buffer[M],table[M+1][M+1];
    int len[M];
    std::cin>>n;
    for(i=0; i<n; i++)
    {
        int buf;
        std::cin>>buf;
        ans[buf-1]=i;
    }
    int a;
    while(std::cin>>a)
    {
        buffer[a-1]=0;
        memset(len,0,sizeof(int)*M);
        memset(table,0,sizeof(int)*(M+1)*(M+1));
        memset(buffer,0,sizeof(int)*M);
        for(i=1; i<n; i++)
        {
            int buf;
            std::cin>>buf;
            buffer[buf-1]=i;
        }
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(table[i][j+1]>table[i+1][j])
                    table[i+1][j+1]=table[i][j+1];
                else
                    table[i+1][j+1]=table[i+1][j];
                if(ans[i]==buffer[j])
                    table[i+1][j+1]++;
            }
        }
        std::cout<<table[n][n]<<'\n';
    }
    return 0;
}
