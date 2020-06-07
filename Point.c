#include "Point.h"
#include <stdlib.h>
Point createPoint(int x, int y, int val) {
    Point p;
    
    p.x = x;
    p.y = y;
    p.val = val;
    return p;
}

void setPointNodeVal(PointNode *pointNode, int x, int y, int val) {
    
    PointNode *current = pointNode;
    while (current != NULL) {
        if (current->p.x == x && current->p.y == y && current->p.val != val) {
            current->p.val = val;
            return;
        }
        current = current->next;
    }
    
}



