#include <string>
#include <map>
#include <unordered_map>

#include "key_map.cpp"
#include "value_map.cpp"
#include "seed.hpp"

PlayerDataParser::PlayerDataParser() {}

PlayerData PlayerDataParser::parse(std::map<std::string, std::string> map) {
  PlayerData player_data = PlayerData();
  player_data.name = map[K_NAME];
  player_data.email = map[K_EMAIL];
  player_data.perceived_skill = stoi(map[K_HOW_GOOD_YOU], nullptr);
  player_data.outward_skill = stoi(map[K_HOW_GOOD_OTHERS], nullptr);
  player_data.frequency = this->parse_frequency(map[K_HOW_REGULAR]);
  player_data.has_played_organized_tt = (bool) stoi(map[K_TT_ORGANIZED], nullptr);
  player_data.has_played_organized_lt = (bool) stoi(map[K_LT_ORGANIZED], nullptr);
  player_data.spin_ability = stoi(map[K_SPIN_ABILITY], nullptr);
  player_data.owns_equipment = stoi(map[K_OWN_EQUIPMENT], nullptr);
  return player_data;
}


PlayFrequency PlayerDataParser::parse_frequency(std::string s) {
    std::unordered_map<std::string, PlayFrequency> map ({
        {V_FREQ_EVERY_YEAR, PlayFrequency::EVERY_YEAR },
        {V_FREQ_EVERY_SIX_MONTHS, PlayFrequency::EVERY_SIX_MONTHS},
        {V_FREQ_EVERY_FOUR_MONTHS, PlayFrequency::EVERY_FOUR_MONTHS},
        {V_FREQ_EVERY_TWO_MONTHS, PlayFrequency::EVERY_TWO_MONTHS},
        {V_FREQ_MONTHLY, PlayFrequency::MONTHLY},
        {V_FREQ_WEEKLY, PlayFrequency::WEEKLY},
        {V_FREQ_TWICE_WEEKLY, PlayFrequency::TWICE_WEEKLY},
        {V_FREQ_DAILY, PlayFrequency::DAILY}
    });

    return map[s];
}
