#include<iostream>

using namespace std;


class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch){
            data = ch;
            for(int i=0;i<26;i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie{
    public:
        TrieNode *root;

        Trie(){
            root = new TrieNode('\0');
        }
//recusrion to insert word
        void insertUtil(TrieNode* root, string word){
            //base case
            if(word.length() == 0){
                root -> isTerminal = true;
                return;
            }
            //assumption, all are CAPS
            int index = word[0] - 'A';
            TrieNode *child;

            //present
            if(root->children[index] != NULL){ 
                child = root -> children[index];
            }
            else{//absent
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }

            //recursion
            insertUtil(child, word.substr(1));
        }
    // insertion of word
        void insertWord(string word){
            insertUtil(root, word);
        }

    //Recursion to search word

        bool searchUtil(TrieNode *root, string word){
            //base case
            if(word.length() == 0){
                return root->isTerminal;
            }

            int index = word[0] - 'A';

            TrieNode * child;

            if(root -> children[index] != NULL){
                child = root -> children[index];
            }
            else{
                return false;
            }

            return searchUtil(child, word.substr(1));
        }

        bool searchWord(string word){
            return searchUtil(root, word);
        }


        void removeUtil(TrieNode *root, string word){
            //base case
            if(word.length() == 0){
                root->isTerminal = false;
                return;
            }

            int index = word[0] - 'A';

            TrieNode * child;

            if(root -> children[index] != NULL){
                child = root -> children[index];
                root -> children[index] = NULL;
            }
            else{
                return;
            }

            removeUtil(child, word.substr(1));
        }

        bool removeWord(string word){
            removeUtil(root, word);
        }

};


int main(){

    Trie *t = new Trie();

    t->insertWord("ARE");
    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");
    t->insertWord("TIS");
    

    cout<< t->searchWord("DO")<<endl;
    t->removeWord("DO");
    cout<< t->searchWord("DO")<<endl;

    return 0;
}
