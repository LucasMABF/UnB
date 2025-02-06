// Aula compressão com Algoritmo de Huffman
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
  unsigned char value;
  int freq;
  struct No *dir;
  struct No *esq;
} No;

typedef struct NoList{
  No *value;
  struct NoList* next;
}NoList;

NoList *insertnode(NoList *list, No *value){
  if(list == NULL || value->freq <= list->value->freq){
    NoList *new_list_node = malloc(sizeof(NoList));
    if(new_list_node == NULL) exit(1);
    new_list_node->next = list;
    new_list_node->value = value;
    return new_list_node;
  }

  
  list->next = insertnode(list->next, value);
  return list;
}

typedef struct charList{
  char value;
  struct charList *next;
} charList;

charList *insertNodeChar(charList *list, char value){
  charList *new = malloc(sizeof(charList));
  if(new == NULL) exit(1);
  new->next = list;
  new->value = value;
  return new;
}

No *CreateTree(FILE *fd, FILE *output){
  int hashmap[256];
  memset(hashmap, 0, 256 * sizeof(int));

  unsigned char c;
  int n_folhas = 0;
  while(1){
    c = fgetc(fd);
    if(feof(fd)) break;
    if(hashmap[c] == 0) {
      n_folhas++;
    }
    hashmap[c]++;
  }
  
  fprintf(output, "%c", n_folhas - 1);

  NoList *list = NULL; 

  for(int i = 0; i < 256; i++){
    if(hashmap[i] == 0) continue;

    No *new = malloc(sizeof(No));
    if(new == NULL) exit(1);
    new->value = i;
    new->freq = hashmap[i];
    new->dir = NULL;
    new->esq = NULL;

    list = insertnode(list, new);
  }

  while(list && list->next){
    No *n1 = list->value;
    No *n2 = list->next->value;

    NoList *new_head = list->next->next;
    free(list->next);
    free(list);
    list = new_head;

    No *new = malloc(sizeof(No));
    if(new == NULL) exit(1);
    new->freq = n1->freq + n2->freq;
    new->esq = n1;
    new->dir = n2;

    list = insertnode(list, new);
  }

  if(!list) return NULL;
  No *result = list->value;
  free(list);
  return result;
}

int getAllcodes(No *tree, char **hashmap, charList *list, FILE *output){
  int n_bits = 0;

  if(tree->esq){
    list = insertNodeChar(list, '0');
    n_bits += getAllcodes(tree->esq, hashmap, list, output);
    charList *tmp = list;
    list = list->next;
    free(tmp);
  }

  if(tree->dir){
    list = insertNodeChar(list, '1');
    n_bits += getAllcodes(tree->dir, hashmap, list, output);
    charList *tmp = list;
    list = list->next;
    free(tmp);
  }

  if(!tree->dir && !tree->esq){
    int len = 1;
    if(!list) return 0;

    charList *atual  = list;
    while(atual->next != NULL){
      len++;
      atual = atual->next;
    }

    char *str = malloc(sizeof(char) * (len + 1));
    if(!str) exit(1);
    str[len] = '\0';

    atual = list;
    for(int i = 1; i <= len; i++){
      str[len - i] = atual->value;
      atual = atual->next;
    }

    fprintf(output, "%c%c%s", tree->value, len, str);
    hashmap[tree->value] = str;
    n_bits += tree->freq * len;
  }

  return n_bits;
}

void compress(FILE *in, FILE *output, char **hashmap, int padding){
  int count = padding;
  unsigned char byte = 0;
  while(1){
    unsigned char c = fgetc(in);
    if(feof(in)) break;

    if(hashmap[c] == NULL){
      printf("shouldn't happen!\n");
      exit(1);
    }

    int size = strlen(hashmap[c]);
    for(int i = 0; i < size; i++){
      byte *= 2;
      if(hashmap[c][i] == '1'){
          byte++;
      }
      count++;

      if(count == 8){
        fprintf(output, "%c", byte);
        byte = 0;
        count = 0;
      }
    }
  }
}

void freeHashMap(char **hashmap){
  for(int i = 0; i < 256; i++){
    if(hashmap[i] == NULL) continue;

    free(hashmap[i]);
  }
}

void freeTree(No *tree){
  if(tree->esq){
    freeTree(tree->esq);
  }

  if(tree->dir){
    freeTree(tree->dir);
  }

  free(tree);
}

No *reassembleTree(FILE *in){
  No *head = malloc(sizeof(No));
  if(head == NULL) exit(1);

  int n = fgetc(in) + 1;
  for(int i = 0; i < n; i++){
    char value = fgetc(in);
    unsigned char size = fgetc(in);
    No *atual = head;
    for(int i = 0; i < size; i++){
      char c = fgetc(in);
      if(c == '0'){
        if(atual->esq){
          atual = atual->esq;
        }else{
          No *new = malloc(sizeof(No));
          if(new == NULL) exit(1);
          atual->esq = new;
          atual = new;
        }
      }else if(c == '1'){
        if(atual->dir){
          atual = atual->dir;
        }else{
          No *new = malloc(sizeof(No));
          if(new == NULL) exit(1);
          atual->dir = new;
          atual = new;
        }
      }else{
        printf("shouldn't happen\n");
        exit(1);
      }
    }
    atual->value = value;
  }

  return head;
}

void decompress(FILE *in, No *tree, FILE *output){
  int padding = fgetc(in); // remove padding
  No *atual = tree;
  while(1){
    unsigned char byte = fgetc(in);
    if(feof(in)) break;

    for(int i = padding; i < 8; i++){
      int bit = (byte >> (7 - i)) & 1;

      if(bit){
        atual = atual->dir;
      }else{
        atual = atual->esq;
      }

      if(!atual->dir && !atual->esq){
        fprintf(output, "%c", atual->value);
        atual = tree;
      }
    }
    padding = 0;
  }
}

int main(int argc, char* argv[]){
  if(argc != 4){
    printf("Incorrect arguments.\n");
    printf("First argument should be subcommand: \"compress\" or \"decompress\".\n");
    printf("Second argument should be the file to be compressed or decompressed.\n");
    printf("Third argument should be the destination file.\n");
    return 1;
  }
  FILE *in = fopen(argv[2], "rb");
  if(in == NULL){
    printf("Error: Unable to open file.\n");
    return 1;
  }

  FILE *output = fopen(argv[3], "wb");
  if(output == NULL){
    printf("Error: Unable to write file.\n");
    return 1;
  }


  if(strcmp(argv[1], "compress") == 0){
    No *tree = CreateTree(in, output);
    if(!tree) {
      printf("Error: Unable to create tree from file.\n");
      exit(1);
    };

    fseek(in, 0, SEEK_SET);

    char **hashmap = malloc(256 * sizeof(char*));
    memset(hashmap, 0, 256 * sizeof(char*));
    int n_bits = getAllcodes(tree, hashmap, NULL, output);
    
    if(!n_bits) {
      printf("Error: Unable to create tree from file.\n");
      exit(1);
    };
    
    int padding = (8 - (n_bits % 8)) % 8;
    fprintf(output, "%c", padding);

    compress(in, output, hashmap, padding);

    freeHashMap(hashmap);
    freeTree(tree);

  }else if(strcmp(argv[1], "decompress") == 0){
    No *tree = reassembleTree(in);

    decompress(in, tree, output);
    freeTree(tree);

  }else{
    printf("Invalid subcommand.\n");
    return 1;
  }

  fclose(in);
  fclose(output);

  printf("Operation performed successfully!\n");

  return 0;
}

