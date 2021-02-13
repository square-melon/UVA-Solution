#include <iostream>

int main()
{
    int i, j, k, n, f, T, first;
    std::cin >> T;
    while(T--)
    {
        first = 0;
        std::cin >> n >> f;
        for(i = 0;i < f; i++ )
        {
            if(first == 0)
                first = 1;
            else
                std::cout << '\n';
            for(j = 1;j <= n; j++ )
            {
                for(k = 0;k < j; k++ )
                    std::cout << j;
                std::cout << '\n';
            }
            for(j = n-1;j >= 1; j-- )
            {
                for(k = 0;k < j; k++ )
                    std::cout << j;
                std::cout << '\n';
            }
        }
        if(T != 0)
            std::cout << '\n';
    }
    return 0;
}
