//
// Created by Daniel Cender on 2019-04-26.
//

#ifndef MAZE1_POINT_H
#define MAZE1_POINT_H

class Point {
private:
    int x, y;
public:
    Point(int x, int y);
    // Imagine I'll need these functions after a while
    Point up(Point& p);
    Point down(Point& p);
    Point left(Point& p);
    Point right(Point& p);
};

#endif //MAZE1_POINT_H
