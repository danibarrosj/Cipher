#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to encrypt a message using the Caesar Cipher
string caesarEncrypt(const string& text, int shift) {
    string encryptedText = "";
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            encryptedText += (c - base + shift) % 26 + base;
        }
        else {
            encryptedText += c; // Keep non-alphabet characters the same
        }
    }
    return encryptedText;
}

int main() {
    string message;
    int shift;

    cout << "Enter a message to encrypt: ";
    getline(cin, message);
    cout << "Enter shift key (1-25): ";
    cin >> shift;

    string encryptedMessage = caesarEncrypt(message, shift);
    cout << "Encrypted Message: " << encryptedMessage << endl;

    // Save to file
    ofstream outFile("encrypted.txt");
    if (outFile.is_open()) {
        outFile << encryptedMessage;
        outFile.close();
        cout << "Encrypted message saved to encrypted.txt" << endl;
    }
    else {
        cerr << "Error saving to file!" << endl;
    }

    return 0;
}
