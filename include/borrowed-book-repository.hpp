#ifndef BORROWED_BOOK_REPOSITORY_HPP_
#define BORROWED_BOOK_REPOSITORY_HPP_

#include "borrowed-book.hpp"
#include <unordered_map>
#include <unordered_set>
#include <vector>

class BorrowedBookRepository {
  private:
    std::unordered_map<int, std::unordered_set<int>> bookIdToUserIds;
    std::vector<BorrowedBook> borrowedBooks;
    std::vector<std::string> fileHeaderTokens = {"USER_ID", "BOOK_ID",
                                                 "BORROW_DATE", "RETURN_DATE"};

  public:
    BorrowedBookRepository();
    ~BorrowedBookRepository();
    void borrowBook(BorrowedBook &borrowedBook);
    void returnBook(int userId, int bookId);
    bool isUserBorrowedThisBook(int userId, int bookId) const;
    std::vector<BorrowedBook> getBorrowedBooks() const;
    std::vector<int> getUserIdsBorrowedABook(int bookId) const;

  private:
    void loadBorrowedBooks();
    void saveBorrowedBooks();
};

#endif // BORROWED_BOOK_REPOSITORY_HPP_