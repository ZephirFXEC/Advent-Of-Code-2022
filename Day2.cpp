#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <sstream>


namespace std {

    template <typename T, typename U>
    struct [[maybe_unused]] hash<pair<T, U>> {
        size_t operator()(const pair<T, U> &p) const {
            size_t const h1 = hash<T>()(p.first);
            size_t const h2 = hash<U>()(p.second);
            return h1 ^ h2;
        }
    };

}  // namespace std


int main() {


    // read a text file
    std::ifstream file(
            R"(C:\Users\enzoc\OneDrive - Griffith College\Dev\workspaces\CLionProjects\AdventOfCode2022\input.txt)");

    // Create a map of string pairs to count values.
    std::unordered_map<std::pair<std::string, std::string>, size_t> count_map = {
            {{ "A", "X" }, 4 },
            {{ "A", "Y" }, 8 },
            {{ "A", "Z" }, 3 },
            {{ "B", "X" }, 1 },
            {{ "B", "Y" }, 5 },
            {{ "B", "Z" }, 9 },
            {{ "C", "X" }, 7 },
            {{ "C", "Y" }, 2 },
            {{ "C", "Z" }, 6 },
    };

    //split the file when blank line is found
    std::string str{};
    std::vector<std::pair<std::string, std::string>> pair{};

    while (std::getline(file, str)) {
        //each line contains two letters separated by a space
        std::istringstream iss(str);
        std::string a;
        std::string b;
        iss >> a >> b;
        pair.emplace_back(a, b);
    }

    // Initialize the count vector with 0s.
    std::vector<size_t> count(pair.size(), 0);

    // Iterate over the pairs and update the count vector.
    for (size_t i = 0; i < pair.size(); ++i) {
        count[i] = count_map[pair[i]];
    }

    // Return the sum of the count vector.
    return std::accumulate(count.begin(), count.end(), 0);
}