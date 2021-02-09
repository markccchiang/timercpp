#include <iostream>

#include "timercpp.h"

using namespace std;

int main() {
    volatile bool loop(true);

    Timer t = Timer();

    t.setInterval([&]() { cout << "Hey.. After each 1s..." << endl; }, 1000);

    t.setTimeout(
        [&]() {
            cout << "Hey.. After 5.2s. But I will stop the timer!" << endl;
            t.stop();
            cout << "End the process!" << endl;
            loop = false;
        },
        5200);

    cout << "I am Timer" << endl;

    while (loop)
        ; // Keep mail thread active

    return 0;
}