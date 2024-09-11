#include "huffman.h"
#include <iostream>

using namespace std;

int main()
{
    string text;

    cout << "Enter a string to encode: ";
    getline(cin, text);

    buildHuffmanTree(text);

    return 0;
}
