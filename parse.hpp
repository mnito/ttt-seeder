#include <string>
#include <map>


enum class PlayFrequency { EVERY_YEAR, EVERY_SIX_MONTHS, EVERY_FOUR_MONTHS, EVERY_TWO_MONTHS, MONTHLY, WEEKLY, TWICE_WEEKLY, DAILY };

class PlayerData {
    public:
        std::string name;
        std::string email;
        int perceived_skill;
        int outward_skill;
        PlayFrequency frequency;
        bool has_played_organized_tt;
        bool has_played_organized_lt;
        int spin_ability;
        bool owns_equipment;
};

class PlayerDataParser {
    public:
        PlayerData parse(std::map<std::string, std::string> map);
    private:
        PlayFrequency parse_frequency(std::string s);
};
