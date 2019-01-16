#include <iostream>
#include <fstream>
#include <cstring>

bool charShift(char*, const int);

const int lengthCap = 32;
const int shift = 13; // Classic from tabletop RPGs

using std::cin;
using std::cout;

int main() {
    char lineBuffer[lengthCap + 1];
    for (short i = 0; i < lengthCap + 1; i++)
        lineBuffer[i] = '\0';
    cout << "Please input a line of text not exceeding "
         << "32 characters.\nOnly letters will be encrypted."
         << "\nInput: ";
    cin.getline(lineBuffer, lengthCap + 1);
    cout << "\nplaintext: \"" << lineBuffer << "\"\n";
    charShift(lineBuffer, lengthCap + 1);
    cout << "\nEnd of program reached.\n\n";
    return 0;
}

// My current plan is for this to only shift letters
bool charShift(char* iBuffer, const int size) {
    for (int i = 0; i < size; i++) {
        if (iBuffer[i] >= 'A' && iBuffer[i] <= 'Z') {

        }
    }
    return true;
}
