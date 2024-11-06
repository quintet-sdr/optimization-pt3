#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <iomanip>
//#include "matrix.h"
#include "methods.h"

using namespace std;

class TransportMatrix {
public:
    vector<int> supply;
    vector<int> demand;
    vector<vector<int>> costs;

public:
    TransportMatrix() = default;

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
        this->costs = std::move(C);
        this->demand = D;
    }


  friend ostream& operator<< (ostream& out, const TransportMatrix& tm) {
    // Заголовок таблицы
    cout << left << setw(15) << "SOURCE";
    cout << left << setw(6 * tm.costs[0].size()) << "COST";
//    for (int i = 0; i < tm.costs[0].size(); i++) {
//    }
    cout << left << setw(8) << "SUPPLY" << endl;

    // Разделитель
    cout << string(tm.costs[0].size() * 6 + 28, '-') << endl;

    // Вывод строк таблицы
    int source_i = 1;
    for (int i = 0; i < tm.costs.size(); i++) {
      cout << left << setw(10) << source_i++;
      for (int j = 0; j < tm.costs[i].size(); j++) {
        cout << right << setw(6) << tm.costs[i][j];
      }
      cout << right << setw(6) << tm.supply[i] << endl;
    }

    // Разделитель
    cout << string(tm.costs[0].size() * 6 + 28, '-') << endl;

    // Вывод строки DEMAND
    cout << left << setw(10) << "DEMAND";
    for (int i = 0; i < tm.demand.size(); i++) {
      cout << right << setw(6) << tm.demand[i];
    }
    cout << left << setw(8) << endl;

    return out;
  }

};

int main() {
    vector<int> s = {3, 2, 1};
    vector<int> d = {1, 2, 1, 1, 1};
    vector<vector<int>> c = {
        {1, 2, 3, 4, 4},
        {1, 6, 7, 5, 5},
        {4, 7, 8, 6, 7}
    };

    TransportMatrix tm = TransportMatrix(s, c, d);
    cout << tm;
}