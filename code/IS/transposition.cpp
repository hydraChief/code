#include<bits/stdc++.h>
using namespace std;

map<int,int> mp;

string encrypt(const string& plaintext, const string& key) {
    int keyLength = key.length();
    int numRows = (plaintext.length() + keyLength - 1) / keyLength;
    vector<vector<char>> grid(numRows, vector<char>(keyLength, ' '));

    int index = 0;
    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < keyLength; ++col) {
            if (index < plaintext.length()) {
                mp[col]++;
                grid[row][col] = plaintext[index++];
            }
        }
    }

    string ciphertext;
    for (char ch : key) {
        int col = ch - '0' - 1;
        cout<<col<<" ";
        for (int row = 0; row < numRows; ++row) {
            if (mp[col] >= row+1) {
                ciphertext += grid[row][col];
            }
        }
    }
    cout<<endl;
    return ciphertext;
}

string decrypt(const string& ciphertext, const string& key) {
    int keyLength = key.length();
    int numRows = (ciphertext.length() + keyLength - 1) / keyLength;
    vector<vector<char>> grid(numRows, vector<char>(keyLength, ' '));

    int index = 0;
    for (char ch : key) {
        int col = ch - '0' - 1;
        cout<<col<<" ";
        for (int row = 0; row < numRows; ++row) {
            if (index < ciphertext.length() && mp[col]>=row+1) {
                grid[row][col] = ciphertext[index++];
                
            }
        }
    }
cout<<endl;
    string plaintext;
    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < keyLength; ++col) {
            if (mp[col]>=row+1) {
                plaintext += grid[row][col];
            }
        }
    }
    return plaintext;
}

int main() {
    string plaintext = "Hello World";
    string key = "2314";

    string ciphertext = encrypt(plaintext, key);
    cout << "Encrypted: " << ciphertext << endl;

    string decrypted = decrypt(ciphertext, key);
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}
