// problem link --

// https://leetcode.com/problems/sum-of-prefix-scores-of-strings/?envType=problem-list-v2&envId=trie

// Trie 

// code -- 


class Solution {
public:
    struct trieNode{
        int count;
        trieNode* children[26];
    };
    trieNode* getNode(){
        trieNode* newNode=new trieNode();
        newNode->count=0;
        for(int i=0;i<26;i++){
            newNode->children[i]=NULL;
        }
        return newNode;
    }
    trieNode* root=getNode();
    void insert(string word){
        trieNode* Crawl=root;
        for(char ch:word){
            int idx=ch-'a';
            if(Crawl->children[idx]==NULL){
                Crawl->children[idx]=getNode();
            }
            Crawl=Crawl->children[idx];
            Crawl->count+=1;
        }
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> res(words.size());
        for(int i=0;i<words.size();i++){
            insert(words[i]);
        }
        for(int i=0;i<words.size();i++){
            string word=words[i];
            int cnt=0;
            trieNode* Crawl=root;
            for(char ch:word){
                int idx=ch-'a';
                Crawl=Crawl->children[idx];
                cnt+=Crawl->count;
            }
            res[i]=cnt;
        }
        return res;
    }
};