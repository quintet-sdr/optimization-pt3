#include "vogel.hpp"
#include <algorithm>
using namespace std;

pair<vector<int>, vector<int>> findDiff(TransportMatrix& tm) {
    vector<int> row_diff;
    vector<int> col_diff;
    int rows = tm.costs.size();
    int cols = tm.costs[0].size();
    for (int i = 0; i < rows; i++) {
        vector<int> arr = tm.costs[i];
        sort(arr.begin(), arr.end());
        row_diff.push_back(arr[1] - arr[0]);
    }
    for(int i = 0; i < cols; i++) {
        vector<int> temp;
        for (int j = 0; j < rows; j++) {
            temp.push_back(tm.costs[j][i]);
        }
        sort(temp.begin(), temp.end());
        col_diff.push_back(temp[1] - temp[0]);
    }

    return make_pair(row_diff, col_diff);
}

void vogel(TransportMatrix& tm) {
    cout << endl << string(tm.costs[0].size() * 6 + 40, '-') << endl;
    cout << "The Vogel Approximation method:" << endl;
    cout << string(tm.costs[0].size() * 6 + 40, '-') << endl;
    int rows = tm.costs.size();
    int cols = tm.costs[0].size();
    int solution = 0;
    while (*max_element(tm.supply.begin(), tm.supply.end()) != 0 || *max_element(tm.demand.begin(), tm.demand.end()) != 0) {
        pair<vector<int>, vector<int>> diffs = findDiff(tm);
        int max_in_rows = *max_element(diffs.first.begin(), diffs.first.end());
        int max_in_columns = *max_element(diffs.second.begin(), diffs.second.end());
        if (max_in_rows >= max_in_columns) {
            for (int i = 0; i < diffs.first.size(); i++) {
                if (diffs.first[i] == max_in_rows) {
                    int min_in_rows = *min_element(tm.costs[i].begin(), tm.costs[i].end());
                    for (int j = 0; j < tm.costs[i].size(); j++) {
                        if (tm.costs[i][j] == min_in_rows) {
                            int min_between_supply_and_demand = min(tm.supply[i], tm.demand[j]);
                            solution += min_between_supply_and_demand * min_in_rows;
                            tm.supply[i] -= min_between_supply_and_demand;
                            tm.demand[j] -= min_between_supply_and_demand;
                            if (tm.demand[j] == 0) {
                                for (int r = 0; r < rows; r++) {
                                    tm.costs[r][j] = 1000;
                                }
                            } else {
                                fill(tm.costs[i].begin(), tm.costs[i].end(), 1000);
                            }
                            break;
                        }
                    }
                    break;
                }
            }
        } else {
            for (int i = 0; i < diffs.second.size(); i++) {
                if (diffs.second[i] == max_in_columns) {
                    int min_in_columns = 1000;
                    for (int j = 0; j < rows; j++) {
                        min_in_columns = min(min_in_columns, tm.costs[j][i]);
                    }
                    for (int c = 0; c < rows; c++) {
                        if (tm.costs[c][i] == min_in_columns) {
                            int min_between_supply_and_demand = min(tm.supply[c], tm.demand[i]);
                            solution += min_between_supply_and_demand * min_in_columns;
                            tm.supply[c] -= min_between_supply_and_demand;
                            tm.demand[i] -= min_between_supply_and_demand;
                            if (tm.demand[i] == 0) {
                                for (int r = 0; r < rows; r++) {
                                    tm.costs[r][i] = 1000;
                                }
                            } else {
                                fill(tm.costs[c].begin(), tm.costs[c].end(), 1000);
                            }
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }
    cout << "Answer: x0 = " << solution << endl;
}



