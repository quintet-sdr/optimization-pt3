#include "parser.hpp"

vector<int> JsonParser::parse_supply(const string& json) {
    vector<int> result;
    istringstream ss(json);
    string key;
    char ch;
    while (ss >> ch) {
        if (ch == '"') {
            getline(ss, key, '"'); 
            if (key == "supply") {
                ss >> ch;
                ss >> ch; 
                while (ss >> ch) {
                    if (ch == ']') {
                        break; 
                    }
                    ss.putback(ch); 
                    int value;
                    ss >> value;
                    result.push_back(value); 
                    ss >> ch; 
                    if (ch == ']') {
                        break;
                    } else if (ch != ',') {
                        break; 
                    }
                }
                break; 
            }
        }
    }
    return result;
}
vector<int> JsonParser::parse_demand(const string& json) {
    vector<int> result;
    istringstream ss(json);
    string key;
    char ch;
    while (ss >> ch) {
        if (ch == '"') {
            getline(ss, key, '"'); 
            if (key == "demand") {
                ss >> ch;
                ss >> ch; 
                while (ss >> ch) {
                    if (ch == ']') {
                        break; 
                    }
                    ss.putback(ch); 
                    int value;
                    ss >> value;
                    result.push_back(value); 
                    ss >> ch; 
                    if (ch == ']') {
                        break;
                    } else if (ch != ',') {
                        break; 
                    }
                }
                break; 
            }
        }
    }
    return result;

}

vector<vector<int>> JsonParser::parse_costs(const string& json) {
    vector<vector<int>> result;
    vector<int> currentVector;
    istringstream ss(json);
    string key;
    char ch;
    while (ss >> ch) {
        if (ch == '"') {
            getline(ss, key, '"');
            if (key == "costs") {
                ss >> ch; 
                ss >> ch; 
                while (ss >> ch) {
                    if (ch == '[') {
                        currentVector.clear();
                    } else if (ch == ']') {
                        if (!currentVector.empty()) {
                            result.push_back(currentVector); 
                            currentVector.clear(); 
                        }
                    } else if (isdigit(ch) || ch == '-') { 
                        ss.putback(ch);
                        int value;
                        ss >> value;
                        currentVector.push_back(value);
                    } else if (ch == ',') {
                        continue;
                    }
                }
                break; 
            }
        }
    }

    return result;
}
