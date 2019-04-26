#ifndef USER_H
#define USER_H

typedef struct s_user
{
    unsigned int id;
    char* name;
    char* phone;
    struct s_user* next;
} user;

#endif