#include <time.h>

class RandomizedSet {
public:
    vector<int> v;
    map<int,int> dict;
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(dict.find(val) == dict.end()){
            v.push_back(val);
            dict[val] = (int)v.size() - 1;
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(dict.find(val) == dict.end()){
            return false;
        }
        int index = dict[val];
        v[index] = v[(int)v.size() - 1];
        dict[v[(int)v.size() - 1]] = index;
        v.pop_back();
        dict.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int tam = (int)v.size();
        int desiredIndex = rand() % tam;
        return v[desiredIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
