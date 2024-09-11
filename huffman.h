// huffman.h

#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>
#include <unordered_map>

// Define the structure for a Huffman Tree Node
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* getNode(char ch, int freq, Node* left = nullptr, Node* right = nullptr);

// Custom comparator for the priority queue
struct comp {
    bool operator()(Node* l, Node* r);
};

// Function declarations for encoding and decoding
void encode(Node* root, std::string str, std::unordered_map<char, std::string>& huffmanCode);
void decode(Node* root, int& index, std::string str);

// Function to build the Huffman Tree
void buildHuffmanTree(std::string text);

#endif
