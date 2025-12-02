# Hanji — Korean Vocabulary Trainer

Hanji is a small command-line program written in C for practicing Korean vocabulary.  
It provides a simple menu to add, delete, and study vocabulary pairs, and stores everything in a plain text file so your data persists between runs.

---

## Features
- Add, and delete Korean ⇄ English word pairs  
- Study mode to review all saved words  
- Automatic load/save to `data/vocabulary.txt`  
- UTF-8 support for Hangul display on Windows  
- Supports up to 1000 vocabulary entries

---

## Screenshot

![Preview](./Screenshot%202025-12-03%20013655.png)

---

## Prerequisites
- Windows (tested)  
- GCC (MinGW, MSYS2, or similar)  
- (Optional) make  

---

## Build & Run (Windows)

### Option 1 — Using `run.bat` (recommended)
1. Install GCC (MinGW or MSYS2).  
2. Double-click `run.bat`, which:
   - switches console to UTF-8  
   - compiles the source files  
   - runs `hanji.exe`

### Option 2 — Using Makefile
```bash
make
./hanji.exe
```

**Notes:** For Hangul to display correctly, use `chcp 65001` and a TrueType font (e.g., Consolas).

---

## Usage

When the program runs:

- **1** → Add Vocabulary  
- **2** → Study Vocabulary 
- **3** → Delete Vocabulary 
- **4** → Exit  

All words are saved automatically to `data/vocabulary.txt`.

---

## Data Format

Stored in `data/vocabulary.txt` (UTF-8).

Each line represents one vocabulary entry.

Editing should be done through the program for best consistency.

---

## Project Structure

```
hanji/
 ├─ src/
 │    ├─ main.c        // main menu + program logic
 │    └─ vocab.c       // vocabulary management
 ├─ include/
 │    └─ vocab.h       // function prototypes & structs
 ├─ data/
 │    └─ vocabulary.txt   // auto-created save file
 ├─ Makefile
 └─ run.bat
```

---

## Advanced Concepts Used

- File handling for saving and loading vocabulary
- Structs to represent words and meanings
- Arrays to store up to 1000 entries
- Modular programming using header files and separate compilation
- String manipulation with `fgets`, `strncpy`, `strcmp`, etc.
- Input sanitization and buffer handling

---

## License & Author

**Author:** Tamim MD 

**Institution:** Computer Science & Engineering, Sejong University

This repository is for educational and coursework purposes.