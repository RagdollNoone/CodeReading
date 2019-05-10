//
// Created by dendy on 19-5-10.
//

#ifndef CODEREADING_POINT_H
#define CODEREADING_POINT_H

typedef struct Point point;
typedef struct Color color;

typedef void (*draw)(const point * const); // 虚函数

// 类似抽象类当中, 实现的方法, 被所有子类继承, 通过继承使得get/set方法共享
typedef int (*get_r) (const point * const);
typedef int (*get_g) (const point * const);
typedef int (*get_b) (const point * const);

typedef void (*set_r) (point * const, const int);
typedef void (*set_g) (point * const, const int);
typedef void (*set_b) (point * const, const int);

struct Color {
    get_r getRedColorFun;
    get_g getGreenColorFun;
    get_b getBlueColorFun;

    set_r setRedColorFun;
    set_g setGreenColorFun;
    set_b setBlueColorFun;
} ;

struct Point{
    int r;
    int g;
    int b;

    color *pColor;
    draw drawFun;
};

point *new_point();
void delete_point(point * const);

// 如果有一个函数在.c文件当中出现了, 但是却没有在这里出现
// 意味着这个函数是私有的

//void printFreePoint();
//void printNewPoint();

void drawFun(const point *const pPointObj);

int getRedColorFun(const point * const pPointObj);
int getGreenColorFun(const point * const pPointObj);
int getBlueColorFun(const point * const pPointObj);
void setRedColorFun(point * const pPointObj, const int value);
void setGreenColorFun(point * const pPointObj, const int value);
void setBlueColorFun(point * const pPointObj, const int value);

#endif //CODEREADING_POINT_H
