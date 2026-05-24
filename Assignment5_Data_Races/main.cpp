#include <iostream>
#include <thread>

int sum = 0;

void add(void) {
    for (int i = 0; i < 100000; i++)
        sum++;  // data race occurs
    return;
}

int main(void)
{
    std::thread thr{add};
    std::thread thr2{add};
    thr.join();
    thr2.join();
    std::cout << "Final Sum: " << sum << std::endl;

    return 0;
}