#ifndef SYSTEM_ACTION_HANDLER_HPP_
#define SYSTEM_ACTION_HANDLER_HPP_

#include "../include/book-repository.hpp"
#include "../include/borrowed-book-repository.hpp"
#include "../include/user-repository.hpp"

class SystemActionHandler {
  private:
    BookRepository bookRepo;
    UserRepository userRepo;
    BorrowedBookRepository borrowedBookRepo;

  public:
    void handleAction(int actionCode);

  private:
    void addBook();
    void searchBooksByPrefixName();
    void printWhoBorrowedBookByName();
    void printBooksSortedById();
    void printBooksSortedByName();
    void addUser();
    void borrowBook();
    void returnBook();
    void printUsers();
    void exit();
};

#endif // SYSTEM_ACTION_HANDLER_HPP_