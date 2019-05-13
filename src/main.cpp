#include <iostream>
#include "FunctionPointer/FunctionPointer.h"
#include "Struct/Point.h"
#include "Struct/Point3D.h"

using namespace std;

int main(int argc, char *argv[]) {
//    FunctionPointer::print();
//    FunctionPointer::howToUseQsort(argc, argv);
//    FunctionPointer::howToUseStrlen();

    Point *point = new_point();
    Point *point3d = new_point3d();

    point->drawFun(point);
    point3d->drawFun(point3d);

    delete_point(point);

    return 0;
}


