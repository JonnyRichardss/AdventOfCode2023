#include <vector>
#include <string>
#include <fstream>
#include <iostream>
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
char FindDigit(string& line) {
    for (string::iterator i = line.begin(); i != line.end(); i++) {
        if (isdigit(*i)) {
            return *i;
        }
    }
}
int GetNumber(string line) {
    string digits = "  ";
    digits[0] = FindDigit(line);
    reverse(line.begin(), line.end());
    digits[1] = FindDigit(line);

    //if the data doesnt go through right, ignore it
    //this is lazy but oh well
    try {
        return stoi(digits);
    }
    catch (...) {
        return 0;

    }
}
int main() {
    //for every line read the first and last digits
    //sum them all



    //first we read the file
    vector<string> lines = ReadFile("input.txt");

    //then extract each number and add to total
    int total = 0;
    for (vector<string>::iterator i = lines.begin(); i != lines.end(); i++) {
        total += GetNumber(*i);
    }
    cout << total << endl;
    return 0;
}