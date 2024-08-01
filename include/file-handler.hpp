#ifndef FILE_HANDLER_HPP_
#define FILE_HANDLER_HPP_

#include <string>
#include <vector>

class FileHandler {
  public:
    static std::vector<std::vector<std::string>> readFromFile(std::string filepath,
                            bool hasHeader);
    static void writeToFile(std::string filepath,
                           const std::vector<std::vector<std::string>> &tokens,
                           const std::vector<std::string> fileheader);
};

#endif // FILE_HANDLER_HPP_