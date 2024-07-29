#include <iostream>
#include <vector>

int main(void) {
    std::vector<int> vec;

    vec.emplace_back(20);
    vec.emplace_back(30);
    vec.emplace_back(10);
    vec.emplace_back(40);

    for (const auto &val : vec) {
        std::cout << val << ' ';
    }
    std::cout << '\n';

    return 0;
}