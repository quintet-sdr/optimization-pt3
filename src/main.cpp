#include "headers/matrix.hpp"
#include "headers/north_west.hpp"
#include "headers/vogel.hpp"

using namespace std;


int main() {
    vector<int> s = {160, 140, 170};
    vector<int> d = {120, 50, 190, 110};
    vector<vector<int>> c = {
        {7, 8, 1, 2},
        {4, 5, 9, 8},
        {9, 2, 3, 6}
    };
    TransportMatrix tm(s, c, d);
    TransportMatrix north_west_matrix = tm;
    TransportMatrix vogel_matrix = tm;
    TransportMatrix russel_matrix = tm;
    cout << tm;
    vogel(vogel_matrix);
    north_west(north_west_matrix);
    return 0;
}