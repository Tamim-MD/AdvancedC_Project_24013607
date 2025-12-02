# Hanji — Korean Vocabulary Trainer

Hanji is a small command-line program written in C for practicing Korean vocabulary. It provides a simple menu to add, edit, delete, and study vocabulary pairs and stores everything in a plain text file so your data persists between runs.

---

## Features

- Add, edit, and delete Korean ⇄ English word pairs  
- Study mode to review all saved words  
- Automatic load/save to `data/vocabulary.txt`  
- UTF‑8 support for Hangul display on Windows (when console is UTF‑8 enabled)  
- Supports up to 1000 vocabulary entries

---

## Screenshot

![Preview](./Screenshot%202025-12-02%20193930.png)

---

## Prerequisites

- Windows (tested)  
- GCC (MinGW, MSYS2, or similar) or any C compiler that supports C99  
- (Optional) make

---

## Build & Run (Windows)

Recommended: use the included `run.bat`.

Option 1 — run.bat (recommended)
1. Install GCC (MinGW or MSYS2).  
2. Double-click `run.bat` or run in PowerShell/CMD:
   - It sets the console to UTF‑8 (chcp 65001), compiles sources, and runs `hanji.exe`.

Option 2 — make (if you have `make`)
```bash
make
./hanji.exe
```

Notes
- If you run from a terminal, ensure the console font supports Hangul and the code page is UTF‑8:
  - chcp 65001
  - Use a TrueType font (e.g., Consolas, DejaVu Sans Mono)

---

## Usage

When you run the program, choose from the menu:

1 → Add Vocabulary  
2 → Study Vocabulary  
3 → Exit

Words are saved automatically to `data/vocabulary.txt`. Edit or remove lines only through the program to avoid format issues.

---

## Data Format

- `data/vocabulary.txt` is a UTF‑8 text file.  
- Each entry is saved as a single line in the format used by the program (plain text pairs). Example entry:
  - Korean<TAB>English

(Do not rely on manual edits unless you understand the separator used.)

---

## Project Structure

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

---

## Contributing

- Fixes and improvements are welcome. Keep changes small and document behavior changes.  
- If adding features, follow the existing modular structure (separate functions in src/, declarations in include/).

---

## License & Author

Author: MD Tamim — Computer Science & Engineering, Sejong University

This repository is intended for learning and coursework use. Include any specific license text here if required.