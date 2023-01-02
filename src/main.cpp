#include <iostream>
#include <chrono>
#include <thread>
#include <string>

struct Split {
    std::string name;
};

int main() {
    auto start_time = std::chrono::steady_clock::now();
    using centiseconds = std::chrono::duration<uint64_t, std::ratio<1, 100>>;
    while(true) {
        std::this_thread::sleep_for(centiseconds(1));
        auto elapsed_time = std::chrono::steady_clock::now() - start_time;
        std::cout << std::chrono::duration_cast<centiseconds>(elapsed_time).count() << std::flush;
    }
    return 0;
}
