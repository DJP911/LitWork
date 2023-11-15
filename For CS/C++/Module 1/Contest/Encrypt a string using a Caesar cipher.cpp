#include <iostream>
#include <string>
using namespace std;

string encryptCaesarCipher(const string& message, int rotation) {
    string encryptedMessage = "";  

    for (char ch : message) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            encryptedMessage += ((ch - base + rotation) % 26) + base;
        } else {
            encryptedMessage += ch;
        }
    }

    return encryptedMessage;
}

int main() {
    // Exercise-1
    string input1 = "AsdfGH";
    string output1 = encryptCaesarCipher(input1, 4);
    cout << "Exercise-1 Output: " << output1 << endl;

    // Exercise-2
    string input2 = "LkjHgg";
    string output2 = encryptCaesarCipher(input2, 4);
    cout << "Exercise-2 Output: " << output2 << endl;

    return 0;
}
