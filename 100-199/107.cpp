#include <iostream>

int main()
{
    long long int a,b,N,amount,notworking,totalheight;
    while(std::cin>>a>>b&&a!=0&&b!=0)//from b to calculate N
    {
        N=1;
        totalheight=b;
        for(long long int i=2;i<=b;i++)
        {
            if(b%i!=0)
                continue;
            long long int buf=b;
            amount=0;
            while(buf%i==0)
            {
                buf/=i;
                amount++;
            }
            if(buf==1)
            {
                N=i;
                break;
            }
        }
        if(N==1)
        {
            int buf=a;
            amount=0;
            while(buf%2==0)
            {
                buf/=2;
                amount++;
            }
        }
        long long int buffer=1,bufh=a,notworking=0;
        for(long long int i=0;i<amount;i++,buffer*=N)
        {
            notworking+=buffer;
            totalheight+=bufh*buffer;
            bufh/=N+1;
        }
        std::cout<<notworking<<' '<<totalheight<<'\n';
    }
    return 0;
}
