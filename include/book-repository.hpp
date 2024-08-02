#ifndef BOOK_REPOSITORY_HPP_
#define BOOK_REPOSITORY_HPP_

#include "book.hpp"
#include "file-handler.hpp"

class BookRepository {
  private:
    std::vector<Book> books;
    const std::vector<std::string> fileHeaderTokens = {"ID", "NAME", "QUANTITY",
                                                       "BORROWED"};

  public:
    BookRepository();
    ~BookRepository();
    void addBook(const Book &book);
    Book borrowBook(int id);
    Book returnBook(int id);
    std::vector<Book> getBooks() const;
    Book getBookByName(std::string name) const;
    std::vector<Book> getBooksByNamePrefix(std::string namePrefix) const;
    bool isBookExist(std::string name) const;

  private:
    void loadBooks();
    void saveBooks();
    int findBookIndexById(int id) const;
};

#endif // BOOK_REPOSITORY_HPP_