
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class CustomStack {
private:
    stack<string> textStack;

public:
    void insert(const string& value) {
        textStack.push(value);
    }

    void deleteText(int value) {
        if (textStack.empty()) {
            cout << "Error: Text is empty." << endl;
            return;
        }

        string& text = textStack.top();
        if (text.length() <= value) {
            textStack.pop();
        } else {
            text = text.substr(0, text.length() - value);
        }
    }

    char get(int value) {
        if (textStack.empty()) {
            cout << "Error: Text is empty." << endl;
            return '\0';
        }

        const string& text = textStack.top();
        if (value <= 0 || value > text.length()) {
            cout << "Error: Invalid index." << endl;
            return '\0';
        }

        return text[value - 1];
    }

    void undo() {
        if (!textStack.empty()) {
            textStack.pop();
        }
    }
};

int main() {
    CustomStack editor;
    string command, value;
    char result;



    while (cin >> command) {
        if (command == "1") {
            cin >> value;
            editor.insert(value);
        } else if (command == "2") {
            cin >> value;
            editor.deleteText(stoi(value));
        } else if (command == "3") {
            cin >> value;
            result = editor.get(stoi(value));
            if (result != '\0') {
                cout << result << endl;
            }
        } else if (command == "4") {
            editor.undo();
        }
    }

    return 0;
}
                                       
