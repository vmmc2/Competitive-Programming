#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

template <class T>
class stack{
    private:
        struct node{
            T data;
            struct node *next;
            node(T val) : data(val), next(NULL) {}
        };
        struct node *head = NULL;
        ll length = 0;
    public:
        void push(T element){
            struct node *temp = new node(element);
            temp->next = head;
            head = temp;
            length++;
            return;
        }
        T top(){
            if(head == NULL || this->length == 0){
                throw "Stack is empty.\n";
            }
            return head->data;
        }
        void pop(){
            if(head == NULL || this->length == 0){
                throw "Stack is empty.\n";
            }
            head = head->next;
            length--;
            return;
        }
        int size(){
            return this->length;
        }
        bool isEmpty(){
            if(head == NULL || this->length == 0) return true;
            else return false;
        }
        void clear(){
            head = NULL;
            this->length = 0;
            return;
        }
};

template <class T>
class SetofStacks{
    private:
        vector<stack<T>> s;
        int capacity = 15;
        int numberofstacks = 0;
    public:
        SetofStacks(int i){
            s.push_back(stack<T>()); //o vetor de stacks inicializa com uma stack.
            numberofstacks++;
        }
        void push(T element){
            if(s[numberofstacks - 1].size() < capacity){
                s[numberofstacks - 1].push(element);
            }else if(s[numberofstacks - 1].size() == capacity){
                s.push_back(stack<T>());
                numberofstacks++;
                s[numberofstacks - 1].push(element);
            }
            return;
        }
        void pop(){
            if(s[numberofstacks - 1].isEmpty()){
                s.pop_back();
                numberofstacks--;
                s[numberofstacks - 1].pop();
            }else{
               s[numberofstacks - 1].pop(); 
            }
            return;
        }
        void popAt(int index){
            if(index >= numberofstacks){
                throw "Index out of bounds.\n";
            }else{
                s[index].pop();
            }
            return;
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    SetofStacks<int> s(0);
    for(int i = 1; i <= 20; i++){
        s.push(i);
    }
    
    
    return 0;
}
