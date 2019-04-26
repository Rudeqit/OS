#include "interface.h"
#include "phonebook.h"

int main(int argc, char *argv[]) {
    user* phonebook = create_phonebook(1, "Pupa", "+ 7 913");
    phonebook = add_user(phonebook, 2, "Lupa", "8 913");
    printAll(phonebook);
    return 0;
}