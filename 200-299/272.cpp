#include <iostream>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::string str;
    int i,pos=0;
    while(getline(std::cin,str))
    {
        for(i=0;i<str.size();i++)
        {
            if(str[i]=='"')
            {
                if(pos==0)
                {
                    std::cout<<"``";
                    pos=1;
                }else
                {
                    std::cout<<"''";
                    pos=0;
                }
            }else
                std::cout<<str[i];
        }
        std::cout<<'\n';
    }
    return 0;
}
