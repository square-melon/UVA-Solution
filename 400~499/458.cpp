//ASCII Code -7
#include <iostream>
#include <string>

int main()
{
    std::string str;
    while(getline(std::cin,str))
    {
        for(int i=0;i<str.size();i++)
            std::cout<<(char)(str[i]-7);
        std::cout<<'\n';
    }
    return 0;
}
