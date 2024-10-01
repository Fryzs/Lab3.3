#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string Text;
    ifstream file("text.txt");
    getline(file, Text);
    std::cout << Text << endl;


    Text[0] = toupper(Text[0]);

    for (size_t i = 0; i < Text.length(); ++i) {
        if (Text[i] == ',' || Text[i] == '.') {

            if (i > 0 && Text[i - 1] == ' ') {
                Text.erase(i - 1, 1);
                --i; 
            }

            if (i + 1 < Text.length() && Text[i + 1] != ' ') {
                Text.insert(i + 1, " ");
            }

            if (Text[i] == '.' && i + 2 < Text.length()) {
                Text[i + 2] = toupper(Text[i + 2]);
            }
        }
    }

    std::cout << Text << endl;

    return 0;
}
