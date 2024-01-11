#include "Marble.h"
#include <iostream>

int main() {
    srand(time(0)); // Seed for random number generation

    Bag myBag;
    Marble blueMarble("blue", 1.0, "glass");

    // Test 1: Add and remove a marble
    myBag.addMarble(blueMarble);
    Marble removedMarble = myBag.removeMarble();
    std::cout << "Removed a " << removedMarble.color << " marble of size " << removedMarble.size << std::endl;

    // Test 2: Try to remove from an empty bag
    try {
        myBag.removeMarble();
    } catch (const std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // Additional tests can be added as needed

    return 0;
}
