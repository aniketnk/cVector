#include "cvector.h"
#include <stdio.h>

int main()
{
    int status;
    void *vec_i = vec_init(2, &status);
    push_back(1, vec_i, &status);
    push_back(2, vec_i, &status);
    push_back(3, vec_i, &status);
    printf((status) ? "success\n" : "fail\n");

    int *res;
    res = at(0, vec_i, &status);
    (status) ? printf("%p :%d\n", res, *res) : printf("fail\n");
    res = at(1, vec_i, &status);
    (status) ? printf("%p :%d\n", res, *res) : printf("fail\n");
    res = at(3, vec_i, &status);
    (status) ? printf("%p :%d\n", res, *res) : printf("fail\n");
    return 1;
}