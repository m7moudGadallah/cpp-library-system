#include "../include/book-repository.hpp"

#include "../include/book-repository.hpp"
#include "../include/file-handler.hpp"
#include "../include/global.hpp"

#include <stdexcept>

BookRepository::BookRepository() { this->loadBooks(); }

BookRepository::~BookRepository() { this->saveBooks(); }

void BookRepository::addBook(const Book &book) { this->books.push_back(book); }

Book BookRepository::borrowBook(int id) {
    int index = this->findBookIndexById(id);
    if (index == -1) {
        throw std::logic_error("Book not found");
    }

    if (this->books[index].getAvailable() <= 0) {
        throw std::logic_error("Sorry all copies is borrowed!");
    }

    this->books[index].setBorrowed(this->books[index].getBorrowed() + 1);
    return this->books[index];
}

Book BookRepository::returnBook(int id) {
    int index = this->findBookIndexById(id);

    if (index == -1) {
        throw std::logic_error("Book not found");
    }
    this->books[index].setBorrowed(this->books[index].getBorrowed() - 1);
    return this->books[index];
}

std::vector<Book> BookRepository::getBooks() const { return this->books; }

std::vector<Book>
BookRepository::getBooksByNamePrefix(std::string prefixName) const {
    std::vector<Book> foundBooks;
    for (const Book &book : this->books) {
        if (book.getName().find(prefixName) == 0) {
            foundBooks.push_back(book);
        }
    }
    return foundBooks;
}

bool BookRepository::isBookExist(std::string name) const {
    for (const Book &book : this->books) {
        if (book.getName() == name)
            return true;
    }

    return false;
}

void BookRepository::loadBooks() {
    std::vector<std::vector<std::string>> lines;
    try {
        lines = FileHandler::readFromFile(BOOKS_FILE_PATH, true);
    } catch (...) {
        throw std::runtime_error("Failed to read from books file");
    }

    for (const std::vector<std::string> &line : lines) {
        Book book;
        book.deserialize(line);
        this->books.push_back(book);
    }
}

void BookRepository::saveBooks() {
    std::vector<std::vector<std::string>> lines;

    for (const Book &book : this->books) {
        lines.push_back(book.serialize());
    }

    try {
        FileHandler::writeToFile(BOOKS_FILE_PATH, lines,
                                 this->fileHeaderTokens);
    } catch (...) {
        throw std::runtime_error("Failed to write to books file");
    }
}

int BookRepository::findBookIndexById(int id) const {
    int size = (int)this->books.size();

    if (size < id and this->books[id].getId() == id) {
        return id;
    }

    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (this->books[mid].getId() == id) {
            return mid;
        }

        if (this->books[mid].getId() < id) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}