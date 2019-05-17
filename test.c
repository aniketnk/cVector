#include "cvector.h"
#include <stdio.h>

int main()
{
    int status;

    // Initialize vector
    void *vec_i = vec_init(2, &status);

    // Append
    push_back(0, vec_i, &status);
    push_back(1, vec_i, &status);
    push_back(2, vec_i, &status);
    printf((status) ? "success\n" : "fail\n");

    int *res;
    // Random access
    res = at(0, vec_i, &status);
    (status) ? printf("%p :%d\n", res, *res) : printf("fail\n");
    res = at(1, vec_i, &status);
    (status) ? printf("%p :%d\n", res, *res) : printf("fail\n");
    // Assign method
    res = assign(4, 4, vec_i, &status);
    (status) ? printf("%p :%d\n", res, *res) : printf("fail %p\n", res);

    // Iterate through vector
    for (int *i = begin(vec_i, &status); i <= end(vec_i, &status); i++)
    {
        printf("%d ", *i);
    }
    printf("\n");
    // printf("\n%p %p\n", begin(vec_i, &status), end(vec_i, &status));
    return 1;
}