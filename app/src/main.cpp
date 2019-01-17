#include <iostream>
#include <fstream>
#include <cstring>

bool charShift(char*, const int);

// Text files will not exceed 70 chars per line,
// but a soft limit of 60 chars is preferred.
const int lengthCap = 70;
const char* file1 = "../data/input.txt";
const char* file2 = "../data/output.txt";

using std::cin;
using std::cout;

int main() {
    char lineBuffer[lengthCap + 1];
    for (short i = 0; i < lengthCap + 1; i++)
        lineBuffer[i] = '\0';
    //cout << "Done creating buffer...\n";
    std::ifstream fin(file1);
    if (!fin) {
        std::cerr << "Could not open " << file1 << '\n';
        return -1;
    }
    std::ofstream fout(file2);
    if (!fout) {
        std::cerr << "Could not open " << file2 << '\n';
        return -1;
    }
    //cout << "Done opening files...\n";
    while (!fin.eof()) {
        //cout << "Entering file read loop...\n";
        fin.getline(lineBuffer, lengthCap + 1);
        //cout << "Just read into line buffer...\n";
        charShift(lineBuffer, lengthCap + 1);
        //cout << "Just encrypted buffer...\n";
        fout << lineBuffer << '\n';
        //cout << "Just wrote to file...\n";
        for (short i = 0; i < lengthCap + 1; i++)
            lineBuffer[i] = '\0';
        //cout << "Just reinitialized buffer...\n";
    }
    //cout << "Done writing to files. Closing now...\n";
    // Don't forget to close!
    fin.close();
    fout.close();
    // Manual demo for the user!
    cout << "Please input a line of text not exceeding "
         << lengthCap << " characters.\nOnly letters will"
         << " be encrypted.\nInput: ";
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
