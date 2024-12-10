#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

Point *new_point(int dimension, double coords[]){
  Point *p = malloc(sizeof(Point));
  p->dimension = dimension;
  p->coords = malloc(dimension * sizeof(double));
  if(p->coords == NULL){
    printf("error");
    return NULL;
  }

  for(int i = 0; i < dimension; i++){
    p->coords[i] = coords[i];
  }

  return p;
}

void delete_point(Point *p){
  free(p->coords);
  free(p);
}

Point *add(Point *p1, Point *p2){
  if(p1->dimension != p2->dimension){
    printf("error");
    return NULL;
  }

  double sums[p1->dimension];

  for(int i = 0; i < p1->dimension; i++){
    sums[i] = p1->coords[i] + p2->coords[i];
  }

  return new_point(p1->dimension, sums);
}

void print_point(Point *p){
  printf("(");
  for(int i = 0; i < p->dimension; i++){
    printf("%.1lf", p->coords[i]);
    if(i != p->dimension - 1) printf(", ");
  }
  printf(")\n");
}

double abs_point(Point *p){
  double sum = 0;

  for(int i = 0; i < p->dimension; i++){
    sum += pow(p->coords[i], 2);
  }

  return sqrt(sum);
}

Point *mul_scalar(Point *p, double t){
  double coords[p->dimension];

  for(int i = 0; i < p->dimension; i++){
    coords[i] = p->coords[i] * t;
  }

  return new_point(p->dimension, coords);

}

