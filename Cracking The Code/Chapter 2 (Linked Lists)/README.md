# 2.7 - Intersection Detection
* There are 2 different ways of solving this problem. The first one involves using two sets(C++), we traverse both linked lists: list A and
list B. And the SetA will contain all nodes(memory addresses) from list A while SetB will contain all nodes(memory adresses) from list B.
After that we just check if there is a node from SetA that is also present in SetB.
Time Complexity should be: O(n*log(n)) and Memory Complexity should be: O(n)
* We can do better using unordered_set of C++, which is implemented using a hashtable. Overall, the time complexity would be O(n) but we have
to consider that when we are working with hastables we may have to deal with collisions. So, in the worst case, the insertion/delete/searching
would be O(n). Space complexity would also be O(n).
* And there is the best way of solving this problem, which has a time complexity of O(n) and a space complexity of O(1)
In this way, we do a while(tempA != tempB) and if tempA gets null we assign it to headB. We do the same thing to tempB (when it hits null,
we assign headA to it) And the loop just goes on until tempA == tempB. It is guaranteed that either tempA and tempB will meet at the inter
section or they will meet at the end of the list(NULL pointer). This is guaranteed because when we do this swap between tempA and tempB we are
assuring that both of them will traverse the same number of nodes in an appropriate way.

```c++
ListNode *a_pointer = headA;
ListNode *b_pointer = headB;
        
while(a_pointer != b_pointer){
    if(a_pointer == NULL){
        a_pointer = headB;
    }else{
        a_pointer = a_pointer->next;
    }
            
    if(b_pointer == NULL){
        b_pointer = headA;
    }else{
        b_pointer = b_pointer->next;
    }
}
return a_pointer;
```
