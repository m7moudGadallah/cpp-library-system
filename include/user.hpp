#ifndef USER_HPP_
#define USER_HPP_

#include "serializable.hpp"
#include <string>

class User : public Serializable {
  private:
    static int idSequence;
    int id;
    std::string name;

  public:
    User(std::string name);
    User();
    int getId() const;
    std::string getName() const;
    void setName(std::string name);
    std::string toString() const;
    std::vector<std::string> serialize() const override;
    void deserialize(const std::vector<std::string> &tokens) override;
};

#endif // USER_HPP_