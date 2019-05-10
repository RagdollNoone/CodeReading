//
// Created by dendy on 19-5-10.
//

#include <cstdlib>
#include <cstdio>
#include "Point.h"


// 私有函数
void printFreePoint() {
    printf("printFreePoint\n");
}

// 私有函数
void printNewPoint() {
    printf("printNewPoint\n");
}

point *new_point() {
    point *p = (point*) malloc(sizeof(point));

    p->r = 0;
    p->g = 0;
    p->b = 0;

    p->pColor = (color*) malloc(sizeof(color));

    p->pColor->getRedColorFun = getRedColorFun;
    p->pColor->getGreenColorFun = getGreenColorFun;
    p->pColor->getBlueColorFun = getBlueColorFun;

    p->pColor->setRedColorFun = setRedColorFun;
    p->pColor->setGreenColorFun = setGreenColorFun;
    p->pColor->setBlueColorFun = setBlueColorFun;

    p->drawFun = drawFun;

    return p;
}

void delete_point(point * const p) {
    if (NULL != p) {
        free(p);
    }
}

void drawFun(const point *const pPointObj) {
    printf("draw a point, r = %d, g = %d, b = %d\n",
            pPointObj->pColor->getRedColorFun(pPointObj),
            pPointObj->pColor->getGreenColorFun(pPointObj),
            pPointObj->pColor->getBlueColorFun(pPointObj));
}

int getRedColorFun(const point * const pPointObj) {
    return pPointObj->r;
}

int getGreenColorFun(const point * const pPointObj) {
    return pPointObj->g;
}

int getBlueColorFun(const point * const pPointObj) {
    return pPointObj->b;
}

void setRedColorFun(point * const pPointObj, const int value) {
    pPointObj->r = value;
}


void setGreenColorFun(point * const pPointObj, const int value) {
    pPointObj->g = value;
}


void setBlueColorFun(point * const pPointObj, const int value) {
    pPointObj->b = value;
}




