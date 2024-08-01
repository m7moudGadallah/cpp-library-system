#include "../include/book.hpp"

#include <sstream>
#include <stdexcept>

int Book::idSequence = 0;

Book::Book(std::string name, int quantity)
    : id(Book::idSequence++), name(name), quantity(quantity), borrowed(0) {}

Book::Book() : Book("", 0) {}

int Book::getId() const { return this->id; }

std::string Book::getName() const { return this->name; }

int Book::getQuantity() const { return this->quantity; }

int Book::getBorrowed() const { return this->borrowed; }

int Book::getAvailable() const { return this->quantity - this->borrowed; }

void Book::setName(std::string name) { this->name = name; }

void Book::setQuantity(int quantity) {
    if (this->borrowed > quantity) {
        throw std::invalid_argument("Quantity cannot be less than borrowed");
    }

    this->quantity = quantity;
}

void Book::setBorrowed(int borrowed) {
    if (borrowed > this->quantity) {
        throw std::invalid_argument("Borrowed cannot be greater than quantity");
    }

    this->borrowed = borrowed;
}

std::string Book::toString() const {
    std::stringstream ss;
    ss << "{id: " << this->id << ", name: " << this->name
       << ", quantity: " << this->quantity << ", borrowed: " << this->borrowed
       << "}";

    return ss.str();
}

bool Book::isEqual(const Book &book) const {
    return this->id == book.getId() and this->name == book.getName() and
           this->quantity == book.getQuantity() and
           this->borrowed == book.getBorrowed();
}

std::vector<std::string> Book::serialize() const {
    std::vector<std::string> tokens;
    tokens.push_back(std::to_string(this->id));
    tokens.push_back(this->name);
    tokens.push_back(std::to_string(this->quantity));
    tokens.push_back(std::to_string(this->borrowed));

    return tokens;
}

void Book::deserialize(const std::vector<std::string> &tokens) {
    if (tokens.size() != 4) {
        throw std::invalid_argument("Invalid number of tokens");
    }

    this->id = std::stoi(tokens[0]);
    this->name = tokens[1];
    this->quantity = std::stoi(tokens[2]);
    this->borrowed = std::stoi(tokens[3]);

    Book::idSequence = this->id + 1;
}