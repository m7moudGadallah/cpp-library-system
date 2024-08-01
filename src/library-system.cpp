#include "../include/library-system.hpp"
#include "../include/system-menu.hpp"

#include <iostream>

void LibrarySystem::run() {
    try {
        actionHandler.handleAction(SystemMenu::mainMenu());
    } catch (std::invalid_argument &e) {
        std::cerr << "Invalid Argument Error: " << e.what() << "\n";
    } catch (std::logic_error &e) {
        std::cerr << "Logic Error: " << e.what() << "\n";
    } catch (...) {
        throw;
    }

    std::cout << "===============================\n\n";
}