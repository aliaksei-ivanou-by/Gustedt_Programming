#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 100
#define SIZE_MAX (size_t)-1

void initialize(size_t parent[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        parent[i] = SIZE_MAX;
    }
}

size_t find(size_t parent[], size_t index) {
    size_t i = index;
    while (parent[i] != SIZE_MAX) {
        i = parent[i];
    }
    return i;
}

void findCompress(size_t parent[], size_t index) {
    size_t root = find(parent, index);
    size_t i = index;
    while (i != root) {
        size_t p = parent[i];
        parent[i] = root;
        i = p;
    }    
}

void findReplace(size_t parent[], size_t index, size_t value) {
    size_t i = index;
    do {
        size_t p = parent[i];
        parent[i] = value;
        i = p;
    } while (i != SIZE_MAX);
}

void unionSets(size_t parent[], size_t left, size_t right) {
    findCompress(parent, left);
    size_t root = find(parent, left);
    findReplace(parent, right, root);
}

void print(size_t arr[], size_t length) {
    printf("[ ");
    for (size_t i = 0; i<length; i++) {
        printf("%zu: %zu\n", i, *(arr+i));
    }
    printf("]\n");
}

int main(void) {
    size_t parent[TABLE_SIZE];
    initialize(parent, TABLE_SIZE);

    for (size_t i = 1; i<100; i++) {
        findReplace(parent, i, i-1);
    }
    parent[50] = SIZE_MAX;
    print(parent, TABLE_SIZE);

    unionSets(parent, 48, 98);
    print(parent, TABLE_SIZE);
	
	return EXIT_SUCCESS;
}
