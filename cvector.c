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
        return NULL;
    }
    *status = 1;
    return &(v->vec[position]);
}

int *begin(vector_int *v, int *status)
{
    /**
     *   Returns an iterator pointing to the first element in the vector.
     */
    return (at(0, v, status));
}

int front(vector_int *v, int *status)
{
    /**
     *  Returns the value of the first element in the vector.
     */
    int *res;
    if ((res = begin(v, status)) != NULL)
        return *res;
    return 0;
}

int expand(int n, vector_int *v)
{
    /**
     *  Resizes the container so that it contains n elements.
     */
    if (n > v->capacity && (v->vec = realloc(v->vec, n)) != NULL)
    {
        v->capacity = n;
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

int *assign(int position, int value, vector_int *v, int *status)
{
    /**
     *  Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
     */
    if (position <= v->size || (*status = expand(position + 1, v)) == 1)
    {
        v->vec[position] = value;
        return &(v->vec[position]);
    }
    return NULL;
}

int size(vector_int *v, int *status)
{
    /**
     *  Returns the number of elements in the vector.
     */
    if (v != NULL)
    {
        *status = 1;
        return v->size;
    }
    *status = 0;
    return -1;
}

int capacity(vector_int *v, int *status)
{
    /**
     *  Returns the size of the storage space currently allocated for the vector, expressed in terms of elements.
     */
    if (v != NULL)
    {
        *status = 1;
        return v->size;
    }
    *status = 0;
    return -1;
}