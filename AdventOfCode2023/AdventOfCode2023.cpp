#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
const string numberWords[] = { "one","two","three","four","five","six","seven","eight","nine" };
const string numberDigits[] = { "1","2","3","4","5","6","7","8","9" };
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
/*
* this doesn't work because of things like twone or eighthree
void convertWords(string &line) {
    //part 2 wants to check for spelled numbers as well as digits - convert all number words to digits on a line then use part one code again
    string output = line;
    for (int i = 0; i < 9; i++) {
        string toFind = numberWords[i];
        string toReplace = numberDigits[i];
        size_t pos=0;
        size_t lastpos = 0;
        while (pos != output.size()-1  ) {
            pos = output.find(toFind,lastpos);
            if (pos == string::npos) {
                break;
            }
            output.replace(pos, toFind.size(), toReplace);
            lastpos = pos + 1;
        }
    }
    line = output;
}
*/
string FindDigit(string& line, bool reversed) {

    int indexOfDigit = INT32_MAX;
    int indexOfWords[9];

    for (int i = 0; i < line.size(); i++) {
        if (isdigit(line[i])) {
            indexOfDigit = i;
            break;
        }
    }
    for (int i = 0; i < 9; i++) {
        indexOfWords[i] = INT32_MAX;

        string toFind = numberWords[i];
        if (reversed) reverse(toFind.begin(), toFind.end());
        size_t pos = line.find(toFind);
        if (pos != string::npos) {
            indexOfWords[i] = pos;
        }
    }
    int* firstWord = min_element(begin(indexOfWords), end(indexOfWords));
    if (*firstWord < indexOfDigit) {
        int index = distance(begin(indexOfWords), firstWord);
        return numberDigits[index];
    }
    return string(1, line[indexOfDigit]);


}
int GetNumber(string line) {
    if (line == "") {
        return 0;
    }
    string digits = "";
    //convertWords(line);
    digits.append(FindDigit(line, false));
    reverse(line.begin(), line.end());
    digits.append(FindDigit(line, true));
    return stoi(digits);
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