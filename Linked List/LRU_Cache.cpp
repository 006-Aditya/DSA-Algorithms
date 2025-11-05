// problem link --

// https://leetcode.com/problems/lru-cache/?envType=problem-list-v2&envId=vmt8p6v6

// LRU Cache

// code -- 


class Node{
public:
    int key,val;
    Node* next;
    Node* prev;
    Node(int k, int v): key(k), val(v), next(NULL), prev(NULL) {};
};
class LRUCache {
public:
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;
    LRUCache(int capacity) {
        this->capacity=capacity;
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
    }

    void remove(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    void insert(Node* node){
        node->next=head->next;
        node->prev=head;
        head->next->prev=node;
        head->next=node;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        Node* node=mp[key];
        remove(node);
        insert(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* node=mp[key];
            node->val=value;
            remove(node);
            insert(node);
        }else{
            if(mp.size()==capacity){
                Node* last=tail->prev;
                remove(last);
                mp.erase(last->key);
                delete last;
            }
            Node* node= new Node(key, value);
            insert(node);
            mp[key]=node;
        }
    }
};
