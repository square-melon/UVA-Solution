#include <iostream>
#include <algorithm>

int** box;
int* used;
int* arrange;
int* bufarrange;
int n,m,length,longest;

bool compare(int a,int b){ return(a>b); }
void DFS(int T);
bool Check(int a,int b);

int main()
{
    int i,j;
    int* buf;
    while(std::cin>>n>>m)
    {
        buf=new int[m];
        box=new int*[n];
        used=new int[n];
        arrange=new int[n];
        bufarrange=new int[n];
        for(i=0;i<n;i++)
            box[i]=new int[m];
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                std::cin>>buf[j];
            std::sort(buf,buf+m,compare);
            for(j=0;j<m;j++)
                box[i][j]=buf[j];
        }
        for(i=0;i<n;i++)
            used[i]=0;
        longest=0;
        for(i=0;i<n;i++)
        {
            length=0;
            bufarrange[0]=i;
            DFS(i);
        }
        for(i=longest-1;i>=0;i--)
            std::cout<<arrange[i]+1<<' ';
        std::cout<<'\n';
        delete[] arrange;
        delete[] used;
        delete[] bufarrange;
        for(i=0;i<n;i++)
            delete[] box[i];
        delete[] box;
    }
    return 0;
}

void DFS(int T)
{
    int i,j;
    length++;
    used[T]=1;
    if(length>longest)
    {
        for(j=0;j<length;j++)
            arrange[j]=bufarrange[j];
        longest=length;
    }
    if(longest==n)
        return;
    for(i=0;i<n;i++)
    {
        if(i==T||used[i]==1)
            continue;
        if(Check(i,T))
        {
            bufarrange[length]=i;
            DFS(i);
            length--;
        }
    }
    used[T]=0;
}

bool Check(int a,int b)
{
    int i,check=1;
    for(i=0;i<m;i++)
    {
        if(box[a][i]>box[b][i])
        {
            check=0;
            break;
        }
    }
    if(check==0)
        return false;
    else
        return true;
}
