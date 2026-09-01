# AGENTS.md

## Repo layout

LeetCode solutions in C++, one directory per problem: `problems/<n>/solution.cpp` is the submission snippet; `problems/<n>/test.cpp` (optional) holds GoogleTest cases for it. `harness/leet.h` provides `TreeNode` / `ListNode` / `Node` variants and tree/list builders used by tests.

## What's in a solution file

Each `solution.cpp` is a LeetCode paste-ready snippet: only the `class Solution` (plus helper methods/classes inside it). It is **not** standalone-compilable:

- No `#include`, no `main`, no test harness. Never add includes to it — tests include `solution.cpp` instead.
- `TreeNode` / `ListNode` / `Node` struct definitions appear as a `/** */` comment block at the top of the file (copied from the LeetCode problem page) — keep this style when writing tree/linked-list solutions; use `nullptr` explicitly in constructors since LeetCode's version differs by problem.
- Style: 2-space indent, opening brace on the same line, `class Solution { public: ... };`.

## How to build and test

```sh
cmake -S . -B build       # first run downloads GoogleTest
cmake --build build -j
./build/lc_<n>            # one problem's tests
ctest --test-dir build    # all registered tests
```

Tests are written when solving new problems, not retroactively for existing ones.

## Writing tests

- Test file `problems/<n>/test.cpp` includes `"solution.cpp"` from the same directory and `"harness/leet.h"` (include dir is the repo root).
- `solution.cpp` files rely on LeetCode's implicit preamble: test files must include the standard headers the solution needs (e.g. `<unordered_map>`, `<string>`, `<stack>`) and add `using namespace std;` before including `solution.cpp` — unqualified names like `vector` or `unordered_map` will not compile otherwise.
- Solutions take non-const references (`vector<int>&`): pass lvalues, not temporaries.
- If the problem's `Node` is a graph node, put `#define Node GraphNode` before including the solution; for `next`/`random` list nodes use `RandomListNode` (see `harness/leet.h`). Tree problems use `buildTree` / `toVector`, list problems `buildList` / `toVector` for input/output construction.
- Register new tests by calling `add_leetcode_test(<n>)` in `CMakeLists.txt`.

## Conventions

- Commit message format: `feat: <problem number>` (older commits sometimes use `feat: exercise N` or `feat: improve N`). Use `feat: <N>` for new solutions.
- If multiple problems are solved in one session, commit each file separately with its number in the message.
