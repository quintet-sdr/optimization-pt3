#include "headers/matrix.hpp"
#include "headers/north_west.hpp"
#include "headers/vogel.hpp"
#include "headers/parser.hpp"

using namespace std;

int main() {
    ifstream inputFile("data.json");
    stringstream buffer;
    buffer << inputFile.rdbuf(); 
    string jsonContent = buffer.str(); 
    JsonParser parser;
    vector<int> supply = parser.parse_supply(jsonContent);
    vector<int> demand = parser.parse_demand(jsonContent);
    vector<vector<int>> costs = parser.parse_costs(jsonContent);
    TransportMatrix tm(supply, costs, demand);
    north_west(tm);
    return 0;
}