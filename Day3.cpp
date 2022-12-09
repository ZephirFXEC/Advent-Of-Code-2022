//
// Created by enzoc on 05/12/2022.
//

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <sstream>

auto main() noexcept -> int {

    // read a text file
    std::ifstream file(
            R"(C:\Users\enzoc\OneDrive - Griffith College\Dev\workspaces\CLionProjects\AdventOfCode2022\input.txt)");


    //split the file at every line
    std::vector<std::string> lines{};
    for (std::string line; std::getline(file, line);) {
        lines.emplace_back(line);
    }

    std::vector<std::string> lhs;
    std::vector<std::string> rhs;
    for (auto &line : lines) {
        //split the line in the middle;
        const uint64_t middle = line.size() / 2;
        std::string const first = line.substr(0, line.size() / 2);
        std::string const second = line.substr(middle, line.size() - middle);
        lhs.emplace_back(first);
        rhs.emplace_back(second);
    }


    std::vector<char> common{};

    for(uint64_t i = 0; i < lines.size(); ++i) {
        for(uint64_t j = 0; j < lhs[i].size(); ++j) {
            for(uint64_t k = 0; k < rhs[i].size(); ++k) {
                if(lhs[i][j] == rhs[i][k]) {
                    common.emplace_back(lhs[i][j]);
                    goto beg;
                }
            }
        }
        beg:;
    }


    // Sum

    uint64_t sum = 0;
    for(auto &c : common) {
        if(std::islower(c) != 0) {
            sum += c - 'a' + 1;
        } else {
            sum += c - 'A' + 27;
        }
    }

    std::cout << sum << std::endl; // Part 1 answer
}