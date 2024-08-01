#include "../include/string-utitlity.hpp"

std::string StringUtility::tolower(const std::string &str) {
    std::string newStr = str;

    for (auto &ch : newStr) {
        ch = std::tolower(ch);
    }

    return newStr;
}

std::vector<std::string> StringUtility::split(const std::string &buffer,
                                              std::string delimiter) {
    std::vector<std::string> tokens;
    size_t cursor = 0;
    size_t delimiter_pos = 0;

    while (cursor < buffer.size() and
           (delimiter_pos = buffer.find(delimiter, cursor)) !=
               std::string::npos) {
        tokens.emplace_back(buffer.substr(cursor, delimiter_pos - cursor));
        cursor = delimiter_pos + delimiter.size();
    }

    if (cursor < buffer.size()) {
        tokens.emplace_back(buffer.substr(cursor));
    }

    return tokens;
}

std::string StringUtility::join(const std::vector<std::string> &tokens,
                                std::string delimiter) {
    std::string buffer = "";

    size_t idx = 0;

    while (idx < tokens.size()) {
        if (idx)
            buffer += delimiter;
        buffer += tokens[idx++];
    }

    return buffer;
}