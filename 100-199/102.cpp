#include <iostream>

int minbin,ans[3],bufans[3],bufbin,classify[3][3];//B=0,G=1,C=2

void Perm(int n);

int main()
{
    int bin[3][3],i,j,total[3]={0};
    while(std::cin>>bin[0][0]>>bin[0][1]>>bin[0][2])
    {
        for(i=0;i<3;i++)
            total[i]=0;
        total[0]=bin[0][0]+bin[0][1]+bin[0][2];
        for(i=1;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                std::cin>>bin[i][j];
                total[j]+=bin[i][j];
            }
        }
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
                classify[i][j]=total[j]-bin[i][j];
        }
        minbin=total[0]+total[1]+total[2];
        bufbin=0;
        Perm(0);
        for(i=0;i<3;i++)
        {
            switch(ans[i])
            {
            case 0:
                std::cout<<"B";
                break;
            case 1:
                std::cout<<"G";
                break;
            case 2:
                std::cout<<"C";
                break;
            }
        }
        std::cout<<" "<<minbin<<'\n';
    }
    return 0;
}

void Perm(int n)
{
    for(int i=0;i<n-1;i++)
    {
        if(bufans[n-1]==bufans[i])
            return;
    }
    if(n==3)
    {
        if(bufbin<minbin)
        {
            for(int i=0;i<3;i++)
                ans[i]=bufans[i];
            minbin=bufbin;
        }
    }else
    {
        bufans[n]=0;
        bufbin+=classify[n][0];
        Perm(n+1);
        bufbin-=classify[n][0];
        bufans[n]=2;
        bufbin+=classify[n][2];
        Perm(n+1);
        bufbin-=classify[n][2];
        bufans[n]=1;
        bufbin+=classify[n][1];
        Perm(n+1);
        bufbin-=classify[n][1];
    }
}
