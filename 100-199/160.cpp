#include <iostream>
#include <cmath>

bool isPrime(int n)
{
    int i;
    for(i=2; i<=(int)sqrt(n); i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

int digit(int n)
{
    if(n/10!=0)
        return digit(n/10)+1;
    else
        return 1;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n,i,cnt2;
    while(std::cin>>n&&n!=0)
    {
        switch(digit(n))
        {
        case 1:
            std::cout<<"  "<<n<<"! =";
            break;
        case 2:
            std::cout<<" "<<n<<"! =";
            break;
        case 3:
            std::cout<<n<<"! =";
            break;
        }
        cnt2=0;
        for(i=2; i<=n; i++)
        {
            if(!isPrime(i))
                continue;
            if(cnt2==15)
            {
                std::cout<<'\n'<<"      ";
                cnt2=0;
            }
            int cnt=0,buffer=n;
            while(buffer/i!=0)
            {
                cnt+=buffer/i;
                buffer/=i;
            }
            switch(digit(cnt))
            {
            case 1:
                std::cout<<"  "<<cnt;
                break;
            case 2:
                std::cout<<" "<<cnt;
                break;
            case 3:
                std::cout<<cnt;
                break;
            }
            cnt2++;
        }
        std::cout<<'\n';
    }
    return 0;
}
