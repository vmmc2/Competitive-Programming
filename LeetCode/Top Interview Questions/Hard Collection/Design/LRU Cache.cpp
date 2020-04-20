#include <map>

class LRUCache {
public:
    struct ListNode{
        int key;
        int val;
        struct ListNode *prev;
        struct ListNode *next;
        ListNode(int k, int v) : key(k), val(v), prev(NULL), next(NULL) {}
    };
    
    map<int,ListNode*> hashtable;
    ListNode *head;
    ListNode *tail;
    int totItems;
    int maxCapacity;
    
    void removeFromList(struct ListNode *temp){
        ListNode *savedprev = temp->prev;
        ListNode *savednext = temp->next;
        savedprev->next = savednext;
        savednext->prev = savedprev;
        return;
    }
    
    void addToFront(struct ListNode *temp){
        temp->prev = head;
        temp->next = head->next;
        head->next->prev = temp;
        head->next = temp;
        return;
    }
    
    struct ListNode* popTail(){
        ListNode* tailItem = tail->prev;
        removeFromList(tailItem);
        return tailItem;
    }
    
    void removeLRUEntry(){
        ListNode *tail = popTail();
        hashtable.erase(tail->key);
        totItems--;
        return;
    }
    
    void moveToHead(struct ListNode *temp){
        removeFromList(temp);
        addToFront(temp);
        return;
    }
    
    LRUCache(int capacity) {
        totItems = 0;
        maxCapacity = capacity;
        head = new ListNode(-69, -69); //dummy
        tail = new ListNode(-68, -68);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(hashtable.find(key) == hashtable.end()){ //se eu nao achei.
            return -1;
        }
        //se eu achei...
        ListNode *temp = hashtable[key];
        moveToHead(temp);
        return temp->val;
    }
    
    void put(int key, int value) {
        if(hashtable.find(key) == hashtable.end()){ //node nao ta presente na cache. tem que criar
            ListNode *temp = new ListNode(key, value);
            hashtable[key] = temp;
            addToFront(temp);
            totItems++;
            if(totItems > maxCapacity){
                removeLRUEntry();
            }
        }else{ //node ta presente na cache.
            ListNode *temp = hashtable[key];
            temp->val = value;
            moveToHead(temp);
        }
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
