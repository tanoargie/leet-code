# AGENTS.md

## Repo layout

Flat collection of LeetCode solutions in C++, one file per problem, named `<problem number>.cpp` at the repo root (e.g. `1.cpp`).

## What's in a file

Each file is a LeetCode submission snippet: only the `class Solution` (plus helper methods/classes inside it). It is **not** standalone-compilable:

- No `#include`, no `main`, no local test harness.
- `TreeNode` / `ListNode` / `Node` struct definitions appear as a `/** */` comment block at the top of the file (copied from the LeetCode problem page) — keep this style when writing tree/linked-list solutions; use `nullptr` explicitly in constructors since LeetCode's version differs by problem.
- Style: 2-space indent, opening brace on the same line, `class Solution { public: ... };`.

## How to verify

There is no build system, test runner, or CI. Solutions are verified by submitting to LeetCode. To check a single file, paste the `class Solution` into the problem's editor. Do not add build files or try to compile locally.

## Conventions

- Commit message format: `feat: <problem number>` (older commits sometimes use `feat: exercise N` or `feat: improve N`). Use `feat: <N>` for new solutions.
- If multiple problems are solved in one session, commit each file separately with its number in the message.
