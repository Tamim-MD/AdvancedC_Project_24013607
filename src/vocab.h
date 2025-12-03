#ifndef VOCAB_H               // include guard start
#define VOCAB_H

#define MAX_WORD_LENGTH 100            // maximum size for Korean word
#define MAX_MEANING_LENGTH 255         // maximum size for English meaning
#define VOCAB_FILE "data/vocabulary.txt"   // default file path

// Structure for storing one vocabulary pair
typedef struct {
    char korean[MAX_WORD_LENGTH];       // Korean word
    char english[MAX_MEANING_LENGTH];   // English meaning
} VocabularyCard;

// Dynamic memory management
void initVocabularyStorage(void);       // allocate memory for vocabulary
void freeVocabularyStorage(void);       // free allocated memory

// Core features
void addVocabulary(void);               // add new word (user input)
void deleteVocabulary(int index);       // delete a word by index
void studyVocabulary(void);             // study mode

// File handling
void loadVocabularyFromFile(const char *filename);   // load data from file
void saveVocabularyToFile(const char *filename);     // save data to file

#endif // VOCAB_H            // include guard end
