// Lista 3 - D - Hash Tables: Ransom Note
#include <stdio.h>
#include <string.h>

#define HT_SIZE 100
#define WORD_SIZE 20

typedef struct Node{
  char word[WORD_SIZE];
  int count;
  struct Node *next;
} Node;


int hash(char *s){
  int len = strlen(s);
  int hash = 0;
  for(int i = 0; i < len; i++){
    hash += s[i];
    hash = (hash * s[i]) % HT_SIZE;
  }

  return hash;
}

int ht_add(Node **ht, Node *n){
  int index = hash(n->word);
  Node *current = ht[index];
  while(current != NULL){
    if(strcmp(n->word, current->word) == 0){
      current->count++;
      return index;
    }
    current = current->next;
  }
  n->next = ht[index];
  ht[index] = n;
  return index;
}

Node *ht_find(Node **ht, char *s){
  int index = hash(s);
  Node *current = ht[index];
  while(current != NULL && strcmp(s, current->word) != 0){
    current = current->next;
  }
  return current;
}


int main(){
  int n, m;
  scanf("%d %d", &n, &m);

  Node * ht[HT_SIZE];
  memset(ht, 0, HT_SIZE * sizeof(ht[0]));

  Node magazine[n];
  for(int i = 0; i < n; i++){
    scanf("%s", magazine[i].word);
    magazine[i].count = 1;
    magazine[i].next = NULL;
    ht_add(ht, &magazine[i]);
  }


  int no = 0;
  for(int i = 0; i < m; i++){
    char word[6];
    scanf("%s", word);
    Node *tmp = ht_find(ht, word);
    if(tmp == NULL){
      no = 1;
      break;
    }
    tmp->count--;
    if(tmp->count < 0){
      no = 1;
      break;
    }
  }

  if(no){
    printf("No\n");
  }else{
    printf("Yes\n");
  }

  return 0;
}

