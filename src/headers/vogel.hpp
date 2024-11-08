#ifndef VOGEL_H
#define VOGEL_H
#include <vector>
#include <iostream>
#include "matrix.hpp"
using namespace std;
pair<vector<int>, vector<int>> findDiff(TransportMatrix& tm);
void vogel(TransportMatrix& tm);
#endif