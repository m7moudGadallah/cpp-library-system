#ifndef USE_REPOSITORY_HPP_
#define USER_REPOSITORY_HPP_

#include "user.hpp"

#include <string>
#include <vector>

class UserRepository {
  private:
    std::vector<User> users;
    const std::vector<std::string> fileHeaderTokens = {"ID", "NAME"};

  public:
    UserRepository();
    ~UserRepository();
    void addUser(const User &user);
    User getUserById(int id) const;
    std::vector<User> getUsers() const;
    bool isUserExist(std::string name) const;
    bool isUserExist(int id) const;

  private:
    void loadUsers();
    void saveUsers();
    int findUserIndexById(int id) const;
};

#endif // USER_REPOSITORY_HPP_