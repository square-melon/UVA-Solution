#include <iostream>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int T,salary[3];
    std::cin>>T;
    for(int i=1;i<=T;i++)
    {
        for(int j=0;j<3;j++)
            std::cin>>salary[j];
        std::sort(salary,salary+3);
        std::cout<<"Case "<<i<<": "<<salary[1]<<'\n';
    }
    return 0;
}
