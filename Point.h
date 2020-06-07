#ifndef _POINT_H
#define _POINT_H

typedef struct {
    int x;
    int y;
    int val;
} Point;

typedef struct pointNode {
    Point p;
    struct pointNode *next;
} PointNode;

Point createPoint(int x, int y, int val);
void setPointNodeVal(PointNode *pointNode, int x, int y, int val);
#endif