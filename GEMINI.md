# Algorithm Beginner Learning Notes

## Project Overview
This repository contains solutions and learning notes for various algorithm competitions and platforms, including AtCoder, LeetCode, Codeforces, Luogu, and Blue Bridge Cup (Lanqiao). It serves as a personal knowledge base for competitive programming.

## Directory Structure

### Platform-Specific Directories
*   **`atcoder/`**: Solutions for AtCoder contests (e.g., `abc394`).
*   **`CodeForce/`**: Solutions for Codeforces rounds.
*   **`leetcode/`**: LeetCode solutions and study plans.
*   **`luogu/`**: Solutions for Luogu problems.
*   **`blue_braige/`**: Blue Bridge Cup (Lanqiao) preparations and past exam solutions.
*   **`niuke/`**: NowCoder (Niuke) contest and practice problems.
*   **`hydro_oj/`**: Solutions for specific OJ contests (e.g., NTU freshman contest).

### Learning & Resources
*   **`class_learning/`**: Course-specific algorithm notes (e.g., binary search, data structures).
*   **`intro/`**: Introductory code for different languages (C++, Go, Python).
*   **`note/`**: Markdown notes, templates, and debugging tips.
*   **`book/`**: Notes from algorithm books (e.g., "Rujin Xunlian Zhinan").

### Tools
*   **`tools/`**: Utility scripts.
    *   `blog_generator.py`: A Python script to generate Markdown blog posts for solved problems (supports LeetCode and Niuke).

## Languages & Environment
*   **Primary Language:** C++ (Standards defined in `CppProperties.json`).
*   **Other Languages:** Python, Kotlin, Go, C#.
*   **Environment:** Windows (`win32`), VS Code.

## Development Workflow

### 1. Solving Problems
Create a new file in the appropriate directory.
*   **Naming Convention:** Use the problem ID or name (e.g., `A.cpp`, `10487-Closest Sums.cpp`).
*   **C++ Style:** Standard competitive programming style.
    *   `#include <bits/stdc++.h>` or specific headers.
    *   `using namespace std;`.
    *   Single `main` function.

### 2. Building & Running
There is no central build system. Compile and run files individually.
*   **C++:** `g++ filename.cpp -o filename.exe && filename.exe`
*   **Python:** `python filename.py`

### 3. Generating Notes
Use the `blog_generator.py` tool to create structured study notes.
```bash
# Interactive mode
python tools/blog_generator.py

# CLI mode (example)
python tools/blog_generator.py --platform leetcode --code path/to/solution.cpp --url https://leetcode.cn/...
```

## Key Configuration Files
*   `CppProperties.json`: VS Code C/C++ IntelliSense configuration for Windows/MSVC.
*   `AGENTS.md`: Instructions for AI agents (referencing `@/openspec/AGENTS.md`).
