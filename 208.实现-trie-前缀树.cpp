/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;

class TrieNode{
public:
    TrieNode* childNode[26];
    bool isVal;

    // 构造函数初始化
    TrieNode() : isVal(false){
        for(int i = 0 ; i < 26; ++i){
            childNode[i] = nullptr;
        }
    }
};



class Trie {
private:
    TrieNode* root;
public:
    
    /** Initialize your data structure here. */
    Trie() : root(new TrieNode()) {}

    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* temp = root;
        for(int i = 0; i < word.size(); ++i){
            if(!temp->childNode[word[i]-'a']){
                temp->childNode[word[i]-'a'] = new TrieNode();
            }
            temp = temp->childNode[word[i]-'a'];
        }
        temp->isVal = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* temp = root;
        for(int i = 0; i<word.size(); ++i){
            if(!temp){
                break;
            }
            temp = temp->childNode[word[i]-'a'];
        }
        //如果temp不是nullptr,判断是不是最后的节点
        return temp ? temp->isVal: false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(int i = 0; i<prefix.size(); ++i){
            if(!temp){
                break;
            }
            temp = temp->childNode[prefix[i]-'a'];
        }
        return temp;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

