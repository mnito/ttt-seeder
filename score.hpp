#include "parse.hpp"


class PlayerScore {
    public:
        PlayerData player;
        double score;
        bool operator <  (const PlayerScore& ps) const {
            return score < ps.score;
        }
        bool operator > (const PlayerScore& ps) const {
            return score > ps.score;
        }
};

class PlayerScorer {
    public:
        unsigned int score(PlayerData player);
};
