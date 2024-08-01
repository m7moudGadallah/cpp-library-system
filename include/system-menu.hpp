#ifndef SYSTEM_MENU_HPP_
#define SYSTEM_MENU_HPP_

#include <string>
#include <tuple>

class SystemMenu {
  public:
    /**
     * @return int Returns (actionCode)
     */
    static int mainMenu();
    /**
     * @return int Returns (bookName, quantity)
     */
    static std::tuple<std::string, int> addBookMenu();
    /**
     * @return int Returns (bookPrefixName)
     */
    static std::string searchBooksByPrefixNameMenu();
    /**
     * @return int Returns (bookName)
     */
    static std::string printWhoBorrowedBookByNameMenu();
    /**
     * @return int Returns (userName)
     */
    static std::tuple<std::string> addUserMenu();
    /**
     * @return int Returns (userId, bookId, borrowDate, returnDate)
     */
    static std::tuple<int, int, std::string, std::string> borrowBookMenu();
    /**
     * @return int Returns (userId, bookId)
     */
    static std::tuple<int, int> returnBookMenu();
};

#endif // SYSTEM_MENU_HPP_