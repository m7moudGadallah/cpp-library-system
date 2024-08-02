#ifndef BORROWED_BOOK_HPP_
#define BORROWED_BOOK_HPP_

#include "serializable.hpp"
#include <string>

class BorrowedBook : public Serializable {
  private:
    int userId;
    int bookId;
    std::string borrowDate;
    std::string returnDate;

  public:
    BorrowedBook(int userId, int bookId, std::string borrowDate,
                 std::string returnDate);
    BorrowedBook();
    int getUserId() const;
    int getBookId() const;
    std::string getBorrowDate() const;
    std::string getReturnDate() const;
    void setUserId(int userId);
    void setBookId(int bookId);
    void setBorrowDate(std::string borrowDate);
    void setReturnDate(std::string returnDate);
    std::string toString() const;
    std::vector<std::string> serialize() const override;
    void deserialize(const std::vector<std::string> &tokens) override;
};

#endif // BORROWED_BOOK_HPP_