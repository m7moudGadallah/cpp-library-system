#include "../include/system-menu.hpp"

#include <iostream>

int SystemMenu::mainMenu() {
    std::cout << "Library Menu:\n"
              << "1) add_book\n"
              << "2) search_books_by_prefix_name\n"
              << "3) print_who_borrowed_book\n"
              << "4) show_books_sorted_by_id\n"
              << "5) show_books_sorted_by_name\n"
              << "6) add_user\n"
              << "7) borrow_book\n"
              << "8) return_book\n"
              << "9) print_users\n"
              << "10) exit\n"
              << "\nEnter your choice[1-10]: ";

    int choice;

    try {
        std::cin >> choice;
        std::cin.ignore();
    } catch (...) {
        throw std::logic_error("Invalid input!");
    }

    return choice;
}

std::tuple<std::string, int> SystemMenu::addBookMenu() {
    std::string name;
    int quantity;

    try {
        std::cout << "Enter book name: ";
        std::getline(std::cin, name);
        std::cout << "Enter book quantity: ";
        std::cin >> quantity;
    } catch (...) {
        throw std::logic_error("Invalid input!");
    }

    return {name, quantity};
}

std::string SystemMenu::searchBooksByPrefixNameMenu() {
    std::string prefixName;

    try {
        std::cout << "Enter book name prefix: ";
        std::getline(std::cin, prefixName);
    } catch (...) {
        throw std::logic_error("Invalid input!");
    }

    return prefixName;
}

std::string SystemMenu::printWhoBorrowedBookByNameMenu() {
    std::string bookName;

    try {
        std::cout << "Enter book name: ";
        std::getline(std::cin, bookName);
    } catch (...) {
        throw std::logic_error("Invalid input!");
    }

    return bookName;
}

std::tuple<std::string> SystemMenu::addUserMenu() {
    std::string userName;

    try {
        std::cout << "Enter user name: ";
        std::getline(std::cin, userName);
    } catch (...) {
        throw std::logic_error("Invalid input!");
    }

    return userName;
}

std::tuple<int, int, std::string, std::string> SystemMenu::borrowBookMenu() {
    int userId;
    int bookId;
    std::string borrowDate;
    std::string returnDate;

    try {
        std::cout << "Enter user id: ";
        std::cin >> userId;
        std::cout << "Enter book id: ";
        std::cin >> bookId;
        std::cin.ignore();
        std::cout << "Enter borrow date (yyyy-mm-dd): ";
        std::getline(std::cin, borrowDate);
        std::cout << "Enter return date (yyyy-mm-dd): ";
        std::getline(std::cin, returnDate);
    } catch (...) {
        throw std::logic_error("Invalid input!");
    }

    return {userId, bookId, borrowDate, returnDate};
}

std::tuple<int, int> SystemMenu::returnBookMenu() {
    int userId;
    int bookId;

    try {
        std::cout << "Enter user id: ";
        std::cin >> userId;
        std::cout << "Enter book id: ";
        std::cin >> bookId;
    } catch (...) {
        throw std::logic_error("Invalid input!");
    }

    return {userId, bookId};
}