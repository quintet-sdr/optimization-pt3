#include "russel.hpp"

using namespace std;

struct pair_hash {
  template<class T1, class T2>
  size_t operator()(const pair<T1, T2> &p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ (hash2 << 1);
  }
};

pair<pair<int, int>, int> findMaxAbsValue(const vector<vector<pair<pair<int, int>, int>>> &matrix) {
  pair<pair<int, int>, int> maxElement = {{0, 0}, 0};
  int maxAbsValue = 0;

  for (const auto &row : matrix) {
    for (const auto &element : row) {
      int absValue = abs(element.second);
      if (absValue > maxAbsValue) {
        maxAbsValue = absValue;
        maxElement = element;
      }
    }
  }
  return maxElement;
}

void russel(TransportMatrix &tm) {
  cout << endl << string(tm.costs[0].size() * 6 + 40, '-') << endl;
  cout << "The Russel's Approximation method" << endl;
  unordered_set<pair<int, int>, pair_hash> peaked;
  vector<pair<int, int>> answer;
  int r = tm.costs.size(), c = tm.costs[0].size();
  while (peaked.size() != tm.costs.size() * tm.costs[0].size()) {
    vector<int> colMax, rowMax;
    for (int i = 0; i < tm.costs[0].size(); i++) {
      int maximum = numeric_limits<int>::min();
      for (int j = 0; j < tm.costs.size(); j++) {
        if (maximum < tm.costs[j][i] && peaked.find({j, i}) == peaked.end()) {
          maximum = tm.costs[j][i];
        }
      }
      if (maximum != numeric_limits<int>::min()) {
        colMax.push_back(maximum);
      }
    }

    for (int i = 0; i < tm.costs.size(); i++) {
      int maximum = numeric_limits<int>::min();
      for (int j = 0; j < tm.costs[i].size(); j++) {
        if (tm.costs[i][j] > maximum && peaked.find({i, j}) == peaked.end()) {
          maximum = tm.costs[i][j];
        }
      }
      if (maximum != numeric_limits<int>::min()) {
        rowMax.push_back(maximum);
      }
    }

    vector<vector<pair<pair<int, int>, int>>> temporary(r, vector<pair<pair<int, int>, int>>(c));
    int o = 0;
    for (int i = 0; i < tm.costs.size(); i++) {
      int l = 0;
      bool flag = false;
      for (int j = 0; j < tm.costs[i].size(); j++) {
        if (peaked.find({i, j}) == peaked.end()) {
          temporary[o][l].first = make_pair(i, j);
          temporary[o][l].second = tm.costs[i][j] - colMax[l] - rowMax[o];
          l++;
          flag = true;
        }
      }
      if (flag) {
        o++;
      }
    }

    pair<pair<int, int>, int> minVal = findMaxAbsValue(temporary);
    int i = minVal.first.first, j = minVal.first.second;
    int cell = tm.costs[i][j];
    int supply = tm.supply[i], demand = tm.demand[j];
    int minimum = min(supply, demand);
    tm.demand[j] -= minimum;
    tm.supply[i] -= minimum;
    answer.emplace_back(cell, minimum);
    if (minimum == supply) {
      for (int k = 0; k < tm.costs[i].size(); k++) {
        peaked.emplace(i, k);
      }
      r--;
    } else {
      for (int k = 0; k < tm.costs.size(); k++) {
        peaked.emplace(k, j);
      }
      c--;
    }
  }

  int x0 = 0;
  for (int i = 0; i < answer.size(); i++) {
    x0 += answer[i].first * answer[i].second;
  }
  cout << "Answer: x0 = " << x0 << endl;
  cout << string(tm.costs[0].size() * 6 + 40, '-') << endl;
}
