#include <iostream>

int main()
{
    int a,b,buf,sum,n,cnt;
    std::cin>>n;
    while(n--)
    {
        std::cin>>cnt;
        sum=0;
        while(cnt--)
        {
            std::cin>>a>>buf>>b;
            sum+=a*b;
        }
        std::cout<<sum<<'\n';
    }
    return 0;
}
