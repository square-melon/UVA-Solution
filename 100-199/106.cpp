#include <iostream>
#include <cstring>
#define M 1000001

int num[M]= {0};

int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

int lim(int n)
{
    int i;
    for(i=1; i<1000; i++)
    {
        if(n>i*i&&n<(i+1)*(i+1))
            return i;
    }
    return 1000;
}

//利用a=m^2-n^2 b=2mn c=m^2+n^2(m,n一奇一偶且互質可找互質正整數解)
int main()
{
    int group;
    int i,j;
    int input;
    long long int a,b,c;
    while(std::cin>>input)
    {
        group=0;
        int limit=lim(input);
        for(i=1; i<=limit; i++)
        {
            for(j=i+1; j<=limit; j+=2)
            {
                if(i*i+j*j>input)
                    break;
                if(gcd(i,j)!=1)
                    continue;
                a=j*j-i*i;
                b=2*i*j;
                c=i*i+j*j;
                group++;
                int k=1;
                while(c*k<=input)
                {
                    num[a*k]=1;
                    num[b*k]=1;
                    num[c*k]=1;
                    k++;
                }
            }
        }
        int cnt=0;
        std::cout<<group<<' ';
        for(i=1; i<=input; i++)
        {
            if(num[i]==0)
                cnt++;
        }
        std::cout<<cnt<<'\n';
        std::memset(num,0,sizeof(int)*M);
    }
    return 0;
}
