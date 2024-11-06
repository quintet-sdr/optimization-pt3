#include "headers/matrix.h"
using namespace std;
int main() {
    vector<int> s = {1, 2, 3};
    vector<int> d = {3, 2, 1};
    vector<vector<int>> c = {
        {1, 2, 3},
        {1, 2, 3},
        {1, 2, 3}
    };

    TransportMatrix tm = TransportMatrix(s, c, d);
    cout << tm;
}