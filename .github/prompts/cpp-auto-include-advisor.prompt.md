---
description: "Recommend and configure VS Code C++ auto-include workflow with caveats"
name: "C++ Auto Include Advisor"
argument-hint: "project type; toolchain; constraints; current issue"
agent: "agent"
---
Help configure C++ development in VS Code so required headers are inserted or suggested while coding.

Use the slash-command argument as context in this format:
`project type; toolchain; constraints; current issue`

Task:
1. Recommend practical implementation paths in priority order:
   - `clangd` code actions and include cleanup
   - VS Code C/C++ extension IntelliSense and quick fixes
   - `clang-tidy` and/or IWYU for stricter include management
2. For each path, provide:
   - what it can and cannot automate
   - exact setup steps in VS Code
   - required extensions and key settings
   - quick verification steps
3. Choose one best default path for the provided context and explain why.
4. Provide a caution checklist covering:
   - transitive include traps
   - missing or wrong include suggestions
   - `bits/stdc++.h` portability limits
   - GCC, Clang, and MSVC differences
   - indexing and performance costs
5. Provide copy-paste config snippets:
   - `.vscode/settings.json`
   - optional `.clangd` or `clang-tidy` config
6. End with a troubleshooting table with columns:
   - symptom
   - likely cause
   - fix

Output format:
- Section 1: Recommended approach
- Section 2: Setup steps
- Section 3: Caveats and limits
- Section 4: Verification checklist
- Section 5: Troubleshooting

Rules:
- Be explicit about tradeoffs; do not imply perfect auto-include.
- Respond in Simplified Chinese unless the user asks for another language.
- Prefer portable headers by default.
- For competitive-programming context, `bits/stdc++.h` can be listed as an explicit optional shortcut, but always provide a portable alternative include set.
- Keep commands and config snippets minimal and directly usable.
