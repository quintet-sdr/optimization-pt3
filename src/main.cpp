#include "headers/matrix.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    vector<int> s = {1, 2, 3};
    vector<int> d = {3, 2, 1};
    vector<vector<int>> c = {
        {1, 2, 3},
        {1, 2, 3},
        {1, 2, 3}
    };

    MATRIX_H::TransportMatrix tm(s, c, d);
    cout << tm;
}