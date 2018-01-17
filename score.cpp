#include <unordered_map>

#include "score.hpp"


const unsigned int WEIGHT_PERCEIVED_SKILL = 2;
const unsigned int WEIGHT_OUTWARD_SKILL = 3;
const unsigned int WEIGHT_FREQUENCY = 4;
const unsigned int WEIGHT_HAS_PLAYED_ORGANIZED_TT = 5;
const unsigned int WEIGHT_HAS_PLAYED_ORGANIZED_LT = 5;
const unsigned int WEIGHT_SPIN_ABILITY = 4;
const unsigned int WEIGHT_OWNS_EQUIPMENT = 5;


unsigned int PlayerScorer::score(PlayerData player) {
    unsigned int score = 0;

    score += player.perceived_skill * WEIGHT_PERCEIVED_SKILL;
    score += player.outward_skill * WEIGHT_OUTWARD_SKILL;
    score += static_cast<int>(player.frequency) * WEIGHT_FREQUENCY;
    score += player.has_played_organized_tt * WEIGHT_HAS_PLAYED_ORGANIZED_TT;
    score += player.has_played_organized_lt * WEIGHT_HAS_PLAYED_ORGANIZED_LT;
    score += player.spin_ability * WEIGHT_SPIN_ABILITY;
    score += player.owns_equipment * WEIGHT_OWNS_EQUIPMENT;

    return score;
}
