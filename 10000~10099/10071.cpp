#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int v,t;
    while(std::cin>>v>>t)
        std::cout<<v*t*2<<'\n';
    return 0;
}
