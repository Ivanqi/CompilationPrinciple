#ifndef UTIL_H
#define UTIL_H

typedef char *string;

#define LIST(name)              \
typedef struct name##List_s {   \
    int size;                   \
    int length;                 \
    name *array;                \
} name##List;                   \
                                \
void append_##name(name##List *list, name n);           \
int list_find_index_##name(name##List* list, name n);   \
name##List* create_##name##_list();

#define LIST_APPEND(name)                                               \
void append_##name(name##List* list, name n) {                          \
    if (list->length >= list->size) {                                   \
        name *new_arr = (name*)malloc(list->size * 2 * sizeof(name));   \
        for (int i = 0; i < list->size; i++) {                          \
            new_arr[i] = list->array[i];                                \
        }                                                               \
        free(list->array);                                              \
        list->size *= 2;                                                \
        list->array = new_arr;                                          \
    }                                                                   \
    list->array[list->length++] = n;                                    \
}                                                                       \

#define LIST_CREATE(name)                                               \
name##List* create_##name##_list() {                                    \
    name##List *list = (name##List *) malloc(sizeof(name##List));       \
    list->size = 8;                                                     \
    list->length = 0;                                                   \
    list->array = (name *) malloc(sizeof(name) * 8);                    \
}                                                                       \

#define LIST_FIND(name)                                                 \
int list_find_index_##name(name##List *list, name n) {                  \
    for (int i = 0; i < list->length; i++) {                            \
        if (list->array[i] == n)    {                                   \
            return i;                                                   \
        }                                                               \
    }                                                                   \
    return -1;                                                          \
}                                                                       \

typedef char byte;

LIST(int)
LIST(byte)
LIST(string)
#endif