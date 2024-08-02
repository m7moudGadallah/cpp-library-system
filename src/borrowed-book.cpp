#include "../include/borrowed-book.hpp"
#include "../include/string-utitlity.hpp"

#include <sstream>
#include <stdexcept>

BorrowedBook::BorrowedBook(int userId, int bookId, std::string borrowDate,
                           std::string returnDate)
    : userId(userId), bookId(bookId), borrowDate(borrowDate),
      returnDate(returnDate) {}

BorrowedBook::BorrowedBook() : BorrowedBook(-1, -1, "", "") {}

int BorrowedBook::getUserId() const { return this->userId; }

int BorrowedBook::getBookId() const { return this->bookId; }

std::string BorrowedBook::getBorrowDate() const { return this->borrowDate; }

std::string BorrowedBook::getReturnDate() const { return this->returnDate; }

void BorrowedBook::setUserId(int userId) { this->userId = userId; }

void BorrowedBook::setBookId(int bookId) { this->bookId = bookId; }

// validate date
void validateDate(std::string date) {
    try {
        auto tokens = StringUtility::split(date, "-");
        if (tokens.size() != 3) {
            throw;
        }

        int year = std::stoi(tokens[0]);
        int month = std::stoi(tokens[1]);
        int day = std::stoi(tokens[2]);

        if (year < 2024)
            throw;
        if (month < 1 or month > 12)
            throw;
        if (day < 1 or month > 31)
            throw;
    } catch (...) {
        throw std::invalid_argument("Invalid date format!");
    }
}

void BorrowedBook::setBorrowDate(std::string borrowDate) {
    validateDate(borrowDate);
    this->borrowDate = borrowDate;
}

void BorrowedBook::setReturnDate(std::string returnDate) {
    validateDate(returnDate);
    this->returnDate = returnDate;
}

std::string BorrowedBook::toString() const {
    std::stringstream ss;

    ss << "{ userId: " << this->userId << ", bookId: " << this->bookId
       << ", borrowDate: " << this->borrowDate
       << ", returnDate: " << this->returnDate << "}";

    return ss.str();
}

std::vector<std::string> BorrowedBook::serialize() const {
    std::vector<std::string> tokens;
    tokens.push_back(std::to_string(this->userId));
    tokens.push_back(std::to_string(this->bookId));
    tokens.push_back(this->borrowDate);
    tokens.push_back(this->returnDate);

    return tokens;
}

void BorrowedBook::deserialize(const std::vector<std::string> &tokens) {
    if (tokens.size() != 4) {
        throw std::invalid_argument("Invalid number of tokens");
    }

    this->userId = std::stoi(tokens[0]);
    this->bookId = std::stoi(tokens[1]);
    this->borrowDate = tokens[2];
    this->returnDate = tokens[3];
}