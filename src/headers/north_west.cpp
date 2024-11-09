#include "north_west.hpp"
#include <algorithm>

using namespace std;

void north_west(TransportMatrix& tm) {
  cout << endl << string(tm.costs[0].size() * 6 + 40, '-') << endl;
  cout << "The North-West corner method" << endl;
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
          for (int k = j; k < tm.costs[i].size(); k++) {
            peaked.emplace_back(i, k);
          }
        } else {
          for (int k = i; k < tm.costs.size(); k++) {
            peaked.emplace_back(k, j);
          }
        }
      }
    }
  }
  int x0 = 0;
  for (int i = 0; i < answer.size(); i++) {
    x0 += answer[i].first * answer[i].second;
  }
  cout << "Answer: x0 = " << x0 << endl;
  cout << string(tm.costs[0].size() * 6 + 40, '-') << endl;
}