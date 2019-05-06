#ifndef INTERFACE_H
#define INTERFACE_H

#include "user.h"
#include <stdio.h>

void printAll(phonebook* phonebook);
void printUser(user* user);
void printRemoveError();
void printSearchError();
void printInputError();
void printAddError();
void printUpdateError();
void printMenu();
void printStart();
int AddMenu(phonebook* phonebook);
int AddMenu_(phonebook* phonebook);
int remove_user_by_id_menu(phonebook* phonebok);
int updateMenu(phonebook* phonebook);
int searchMenu(phonebook* phonebook);

#endif