/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <cmath>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        unsigned long long int num1 = 0;
        unsigned long long int num2 = 0;
        unsigned long long int ans = 0;
        int power = 0;
        //Getting the first number
        while(temp1 != NULL){
            num1 += (temp1->val)*pow(10, power)*1LL;
            power++;
            temp1 = temp1->next;
        }
        power = 0;
        while(temp2 != NULL){
            num2 += (temp2->val)*pow(10,power)*1LL;
            power++;
            temp2 = temp2->next;
        }
        ans = num1 + num2;
        ListNode* l3 = NULL;
        ListNode* temp3 = NULL;
        int digit;
        digit = ans % 10; //extracting the last digit from the number
        ans = ans/10;
        l3 = new ListNode(digit);
        temp3 = l3;
        while(ans != 0){
            digit = ans % 10; 
            ans = ans/10;
            temp3->next = new ListNode(digit);
            temp3 = temp3->next;
        }
        return l3;
    }
};
