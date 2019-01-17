#include <iostream>
#include <fstream>
#include <cstring>

bool charShift(char*, const int);

const int lengthCap = 32;

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
    cout << "\nMaster: \"" << lineBuffer << "\"\n";
    charShift(lineBuffer, lengthCap + 1);
    cout << "\nCipher: \"" << lineBuffer << "\"\n";
    cout << "\nEnd of program reached.\n\n";
    return 0;
}

// My current plan is for this to only shift letters,
// and the key is a rotation of 13.
bool charShift(char* iBuffer, const int size) {
    for (int i = 0; i < size; i++) {
        if (iBuffer[i] >= 'A' && iBuffer[i] <= 'M')
            iBuffer[i] += 13;
        else if (iBuffer[i] >= 'N' && iBuffer[i] <= 'Z')
            iBuffer[i] -= 13;
        else if (iBuffer[i] >= 'a' && iBuffer[i] <= 'm')
            iBuffer[i] += 13;
        else if (iBuffer[i] >= 'n' && iBuffer[i] <= 'z')
            iBuffer[i] -= 13;
    }
    return true;
}
