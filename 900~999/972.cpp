#include <iostream>
#include <iomanip>
#include <algorithm>

int main()
{
    int sep_f, sep_g, i, j, now_f, now_g;
    float buf1, buf2, f[100], g[100], local_min;
    while(std::cin >> sep_f)
    {
        now_f = 0;
        for(i = 0;i < sep_f; i++ )
        {
            std::cin >> buf1 >> buf2;
            for(j = 0;j < (int) buf2 * 10; j++ )
                f[now_f+j] = buf1;
            now_f += buf2 * 10;
        }
        std::cin >> sep_g;
        now_g = 0;
        for(i = 0;i < sep_g; i++ )
        {
            std::cin >> buf1 >> buf2;
            for(j = 0;j < (int) buf2 * 10; j++ )
                g[now_g+j] = buf1;
            now_g += buf2 * 10;
        }
        local_min = 10.0;
        for(i = 0;i < 100; i++ )
            local_min = std::min(local_min, std::max(f[i], g[i]));
        std::cout << std::fixed << std::setprecision(3) << local_min << '\n';
    }
    return 0;
}
