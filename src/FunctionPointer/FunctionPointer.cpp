//
// Created by dendy on 19-5-9.
//
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include "FunctionPointer.h"

using namespace std;

size_t FunctionPointer::strlen(const char *str) {
    const char *s;

//    int myNull = 0;

    // 不能用s比较, 关心的问题是NULL和\0有什么区别
    // 因为字符串常量末尾插入的是\0
//    printf("s == NULL: %s\n", str == NULL);
//    printf("s == 0: %s\n", str == 0);
//    printf("s == myNull: %s", str == myNull); // 编译错误

    // 下面这句话表达的是不停的向后移动字符串的首地址
    for (s = str; *s; ++s) {
//        printf("just for break\n");
    }

    return (s - str);
}

void FunctionPointer::howToUseStrlen() {
    char array[10] = "";
    cout << "char array length is: " << FunctionPointer::strlen(array) << endl;
    array[0] = 'L';
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
        cout << array[i];
    }
    cout << endl;

    char *s = "Hello World";
    char s_array[12] = "Hello World";
    cout << "s length is: " << FunctionPointer::strlen(s) << endl;
//    s = &s_array[0];
    s[0] = 'L'; // 越权处理字符串常量, 这东西写保护, 程序异常退出, 打开上面这句注释就可以修改了
    cout << "Use cout print s: " << s << endl;
    printf("Use printf print s: %s\n", s);
}

int FunctionPointer::cmpstringp(const void *p1, const void *p2) {
    /*
    The actual arguments to this function are "pointers to
    pointers to char", but strcmp(3) arguments are "pointers
    to char", hence the following cast plus dereference
     */

    return strcmp(* (char * const *) p1, * (char * const *) p2);

}

int FunctionPointer::howToUseQsort(int argc, char *argv[]) {
    int j;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <string>...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // 第二个参数表示参与排序的元素的个数
    qsort(&argv[1], argc - 1, sizeof(char *), cmpstringp);

    for (j = 1; j < argc; j++)
        puts(argv[j]);

    exit(EXIT_SUCCESS);
}

char* FunctionPointer::inet_ntoa(int a, int b, int c, int d) {
#define NUM_BUFS 4
    static int bufno;
    static struct {
        char addr[16];
    } bufs[NUM_BUFS];

    sprintf(bufs[(bufno + 1) % NUM_BUFS].addr, "%d.%d.%d.%d", a, b, c, d);
    char *s = bufs[(bufno + 1) % NUM_BUFS].addr;
    bufno = (bufno + 1) % NUM_BUFS;

    return s;
#undef NUM_BUFS
}

void FunctionPointer::print() {
    printf("%s To %s\n", inet_ntoa(10, 90, 65, 42), inet_ntoa(192, 168, 0, 1));
}