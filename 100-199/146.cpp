#include <iostream>
#include <cstring>
#define M 26

int main()
{
    std::string code;
    int alphabat[M],j,flag,i,stuck;
    while(std::cin>>code&&code!="#")
    {
        memset(alphabat,0,sizeof(int)*M);
        flag=1;
        alphabat[code[code.size()-1]-'a']++;
        for(i=code.size()-2;i>=0;i--)
        {
            alphabat[code[i]-'a']++;
            if(code[i]<code[i+1])
            {
                stuck=code[i]-'a';
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            std::cout<<"No Successor\n";
            continue;
        }
        for(j=0;j<i;j++)
            std::cout<<code[j];
        for(j=stuck+1;j<M;j++)
        {
            if(alphabat[j]!=0)
                break;
        }
        alphabat[j]--;
        std::cout<<(char)(j+'a');
        for(j=stuck;j<M;j++)
        {
            while(alphabat[j]!=0)
            {
                std::cout<<(char)(j+'a');
                alphabat[j]--;
            }
        }
        std::cout<<'\n';
    }
    return 0;
}
