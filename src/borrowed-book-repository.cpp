#include "../include/borrowed-book-repository.hpp"
#include "../include/file-handler.hpp"
#include "../include/global.hpp"

#include <stdexcept>

BorrowedBookRepository::BorrowedBookRepository() { this->loadBorrowedBooks(); }

BorrowedBookRepository::~BorrowedBookRepository() { this->saveBorrowedBooks(); }

void BorrowedBookRepository::borrowBook(BorrowedBook &borrowedBook) {
    if (this->bookIdToUserIds.count(borrowedBook.getBookId()) > 0 and
        this->bookIdToUserIds.at(borrowedBook.getBookId())
            .count(borrowedBook.getUserId())) {
        throw std::logic_error("User already borrowed this book");
    }

    this->borrowedBooks.emplace_back(borrowedBook);
    this->bookIdToUserIds[borrowedBook.getBookId()].emplace(
        borrowedBook.getUserId());
    this->saveBorrowedBooks();
}

void BorrowedBookRepository::returnBook(int userId, int bookId) {
    if (!this->bookIdToUserIds.count(bookId)) {
        throw std::logic_error("Book ID not found");
    }

    if (!this->bookIdToUserIds.at(bookId).count(userId)) {
        throw std::logic_error("User did not borrow this book");
    }

    for (size_t i = 0; i < this->borrowedBooks.size(); i++) {
        if (this->borrowedBooks[i].getUserId() == userId and
            this->borrowedBooks[i].getBookId() == bookId) {
            this->borrowedBooks.erase(this->borrowedBooks.begin() + i);
            break;
        }
    }

    this->bookIdToUserIds[bookId].erase(userId);
    this->saveBorrowedBooks();
}

bool BorrowedBookRepository::isUserBorrowedThisBook(int userId,
                                                    int bookId) const {
    if (!this->bookIdToUserIds.count(bookId)) {
        throw std::logic_error("Book ID not found");
    }

    return this->bookIdToUserIds.at(bookId).count(userId) > 0;
}

std::vector<BorrowedBook> BorrowedBookRepository::getBorrowedBooks() const {
    return this->borrowedBooks;
}

std::vector<int>
BorrowedBookRepository::getUserIdsBorrowedABook(int bookId) const {
    if (!this->bookIdToUserIds.count(bookId)) {
        throw std::logic_error("Book ID not found");
    }

    std::vector<int> userIds;

    for (auto userId : this->bookIdToUserIds.at(bookId)) {
        userIds.emplace_back(userId);
    }

    return userIds;
}

void BorrowedBookRepository::loadBorrowedBooks() {
    std::vector<std::vector<std::string>> lines;
    try {
        lines = FileHandler::readFromFile(BORROWED_BOOKS_FILE_PATH, true);
    } catch (...) {
        throw std::runtime_error("Failed to read from borrowed books file");
    }

    for (const std::vector<std::string> &line : lines) {
        BorrowedBook borrowedBook;
        borrowedBook.deserialize(line);
        this->borrowedBooks.push_back(borrowedBook);
        this->bookIdToUserIds[borrowedBook.getBookId()].emplace(
            borrowedBook.getUserId());
    }
}

void BorrowedBookRepository::saveBorrowedBooks() {
    std::vector<std::vector<std::string>> lines;

    for (const BorrowedBook &borrowedBook : this->borrowedBooks) {
        lines.push_back(borrowedBook.serialize());
    }

    try {
        FileHandler::writeToFile(BORROWED_BOOKS_FILE_PATH, lines,
                                 this->fileHeaderTokens);
    } catch (...) {
        throw std::runtime_error("Failed to write to borrowed books file");
    }
}