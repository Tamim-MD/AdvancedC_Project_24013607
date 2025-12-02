#include <stdio.h>                      // file I/O
#include <stdlib.h>                     // general utilities
#include <string.h>                     // string functions
#include "vocab.h"                      // header for vocabulary functions

#define MAX_VOCABULARY_SIZE 1000        // max total entries stored

// Internal structure used for file I/O
typedef struct {
    char word[MAX_WORD_LENGTH];         // Korean word
    char meaning[MAX_MEANING_LENGTH];   // English meaning
} InternalCard;

static InternalCard vocabulary[MAX_VOCABULARY_SIZE];   // stored vocab list
static int vocabulary_count = 0;                       // current count


// ----------------------------
// Load vocabulary from file
// ----------------------------
void load_vocabulary(const char *filename) {
    FILE *file = fopen(filename, "r");                 // open file in read mode
    if (file == NULL) return;                          // if no file, skip loading

    while (vocabulary_count < MAX_VOCABULARY_SIZE &&
           fscanf(file, "%99[^,],%254[^\n]\n",
                  vocabulary[vocabulary_count].word,
                  vocabulary[vocabulary_count].meaning) == 2) {
        vocabulary_count++;                             // increase count for each entry
    }

    fclose(file);                                       // close file
}


// ----------------------------
// Save vocabulary to file
// ----------------------------
void save_vocabulary(const char *filename) {
    FILE *file = fopen(filename, "w");                 // open file in write mode
    if (file == NULL) {
        perror("Failed to open vocabulary file for writing");
        return;
    }

    for (int i = 0; i < vocabulary_count; i++) {       // write each entry
        fprintf(file, "%s,%s\n", vocabulary[i].word,
                                vocabulary[i].meaning);
    }

    fclose(file);                                      // close file
}


// ----------------------------
// Add a new word
// ----------------------------
void add_word(const char *word, const char *meaning) {
    if (vocabulary_count < MAX_VOCABULARY_SIZE) {      // check space
        strncpy(vocabulary[vocabulary_count].word, word, MAX_WORD_LENGTH - 1);
        vocabulary[vocabulary_count].word[MAX_WORD_LENGTH-1] = '\0';

        strncpy(vocabulary[vocabulary_count].meaning, meaning, MAX_MEANING_LENGTH - 1);
        vocabulary[vocabulary_count].meaning[MAX_MEANING_LENGTH-1] = '\0';

        vocabulary_count++;                            // increase count
    } else {
        printf("Vocabulary limit reached.\n");         // error if full
    }
}


// ----------------------------
// Delete a word by its Korean text
// ----------------------------
void delete_word(const char *word) {
    for (int i = 0; i < vocabulary_count; i++) {        // search for word
        if (strcmp(vocabulary[i].word, word) == 0) {    // match found
            for (int j = i; j < vocabulary_count - 1; j++)
                vocabulary[j] = vocabulary[j + 1];      // shift entries left

            vocabulary_count--;                         // decrease count
            return;
        }
    }
    printf("Word not found.\n");                        // if no match
}


// ----------------------------
// Edit a word's text & meaning
// ----------------------------
void edit_word(const char *old_word, const char *new_word, const char *new_meaning) {
    for (int i = 0; i < vocabulary_count; i++) {         // search entry
        if (strcmp(vocabulary[i].word, old_word) == 0) {
            strncpy(vocabulary[i].word, new_word, MAX_WORD_LENGTH - 1);
            vocabulary[i].word[MAX_WORD_LENGTH-1] = '\0';

            strncpy(vocabulary[i].meaning, new_meaning, MAX_MEANING_LENGTH - 1);
            vocabulary[i].meaning[MAX_MEANING_LENGTH-1] = '\0';
            return;
        }
    }
    printf("Word not found.\n");
}


// ----------------------------
// Display all vocabulary
// ----------------------------
void study_vocabulary() {
    if (vocabulary_count == 0) {                         // check empty
        printf("\nNo vocabulary found.\n");
        printf("Please add words first.\n\n");
        return;
    }

    printf("\n--- Study Mode ---\n");
    for (int i = 0; i < vocabulary_count; i++) {         // list all
        printf("%d: Word: %s, Meaning: %s\n",
               i + 1, vocabulary[i].word, vocabulary[i].meaning);
    }
    printf("------------------\n\n");
}


// ----------------------------
// Wrapper: Add vocabulary (user input)
// ----------------------------
void addVocabulary(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}    // clear input buffer

    char korean[MAX_WORD_LENGTH];
    char english[MAX_MEANING_LENGTH];

    printf("Enter Korean: ");
    if (!fgets(korean, sizeof korean, stdin)) return;
    korean[strcspn(korean, "\r\n")] = '\0';             // remove newline

    printf("Enter English: ");
    if (!fgets(english, sizeof english, stdin)) return;
    english[strcspn(english, "\r\n")] = '\0';

    add_word(korean, english);                           // store new word
    printf("Added: %s = %s\n", korean, english);
}


void studyVocabulary(void) {
    study_vocabulary();                                  // wrapper call
}


void loadVocabularyFromFile(const char *filename) {
    load_vocabulary(filename);                           // wrapper call
}


void saveVocabularyToFile(const char *filename) {
    save_vocabulary(filename);                           // wrapper call
}


// ----------------------------
// Edit by index (menu uses index instead of string match)
// ----------------------------
void editVocabulary(int index, const char *korean, const char *english) {
    if (index < 0 || index >= vocabulary_count) {        // index valid?
        printf("Index out of range.\n");
        return;
    }

    strncpy(vocabulary[index].word, korean, MAX_WORD_LENGTH - 1);
    vocabulary[index].word[MAX_WORD_LENGTH-1] = '\0';

    strncpy(vocabulary[index].meaning, english, MAX_MEANING_LENGTH - 1);
    vocabulary[index].meaning[MAX_MEANING_LENGTH-1] = '\0';
}


// ----------------------------
// Delete by index
// ----------------------------
void deleteVocabulary(int index) {
    if (index < 0 || index >= vocabulary_count) {        // index valid?
        printf("Index out of range.\n");
        return;
    }

    for (int j = index; j < vocabulary_count - 1; j++)
        vocabulary[j] = vocabulary[j + 1];               // shift entries left

    vocabulary_count--;                                  // reduce count
}
