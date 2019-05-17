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
    if (position > v->size || position < 0)
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

int *end(vector_int *v, int *status)
{
    /**
     *   Returns an iterator pointing to the last element in the vector.
     */
    return (at(size(v, status), v, status));
}

int back(vector_int *v, int *status)
{
    /**
     *  Returns the value of the last element in the vector.
     */
    int *res;
    if ((res = end(v, status)) != NULL)
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
    return (insert(size(v, status), element, v, status));
}

int *assign(int position, int value, vector_int *v, int *status)
{
    /**
     *  Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
     */
    if (position <= v->size || (*status = expand(position + 1, v)) == 1)
    {
        v->vec[position] = value;
        if (position > v->size)
            v->size = position;
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
        return v->capacity;
    }
    *status = 0;
    return -1;
}

int pop_back(vector_int *v, int *status)
{
    /**
     *  Removes the last element in the vector, effectively reducing the container size by one.
     */
    if (size < 0)
    {
        *status = 0;
        return 0;
    }
    *status = 1;
    v->size -= 1;
    return v->vec[v->size + 1];
}

int empty(vector_int *v, int *status)
{
    /**
     *  Returns whether the vector is empty (i.e. whether its size is 0).
     */
    if (size(v, status) >= 1)
        return 0;
    return 1;
}

void destroy(vector_int *v, int *status)
{
    /**
     *  Destroys the container object.
     */
    if (v != NULL)
    {
        int *vec = v->vec;
        free(vec);
        free(v);
        *status = 1;
        return;
    }
    *status = 0;
    return;
}

void clear(vector_int *v, int *status)
{
    /**
     *  Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
     */
    if (v != NULL)
    {
        int *vec = v->vec;
        free(vec);
        int originalCapacity = capacity(v, status);
        v->size = 0;
        v->capacity = 0;
        *status = expand(originalCapacity, v);
        return;
    }
    *status = 0;
    return;
}

int *insert(int position, int value, vector_int *v, int *status)
{
    /**
     * The vector is extended by inserting new elements before the element at the specified position, effectively increasing the container size by 1.
     */
    if (v == NULL)
    {
        *status = 0;
        return NULL;
    }
    if (position > size(v, status))
    {
        return assign(position, value, v, status);
    }
    *status = 1;
    if (size(v, status) + 1 > capacity(v, status))
        *status = expand(2 * capacity(v, status), v);
    for (int i = size(v, status); i > position; --i)
    {
        v->vec[i] = v->vec[i - 1];
    }
    v->size += 1;
    v->vec[position] = value;
    return &(v->vec[position]);
}

void swap(int i, int j, vector_int *v, int *status)
{
    /**
     * Exchange values of two elements
     */
    if (i > size(v, status) || j > size(v, status))
    {
        *status = 0;
        return;
    }
    int temp = v->vec[i];
    v->vec[i] = v->vec[j];
    v->vec[j] = temp;
    return;
}