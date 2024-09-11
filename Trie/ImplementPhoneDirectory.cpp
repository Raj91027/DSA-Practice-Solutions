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
            int index = word[0] - 'a';
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

        void printSuggestions(TrieNode* curr, vector<string> &temp, string prefix){
            if(curr->isTerminal){
                temp.push_back(prefix);
            }

            for(char ch='a';ch<='z';ch++){
                TrieNode* next = curr->children[ch-'a'];
                if(next!=NULL){
                    prefix.push_back(ch);
                    printSuggestions(next,temp,prefix);
                    prefix.pop_back();
                }
            }
        }
        vector<vector<string>> getSuggestions(string str){
            TrieNode* prev = root;

            vector<vector<string>> output;
            string prefix;

            for(int i=0; i<str.length(); i++){
                char lastch = str[i];
                prefix.push_back(lastch);

                TrieNode* curr = prev->children[lastch-'a'];

                if(curr==NULL)
                    break;

                vector<string> temp;
                printSuggestions(curr, temp, prefix);

                output.push_back(temp);
                temp.clear();
                prev = curr;
            }
            return output;
        }
        
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    Trie *t = new Trie();

    for(int i=0; i<contactList.size(); i++){
        t->insertWord(contactList[i]);
    }

    return t->getSuggestions(queryStr);
}