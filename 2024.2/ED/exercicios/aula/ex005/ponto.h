typedef struct {
  int dimension;
  double *coords;
} Point;


Point *new_point(int dimension, double coords[]);

void delete_point(Point *p1);

Point *add(Point *p1, Point *p2);

void print_point(Point *p1);

double abs_point(Point *p1);

Point *mul_scalar(Point *p, double t);
