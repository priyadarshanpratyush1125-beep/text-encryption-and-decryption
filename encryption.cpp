#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // Get string to be encrypted.
    cout << "Enter a string to encrypt : ";

    string str;
    getline(cin, str); // Include white spaces

    // Add ~ at the end of string.
    str += '~';

    int len = str.length();

    // Array of strings to store all rotations.
    vector<string> b(len);

    // Burrows-Wheeler Transformation
    // Store all possible rotations by rotating each character by 1 unit.
    cout << "\nPossible strings after rotation :\n\n";

    for (int j = 0; j < len; j++)
    {
        // Store last character of string.
        char last = str[len - 1];

        // Displace each character by one unit.
        for (int i = len - 1; i > 0; i--)
        {
            str[i] = str[i - 1];
        }

        // Make stored last character the first character.
        str[0] = last;

        // Store and print rotated string.
        b[j] = str;

        cout << b[j] << '\n';
    }

    // Sort stored strings in lexical order.
    // Bubble Sort algorithm.
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1; j++)
        {
            // Compare two strings.
            // If first string is greater than second, swap them.
            if (b[j] > b[j + 1])
            {
                swap(b[j], b[j + 1]);
            }
        }
    }

    // Print lexical ordered strings one by one.
    cout << "\nArranging in lexical order :\n\n";

    for (int j = 0; j < len; j++)
    {
        cout << b[j] << '\n';
    }

    // Encrypted string made up of last character
    // of each lexical ordered string from top to bottom.
    cout << "\nEncrypted string : ";

    for (int j = 0; j < len; j++)
    {
        cout << b[j][len - 1];
    }

    cout << '\n';

    return 0;
}

