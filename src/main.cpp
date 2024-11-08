#include "headers/matrix.hpp"
#include "headers/vogel.hpp"

using namespace std;

int main() {
    vector<int> s = {1, 2, 3};
    vector<int> d = {3, 2, 1};
    vector<vector<int>> c = {
        {1, 2, 3},
        {1, 2, 3},
        {1, 2, 3}
    };

    TransportMatrix tm(s, c, d);
    cout << tm;
    vogel(tm);
    return 0;
}