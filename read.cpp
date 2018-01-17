#include <fstream>
#include <map>
#include <vector>
#include <functional>

#include "read.hpp"

CsvReader::CsvReader(std::string filename) {
    this->filename = filename;
    std::ifstream file;
    file.open(filename, std::ios::in);
    if (!file.good()) {
        throw "File does not exist!";
    }
}

std::vector<std::string> CsvReader::split(
    std::string s,
    std::string delimiter,
    std::string separator
) {
    std::vector<std::string> tokens;
    size_t separatorLength = separator.length();
    size_t delimiterLength = delimiter.length();
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        // Process token
        if ((token.substr(0, separatorLength)) == separator) {
            token.erase(0, separatorLength);
        }
        int lastchar = token.length() - separatorLength;
        if ((token.substr(lastchar, separatorLength)) == separator) {
            token.erase(lastchar, separatorLength);
        }
        tokens.push_back(token);
        s.erase(0, pos + delimiterLength);
    }
    return tokens;
}

void CsvReader::read(std::function<void (std::map<std::string, std::string>)> callback) {
    std::ifstream file;
    file.open(filename);

    std::string line;

    if (!getline(file, line)) {
        throw "Cannot get CSV header!";
    }

    std::vector<std::string> headers = this->split(line, ",", "\"");
    size_t headerscount = headers.size();
    std::vector<std::string> rowdata;
    std::map<std::string, std::string> map;
    while (getline(file, line)) {
        rowdata = this->split(line, ",", "\"");

        unsigned int i = 0;
        while (i < headerscount) {
            map[headers[i]] = rowdata[i];
            i += 1;
        }
        callback(map);
        map.empty();
    }
    file.close();
}

std::vector<std::map <std::string, std::string> > CsvReader::read() {
    std::vector<std::map <std::string, std::string> > data;
    this->read( [&data](std::map<std::string, std::string> row) {
        data.push_back(row);
    });
    return data;
}
