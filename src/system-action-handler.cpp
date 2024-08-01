#include "../include/system-action-handler.hpp"

#include "../include/system-menu.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>

void SystemActionHandler::handleAction(int actionCode) {
    switch (actionCode) {
    case 1:
        this->addBook();
        break;
    case 2:
        this->searchBooksByPrefixName();
        break;
    case 3:
        break;
    case 4:
        this->printBooksSortedById();
        break;
    case 5:
        this->printBooksSortedByName();
        break;
    case 6:
        this->addUser();
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
        this->printUsers();
        break;
    case 10:
        this->exit();
        break;
    default:
        throw std::logic_error("Invalid action code");
        break;
    }
}

void SystemActionHandler::addBook() {
    auto [name, quantity] = SystemMenu::addBookMenu();

    if (this->bookRepo.isBookExist(name)) {
        throw std::logic_error("Already exist book with this name");
    }

    this->bookRepo.addBook(Book(name, quantity));
}

void SystemActionHandler::searchBooksByPrefixName() {
    std::string namePrefix = SystemMenu::searchBooksByPrefixNameMenu();

    auto books = this->bookRepo.getBooksByNamePrefix(namePrefix);

    if (books.empty()) {
        std::cout << "Not found books matches this name!\n";
        return;
    }

    for (auto &book : books) {
        std::cout << book.toString() << "\n";
    }
}

void SystemActionHandler::printBooksSortedById() {
    auto books = this->bookRepo.getBooks();

    for (auto book : books) {
        std::cout << book.toString() << "\n";
    }
}

void SystemActionHandler::printBooksSortedByName() {
    auto books = this->bookRepo.getBooks();

    std::sort(books.begin(), books.end(), [](const Book &a, const Book &b) {
        return a.getName() < b.getName();
    });

    for (auto &book : books) {
        std::cout << book.toString() << "\n";
    }
}

void SystemActionHandler::addUser() {
    auto [name] = SystemMenu::addUserMenu();

    if (this->userRepo.isUserExist(name)) {
        throw std::logic_error("Already exist user with this name");
    }

    this->userRepo.addUser(User(name));
}

void SystemActionHandler::printUsers() {
    auto users = this->userRepo.getUsers();

    for (const auto &user : users) {
        std::cout << user.toString() << "\n";
    }
}

void SystemActionHandler::exit() { std::exit(EXIT_SUCCESS); }