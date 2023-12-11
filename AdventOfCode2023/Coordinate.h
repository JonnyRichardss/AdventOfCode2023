#pragma once
#include <vector>
using namespace std;
struct Coordinate {
    int row;
    int col;
    Coordinate(int R=0, int C=0) {
        row = R;
        col = C;
    }
    Coordinate(const Coordinate &c) {
        row = c.row;
        col = c.col;
    }
    vector<Coordinate> GetAllNeighbours() {
        vector<Coordinate> output;
        for (int i = row - 1; i <= row + 1; i++) {
            for (int j = col - 1; j <= col + 1; j++) {
                output.push_back(Coordinate(i, j));
            }
        }
        return output;
    }
    bool operator == (const Coordinate& obj) {
        if (row == obj.row && col == obj.col) {
            return true;
        }
        return false;
    }
    bool operator != (const Coordinate& obj) { //theres probably a way to do this without repeating but i couldnt figure it out faster than the 2 seconds it took me to copy it
        if (row != obj.row && col != obj.col) {
            return true;
        }
        return false;
    }
};