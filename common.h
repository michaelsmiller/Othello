#ifndef __COMMON_H__
#define __COMMON_H__

#include <vector>

#define other(s) (s == WHITE) ? BLACK : WHITE

enum Side { 
    WHITE, BLACK, NO_SIDE
};

class Move {
   
public:
    int x, y;
    Move(int x, int y) {
        this->x = x;
        this->y = y;
    }
    Move(const Move &a)
    {
        x = a.x;
        y = a.y;
    }
    ~Move() {}

    int getX() { return x; }
    int getY() { return y; }

    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
};

#endif
