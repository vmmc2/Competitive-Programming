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
        ListNode* l3 = NULL;
        ListNode* temp3 = NULL;
        int carry = 0;
        int sumdigits;
        int digito;
        
        for(int i = 1; i > 0; i++){
            if(temp1 == NULL) break; //percorri toda a lista 1
            if(temp2 == NULL) break; //percorri toda a lista 2
            sumdigits = (temp1->val) + (temp2->val) + carry;
            if(carry == 1) carry = 0;
            if(sumdigits > 9){
                digito = sumdigits % 10;
                carry = 1;
            }else{
                digito = sumdigits;
            }
            if(i == 1){
                temp3 = new ListNode(digito);
                l3 = temp3;
            }else{
                temp3->next = new ListNode(digito);
                temp3 = temp3->next;
            } 
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if(temp1 == NULL && temp2 == NULL){
            if(carry == 0)return l3;
            else{
                temp3->next = new ListNode(carry);
                temp3 = temp3->next;
                return l3;
            }
        }
        if(temp1 == NULL && temp2 != NULL){
            if(carry == 1){
                sumdigits = temp2->val + carry;
                if(sumdigits > 9){
                    digito = sumdigits % 10;
                    carry = 1;
                }else{
                    digito = sumdigits;
                    carry = 0;
                }
                temp3->next = new ListNode(digito);
                temp3 = temp3->next;
                temp2 = temp2->next;
                while(temp2 != NULL){
                    sumdigits = temp2->val + carry;
                    if(sumdigits > 9){
                        digito = sumdigits % 10;
                        carry = 1;
                    }else{
                        digito = sumdigits;
                        carry = 0;
                    }
                    temp3->next = new ListNode(digito);
                    temp3 = temp3->next;
                    temp2 = temp2->next;
                }
                if(carry == 1){
                    temp3->next = new ListNode(carry);
                    temp3 = temp3->next;
                }
            }else{
                while(temp2 != NULL){
                    temp3->next = new ListNode(temp2->val);
                    temp3 = temp3->next;
                    temp2 = temp2->next;
                }
            }
            return l3;
        }
        if(temp1 != NULL && temp2 == NULL){
            if(carry == 1){
                sumdigits = temp1->val + carry;
                if(sumdigits > 9){
                    digito = sumdigits % 10;
                    carry = 1;
                }else{
                    digito = sumdigits;
                    carry = 0;
                }
                temp3->next = new ListNode(digito);
                temp3 = temp3->next;
                temp1 = temp1->next;
                while(temp1 != NULL){
                    sumdigits = temp1->val + carry;
                    if(sumdigits > 9){
                        digito = sumdigits % 10;
                        carry = 1;
                    }else{
                        digito = sumdigits;
                        carry = 0;
                    }
                    temp3->next = new ListNode(digito);
                    temp3 = temp3->next;
                    temp1 = temp1->next;
                }
                if(carry == 1){
                    temp3->next = new ListNode(carry);
                    temp3 = temp3->next;
                }
            }else{
                while(temp1 != NULL){
                    temp3->next = new ListNode(temp1->val);
                    temp3 = temp3->next;
                    temp1 = temp1->next;
                }
            }
            return l3;
        }
        return l3;
    }
};
