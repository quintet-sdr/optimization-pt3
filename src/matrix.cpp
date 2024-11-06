#include <iostream>
#include <vector>
#include <string>
#include "headers/matrix.h"
#include "headers/methods.h"

using namespace std;

class TransportMatrix {
public:
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


    friend ostream& operator<< (ostream& out, const TransportMatrix& tm) {
        cout << "SOURCE     COSTS     SUPPLY" << endl;
        int source_i = 1;
        for (int i = 0; i < tm.costs.size(); i++) {
            string row = "";
            for (int j = 0; j < tm.costs[i].size(); j++) {
                row += tm.costs[i][j] + " |";
            }
            cout << source_i++ << " " << row << " " << tm.supply[i] << endl;
        }
        // cout << "------" << tm.costs.size() * "-" << "------" << endl;
        string demand = "";
        for (int i = 0; i < tm.demand.size(); i++) {
            demand += tm.demand[i] + " ";
        }
        cout << "DEMAND | " + demand + "| ";
        return out;
    }
};

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