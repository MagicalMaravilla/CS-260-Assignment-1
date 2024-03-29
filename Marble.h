#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

// The Marble class represents a single marble.
class Marble {
public:
    std::string color;   // Color of the marble
    float size;          // Size of the marble
    std::string material;// Material of the marble

    // Constructor for Marble class
    // Initializes a Marble object with the given color, size, and material
    Marble(std::string c, float s, std::string m) : color(c), size(s), material(m) {}
};

// The Bag class represents a bag that can hold multiple marbles.
class Bag {
private:
    std::vector<Marble> marbles; // Vector to store marbles
    const size_t maxCapacity = 1000000; // Maximum capacity aka Big Boi Bag

public:
    // Adds a Marble object to the bag
    // Throws an exception if the bag reaches its maximum capacity
    void addMarble(const Marble& marble) {
        if (marbles.size() >= maxCapacity) {
            throw std::overflow_error("Bag has reached its maximum capacity");
        }
        marbles.push_back(marble);
    }

    // Removes and returns a Marble object from the bag randomly
    // Throws an exception if the bag is empty
    Marble removeMarble() {
        if (marbles.empty()) {
            throw std::out_of_range("Bag is empty");
        }
        int index = rand() % marbles.size(); // Randomly selects an index
        Marble m = marbles[index];           // Retrieves the marble at the index
        marbles.erase(marbles.begin() + index); // Removes the marble from the vector
        return m; // Returns the removed marble
    }

    // Checks if the bag is empty
    bool isEmpty() const {
        return marbles.empty();
    }

    // Returns the number of marbles in the bag
    size_t size() const {
        return marbles.size();
    }
};
