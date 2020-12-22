#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Q.h"
#include "Q.c"

void test_empty(){
    Queue q1=queue_new(2);
    Queue *q=&q1;
    assert(queue_empty(q));
}

void test_add(){
    Queue q1=queue_new(3);
    Queue *q=&q1;
    QueueResult res;
    q=buy(q, 10, &res);
    q=buy(q, 20, &res);
    q=buy(q, 30, &res);
    q=buy(q, 40, &res);
    assert(queue_length(q)==3);
    assert(res.status==QUEUE_FULL);
    assert(queue_full(q));

}

void test_delete(){
    Queue q1=queue_new(3);
    Queue *q=&q1;
    QueueResult res;
    q=buy(q, 10, &res);
    q=buy(q, 20, &res);
    q=buy(q, 30, &res);

    q=sell(q, &res);
    assert(res.data==10);
    assert(queue_length(q)==2);
    q=sell(q, &res);
    q=sell(q, &res);
    q=sell(q, &res);
    assert(res.status==QUEUE_EMPTY);
    assert(queue_length(q)==0);
}

int main()
{
    //printf("Hello world!\n");
    //test_empty();
    //test_add();

    return 0;
}

