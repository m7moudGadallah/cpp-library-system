#include "../include/user.hpp"

#include <sstream>

int User::idSequence = 0;

User::User(std::string name) : id(User::idSequence++), name(name) {}

User::User() : User("") {}

int User::getId() const { return this->id; }

std::string User::getName() const { return this->name; }

void User::setName(std::string name) { this->name = name; }

std::string User::toString() const {
    std::stringstream ss;

    ss << "{id: " << this->id << ", name: " << this->name << "}";

    return ss.str();
}

std::vector<std::string> User::serialize() const {
    std::vector<std::string> tokens;
    tokens.push_back(std::to_string(this->id));
    tokens.push_back(this->name);

    return tokens;
}

void User::deserialize(const std::vector<std::string> &tokens) {
    if (tokens.size() != 2) {
        throw std::invalid_argument("Invalid number of tokens");
    }

    this->id = std::stoi(tokens[0]);
    this->name = tokens[1];

    User::idSequence = this->id + 1;
}