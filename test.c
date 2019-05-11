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

    int res = at(0, vec_i, &status);
    printf((status) ? "%d\n" : "fail\n", res);
    res = at(1, vec_i, &status);
    printf((status) ? "%d\n" : "fail\n", res);
    res = at(3, vec_i, &status);
    printf((status) ? "%d\n" : "fail\n", res);
    return 1;
}