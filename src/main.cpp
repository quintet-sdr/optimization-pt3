#include "headers/matrix.hpp"
#include <algorithm>


using namespace std;

void north_west(TransportMatrix& tm) {
  cout << endl << string(tm.costs[0].size() * 6 + 40, '-') << endl;
  cout << "The North-West corner method" << endl;
  cout << string(tm.costs[0].size() * 6 + 40, '-') << endl;
  vector<pair<int, int>> peaked, answer;
  for (int i = 0; i < tm.costs.size(); i++) {
    for (int j = 0; j < tm.costs[0].size(); j++) {
      if (find(peaked.begin(), peaked.end(), make_pair(i, j)) == peaked.end()) {
        int cell = tm.costs[i][j];
        int supply = tm.supply[i], demand = tm.demand[j];

        int minimum = min(supply, demand);
        tm.demand[j] -= minimum;
        tm.supply[i] -= minimum;
        answer.emplace_back(cell, minimum);
        if (minimum == supply) {
          cout << "min=supply removed ";
          for (int k = j; k < tm.costs[i].size(); k++) {
            peaked.emplace_back(i, k);
            cout << tm.costs[i][k] << " ";
          }
          cout << endl;
        } else {
          cout << "min=demand removed ";
          for (int k = i; k < tm.costs.size(); k++) {
            peaked.emplace_back(k, j);
            cout << tm.costs[k][j] << " ";
          }
          cout << endl;
        }
      }
    }
  }
  int x0 = 0;
  cout << string(tm.costs[0].size() * 6 + 40, '-') << endl;
  for (int i = 0; i < answer.size(); i++) {
    x0 += answer[i].first * answer[i].second;
    cout << answer[i].first << " * " << answer[i].second;
    if (i != answer.size() - 1) {
      cout << " + ";
    } else {
      cout << " = ";
    }
  }
  cout << x0;
  cout << endl;
  cout << string(tm.costs[0].size() * 6 + 40, '-') << endl;
  cout << "Answer: x0 = " << x0 << endl;
  cout << string(tm.costs[0].size() * 6 + 40, '-') << endl;
}


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
    north_west(tm);
    return 0;
}