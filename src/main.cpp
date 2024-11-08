#include "headers/matrix.hpp"
#include "headers/north_west.hpp"
#include "headers/vogel.hpp"
#include <limits>
#include <cmath>

#include <algorithm>

using namespace std;

pair<int, int> findMaxAbsValuePosition(vector<vector<int>>& matrix) {
  int maxAbsValue = numeric_limits<int>::min();
  pair<int, int> maxPosition = {-1, -1};

  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix[i].size(); ++j) {
      int value = matrix[i][j];
      if (abs(value) > abs(maxAbsValue)) {
        maxAbsValue = value;
        maxPosition = {i, j};
      }
    }
  }

  return maxPosition;
}


void russel(TransportMatrix& tm) {
  vector<pair<int, int>> peaked, answer;
  int r = tm.costs.size(), c = tm.costs[0].size();
  while (peaked.size() != tm.costs.size() * tm.costs[0].size()) {
    vector<int> colMax, rowMax;
    for (int i = 0; i < tm.costs[0].size(); i++) {
      int maximum = numeric_limits<int>::min();
      for (int j = 0; j < tm.costs.size(); j++) {
        if (maximum < tm.costs[j][i] && find(peaked.begin(), peaked.end(), make_pair(i, j)) == peaked.end()) {
          maximum = tm.costs[j][i];
        }
      }
      colMax.push_back(maximum);
    }

    for (int i = 0; i < tm.costs.size(); i++) {
      int maximum = numeric_limits<int>::min();

      for (int j = 0; j < tm.costs[i].size(); j++) {
        if (tm.costs[i][j] > maximum && find(peaked.begin(), peaked.end(), make_pair(i, j)) == peaked.end()) {
          maximum = tm.costs[i][j];
        }
      }
      rowMax.push_back(maximum);
    }

    vector<vector<int>> temporary(r, vector<int>(c));
    for (int i = 0; i < tm.costs.size(); i++) {
      for (int j = 0; j < tm.costs[i].size(); j++) {
        if (find(peaked.begin(), peaked.end(), make_pair(i, j)) == peaked.end()) {
          temporary[i][j] = tm.costs[i][j] - colMax[j] - rowMax[i];
        }
      }
    }

    pair<int, int> minVal = findMaxAbsValuePosition(temporary);
    int i = minVal.first, j = minVal.second;
    int cell = tm.costs[i][j];
    int supply = tm.supply[i], demand = tm.demand[j];
    int minimum = min(supply, demand);
    tm.demand[j] -= minimum;
    tm.supply[i] -= minimum;
    answer.emplace_back(cell, minimum);
    if (minimum == supply) {
      for (int k = 0; k < tm.costs[i].size(); k++) {
        peaked.emplace_back(i, k);
      }
      r--;
    } else {
      for (int k = 0; k < tm.costs.size(); k++) {
        peaked.emplace_back(k, j);
      }
      c--;
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
//    vogel(tm);
//    north_west(tm);
    russel(tm);
    return 0;
}