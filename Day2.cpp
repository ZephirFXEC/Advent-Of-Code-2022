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
    std::unordered_map<std::pair<std::string_view, std::string_view>, size_t> count_map_p1 = {
            {{ "A", "X" }, 4ull },
            {{ "A", "Y" }, 8ull },
            {{ "A", "Z" }, 3ull },
            {{ "B", "X" }, 1ull },
            {{ "B", "Y" }, 5ull },
            {{ "B", "Z" }, 9ull },
            {{ "C", "X" }, 7ull },
            {{ "C", "Y" }, 2ull },
            {{ "C", "Z" }, 6ull },
    };

    //split the file when blank line is found
    std::vector<std::pair<std::string_view, std::string_view>> pair{};

    for (std::string line; std::getline(file, line);) {
        //each line contains two letters separated by a space
        std::istringstream iss(line);
        std::string a;
        std::string b;
        iss >> a >> b;
        pair.emplace_back(a, b);
    }

    // Initialize the count vector with 0s.
    std::vector<size_t> count(pair.size(), 0);

    // Iterate over the pairs and update the count vector.
    for (size_t i = 0; i < pair.size(); ++i) {
        count[i] = count_map_p1[pair[i]];
    }

    // Return the sum of the count vector.
    int sum = std::accumulate(count.begin(), count.end(), 0); // Part 1


    // PART 2
    // Create a map of string pairs to count values.
    std::unordered_map<std::pair<std::string_view, std::string_view>, size_t> count_map_p2 = {
            {{ "A", "X" }, 3ull },
            {{ "A", "Y" }, 4ull },
            {{ "A", "Z" }, 8ull },
            {{ "B", "X" }, 1ull },
            {{ "B", "Y" }, 5ull },
            {{ "B", "Z" }, 9ull },
            {{ "C", "X" }, 2ull },
            {{ "C", "Y" }, 6ull },
            {{ "C", "Z" }, 7ull },
    };

    // Initialize the count vector with 0s.
    std::vector<size_t> count2(pair.size(), 0);

    // Iterate over the pairs and update the count vector.
    for (size_t i = 0; i < pair.size(); ++i) {
        count2[i] = count_map_p2[pair[i]];
    }

    // Return the sum of the count vector.
    return std::accumulate(count2.begin(), count2.end(), 0); // Part 2
}