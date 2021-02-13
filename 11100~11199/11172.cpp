#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int a,b,T;
    std::cin>>T;
    while(T--)
    {
        std::cin>>a>>b;
        if(a>b)
            std::cout<<">\n";
        else if(a<b)
            std::cout<<"<\n";
        else
            std::cout<<"=\n";
    }
    return 0;
}
