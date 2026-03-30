 /*
                Author: Hayden Wagner
                Date: March 30 2026
                Lab Purpose: Creating a Huffman Tree to encode text documents 
                A.I. Disclaimer: THIS LAB WAS MADE WITHOUT THE USE OF AI
            */

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <utility>
#include <iomanip>

using namespace std;

struct Node {
  char data;
  int freq;
  Node *left, *right;};

// function prototype
// create a new tree node
Node *newNode(char, int);

// Delete the tree and free memory
void deleteTree(Node *node);     

//compares node frequency and sorts
bool compare(Node* a, Node* b);

//builds huffman tree with the unordered map
Node* buildHuffmanTree(unordered_map<char, int>& freqMap);

//Generates the huffman code for each character in the file
void generateHuffmanCodes(Node* root, string code, unordered_map<char, string>& huffmanCode);

//Finds the huffman code for the character and makes a string
string encodeText(string text, unordered_map<char, string>& huffmanCode);

//Decodes the huffman tree
string decodeText(string encodedText, Node* root);

int main(){
    string filename;

    cout << "Enter text file name: ";
    cin >> filename;
    
    // Read input file
    ifstream inputFile(filename);
    if (!inputFile) {
        cout << "Error opening file.\n";
        return 1;
    }
    
    unordered_map<char, int> freqMap;
    string text;
    char ch;
    //read characters from a file one by one until the end of the file is reached
    while (inputFile.get(ch)) {
         text.push_back(ch);
    }
    inputFile.close();

    for(char ch:text)
        freqMap[ch]++; // Increment the frequency of each character in freqMap
    //Builds huffman tree and stores root as node root
    
    Node* root= buildHuffmanTree(freqMap);

    // This should be placed in the main function after building the Huffman tree.
    unordered_map<char, string> huffmanCode;
    generateHuffmanCodes(root, "", huffmanCode);

    

    //Encodes the text and outputs it to a file
    string encodedText=encodeText(text, huffmanCode);

    ofstream encodedFile;
        encodedFile.open("compressed.bin");
        
        if (!encodedFile) {
            cerr << "Error: Unable to open compressed.txt for writing!" << endl;
            return 1;
        }
        
        encodedFile << encodedText;  // Write encoded text
        encodedFile.close();


    string decodedText= decodeText(encodedText, root);
    ofstream decodedFile;
    decodedFile.open("decompressed.txt");
    decodedFile<<decodedText;
    decodedFile.close();


        for(auto &p :huffmanCode)
            cout<<p.first<< ": "<<p.second<<endl;

        cout<<endl<<"Encoded text (first 100 bits): "<< encodedText.substr(0,100)<<endl<<endl;
        cout<<"Original file size: "<<text.size()<<" bytes"<<endl<<endl;
        cout<<"Compressed file size: "<<encodedText.size()/8<<" bytes (approx)"<<endl<<"Compressed output saved to 'compressed.bin'"<<endl<<endl;
        cout<<"Decompressed file size: "<<decodedText.size()<<" bytes"<<endl<<"Decompressed output saved to 'decompressed.txt'"<<endl<<endl;




    //Deletes the tree dynamically 
    cout<<"Deleting nodes:";
    deleteTree(root);

    cout<<endl<<endl<<"Press any key to exit"<<endl;
    cin.get();
    return 0;
}




// function definition to create a new tree node
Node *newNode(char data, int freq) {

  //Dynamically allocates memory for new nodes.
  Node *temp = new Node;
  temp->data = data;
  temp->freq = freq;
  temp->left = temp->right = NULL;
    
  return temp;
}




// Function to delete the entire tree
void deleteTree(Node *node) {
    
    if (node == NULL) {
        return;
    }

    // Recursively delete left and right children
    deleteTree(node->left);
    deleteTree(node->right);

    // Delete the current node
    cout<<" "<< node->data;
    delete node;
}

//sorts based on node frequency
bool compare(Node* a, Node* b) {
            return a->freq < b->freq;}


// Build Huffman Tree with vector
        Node* buildHuffmanTree(unordered_map<char, int>& freqMap) {
            vector<Node*> nodes;  // Store nodes in a vector
        
            // Step 1: Convert frequency map into nodes
            for (auto pair: freqMap) {
                
                char character = pair.first;   // Get the character (e.g., 'a')
                int frequency = pair.second;   // Get the frequency (e.g., 15)
                
                //Create a node using newNode function with character and its frequency
                Node* tempNode= newNode(character, frequency);
        
                // Use push_back to add the newly created node to the nodes vector.
                nodes.push_back(tempNode);
            }
        
            // Step 2: Sort nodes by frequency
            // This loop continues merging nodes until only one node remains, which becomes the root of the Huffman Tree.
            while (nodes.size() > 1) {
                sort(nodes.begin(), nodes.end(), compare);  //sort the nodes in ascending order of frequency 
        
                // Take two smallest frequency nodes
                Node* left = nodes[0];  //Hint: The node at index 0 has the smallest frequency.
                Node* right = nodes[1]; //Hint: The node at index 1 has the second smallest frequency.
        
                // Create a new node combining both
                // '\0' is the most common placeholder for internal nodes.
                Node* merged = newNode('\0', (left->freq+right->freq)); //Hint: The frequency of the merged node is the sum of left and right nodes' frequencies.
                merged->left = left;
                merged->right = right;
        
                // Remove the first two nodes from the list
                nodes.erase(nodes.begin(), nodes.begin() + 2);
                
                nodes.push_back(merged);//Hint: push_back() adds the merged node to the end of the nodes vector.
            }
            
            // Ensure the vector is not empty before accessing index 0
            if (nodes.empty()) return nullptr;
            return nodes[0];  // The last remaining node is the root
        }


        void generateHuffmanCodes(Node* root, string code, unordered_map<char, string>& huffmanCode) {
                if (root == nullptr) return; // Base case: Stop recursion if tree is empty

                //// If the node is a leaf node (contains a character)
                if (root->left == nullptr && root->right == nullptr) {
                    huffmanCode[root->data] = code; // Store Huffman code for this character
                    return;
                }

                //If the node has a left child, assigns 0 for a left branch
                generateHuffmanCodes(root->left, code + "0", huffmanCode);
                //If the node has a right child, assigns 1 for a right branch
                generateHuffmanCodes(root->right, code + "1", huffmanCode);
            }



// Encode the text using Huffman Codes
        string encodeText(string text, unordered_map<char, string>& huffmanCode) {
            string encodedText;
            for (char ch : text) {
                encodedText.append(huffmanCode[ch]); //Append the Huffman code of each character to the encoded text.
            }
            return encodedText;
        }




    // Decode Huffman encoded text
        string decodeText(string encodedText, Node* root) {
            string decodedText;
            Node* current = root; //Start at the root of the Huffman tree
            //Loop through each bit in encodedText
            for (char bit : encodedText) {
        
                // If the bit is '0', move to the left child; if the bit is '1', move to the right child.
                current = (bit == '0') ? current->left : current->right; //Hint: Use the left child when the bit is '0' and the right child when the bit is '1'.
                
                // Check if we reach a leaf node (character node)
                if (current->left == nullptr && current->right == nullptr) {  
                    decodedText += current->data; // Append the decoded character to the result
                    current = root;  // Reset to the root for the next character
                }
            }
            return decodedText; // Return the fully decoded string
        }