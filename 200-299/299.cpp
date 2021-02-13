#include <iostream>
#include <cstring>
#define M 50

int main()
{
    int T,i,j,n,swapt;
    int train[M];
    std::cin>>T;
    while(T--)
    {
        std::cin>>n;
        memset(train,0,M);
        for(i=0;i<n;i++)
            std::cin>>train[i];
        swapt=0;
        for(i=0;i<n;i++)
        {
            for(j=i;j<n;j++)
            {
                if(train[j]==i+1)
                    break;
            }
            swapt+=j-i;
            for(;j>i;j--)
                train[j]=train[j-1];
            train[i]=i+1;
        }
        std::cout<<"Optimal train swapping takes "<<swapt<<" swaps.\n";
    }
    return 0;
}
