#include <utility>
#include <iomanip>
#include "matrix.hpp"

using namespace std;

TransportMatrix::TransportMatrix() : supply(0), demand(0), costs(0) {};

TransportMatrix::TransportMatrix(const vector<int>& S, vector<vector<int>> C, const vector<int>& D) : supply(S), demand(D), costs(std::move(C)) {}

bool TransportMatrix::check_the_balance(const TransportMatrix& tm) {
  int sum_S = 0, sum_D = 0;
        for (int i : tm.supply) {
            sum_S += i;
        }
        for (int i : tm.demand) {
            sum_D += i;
        }
        if (sum_S != sum_D) {
            cout << "The problem is not balanced" << endl;
            return false;
        }
        return true;
}

ostream& operator<< (ostream& out, TransportMatrix& tm) {
    out << left << setw(15) << "SOURCE";

    out << left << setw(6 * tm.costs[0].size()) << "COST";

    out << left << setw(8) << "SUPPLY" << endl;

    out << string(tm.costs[0].size() * 6 + 28, '-') << endl;

    int source_i = 1;
    for (int i = 0; i < tm.costs.size(); i++) {
      out << left << setw(10) << "A" + to_string(source_i++);
      for (int j : tm.costs[i]) {
        out << right << setw(6) << j;
      }
      out << right << setw(6) << tm.supply[i] << endl;
    }

    out << string(tm.costs[0].size() * 6 + 28, '-') << endl;

    out << left << setw(10) << "DEMAND";
    for (int i : tm.demand) {
      out << right << setw(6) << i;
    }
    out << endl;
//    out << left << setw(8) << endl;

    return out;
}



