#include <string>
#include <map>
#include <vector>

class CsvReader {
    private:
        std::string filename;
        std::vector<std::string> split(
            std::string s,
            std::string delimiter,
            std::string separator
        );

    public:
        CsvReader(std::string filename);
        std::vector<std::map <std::string, std::string> > read();
        void read(std::function<void (std::map<std::string, std::string>)> callback);
};
