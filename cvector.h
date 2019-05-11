/**
 * A simple vector library in C
 * 
 * TODO: 
 * 1. Implement for integers
 * 2. Implement for doubles 
 * 
 * Functions to implement
 * 1. init() to initialize the array
 * 2. length() to get array length
 * 3. at() to get element at index
 * 4. push_back() to append
 * 5. pop_back() to pop last element
 * 6. sort() to sort elements
 * 7. insert_at() to insert at a index
 * 
 */

typedef struct
{
    int *vec;
    int size;
    int capacity;
} vector_int;

vector_int *vec_init(int size, int *status);
int at(int position, vector_int *v, int *status);
int push_back(int element, vector_int *v, int *status);