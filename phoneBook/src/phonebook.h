#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "user.h"
#include <stdlib.h>

phonebook *create_phonebook();
int add_user(phonebook *phonebook, size_t id, char* name, char* phone);
void delete_phonebook(phonebook* phonebook);

#endif