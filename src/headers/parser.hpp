#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <stdexcept>
#include <fstream>
using namespace std;
class JsonParser {
public:
    string read_json_file(const string& filePath);
    static vector<int> parse_supply(const string& json);
    static vector<int> parse_demand(const string& json);
    static vector<vector<int>> parse_costs(const string& json);
};
#endif