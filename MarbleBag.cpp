#include "Marble.h"
#include <iostream>

int main() {
    srand(time(0)); // Initialize random seed based on current time

    Bag myBag; // Create an instance of Bag to hold marbles
    Marble blueMarble("blue", 1.0, "glass"); // Create a blue marble of glass material
    Marble redMarble("red", 1.5, "plastic"); // Create a red marble of plastic material

    // Test 1: Add and Remove a Marble
    myBag.addMarble(blueMarble); // Add the blue marble to the bag
    Marble removedMarble = myBag.removeMarble(); // Remove a marble from the bag
    // Display the properties of the removed marble
    std::cout << "Removed a " << removedMarble.color << " marble of size " << removedMarble.size << std::endl;

    // Test 2: Remove from an Empty Bag
    try {
        myBag.removeMarble(); // Attempt to remove a marble from an empty bag
    } catch (const std::out_of_range& e) {
        // Catch and display the exception if the bag is empty
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // Test 3: Test Bag Capacity
    try {
        // Attempt to add more marbles than the bag's capacity
        for (int i = 0; i < 1000001; ++i) {
            myBag.addMarble(redMarble); // Add a red marble to the bag
        }
    } catch (const std::overflow_error& e) {
        // Catch and display the exception if the bag reaches maximum capacity
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
