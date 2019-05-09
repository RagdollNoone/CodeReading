//
// Created by dendy on 19-5-9.
//
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "FunctionPointer.h"

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