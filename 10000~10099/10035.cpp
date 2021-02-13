#include <iostream>
#include <cstring>

void Convert();
void Plus();

std::string str1,str2;
int num1[100],num2[100],ans[100],carry;

int main()
{
    while(std::cin>>str1>>str2)
    {
        if(str1=="0"&&str2=="0")
            break;
        memset(num1,0,100);
        memset(num2,0,100);
        Convert();
        carry=0;
        Plus();
        if(carry==0)
            std::cout<<"No carry operation.\n";
        else if(carry==1)
            std::cout<<"1 carry operation.\n";
        else
            std::cout<<carry<<" carry operations.\n";
    }
    return 0;
}

void Convert()
{
    int i;
    for(i=str1.size()-1;i>=0;i--)
        num1[str1.size()-i-1]=str1[i]-'0';
    for(i=str2.size()-1;i>=0;i--)
        num2[str2.size()-i-1]=str2[i]-'0';
}

void Plus()
{
    int i;
    for(i=0;i<str1.size()||i<str2.size();i++)
    {
        if(num1[i]+num2[i]>=10)
        {
            num1[i+1]++;
            carry++;
        }
    }
}
