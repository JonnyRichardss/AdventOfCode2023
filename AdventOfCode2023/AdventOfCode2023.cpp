// AdventOfCode2023.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Game.h"
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
int main()
{
    vector<string> lines = ReadFile("input.txt");
    int GameTotal = 0;
    //For every game, construct and call checkGame
    for (vector<string>::iterator i = lines.begin(); i != lines.end(); i++) {
        string line = *i;
        if (line == "") continue;
        Game g(line);
        /*
        if (g.CheckGame(12,13,14)) {
            GameTotal += g.id;
        }
        else {
            cout << endl;
        }
        */
        GameTotal += g.getPower();
    }
    cout << GameTotal << endl;
    return 0;
}
