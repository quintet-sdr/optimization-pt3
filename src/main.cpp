#include "headers/matrix.hpp"
#include "headers/north_west.hpp"
#include "headers/vogel.hpp"
#include "headers/russel.hpp"
#include "headers/parser.hpp"

using namespace std;

int main() {
    JsonParser parser;
    vector<string> json_files = {
        "tests/Test-1.json",
        "tests/Test-2.json",
        "tests/Test-3.json"
    };
     for (const string& file : json_files) {
        cout << "Processing: " << file << endl;
        string json_data = parser.read_json_file(file);
        vector<int> supply = parser.parse_supply(json_data);
        vector<int> demand = parser.parse_demand(json_data);
        vector<vector<int>> costs = parser.parse_costs(json_data);
        TransportMatrix tm(supply, costs, demand);
        if (!tm.check_the_balance(tm)) {
            continue;
        }
        TransportMatrix vogel_matrix = tm;
        TransportMatrix russel_matrix = tm;
        TransportMatrix north_west_matrix = tm;
        north_west(north_west_matrix);
        vogel(vogel_matrix);
        russel(russel_matrix);
    }
    return 0;
}
