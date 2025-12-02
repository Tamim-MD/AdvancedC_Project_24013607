#include <stdio.h>                      // file I/O
#include <stdlib.h>                     // general utilities
#include <string.h>                     // string functions
#include "vocab.h"                      // header for vocabulary functions

#define MAX_VOCABULARY_SIZE 1000        // max total entries stored

// Structure used for vocabulary entries
typedef struct {
    char word[MAX_WORD_LENGTH];         // Korean word
    char meaning[MAX_MEANING_LENGTH];   // English meaning
} InternalCard;

static InternalCard vocabulary[MAX_VOCABULARY_SIZE];   // stored vocab list
static int vocabulary_count = 0;                       // how many words stored


// ----------------------------
// Load vocabulary from file
// ----------------------------
void load_vocabulary(const char *filename) {
    FILE *file = fopen(filename, "r");                 // open file in read mode
    if (file == NULL) return;                          // if file doesn't exist, skip

    while (vocabulary_count < MAX_VOCABULARY_SIZE &&
           fscanf(file, "%99[^,],%254[^\n]\n",
                  vocabulary[vocabulary_count].word,
                  vocabulary[vocabulary_count].meaning) == 2) {
        vocabulary_count++;                            // count every loaded entry
    }

    fclose(file);
}


// ----------------------------
// Save vocabulary to file
// ----------------------------
void save_vocabulary(const char *filename) {
    FILE *file = fopen(filename, "w");                 // open for writing
    if (file == NULL) {
        perror("Failed to open vocabulary file for writing");
        return;
    }

    for (int i = 0; i < vocabulary_count; i++) {
        fprintf(file, "%s,%s\n",
                vocabulary[i].word,
                vocabulary[i].meaning);                // save each entry
    }

    fclose(file);
}


// ----------------------------
// Add a new word
// ----------------------------
void add_word(const char *word, const char *meaning) {
    if (vocabulary_count < MAX_VOCABULARY_SIZE) {
        strncpy(vocabulary[vocabulary_count].word, word, MAX_WORD_LENGTH - 1);
        vocabulary[vocabulary_count].word[MAX_WORD_LENGTH - 1] = '\0';

        strncpy(vocabulary[vocabulary_count].meaning, meaning, MAX_MEANING_LENGTH - 1);
        vocabulary[vocabulary_count].meaning[MAX_MEANING_LENGTH - 1] = '\0';

        vocabulary_count++;                            // increase count
    } else {
        printf("Vocabulary limit reached.\n");
    }
}


// ----------------------------
// Display all vocabulary
// ----------------------------
void study_vocabulary() {
    if (vocabulary_count == 0) {
        printf("\nNo vocabulary found.\n");
        printf("Please add words first.\n\n");
        return;
    }

    printf("\n--- Study Mode ---\n");
    for (int i = 0; i < vocabulary_count; i++) {
        printf("%d: Word: %s, Meaning: %s\n",
               i + 1,
               vocabulary[i].word,
               vocabulary[i].meaning);
    }
    printf("------------------\n\n");
}


// ----------------------------
// Wrapper: Add vocabulary (input from user)
// ----------------------------
void addVocabulary(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}    // clear input buffer

    char korean[MAX_WORD_LENGTH];
    char english[MAX_MEANING_LENGTH];

    printf("Enter Korean: ");
    if (!fgets(korean, sizeof(korean), stdin)) return;
    korean[strcspn(korean, "\r\n")] = '\0';

    printf("Enter English: ");
    if (!fgets(english, sizeof(english), stdin)) return;
    english[strcspn(english, "\r\n")] = '\0';

    add_word(korean, english);
    printf("Added: %s = %s\n", korean, english);
}


void studyVocabulary(void) {
    study_vocabulary();
}

void loadVocabularyFromFile(const char *filename) {
    load_vocabulary(filename);
}

void saveVocabularyToFile(const char *filename) {
    save_vocabulary(filename);
}


// ----------------------------
// Delete vocabulary by index
// ----------------------------
void deleteVocabulary(int index) {
    if (index < 0 || index >= vocabulary_count) {
        printf("Index out of range.\n");
        return;
    }

    for (int j = index; j < vocabulary_count - 1; j++) {
        vocabulary[j] = vocabulary[j + 1];              // shift entries left
    }

    vocabulary_count--;                                 // reduce count
}
