#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <iostream>
#include <string>
using namespace std;
class TransportMatrix{
    public:
        vector<int> supply;
        vector<int> demand;
        vector<vector<int>> costs;
        TransportMatrix();
        TransportMatrix(vector<int> S, vector<vector<int>> C, vector<int> D);
        friend ostream& operator<<(ostream& out, const TransportMatrix& tm);
};
ostream& operator<< (ostream& out, TransportMatrix& tm);
#endif