#include <chrono>
#include <iostream>
#include <thread>

class Timer {
    bool clear = false;

public:
    void setTimeout(const std::function<void()>& function, int delay);
    void setInterval(const std::function<void()>& function, int interval);
    void stop();
};

void Timer::setTimeout(const std::function<void()>& function, int delay) {
    this->clear = false;
    std::thread t([=]() {
        if (this->clear) {
            return;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        if (this->clear) {
            return;
        }
        function();
    });
    t.detach();
}

void Timer::setInterval(const std::function<void()>& function, int interval) {
    this->clear = false;
    std::thread t([=]() {
        while (true) {
            if (this->clear) {
                return;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(interval));
            if (this->clear) {
                return;
            }
            function();
        }
    });
    t.detach();
}

void Timer::stop() {
    this->clear = true;
}