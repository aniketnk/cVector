#include "cvector.h"
#include <stdlib.h>

vector_int *vec_init(int size, int *status)
{
    vector_int *v = malloc(sizeof(vector_int));
    if (v)
    {
        v->vec = calloc(size, sizeof(int));
        v->size = 0;
        v->capacity = size;
    }
    *status = v && v->vec; //status = 0 if malloc or calloc fails
    return v;
}

int *at(int position, vector_int *v, int *status)
{
    /**
     *  Returns a reference to the element at position n in the vector.
     */
    if (position >= v->size || position < 0)
    {
        *status = 0; // status = 0 if index out of bounds
        return 0;
    }
    *status = 1;
    return &(v->vec[position]);
}

int expand(vector_int *v)
{
    v->vec = realloc(v->vec, v->capacity * 2);
    if (!v->vec)
        return 0;

    v->capacity *= 2;
    return 1;
}

int *push_back(int element, vector_int *v, int *status)
{
    if (v->size + 1 >= v->capacity)
    {
        *status = expand(v);
    }
    v->vec[v->size++] = element;
    return &(v->vec[v->size]);
}