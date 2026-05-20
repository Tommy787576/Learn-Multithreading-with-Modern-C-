#include <iostream>
#include <thread>

void game(int finalNum) {
    for (int i = 1; i <= finalNum; i++) {
        if (i % 3 == 0 && i % 5 == 0)
            std::cout << "fizzbuzz" << std::endl;
        else if (i % 3 == 0)
            std::cout << "fizz" << std::endl;
        else if (i % 5 == 0)
            std::cout << "buzz" << std::endl;
        else
            std::cout << i << std::endl;
    }
    return;
}

int main(int argc, char *argv[])
{
    std::thread thr{game, 30000};
    thr.join();

    return 0;
}