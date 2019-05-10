//
// Created by dendy on 19-5-10.
//

#include <cstdlib>
#include <cstdio>
#include "Point3D.h"


point *new_point3d() {
    point *pbase = new_point();
    point3d *p3d = (point3d*) malloc(sizeof(point3d));

    p3d->base = *pbase;
    p3d->base.drawFun = drawPoint3dFun;

    p3d->x = 0;
    p3d->y = 0;
    p3d->z = 0;

    return (point*)p3d;
}

void delete_point(point3d * const pPoint3dObj) {
    if (NULL != pPoint3dObj) {
        delete_point(pPoint3dObj);
        free(pPoint3dObj);
    }
}

void drawPoint3dFun(const point *const pPointObj) {
    printf("draw a 3d point, r = %d, g = %d, b = %d\n",
           pPointObj->pColor->getRedColorFun(pPointObj),
           pPointObj->pColor->getGreenColorFun(pPointObj),
           pPointObj->pColor->getBlueColorFun(pPointObj));
}
