#include <iostream>

int main(int argc, const char **argv)
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            std::cout << "  ";
        }
        int currentValue = i;
        for (int j = 1; j <= i; j++)
        {
            std::cout << currentValue << " ";
            currentValue = currentValue + (n - j);
        }
        std::cout << std::endl;
    }
    return 0;
}