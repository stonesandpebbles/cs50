/*************************************************************************
 * queue.c
 *
 * Implements a simple queue structure for char* s. This version uses
 * dynamic, heap-allocated storage for the char* s instead of a
 * statically-sized stack array.
 ************************************************************************/

// for strdup() in the testing code
#define _XOPEN_SOURCE 500

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// feel free to change as desired!
#define INITIAL_CAPACITY 5
#define TEST_CAPACITY 10

typedef struct
{
    // the index of the first element in the queue
    int head;

    // dynamic storage for the elements in the queue
    char** strings;

    // the number of elements in the queue
    int size;

    // the allocated capacity of the queue
    int capacity;
}
queue;

// declare a queue (as a global variable)
queue q;

/**
 * Puts a new element into the queue into the "end" of the data structure
 * so that it will be retrived after the other elements already in the
 * queue.
 */
bool enqueue(char* str)
{
    // TODO
    if (str == NULL) return false;
    if (q.size < q.capacity)
    {

        q.strings[q.size] = str;
    }
    
    else
    {
        q.capacity *= 2;
        q.strings = realloc(q.strings, q.capacity * sizeof(char*));
        q.strings[(q.head + q.size) % q.capacity] = str;
        
    }
    q.size += 1;
    return true;
}

/**
 * Retrieves ("dequeues") the first element in the queue, following the
 * the "first-in, first-out" (FIFO) ordering of the data structure.
 * Reduces the size of the queue and adjusts the head to the next element.
 */
char* dequeue(void)
{
    // TODO
    if (q.size == 0)
    {
        return NULL;
    }
    
    char* elem = q.strings[q.head];
    q.head = (q.head + 1) % q.capacity;
    q.size -= 1;
    return elem;
}

/**
 * Implements some simple test code for our queue
 */
int main(void)
{
    // initialize the queue
    q.head = 0;
    q.strings = malloc(INITIAL_CAPACITY * sizeof(char*));
    q.size = 0;
    q.capacity = INITIAL_CAPACITY;

    printf("Enqueueing %d strings...", TEST_CAPACITY);
    for (int i = 0; i < TEST_CAPACITY; i++)
    {
        char str[12];
        sprintf(str, "%d", i);
        enqueue(strdup(str));
    }
    printf("done!\n");

    printf("Making sure that the queue size is indeed %d...", TEST_CAPACITY);
    assert(q.size == TEST_CAPACITY);
    printf("good!\n");

    printf("Dequeueing everything...");
    char* str_array[TEST_CAPACITY];
    for (int i = 0; i < TEST_CAPACITY; i++)
    {
        str_array[i] = dequeue();
    }
    printf("done!\n");

    printf("Making sure that dequeue() returned values in FIFO order...");
    for (int i = 0; i < TEST_CAPACITY; i++)
    {
        char str[12];
        sprintf(str, "%d", i);
        assert(strcmp(str_array[i], str) == 0);
        free(str_array[i]);
    }
    printf("good!\n");

    printf("Making sure that the queue is now empty...");
    assert(q.size == 0);
    printf("good!\n");

    printf("Making sure that dequeue() now returns NULL...");
    assert(dequeue() == NULL);
    printf("good!\n");

    printf("Making sure that the head wraps around appropriately...");
    for (int i = 0; i < TEST_CAPACITY; i++)
    {
        enqueue("cs50!");
    }

    // to make sure that they adjust the head pointer appropriately, we'll
    // enqueue and dequeue a bunch of times to make sure they don't just
    // walk off the end of the char* strings[] array
    for (int i = 0; i < TEST_CAPACITY * 10; i++)
    {
        for (int j = 0; j < TEST_CAPACITY / 2; j++)
        {
            assert(dequeue());
        }

        for (int j = 0; j < TEST_CAPACITY / 2; j++)
        {
            enqueue("cs50!");
        }
    }
    printf("good!\n");

    // reinitialize the queue
    free(q.strings);
    q.head = 0;
    q.strings = malloc(INITIAL_CAPACITY * sizeof(char*));
    q.size = 0;
    q.capacity = INITIAL_CAPACITY;

    for (int i = 0; i < TEST_CAPACITY; i++)
    {
        enqueue("cs50!");
    }

    for (int i = 0; i < TEST_CAPACITY / 2; i++)
    {
        assert(dequeue());
    }

    for (int i = 0; i < TEST_CAPACITY * 2; i++)
    {
        enqueue("cs50!");
    }

    printf("\n********\nSuccess!\n********\n");

    // clean up
    free(q.strings);

    return 0;
}
