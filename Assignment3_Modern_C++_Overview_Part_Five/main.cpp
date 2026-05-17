#include <iostream>
#include <random>

std::mt19937 mt;

int main()
{
    std::uniform_int_distribution<int> uid(0, 10);
    for (int i = 0; i < 10; i++)
        std::cout << uid(mt) << ' ';
    std::cout << std::endl;

    std::uniform_real_distribution<float> frd(0, 100.0);
    for (int i = 0; i < 5; i++)
        std::cout << frd(mt) << ' ';
    std::cout << std::endl;

    return 0;
}