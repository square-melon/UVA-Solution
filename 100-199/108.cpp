/*Build 1 2-dimensions matrix
 *sum[i][j]=sigma(k = 0 to i)sum[k][j]
 *To simplify calculation(list all possibilities)
 */
#include <iostream>
#define M 100

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int element[M][M],sum1[M][M]= {0},n,i,j,maxsum;
    std::cin>>n;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            std::cin>>element[i][j];
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            for(int k=0; k<=i; k++)
                sum1[i][j]+=element[k][j];
        }
    }
    maxsum=element[0][0];
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            for(int k=i; k<n; k++)
            {
                for(int l=j; l<n; l++)
                {
                    int buffer=0;
                    for(int x=j; x<=l; x++)
                        buffer+=sum1[k][x]-sum1[i][x];
                    if(buffer>maxsum)
                        maxsum=buffer;
                }
            }
        }
    }
    std::cout<<maxsum<<'\n';
    return 0;
}
