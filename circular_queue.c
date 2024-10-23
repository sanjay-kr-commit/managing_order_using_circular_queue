#include "circular_queue.h"

#include <stdio.h>
#include <stdlib.h>

struct circular_queue {
    int max_size ,
        front ,
        rear ,
        *buffer ;
};

circular_queue* create_circular_queue(const int limit ) {
    circular_queue *queue = malloc(sizeof(circular_queue));
    queue->buffer = malloc(sizeof(int)*limit);
    queue->max_size = limit ;
    queue->front = 0 ;
    queue->rear = 0 ;
    return queue;
}

void push_circular_queue( circular_queue *queue, int data ) {
    if ( queue == NULL ) {
        printf( "Queue is null\n" ) ;
        return;
    }
    if ( queue->rear - queue->front == queue->max_size ) {
        printf( "Queue is at maximum size : %d\n" , queue->max_size ) ;
        return;
    }
    queue->buffer[queue->rear++%queue->max_size] = data ;
}

int pop_circular_queue( circular_queue *queue ) {
    if ( queue == NULL ) {
        printf( "Queue is null\n" ) ;
        return -1 ;
    }
    if ( queue->rear - queue->front == 0 ) {
        printf( "Queue is empty\n" ) ;
        return -1 ;
    }
    return queue->buffer[queue->front++%queue->max_size] ;
}

void print_circular_queue(const circular_queue *queue ) {
    if ( queue == NULL ) {
        printf( "Queue is null\n" ) ;
        return;
    }
    for ( int i = queue->front ; i < queue->rear ; i++ ) {
        printf( "%d -> " , queue->buffer[i%queue->max_size] ) ;
    }
    printf( "NULL\n" ) ;
}

int size_circular_queue( const circular_queue *queue ) {
    return queue->rear - queue->front ;
}