#include "headers/matrix.hpp"
#include "headers/north_west.hpp"

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
    cout << tm;
//    vogel(tm);
    north_west(tm);
    return 0;
}