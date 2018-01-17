#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>

#include "read.hpp"
#include "score.hpp"


int main() {
    std::vector<std::map <std::string, std::string> > data;
    PlayerDataParser parser = PlayerDataParser();
    PlayerScorer scorer = PlayerScorer();
    std::vector<PlayerScore> playerscores;

    try {
        CsvReader reader = CsvReader("data.csv");
        data = reader.read();
        reader.read( [&parser, &scorer, &playerscores](std::map<std::string, std::string> row) {
            PlayerData player = parser.parse(row);
            unsigned int score = scorer.score(player);
            PlayerScore ps = PlayerScore();
            ps.player = player;
            ps.score = score;
            playerscores.push_back(ps);
        });
    } catch(const char* e) {
        std::cout << e << std::endl;
    }

    std::sort(playerscores.begin(), playerscores.end(), std::greater<PlayerScore>());

    for(unsigned int i = 0; i < playerscores.size(); i += 1) {
        PlayerScore ps = playerscores[i];
        std::cout << (i + 1) << ". " << ps.player.name << " (" << ps.score << ")" << std::endl;
    }

    return 0;
}
