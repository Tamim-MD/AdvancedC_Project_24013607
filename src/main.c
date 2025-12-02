#include <stdio.h>                 // for printf, scanf
#include <stdlib.h>                // for exit()
#include "vocab.h"                 // header for vocabulary functions

// Show menu options to the user
void display_menu() {
    printf("=== Hanji: Korean Vocabulary Trainer ===\n");
    printf("1. Add Vocabulary\n");
    printf("2. Study Vocabulary\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;                    // stores user menu choice

    loadVocabularyFromFile(VOCAB_FILE);   // load saved vocabulary

    while (1) {                    // main program loop
        display_menu();            // show menu
        scanf("%d", &choice);      // read user choice

        switch (choice) {          // handle selected option
            case 1:
                addVocabulary();                           // add new word
                saveVocabularyToFile(VOCAB_FILE);          // save after adding
                break;

            case 2:
                studyVocabulary();                         // show study list
                break;

            case 3:
                printf("Exiting the application.\n");
                exit(0);                                   // terminate program

            default:
                printf("Invalid option. Please try again.\n"); // wrong input
        }
    }

    return 0;                      // not reached (exit() used)
}
