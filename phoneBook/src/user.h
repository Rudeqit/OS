#ifndef USER_H
#define USER_H

#include <string.h>

typedef struct {
    size_t id;
    char* name;
    char* phone;
} user;

typedef struct {
    size_t numbUsers;
    size_t size;
    size_t block_size;
    user** users;
} phonebook;

#endif