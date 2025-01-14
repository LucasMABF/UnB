#include <stdio.h>

typedef struct Node {
    char value;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Stack* createStack();

int isEmpty(Stack* stack);

void push(Stack* stack, char value);

char pop(Stack* stack);

char peek(Stack* stack);

void freeStack(Stack* stack);

int isValid(char *s){
  Stack *stack = createStack();
  int idx = 0;
  while(1){
    char c = s[idx];
    if(c == '\0'){
      freeStack(stack);
      return 1;
    }else if(c == '{' || c == '[' || c == '('){
      push(stack, c);
    }else if(c == '}'){
      if(pop(stack) != '{'){
        freeStack(stack);
        return 0;
      };
    }else if(c == ']'){
      if(pop(stack) != '['){
        freeStack(stack);
        return 0;
      };
    }else if(c == ')'){
      if(pop(stack) != '('){
        freeStack(stack);
        return 0;
      };
    }
    idx++;
  }
  return 0;
}

int main(){
  char *s = "()";

  printf("%d", isValid(s));
  return 0;
}

