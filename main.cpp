#include <iostream>
#include <map>
#include <vector>
#include "read.hpp"
#include "seed.hpp"

int main() {
    std::vector<std::map <std::string, std::string> > data;
    PlayerDataParser parser = PlayerDataParser();

    try {
        CsvReader reader = CsvReader("data.csv");
        data = reader.read();
        reader.read( [&parser](std::map<std::string, std::string> row) {
            std::cout << row.at("What is your name?") << std::endl;
            parser.parse(row);
        });
    } catch(const char* e) {
        std::cout << e << std::endl;
    }

    std::cout << "============================BREAK=============================" << std::endl;

    for(int i = 0; i < data.size(); i += 1) {
        std::cout << data.at(i).at("What is your name?") << std::endl;
    }

    return 0;
}
