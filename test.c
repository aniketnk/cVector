#include "cvector.h"
#include <stdio.h>

int main()
{
    int status;
    int *res;

    // Initialize vector
    void *vec_i = vec_init(2, &status);

    // Append
    push_back(0, vec_i, &status);
    printf((status) ? "push\t :success\n" : "push\t :fail\n");
    push_back(1, vec_i, &status);
    printf((status) ? "push\t :success\n" : "push\t :fail\n");
    push_back(2, vec_i, &status);
    printf((status) ? "push\t :success\n" : "push\t :fail\n");

    // Random access
    res = at(0, vec_i, &status);
    (status) ? printf("at\t :*(%p) = %d\n", res, *res) : printf("fail\n");
    res = at(1, vec_i, &status);
    (status) ? printf("at\t :*(%p) = %d\n", res, *res) : printf("fail\n");
    // Assign method
    res = assign(4, 4, vec_i, &status);
    (status) ? printf("assign\t :*(%p) = %d\n", res, *res) : printf("fail %p\n", res);

    // Iterate through vector
    printf("iterate\t :");
    for (int *i = begin(vec_i, &status); i <= end(vec_i, &status); i++)
    {
        printf("%d ", *i);
    }
    printf("\n");

    //swap
    swap(1, 4, vec_i, &status);
    (status) ? printf("swap\t :success\n") : printf("swap\t :fail\n");

    //pop_back
    *res = pop_back(vec_i, &status);
    (status) ? printf("pop_back :%d\n", *res) : printf("fail\n");
    *res = pop_back(vec_i, &status);
    (status) ? printf("pop_back :%d\n", *res) : printf("fail\n");

    // Iterate through vector
    printf("iterate\t :");
    for (int *i = begin(vec_i, &status); i <= end(vec_i, &status); i++)
    {
        printf("%d ", *i);
    }
    printf("\n");
    return 1;
}