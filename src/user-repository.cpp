#include "../include/user-repository.hpp"
#include "../include/file-handler.hpp"
#include "../include/global.hpp"
#include "../include/string-utitlity.hpp"
#include "stdexcept"

UserRepository::UserRepository() { this->loadUsers(); };

UserRepository::~UserRepository() { this->saveUsers(); };

void UserRepository::addUser(const User &user) {
    this->users.push_back(user);
    this->saveUsers();
}

User UserRepository::getUserById(int id) const {
    int index = this->findUserIndexById(id);

    if (index == -1) {
        throw std::logic_error("Not found user with this id");
    }

    return this->users[index];
}

std::vector<User> UserRepository::getUsers() const { return this->users; }

bool UserRepository::isUserExist(std::string name) {
    name = StringUtility::tolower(name);

    for (const auto &user : users) {
        if (StringUtility::tolower(user.getName()) == name) {
            return true;
        }
    }

    return false;
}

void UserRepository::loadUsers() {
    std::vector<std::vector<std::string>> lines;
    try {
        lines = FileHandler::readFromFile(USERS_FILE_PATH, true);
    } catch (...) {
        throw std::runtime_error("Failed to read from users file");
    }

    for (const std::vector<std::string> &line : lines) {
        User user;
        user.deserialize(line);
        this->users.push_back(user);
    }
}

void UserRepository::saveUsers() {
    std::vector<std::vector<std::string>> lines;

    for (const User &user : this->users) {
        lines.push_back(user.serialize());
    }

    try {
        FileHandler::writeToFile(USERS_FILE_PATH, lines,
                                 this->fileHeaderTokens);
    } catch (...) {
        throw std::runtime_error("Failed to write to users file");
    }
}

int UserRepository::findUserIndexById(int id) const {
    int size = (int)this->users.size();

    if (size < id and this->users[id].getId() == id) {
        return id;
    }

    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (this->users[mid].getId() == id) {
            return mid;
        }

        if (this->users[mid].getId() < id) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}