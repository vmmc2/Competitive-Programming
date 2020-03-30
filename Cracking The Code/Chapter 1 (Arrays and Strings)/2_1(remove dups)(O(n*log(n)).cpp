#include <cmath>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// LINKED LIST DATA STRUCTURE AND METHODS //
struct node{
  int val;
  struct node *next;
  node(int x): val(x), next(NULL) {}
};

struct node *head = NULL;
struct node *tail = NULL;

void append(int val){
  //lista ta inicialmente vazia.
  if(head == NULL && tail == NULL){
    struct node *temp = new node(val);
    head = temp;
    tail = temp;
    return;
  }
  //lista nao ta vazia. Ou seja, tail nao aponta para NULL
  tail->next = new node(val);
  tail = tail->next;
  return;
}
void print_list(struct node *temp){
  while(temp != NULL){
    cout << temp->val << " -> ";
    temp = temp->next;
  }
  cout << "NULL" << "\n";
  return;
}
///////////////////////////////////////////


void delete_duplicate(struct node *temp){
  map<int,bool> hashtable;
  while(temp->next != NULL){
    if(hashtable[temp->next->val] == true){
      temp->next = temp->next->next;
    }else{
      hashtable[temp->next->val] = true;
      temp = temp->next;
    }
  }
  return;
}


int main() {
  ios_base::sync_with_stdio(false);
  append(pow(2,31)*(-1)); //Node sentinela.
  //for(int i = 1; i <= 10; i++){
    append(1);
    append(1);
    append(1);
    append(3);
    append(4);
    append(4);
    append(5);
  //}
  print_list(head);
  delete_duplicate(head);
  print_list(head);
  return 0;
}
