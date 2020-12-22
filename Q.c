#include <assert.h>
#include "Q.h"

#include <stdint.h>

Queue   queue_new(uint32_t size){
    if (size<=MAX_LEN){
        size=(size>0 && size<(Q_LEN)) ? size: Q_LEN;
        Queue q1 = {size, 0, 0,0,{0}};
    }else{
        Queue* sell(q, *res);
        size=(size>0 && size<(Q_LEN)) ? size: Q_LEN;
        Queue q1 = {size, 0, 0,0,{0}};

    }
    return q1;
}

uint8_t  queue_full(Queue *q){
    assert(q!=NULL);
    return(q->count == q->size);
}

uint8_t   queue_empty(Queue *q){
    assert (q != NULL);
    return (q->count == 0);
}

Queue*  buy(Queue *q,int32_t ele, QueueResult *res){
    assert(q!=NULL);

    if (q->count < q->size){
        q->data[q->rear] = ele;
        q->rear = (q->rear+1) %q->size;
        ++q->count;
        res->status = QUEUE_OK;



    }else {
        res->status = QUEUE_FULL;
    }
    return q;
}



Queue* sell(Queue *q, QueueResult *res){
    assert(q!=NULL);
    if(q->count!=0){
        res->data=q->data[q->front];
        q->front=(q->front+1)%q->size;
        --q->count;
        res->status=QUEUE_OK;

    }else{
        res->status=QUEUE_EMPTY;
    }
    return q;
}


uint32_t    queue_length(Queue *q){
    assert(q!=NULL);
    return q->count;
}


uint8_t TradingQ(Queue *q,int32_t ele, int32_t date,int32_t price,int32_t quantity ){
    assert(q!=NULL);

    if (q->count < q->size){
        q->data[q->rear] = ele;

        q->rear = (q->rear+1) %q->size;
        ++q->count;
        res->status = QUEUE_OK;



    }else {
        res->status = QUEUE_FULL;
    }
    return q;
}



uint8_t     q_lookup(const  Queue *q,int32_t key){
    assert (q!=NULL);
    Node *cur = q->rear;

    for (cur = list->rear; cur !=NULL; cur = cur ->next){
        if (cur->data == key){
            break;
        }
    }
    return (cur != NULL); //if cur is NULL, return 0. if cur is not NULL, return 1

}