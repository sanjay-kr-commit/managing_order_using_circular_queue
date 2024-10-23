#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

typedef struct circular_queue circular_queue;

circular_queue *create_circular_queue( int limit );

void push_circular_queue( circular_queue *queue, int data );

int pop_circular_queue( circular_queue *queue );

void print_circular_queue(const circular_queue *queue );

int size_circular_queue( const circular_queue *queue );

#endif //CIRCULAR_QUEUE_H
