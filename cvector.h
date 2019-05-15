/**
 * A simple vector library in C
 * 
 * Functions to implement:
 * 1. init()  - Initialize a vector
 * 2. destroy()
 * 3. assign()
 * 4. size()
 * 5. capacity()
 * 6. empty()
 * 7. at()
 * 8. front()
 * 9. back()
 * 10. data()
 * 11. push_back()
 * 12. pop_back()
 * 13. insert()
 * 14. erase()
 * 15. swap()
 * 16. clear()
 * 17. sort()
 * 18. binary_search()
 * 
 */

typedef struct
{
    int *vec;
    int size;
    int capacity;
} vector_int;

vector_int *vec_init(int size, int *status);
int *at(int position, vector_int *v, int *status);
int *push_back(int element, vector_int *v, int *status);