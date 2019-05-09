//
// Created by dendy on 19-5-9.
//

#ifndef CODEREADING_FUNCTIONPOINTER_H
#define CODEREADING_FUNCTIONPOINTER_H
class FunctionPointer {

public:
    static void print();
    static int howToUseQsort(int, char *[]);
    static void howToUseStrlen();

private:
    static char *inet_ntoa(int, int, int, int);
    static int cmpstringp(const void *, const void *);
    static size_t strlen(const char *);
};


#endif //CODEREADING_FUNCTIONPOINTER_H
