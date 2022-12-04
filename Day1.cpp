#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>


int main() {
    // read a text file
    std::ifstream file(
            "C:\\Users\\enzoc\\OneDrive - Griffith College\\Dev\\workspaces\\CLionProjects\\AdventOfCode2022\\input.txt");

    //split the file when blank line is found
    std::string str{};
    std::vector<int> calories{};

#pragma unroll
    while (std::getline(file, str)) {
        if (str.empty()) {
            calories.push_back(-1);
        } else {
            std::istringstream iss(str);
            int cal = 0;
            iss >> cal;
            calories.push_back(cal);
        }
    }

    // Use std::transform to compute the sum of each group of calories
    std::vector<int> elves;
    std::transform(calories.begin(), calories.end(), std::back_inserter(elves),
                   [](int x) {
                       static int sum = 0;
                       if (x == -1) {
                           sum = 0;
                       } else {
                           sum += x;
                       }
                       return sum;
                   }
    );

    // PART 1
    int max_sum = *std::max_element(elves.begin(), elves.end());

    //PART 2
    std::sort(elves.begin(), elves.end(), std::greater<>());
    return elves[0] + elves[1] + elves[2];
}