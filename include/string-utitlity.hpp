#ifndef STRING_UTILITY_HPP_
#define STRING_UTILITY_HPP_

#include <string>
#include <vector>

class StringUtility {
  public:
    static std::vector<std::string> split(const std::string &buffer,
                                          std::string delimiter);
    static std::string join(const std::vector<std::string> &tokens,
                            std::string delimiter);
};

#endif // STRING_UTILITY_HPP_