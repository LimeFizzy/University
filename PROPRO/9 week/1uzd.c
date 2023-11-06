#include <stdio.h>
#include <math.h>

//a)
typedef struct Point
{
    double x, y;
} Point;

Point createPoint(double x, double y);
void printPoint(Point p);
double getDistance(Point a, Point b);

int main(){
    printPoint(createPoint(2, -3));
    printPoint(createPoint(-4, 5));
    //d)
    printf("%.1lf\n", getDistance(createPoint(2, -3), createPoint(-4, 5)));
    return 0;
}


//c)
Point createPoint(double x, double y){
    Point p0;
    p0.x = x;
    p0.y = y;
    return p0;
}

//b)
void printPoint(Point p){
    printf("(%.1lf,%.1lf)\n", p.x, p.y);
}

//d)
double getDistance(Point a, Point b){
    return sqrt(pow((b.x-a.x), 2) + pow((b.y-a.y), 2));
}