#include <iostream>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::string str;
    std::string keyboard="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    int i,j;
    while(getline(std::cin,str))
    {
        for(i=0;i<str.size();i++)
        {
            if(str[i]==' ')
                std::cout<<' ';
            else
            {
                for(j=0;j<keyboard.size();j++)
                {
                    if(keyboard[j]==str[i])
                        break;
                }
                std::cout<<keyboard[j-1];
            }
        }
        std::cout<<'\n';
    }
    return 0;
}
