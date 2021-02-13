#include <iostream>

int skyline[10005]= {0};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int L,H,R,i,j,maxR=0;
    bool first=false;
    while(std::cin>>L>>H>>R)
    {
        if(maxR<R)
            maxR=R;
        for(i=L; i<R; i++)
        {
            if(skyline[i]<H)
                skyline[i]=H;
        }
    }
    for(i=1; i<=maxR; i++)
    {
        if(skyline[i-1]!=skyline[i])
        {
            if(first)
                std::cout<<' ';
            first=true;
            std::cout<<i<<" "<<skyline[i];
        }
    }
    std::cout<<'\n';
    return 0;
}
