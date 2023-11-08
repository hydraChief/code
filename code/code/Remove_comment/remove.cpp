#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Open the input file for reading
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Error opening input.txt" << endl;
        return 1;
    }

    // Read the code from the input file
    string code;
    string line;
    while (getline(inputFile, line)) {
        code += line + "\n";
    }
    inputFile.close();  // Close the input file

    // Process the code to remove comments
    string result = "";
    bool inSingleLineComment = false;
    bool inMultiLineComment = false;

    for (size_t i = 0; i < code.size(); i++) {
        if (!inSingleLineComment && !inMultiLineComment) {
            if (code[i] == '/' && code[i + 1] == '/') {
                inSingleLineComment = true;
                i++;
            } else if (code[i] == '/' && code[i + 1] == '*') {
                inMultiLineComment = true;
                i++;
            } else {
                result += code[i];
            }
        } else if (inSingleLineComment && code[i] == '\n') {
            inSingleLineComment = false;
            result += '\n';
        } else if (inMultiLineComment && code[i] == '*' && code[i + 1] == '/') {
            inMultiLineComment = false;
            i++;
        }
    }

    // Open the output file for writing
    ofstream outputFile("output.txt");
    if (!outputFile) {
        cerr << "Error opening output.txt" << endl;
        return 1;
    }

    // Write the code without comments to the output file
    outputFile << result;
    outputFile.close();  // Close the output file

    return 0;
}
