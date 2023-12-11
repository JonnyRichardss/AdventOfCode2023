// AdventOfCode2023.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
struct Coordinate {
    int row;
    int col;
    Coordinate(int R, int C) {
        row = R;
        col = C;
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
};
vector<string> ReadFile(string filePath) {
    std::vector<std::string> output;
    char lineBuffer[1024];
    std::ifstream myFile(filePath);

    if (myFile.is_open()) {
        while (!myFile.eof()) {
            lineBuffer[0] = '\0'; //empty string
            myFile.getline(lineBuffer, 1024);
            output.push_back(lineBuffer);
        }
        myFile.close();
    }
    return output;
}

vector<Coordinate> FindSymbols(vector<vector<char>> &input) {
    vector<Coordinate>output;
    for (int row = 0; row < input.size(); row++) {
        for (int col = 0; col <input[row].size(); col++) {
            char c = input[row][col];
            if (!isalnum(c) && c != '.') {
                output.push_back(Coordinate(row, col));
            }
        }
    }
    return output;
}

vector<Coordinate> FindDigitNeighbours(vector<vector<char>> &grid,Coordinate place) {
    vector <Coordinate> output;

    vector<Coordinate> allNeighbours = place.GetAllNeighbours();
    vector<Coordinate> validNeighbours;
    for (vector<Coordinate>::iterator i = allNeighbours.begin(); i != allNeighbours.end(); i++) {
        if (i->row < 0 || i->col < 0 || i->row >= grid.size() || i->col >= grid.size()) continue;
        
        validNeighbours.push_back(*i);
    }

    for (vector<Coordinate>::iterator i = validNeighbours.begin(); i != validNeighbours.end(); i++) {
        char c = grid[i->row][i->col];
        if (isdigit(c)) {
            output.push_back(*i);
        }
    }
    return output;
}

int GetFullNumber(vector<vector<char>> &grid, Coordinate place,vector<Coordinate> &usedCoords) {
    int output = 0;
    vector<char> row = grid[place.row];
    int indexLastDigit = 0;
    for (int i = place.col; i < row.size(); i++) {
        if (!isdigit(row[i])) {
            indexLastDigit = i - 1;
            break;
        }
    }
    int exponent = 0;
    for (int i = indexLastDigit; i >= 0; i--) {
        if (find(usedCoords.begin(), usedCoords.end(), Coordinate(place.row, i)) != usedCoords.end()) {
            return 0;
        }
        if (!isdigit(row[i])) break;
        
        output += (row[i]-'0') * pow(10, exponent);
        exponent++;
        usedCoords.push_back(Coordinate(place.row, i));
    }
    return output;
}

int main()
{


    vector<string> lines = ReadFile("input.txt");
    vector<vector<char>> engine;

    //ENGINE IS A VECTOR OF ROWS
    //[row][col]
    //read into 2d array of chars
    // 
    // 
    //this is a 2d vector ive never done this before but I dont full understand c++ arrays they shout at me a lot :(
    for (vector<string>::iterator row = lines.begin(); row != lines.end(); row++) {
        if (*row == "") continue;
        engine.push_back(vector<char>(( * row).begin(), (*row).end()));
    }
    vector<Coordinate> allSymbols = FindSymbols(engine);
    //cout << "test" << endl;

    //for every symbol check its neighbours for numbers
    //read the ints backwards
    // += int * 10 ^ index
    int output = 0;
    vector<Coordinate> usedCoords;
    for (vector<Coordinate>::iterator i = allSymbols.begin(); i != allSymbols.end(); i++) {
        vector<Coordinate> digitNeighbours = FindDigitNeighbours(engine,*i);
        for (vector<Coordinate>::iterator j = digitNeighbours.begin(); j != digitNeighbours.end(); j++) {
            output += GetFullNumber(engine, *j,usedCoords);
        }
    }
    cout << output << endl;
    return 0;
}


