#include <iostream>
#include <algorithm>
#include <iomanip>

int main()
{
    int cnt = 1;
    int n, i, j, k;
    std::cin >> n;
    while(n != 0)
    {
        float x[2*n], y[2*n], rec[n][3], sum = 0;
        for(i = 0;i < n; i++ )//set points
        {
            std::cin >> rec[i][0] >> rec[i][1] >> rec[i][2];
            x[2*i] = rec[i][0] - rec[i][2];
            x[2*i+1] = rec[i][0] + rec[i][2];
            y[2*i] = rec[i][1] - rec[i][2];
            y[2*i+1] = rec[i][1] + rec[i][2];
        }
        std::sort(x,x+2*n);
        std::sort(y,y+2*n);
        for(i = 0;i < 2*n-1; i++ )//find whether small rectangles are included in the area
        {
            for(j = 0;j < 2*n-1; j++ )
            {
                for(k = 0;k < n; k++ )
                {
                    if(rec[k][0] - rec[k][2] <= x[i] && rec[k][0] + rec[k][2] >= x[i+1] && rec[k][1] - rec[k][2] <= y[j] && rec[k][1] + rec[k][2] >= y[j+1])
                    {
                        sum += ( x[i+1] - x[i] ) * ( y[j+1] - y[j] );
                        break;
                    }
                }
            }
        }
        std::cout << cnt << ' ' << std::fixed << std::setprecision(2) << sum << '\n';
        cnt++;
        std::cin >> n;
    }
    return 0;
}
