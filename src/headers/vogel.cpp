#include "vogel.hpp"
#include <algorithm>

using namespace std;

pair<vector<int>, vector<int>> find_row_col_diff(TransportMatrix& tm) {
    vector<int> row_diff;
    vector<int> col_diff;
    int rows = tm.costs.size();
    int cols = tm.costs[0].size();
    for (int i = 0; i < rows; i++) {
        vector<int> arr = tm.costs[i];
        sort(arr.begin(), arr.end());
        row_diff.push_back(arr[1] - arr[0]);
    }
    for (int i = 0; i < cols; i++) {
        vector<int> temp;
        for (int j = 0; j < rows; j++) {
            temp.push_back(tm.costs[j][i]);
        }
        sort(temp.begin(), temp.end());
        col_diff.push_back(temp[1] - temp[0]);
    }

    return make_pair(row_diff, col_diff);
}

int find_min_cost_in_row(TransportMatrix& tm, int row) {
    return *min_element(tm.costs[row].begin(), tm.costs[row].end());
}

int find_min_cost_in_column(TransportMatrix& tm, int col) {
    int min_cost = 1000;
    for (int j = 0; j < tm.costs.size(); j++) {
        min_cost = min(min_cost, tm.costs[j][col]);
    }
    return min_cost;
}

void update_supply_demand(TransportMatrix& tm, int supply_index, int demand_index, int amount, int cost, int& solution) {
    solution += amount * cost;
    tm.supply[supply_index] -= amount;
    tm.demand[demand_index] -= amount;

    if (tm.demand[demand_index] == 0) {
        for (int r = 0; r < tm.costs.size(); r++) {
            tm.costs[r][demand_index] = 1000; 
        }
    } else {
        fill(tm.costs[supply_index].begin(), tm.costs[supply_index].end(), 1000); 
    }
}

void vogel(TransportMatrix& tm) {
    cout << endl << string(tm.costs[0].size() * 6 + 40, '-') << endl;
    cout << "The Vogel Approximation method:" << endl;
    cout << string(tm.costs[0].size() * 6 + 40, '-') << endl;

    int solution = 0;
    while (*max_element(tm.supply.begin(), tm.supply.end()) != 0 || *max_element(tm.demand.begin(), tm.demand.end()) != 0) {
        pair<vector<int>, vector<int>> diffs = find_row_col_diff(tm);
        int max_in_rows = *max_element(diffs.first.begin(), diffs.first.end());
        int max_in_columns = *max_element(diffs.second.begin(), diffs.second.end());

        if (max_in_rows >= max_in_columns) {
            for (int i = 0; i < diffs.first.size(); i++) {
                if (diffs.first[i] == max_in_rows) {
                    int min_cost = find_min_cost_in_row(tm, i);
                    for (int j = 0; j < tm.costs[i].size(); j++) {
                        if (tm.costs[i][j] == min_cost) {
                            int amount = min(tm.supply[i], tm.demand[j]);
                            update_supply_demand(tm, i, j, amount, min_cost, solution);
                            break;
                        }
                    }
                    break;
                }
            }
        } else {
            for (int i = 0; i < diffs.second.size(); i++) {
                if (diffs.second[i] == max_in_columns) {
                    int min_cost = find_min_cost_in_column(tm, i);
                    for (int c = 0; c < tm.costs.size(); c++) {
                        if (tm.costs[c][i] == min_cost) {
                            int amount = min(tm.supply[c], tm.demand[i]);
                            update_supply_demand(tm, c, i, amount, min_cost, solution);
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


