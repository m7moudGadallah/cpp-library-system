#ifndef BOOK_HPP_
#define BOOK_HPP_

#include "serializable.hpp"
#include <string>

class Book : public Serializable {
  private:
    static int idSequence;
    int id;
    std::string name;
    int quantity;
    int borrowed;

  public:
    Book(std::string name, int quantity);
    Book();
    int getId() const;
    std::string getName() const;
    int getQuantity() const;
    int getBorrowed() const;
    int getAvailable() const;
    void setName(std::string name);
    void setQuantity(int quantity);
    void setBorrowed(int borrowed);
    std::string toString() const;
    bool isEqual(const Book &book) const;
    std::vector<std::string> serialize() const override;
    void deserialize(const std::vector<std::string> &tokens) override;
};

#endif // BOOK_HPP_