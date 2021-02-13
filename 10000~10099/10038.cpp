#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <cstring>
#define M 3000

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n,i;
    bool check;
    std::vector<int> seq;
    int m_abs[M];
    while(std::cin>>n)
    {
        memset(m_abs,M,sizeof(int));
        seq.clear();
        for(i=0; i<n; i++)
        {
            int buffer;
            std::cin>>buffer;
            seq.push_back(buffer);
        }
        for(i=0; i<n-1; i++)
            m_abs[i]=abs(seq[i]-seq[i+1]);
        std::sort(m_abs,m_abs+(n-1));
        check=true;
        for(i=1; i<=n-1; i++)
        {
            if(m_abs[i-1]!=i)
            {
                check=false;
                break;
            }
        }
        if(!check)
            std::cout<<"Not jolly\n";
        else
            std::cout<<"Jolly\n";
    }
    return 0;
}
