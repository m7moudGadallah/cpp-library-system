#include "../include/library-system.hpp"
#include <iostream>

int main(void) {
    std::cout << "Welcome to Library System\n";

    LibrarySystem system;

    while (true) {
        system.run();
    }

    return EXIT_SUCCESS;
}