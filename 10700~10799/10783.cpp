#include <iostream>

int main()
{
    long long int a,b,sum;
    int n;
    std::cin>>n;
    for(int i=1;i<=n;i++)
    {
        std::cin>>a>>b;
        sum=0;
        for(int j=a;j<=b;j++)
        {
            if(j%2==0)
                continue;
            sum+=j;
        }
        std::cout<<"Case "<<i<<": "<<sum<<'\n';
    }
    return 0;
}
