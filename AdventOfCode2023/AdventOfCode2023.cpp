// AdventOfCode2023.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Card.h"
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
    vector<Card> allCards;
    for (string line : lines) {
       if (line != "") allCards.push_back(Card(line));
    }
    int output = 0;
    for (Card c : allCards) {
        output += c.GetValue();
    }
    cout << output << endl;

    output = 0;
    vector<Card> remainingCards = allCards;
    while (remainingCards.size()>0) {
        vector<Card> copies;
        for (Card c : remainingCards) {
            output++;
            vector<Card> theseCopies = c.MakeCopies(allCards);
            copy(theseCopies.begin(), theseCopies.end(), back_inserter(copies));
        }
        remainingCards.clear();
        remainingCards = copies;
    }
    cout << output << endl;
}
