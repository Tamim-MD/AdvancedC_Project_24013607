#include <stdio.h>                 // for printf, scanf
#include <stdlib.h>                // for exit()
#include "vocab.h"                 // vocabulary function declarations

// Show menu options
void display_menu() {
    printf("=== Hanji: Korean Vocabulary Trainer ===\n");
    printf("1. Add Vocabulary\n");
    printf("2. Study Vocabulary\n");
    printf("3. Delete Vocabulary\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;        // menu choice
    int index;         // index for delete

    initVocabularyStorage();                // allocate memory dynamically
    loadVocabularyFromFile(VOCAB_FILE);     // load stored words

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addVocabulary();                          // add new word
                saveVocabularyToFile(VOCAB_FILE);         // save changes
                break;

            case 2:
                studyVocabulary();                        // review all words
                break;

            case 3:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                index--;                                   // convert 1-based to 0-based
                deleteVocabulary(index);                   // delete entry
                saveVocabularyToFile(VOCAB_FILE);          // save changes
                break;

            case 4:
                printf("Exiting the application.\n");
                saveVocabularyToFile(VOCAB_FILE);          // final save
                freeVocabularyStorage();                   // free DMA before exit
                exit(0);

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    freeVocabularyStorage();
    return 0;
}
