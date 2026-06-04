// Packaged task example
// Executes the task in a new thread
#include <future>
#include <iostream>
#include <chrono>

using namespace std::literals;

void producer(int a, int b, std::promise<int>& prom) {
    std::this_thread::sleep_for(2s);
    prom.set_value(a + b);
    return;
}

void consumer(std::future<int>& fut) {
    std::cout << "Waiting for result\n";
    std::cout << "6 + 7 is " << fut.get() << '\n';
}

int main() {
	std::promise<int> p;
	auto fut = p.get_future();

	std::thread thr_producer(producer, 6, 7, std::ref(p));
    std::thread thr_consumer(consumer, std::ref(fut));

    thr_producer.join();
    thr_consumer.join();

    return 0;
}