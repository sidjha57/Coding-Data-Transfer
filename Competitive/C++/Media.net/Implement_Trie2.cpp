#include <bits/stdc++.h> 

struct Node {
    Node *links[26];
    int words;
    int freq;
    
    Node () {
        for (int i=0; i<26; i++) {
            links[i] = NULL;
            words = 0;
            freq = 0;
        }
    }
    
    ~Node () {
        for (int i=0; i<26; i++) {
            if (links[i] != NULL) {
                delete links[i];
            }
        }
    }
    
    bool isPresent(char ch) {
        return links[ch-'a'] != NULL;
    }
    
    Node* get(char ch) {
        return links[ch-'a'];
    }
    void put (char ch, Node *node) {
        links[ch-'a'] = node;
    }
    void increment_freq () {
        freq++;
    }
    void decrement_freq() {
        freq--;
    }
    void decrement_words() {
        words--;
    }
    void increment_words() {
        words++;
    }
    int get_freq() {
        return freq;
    }
    int get_words() {
        return words;
    }
};

class Trie{
    private:
        Node *root; 
    public:

    Trie(){
        root = new Node();
    }
    
    ~Trie() {
        delete root;
    }

    void insert(string &word){
        Node *node = root;
        for (int i=0; i<word.size(); i++) {
            if (!node->isPresent(word[i])) {
               node->put(word[i],new Node());
            }
             node = node->get(word[i]);
             node->increment_freq();
        }
        node->increment_words();
//         node->increment_freq();
    }

    int countWordsEqualTo(string &word){
        Node *node = root;
        for (int i=0; i<word.size(); i++) {
            if (!node->isPresent(word[i])) {
                return 0;
            }
            node = node->get(word[i]);
        }
        
        return node->get_words();
    }

    int countWordsStartingWith(string &word){
        Node *node = root;
        for (int i=0; i<word.size(); i++) {
            if (!node->isPresent(word[i])) {
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->get_freq();
    }

    void erase(string &word){
        Node *node = root, *tmp = root;
        node = node->get(word[0]);
        node->decrement_freq();
        for (int i=1; i<word.size(); i++) {
            tmp = node;
            if (!tmp->get_freq()) tmp = NULL;
    
            node = node->get(word[i]);
            node->decrement_freq();
        }
        node->decrement_words();
        if (!node->get_words())  node = NULL;
    }
};
