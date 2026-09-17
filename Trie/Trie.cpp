#include<iostream>
using namespace std;
/*
    Visulization of Trie Data Structure:

       TrieNode
                    ┌─────────────────┐
                    │ isEndOfWord     │
                    │     false       │
                    ├─────────────────┤
                    │ children[0] ────┼──→ nullptr   ('a')
                    │ children[1] ────┼──→ nullptr   ('b')
                    │ children[2] ────┼──→ nullptr   ('c')
                    │      ...        │
                    │ children[24] ───┼──→ nullptr   ('y')
                    │ children[25] ───┼──→ nullptr   ('z')
                    └─────────────────┘
*/
class TrieNode {
    public:
    TrieNode* children[26];
    bool isEndOfWord;
    TrieNode() {
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }
};

class Trie { // Using Trie Data Structure to store words
    private:
        TrieNode* root;
    public:
        Trie() {
            root = new TrieNode();
        }
        /* Inserts a word into the trie.
        Logic: For each character in the word, 
        check if the corresponding child node exists.
        If not, create a new TrieNode.
        Move to the child node and repeat for the next character.
        Finally, mark the end of the word. */

        void insert(string word){
            TrieNode* curr = root;
            for(char ch: word){
                int index = ch-'a';
                if(curr->children[index]==NULL){
                    curr->children[index] = new TrieNode();
                }
                curr = curr->children[index];
            }
            curr->isEndOfWord = true; 
        }

        bool search(string word){
            TrieNode* curr = root;
            for(char ch: word){
                int index = ch-'a';
                if(curr->children[index]==NULL){
                    return false;
                }
                curr = curr->children[index];
            }
            return curr->isEndOfWord; 
        }
};

int main() {
    return 0;
}