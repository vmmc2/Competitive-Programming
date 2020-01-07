class MinStack {
public:
    /** initialize your data structure here. */
    struct node{
        int number;
        int minimo;
        struct node *next = NULL;
    };
    struct node *head;
    int size;
    //primeiro elemento do pair:o numero em si
    //segundo elemento do pair: o minimo ate entao
    MinStack() {
        head = NULL;
        size = 0;
    }
    int top() {
        return head->number;
    }
    void push(int x) {
        struct node *temp = (struct node *)malloc(sizeof(node));
        temp->number = x;
        if(size == 0){
            temp->minimo = x;
        }else{
            int y = head->minimo;
            temp->minimo = min(x,y);
        }
        temp->next = head;
        head = temp;
        size++;
    }
    void pop() {
        struct node *trash = head;
        head = head->next;
        size--;
        free(trash);
    }
    int getMin() {
        return head->minimo;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
