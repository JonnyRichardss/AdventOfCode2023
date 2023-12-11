// AdventOfCode2023.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//NOTES FOR TASK 2
/*
looking for symbols wasnt working so i looked for numbers
that turned out to be stupid because now i need to find a symbol with two numbers



find asterisk with exactly two numbers and multiply them
sum over every asterisk


MAYBE GO BACK AND DEBUG SYMBOL VERSION - correct solution was 549908
*/





#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "Coordinate.h"
#include "Helpers.h"
#include "GridNumber.h"
using namespace std;

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

GridNumber GetNumber(vector<string>& lines, int rowIndex, int &firstIndex,vector<Gear> &ExistingGears) {
    string line = lines[rowIndex];
    Coordinate startCoord(rowIndex, firstIndex);
    string allDigits;
    int lastIndex;
    for (int i = firstIndex; i <= line.size(); i++) {
        if (!isdigit(line[i]) || i == line.size()) {
            lastIndex = i - 1;
            break;
        }
        allDigits.push_back(line[i]);
    }
    Coordinate endCoord(rowIndex, lastIndex);
    int val = stoi(allDigits);
    GridNumber g(lines,val, startCoord, endCoord);
    firstIndex = endCoord.col + 1;
    return (g);
}

int SumAllNumbers(vector<string> &lines, vector<Gear>& ExistingGears) {
    int output = 0;
    for (int i = 0; i < lines.size(); i++) {
        if (lines[i] == "") 
        { continue; }
        for (int j = 0; j < lines[i].size(); j++) {
            if (isdigit(lines[i][j])) {
                GridNumber g = GetNumber(lines, i, j, ExistingGears);
                g.AddAllGears(lines, ExistingGears);
                output += g.value;
            }
        }
    }
    return output;
}
int main()
{


    vector<string> lines = ReadFile("input.txt");
   // vector<vector<char>> engine;

    //ENGINE IS A VECTOR OF ROWS
    //[row][col]
    //read into 2d array of chars
    // 
    // 
    //this is a 2d vector ive never done this before but I dont full understand c++ arrays they shout at me a lot :(
    /*
    for (vector<string>::iterator row = lines.begin(); row != lines.end(); row++) {
        string s = *row;
        if (s == "") continue;
        engine.push_back(vector<char>((s).begin(), (s).end()));


        vector<string> words = Split(s, '.');

    }
    */




    vector<Gear> allGears;
    cout<<"Sum Of Numbers:" << SumAllNumbers(lines,allGears) << endl;
    int ratiosum = 0;
    for (vector<Gear>::iterator i = allGears.begin(); i != allGears.end(); i++) {
        Gear g = *i;
        if (g.countAdjacent == 2) {
            ratiosum += g.ratio;
        }
    }
    cout << "Sum Of Ratios:"<<ratiosum << endl;
    return 0;
}


