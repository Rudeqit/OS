#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "user.h"
#include <stdlib.h>

phonebook* create_phonebook();
int add_user(phonebook* phonebook, size_t id, char* name, char* phone);
void delete_phonebook(phonebook* phonebook);
user* search_by_id(phonebook* phonebook, size_t id);
user* search_by_name(phonebook* phonebook, char* name);
user* search_by_phone(phonebook* phonebook, char* phone);
int remove_user_by_id(phonebook* phonebook, size_t id);

#endif