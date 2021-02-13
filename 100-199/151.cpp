#include <iostream>
#include <vector>

std::vector<int> people;
int n,m;

void kill(int a,int place)
{
    if(people.size()==1)
        return;
    if(a==m)
    {
        if(people[place]==13)
        {
            people.erase(people.begin()+place);
            return;
        }
        people.erase(people.begin()+place);
        kill(1,place%people.size());
    }
    else
        kill(a+1,(place+1)%people.size());
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int i;
    while(std::cin>>n&&n!=0)
    {
        for(m=1; m<=n; m++)
        {
            people.clear();
            for(i=1; i<=n; i++)
                people.push_back(i);
            kill(m,0);
            if(people[0]==13)
                break;
        }
        std::cout<<m<<'\n';
    }
    return 0;
}
