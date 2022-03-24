#ifndef BCGEN_H
#define BCGEN_H

enum StoreLoad {
    Store,
    Load,
};

typedef struct {
    enum StoreLoad is_store;
} Context;

#endif