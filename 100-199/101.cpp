#include <iostream>
#include <vector>
#include <string>
#define M 25

std::vector<int> block[M];
std::vector<int> position;

void moveonto(int a,int b);
void moveover(int a,int b);
void pileonto(int a,int b);
void pileover(int a,int b);

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int a,b,n,i,j;
    std::string act1,act2;
    while(std::cin>>n)
    {
        for(i=0; i<n; i++)
            block[i].clear();
        position.clear();
        for(i=0; i<n; i++)
        {
            position.push_back(i);
            block[i].push_back(i);
        }
        std::cin>>act1;
        while(act1!="quit")
        {
            std::cin>>a>>act2>>b;
            if(a==b||position[a]==position[b])
            {
                std::cin>>act1;
                continue;
            }
            if(act1=="move")
            {
                if(act2=="onto")
                    moveonto(a,b);
                if(act2=="over")
                    moveover(a,b);
            }
            else
            {
                if(act2=="onto")
                    pileonto(a,b);
                if(act2=="over")
                    pileover(a,b);
            }
            std::cin>>act1;
        }
        for(i=0; i<n; i++)
        {
            std::cout<<i<<":";
            for(j=0; j<block[i].size(); j++)
                std::cout<<' '<<block[i][j];
            std::cout<<'\n';
        }
    }
    return 0;
}

void moveonto(int a,int b)
{
    int i,j;
    std::vector<int> buffer;
    for(i=block[position[a]].size()-1; i>=0; i--)
    {
        if(block[position[a]][i]==a)
        {
            block[position[a]].pop_back();
            break;
        }
        else
        {
            buffer.push_back(block[position[a]][i]);
            block[position[a]].pop_back();
        }
    }
    for(j=block[position[b]].size()-1; j>=0; j--)
    {
        if(block[position[b]][j]==b)
            break;
        else
        {
            buffer.push_back(block[position[b]][j]);
            block[position[b]].pop_back();
        }
    }
    for(int k=buffer.size()-1; k>=0; k--)
    {
        if(buffer[k]!=a)
            block[buffer[k]].push_back(buffer[k]);
        position[buffer[k]]=buffer[k];
        buffer.pop_back();
    }
    block[position[b]].push_back(a);
    position[a]=position[b];
}

void moveover(int a,int b)
{
    int i,j;
    std::vector<int> buffer;
    for(i=block[position[a]].size()-1; i>=0; i--)
    {
        if(block[position[a]][i]==a)
        {
            block[position[a]].pop_back();
            break;
        }
        else
        {
            buffer.push_back(block[position[a]][i]);
            block[position[a]].pop_back();
        }
    }
    for(int k=buffer.size()-1; k>=0; k--)
    {
        if(buffer[k]!=a)
            block[buffer[k]].push_back(buffer[k]);
        position[buffer[k]]=buffer[k];
        buffer.pop_back();
    }
    block[position[b]].push_back(a);
    position[a]=position[b];
}

void pileonto(int a,int b)
{
    int i,j;
    std::vector<int> buffer,buffer2;
    for(i=block[position[a]].size()-1; i>=0; i--)
    {
        buffer.push_back(block[position[a]][i]);
        block[position[a]].pop_back();
        if(block[position[a]][i]==a)
            break;
    }
    for(j=block[position[b]].size()-1; j>=0; j--)
    {
        if(block[position[b]][j]==b)
            break;
        else
        {
            buffer2.push_back(block[position[b]][j]);
            block[position[b]].pop_back();
        }
    }
    for(int k=buffer2.size()-1; k>=0; k--)
    {
        block[buffer2[k]].push_back(buffer2[k]);
        position[buffer2[k]]=buffer2[k];
        buffer2.pop_back();
    }
    for(int k=buffer.size()-1; k>=0; k--)
    {
        block[position[b]].push_back(buffer[k]);
        position[buffer[k]]=position[b];
        buffer.pop_back();
    }
}

void pileover(int a,int b)
{
    int i,j;
    std::vector<int> buffer;
    for(i=block[position[a]].size()-1; i>=0; i--)
    {
        buffer.push_back(block[position[a]][i]);
        block[position[a]].pop_back();
        if(block[position[a]][i]==a)
            break;
    }
    for(int k=buffer.size()-1; k>=0; k--)
    {
        block[position[b]].push_back(buffer[k]);
        position[buffer[k]]=position[b];
        buffer.pop_back();
    }
}
