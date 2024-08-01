#ifndef SERIALIZABLE_HPP_
#define SERIALIZABLE_HPP_

#include <string>
#include <vector>

class Serializable {
  public:
    virtual std::vector<std::string> serialize() const = 0;
    virtual void deserialize(const std::vector<std::string> &tokens) = 0;
};

#endif // SERIALIZABLE_HPP_