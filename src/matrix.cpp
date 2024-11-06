#include <iostream>
#include <vector>

using namespace std;

class TransportMatrix {
private:
    vector<int> supply;
    vector<int> demand;
    vector<vector<int>> costs;

public:
    TransportMatrix() {};

    TransportMatrix(vector<int> S, vector<vector<int>> C, vector<int> D) {
        int sum_S = 0, sum_D = 0;
        for (int i = 0; i < S.size(); i++) {
            sum_S += S[i];
        }
        for (int i = 0; i < D.size(); i++) {
            sum_D += D[i];
        }

        if (sum_S != sum_D) {
            cout << "The problem is not balanced" << endl;
            exit(-1);
        }

        this->supply = S;
        this->costs = C;
        this->demand = D;
    }
};

int main() {
    vector<int> s = {1, 2, 3};
    vector<int> d = {3, 3, 1};
    vector<vector<int>> c = {
        {1, 2, 3},
        {1, 2, 3},
        {1, 2, 3}
    };

    TransportMatrix tm = TransportMatrix(s, c, d);
}