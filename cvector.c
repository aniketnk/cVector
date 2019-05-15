#include "cvector.h"
#include <stdlib.h>

vector_int *vec_init(int size, int *status)
{
    /**
     * Constructs a vector and initializing its contents.
     */
    vector_int *v;
    if ((v = malloc(sizeof(vector_int))) != NULL)
    {
        v->vec = calloc(size, sizeof(int));
        v->size = 0;
        v->capacity = size;
        return v;
    }
    *status = 0; //status = 0 if malloc or calloc fails
    return NULL;
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

int expand(int n, vector_int *v)
{
    /**
     *  Resizes the container so that it contains n elements.
     */
    if (n > v->capacity && (v->vec = realloc(v->vec, n)) != NULL)
    {
        v->capacity *= 2;
        return 1;
    }
    return 0;
}

int *push_back(int element, vector_int *v, int *status)
{
    /**
     * Adds a new element at the end of the vector, after its current last element
     */
    if (v->size + 1 >= v->capacity)
    {
        *status = expand(2 * v->capacity, v);
    }
    v->vec[v->size++] = element;
    return &(v->vec[v->size]);
}