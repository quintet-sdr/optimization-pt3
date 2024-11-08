#ifndef VOGEL_H
#define VOGEL_H
#include <vector>
#include <iostream>
#include "matrix.hpp"
using namespace std;
pair<vector<int>, vector<int>> find_row_col_diff(TransportMatrix& tm);
int find_min_cost_in_row(TransportMatrix& tm, int row);
int find_min_cost_in_column(TransportMatrix& tm, int col);
void update_supply_demand(TransportMatrix& tm, int supply_index, int demand_index, int amount, int cost, int& solution);
void vogel(TransportMatrix& tm);
#endif