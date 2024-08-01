#include "../include/file-handler.hpp"
#include "../include/global.hpp"
#include "../include/string-utitlity.hpp"

#include <fstream>

std::vector<std::vector<std::string>>
FileHandler::readFromFile(std::string filepath, bool hasHeader) {
    std::vector<std::vector<std::string>> lines;
    std::ifstream fin(filepath);

    if (fin.fail()) {
        throw std::runtime_error("File not found");
    }

    std::string buffer;

    if (hasHeader) {
        getline(fin, buffer);
    }

    while (getline(fin, buffer)) {
        if (buffer.empty())
            continue;
        lines.push_back(StringUtility::split(buffer, FILE_DELIMITER));
    }

    fin.close();

    return lines;
}

void FileHandler::writeToFile(
    std::string filepath, const std::vector<std::vector<std::string>> &lines,
    const std::vector<std::string> fileheader) {
    std::ofstream fout(filepath);

    if (fout.fail()) {
        throw std::runtime_error("File not found");
    }

    std::string buffer = "";
    fout << StringUtility::join(fileheader, FILE_DELIMITER) << "\n\n";

    for (const auto &line : lines) {
        fout << StringUtility::join(line, FILE_DELIMITER) << "\n";
    }

    fout.close();
}