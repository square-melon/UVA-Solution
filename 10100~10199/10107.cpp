#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<long long int> vec;
    long long int buf;
    std::cin >> buf;
    vec.push_back(buf);
    std::cout << buf << '\n';
    while(std::cin >> buf)
    {
        vec.push_back(buf);
        long long int arr[vec.size()];
        for(long long int i = 0;i < vec.size(); i++ )
            arr[i] = vec[i];
        std::sort(arr,arr+vec.size());
        if(vec.size() % 2 == 1)
            std::cout << arr[(vec.size()+1)/2-1] << '\n';
        else
            std::cout << ( arr[vec.size()/2] + arr[vec.size()/2-1] ) / 2 << '\n';
    }
    return 0;
}
