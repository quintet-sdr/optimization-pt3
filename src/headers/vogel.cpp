#include "vogel.hpp"
#include <algorithm>
using namespace std;


void vogel(TransportMatrix& tm) {
    int rows = tm.costs.size();
    int cols = tm.costs[0].size();
    int solution = 0;
    while (true) {
        vector<int> row_diff;
        vector<int> col_diff;
        for (int i = 0; i < rows; i++) {
            sort(tm.costs[i].begin(), tm.costs[i].end());
            row_diff.push_back(tm.costs[1][0] - tm.costs[0][0]);
        }
        for(int i = 0; i < cols; i++) {
            vector<int> temp;
            for (int j = 0; j < rows; j++) {
                temp.push_back(tm.costs[j][i]);
            }
            sort(temp.begin(), temp.end());
            col_diff.push_back(temp[1] - temp[0]);
        }
        pair<vector<int>, vector<int>> diffs = make_pair(row_diff, col_diff);
        int max_in_rows = *max_element(diffs.first.begin(), diffs.first.end());
        int max_in_columns = *max_element(diffs.second.begin(), diffs.second.end());
        if (max_in_rows > max_in_columns) {
            for (int i = 0; i < diffs.first.size(); i++) {
                if (diffs.first[i] == max_in_rows) {
                    int min_element_in_costs = *min_element(tm.costs[i].begin(), tm.costs[i].end());

                }
            }
        }
    }
}



