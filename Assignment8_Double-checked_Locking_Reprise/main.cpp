#include <mutex>
#include <thread>
#include <atomic>

class some_type {
	// ...
public:
	void do_it() { /*...*/ }
};

std::atomic<some_type*> ptr{nullptr};            // Variable to be lazily initialized
std::mutex process_mutex;

void process() {
    if (!ptr) {                     // First check of ptr
        std::lock_guard<std::mutex> lk(process_mutex);
        
        if (!ptr)                  // Second check of ptr
            ptr = new some_type;   // Initialize ptr
    }
    some_type* tmp_ptr = ptr;
    tmp_ptr->do_it();
}

int main(void) {
    std::thread th1{process}, th2{process};
    th1.join();
    th2.join();
    return 0;
}