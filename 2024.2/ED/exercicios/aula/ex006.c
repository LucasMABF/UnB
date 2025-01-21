#include <stdio.h>
#include <stdlib.h>

typedef struct queueNode{
  int value;
  struct queueNode *next;
} queueNode;

typedef struct queue{
  queueNode *start;
  queueNode *end;
} queue;

queue new_queue(){
  queue q;
  q.start = NULL;
  q.end = NULL;
  return q;
}

void enqueue(queue *queue, int item){
  queueNode *n = malloc(sizeof(queueNode));
  n->value = item;
  n->next = NULL;

  if(queue->start == NULL){
    queue->start = n;
    queue->end = n;
  }else{
    queue->end->next = n;
    queue->end = n;
  }
}

int dequeue(queue *queue){
  if(queue->start == NULL){
    return -1;
  }
  int i = queue->start->value;
  queueNode *n = queue->start->next; 
  free(queue->start);
  queue->start = n;
  return i;
}

int front(queue *queue){
  if(queue->start == NULL){
    return -1;
  }
  return queue->start->value;
}

int isEmpty(queue *queue){
  return queue->start == NULL;
}

int size(queue *queue){
  int s = 0;
  queueNode *next = queue->start;
  while(next != NULL){
    s++;
    next = next->next;
  }

  return s;
}

int main(){

  queue q = new_queue();

  enqueue(&q, 1);
  enqueue(&q, 2);
  enqueue(&q, 3);
  enqueue(&q, 4);
  enqueue(&q, 5);

  printf("size: %d\n", size(&q));
  printf("empty: %d\n", isEmpty(&q));
  printf("front: %d\n", front(&q));
  printf("item: %d\n", dequeue(&q));
  printf("front: %d\n", front(&q));
  printf("item: %d\n", dequeue(&q));
  printf("item: %d\n", dequeue(&q));
  printf("item: %d\n", dequeue(&q));
  printf("item: %d\n", dequeue(&q));
  printf("item: %d\n", dequeue(&q));
  printf("item: %d\n", dequeue(&q));
  printf("empty: %d\n", isEmpty(&q));

  return 0;
}
