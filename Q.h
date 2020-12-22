#include <stdint.h>
#include "appconst.h"

#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED


typedef struct _queue_ Queue;

struct  _queue_{
    uint32_t    size;
    uint32_t    count;
    uint32_t    rear;
    uint32_t    front;
    int32_t     data[Q_LEN];
};



typedef struct _transaction_details_ tdetails;

struct _transaction_details_{
    int32_t comp_name;
    int32_t status;
    int32_t price;
    int32_t quantity;
};


typedef struct _queue_result_ QueueResult;

struct _queue_result_{
    int32_t     data;
    uint32_t    status;
};

/*Public interface*/
Queue queue_new(uint32_t size);
uint8_t queue_full(Queue *q);
uint8_t queue_empty(Queue *q);
Queue*  buy(Queue *q,int32_t ele,QueueResult *res);
Queue*  sell(Queue *q, QueueResult *res);
uint32_t    queue_length(Queue *q);
uint8_t     q_lookup(const  Queue *q,int32_t key);

uint8_t TradingQ(Queue *q,int32_t ele, int32_t date,int32_t price,int32_t quantity );
#endif // QUEUE_H_INCLUDED



