// huffman.cpp

#include "huffman.h"
#include <iostream>
#include <queue>

using namespace std;

// Function to create a new node
Node* getNode(char ch, int freq, Node* left, Node* right)
{
    Node* node = new Node();
    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;
    return node;
}

// Comparator for the priority queue
bool comp::operator()(Node* l, Node* r)
{
    return l->freq > r->freq;
}

// Function to encode the characters
void encode(Node* root, string str, unordered_map<char, string>& huffmanCode)
{
    if (root == nullptr)
        return;

    if (!root->left && !root->right)
        huffmanCode[root->ch] = str;

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

// Function to decode the encoded string
void decode(Node* root, int& index, string str)
{
    if (root == nullptr)
        return;

    if (!root->left && !root->right) {
        cout << root->ch;
        return;
    }

    index++;

    if (str[index] == '0')
        decode(root->left, index, str);
    else
        decode(root->right, index, str);
}

// Function to build the Huffman Tree
void buildHuffmanTree(string text)
{
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    priority_queue<Node*, vector<Node*>, comp> pq;

    for (auto pair : freq) {
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }

    while (pq.size() != 1)
    {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        int sum = left->freq + right->freq;
        pq.push(getNode('\0', sum, left, right));
    }

    Node* root = pq.top();

    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    cout << "Huffman Codes are:\n" << '\n';
    for (auto pair : huffmanCode) {
        cout << pair.first << " " << pair.second << '\n';
    }

    string encodedStr = "";
    for (char ch : text) {
        encodedStr += huffmanCode[ch];
    }

    cout << "\nEncoded string is:\n" << encodedStr << '\n';

    string choice;
    cout << "\nWould you like to decode the string? (yes/no): ";
    cin >> choice;

    if (choice == "yes" || choice == "Yes" || choice == "YES") {
        
        int index = -1;
        cout << "\nDecoded string is: \n";
        while (index < (int)encodedStr.size() - 2) {
            decode(root, index, encodedStr);
        }
        cout << '\n';
    } else if (choice == "no" || choice == "No" || choice == "NO") {
        cout << "Decoding skipped.\n";
    } else {
        cout << "Invalid input. Please enter 'yes' or 'no'.\n";
    }

    // Print the original string at the end
    cout << "\nOriginal string was:\n" << text << '\n';
}
