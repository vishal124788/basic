#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define QUEUE_EMPTY INT_MIN

//voltaile int a ;
typedef struct{
    int *values;
    int head ,tail,num_entries,size;

}queue;

queue* q_create(int max_size){
    queue* q = malloc(sizeof(queue));
    q->size = max_size;
    q->values = malloc(sizeof(int)*q->size);
    q->num_entries = 0;
    q->head = 0;
    q->tail = 0;

    return q ; 
}

void q_destroy(queue *q){
    free(q->values);
    free(q);
}

bool q_empty(queue * q){
    return (q->num_entries == 0 );
}

bool q_full(queue * q){
    return (q->num_entries == q->size);
}

bool q_enqueue(queue *q , int value){
    if(q_full(q)){
        return false ;
    }

    q->values[q->tail] =value ;
    q->num_entries++;
    q->tail = (q->tail +1) % q->size;

    return true;
}

int q_dequeue(queue *q){
    int result;
    if(q_empty(q)){
        return QUEUE_EMPTY;
    }
    result = q->values[q->head];
    q->head = (q->head +1) % q->size;
    q->num_entries--;

    return result ;

}

int main()
{   
    queue *q1 =q_create(5);

    q_enqueue(q1,56);
    q_enqueue(q1,65);
    q_enqueue(q1,66);
    q_enqueue(q1,298);
    q_enqueue(q1,66);
    q_enqueue(q1,63);

    int t;
    while((t= q_dequeue(q1)) != QUEUE_EMPTY){
        printf("*t = %d\n ,t ");
    }

    q_destroy(q1);

    return 0;
}  