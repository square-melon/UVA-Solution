#include <iostream>
#include <iomanip>

int main()
{
    int T, n, i, sum, cnt;
    float average;
    double ans;
    std::cin >> T;
    while(T--)
    {
        std::cin >> n;
        int grade[n];
        cnt = 0;
        sum = 0;
        for(i = 0;i < n; i++ )
        {
            std::cin >> grade[i];
            sum += grade[i];
        }
        average = (float) sum / n;
        for(i = 0;i < n; i++ )
        {
            if((float) grade[i] > average)
                cnt++;
        }
        ans = (double) cnt / n * 100;
        std::cout << std::fixed << std::setprecision(3) << ans << '%' << '\n';
    }
    return 0;
}
