/**
 * A simple vector library in C
 * 
 * Functions to implement:
 * init() ✓
 * destroy() ✓
 * assign() ✓
 * size() ✓
 * capacity() ✓
 * empty()
 * at() ✓
 * front() ✓ and begin() ✓
 * back() and end() ✓
 * data() ✗
 * push_back() ✓
 * pop_back() ✓
 * insert()
 * erase()
 * swap() ✓
 * clear() ✓
 * sort()
 * binary_search()
 * 
 */

typedef struct
{
    int *vec;
    int size;
    int capacity;
} vector_int;

vector_int *vec_init(int size, int *status);
void destroy(vector_int *v, int *status);
int *assign(int position, int value, vector_int *v, int *status);
int size(vector_int *v, int *status);
int capacity(vector_int *v, int *status);
int empty(vector_int *v, int *status);
int *at(int position, vector_int *v, int *status);
int front(vector_int *v, int *status);
int *begin(vector_int *v, int *status);
int back(vector_int *v, int *status);
int *end(vector_int *v, int *status);
int *push_back(int element, vector_int *v, int *status);
int pop_back(vector_int *v, int *status);
int *insert(int position, int value, vector_int *v, int *status);
void swap(int i, int j, vector_int *v, int *status);
void clear(vector_int *v, int *status);