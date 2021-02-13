#include <iostream>
#include <cmath>

int main()
{
    double p,n;
    while(std::cin>>n>>p)
        std::cout<<(int)round(pow(p,(1.0/n)))<<'\n';
    return 0;
}
