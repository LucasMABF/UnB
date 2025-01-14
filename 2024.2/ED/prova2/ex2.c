#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* trocaLista(struct ListNode* head) {

  if(head == NULL){
    return NULL;
  }

  if(head->next == NULL){
    return head;
  }

  struct ListNode* tmp = head->next->next;
  struct ListNode* tmp1 = head->next;
  head->next->next = head;
  head->next = trocaLista(tmp);
  return tmp1;
}
int main(){
  return 0;
}

// 1 2 3 4 5 6 7 
// 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> -> NULL 
// 2 1 4 3 6 5
// 2 -> 1 -> 4 -> 3 -> 6 -> 5 -> NULL 

