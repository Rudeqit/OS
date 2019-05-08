#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "user.h"
#include <stdlib.h>
#include <stdio.h>

phonebook* create_phonebook();
int add_user(phonebook* phonebook, size_t id, char* name, char* phone);
void delete_phonebook(phonebook* phonebook);
int remove_user_by_id(phonebook* phonebook, size_t id);
user* search_by_id(phonebook* phonebook, size_t id);
user* search_by_name(phonebook* phonebook, char* name);
user* search_by_phone(phonebook* phonebook, char* phone);
int update_user_by_id(phonebook* phonebook, size_t id, char* NewName, char* NewPhone);
int update_name_user_by_id(phonebook* phonebook, size_t id, char* NewName);
int update_phone_user_by_id(phonebook* phonebook, size_t id, char* NewPhone);
char* get_str();
char* to_dynamic_str(char* str);

#endif