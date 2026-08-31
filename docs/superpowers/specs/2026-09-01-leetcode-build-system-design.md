# LeetCode local build & test harness — design

Date: 2026-09-01
Status: approved

## Goal

Add a local build system so LeetCode solutions in this repo can be compiled
and tested on the machine instead of only via LeetCode's web editor.

Scope: compile + run real tests. GoogleTest as the framework, CMake as the
build tool. Initial deliverable: directory structure, harness, build system.
**No tests are written for existing solutions** — tests are added when solving
new problems going forward (and opportunistically for old ones).

## Layout

```
CMakeLists.txt
harness/leet.h                 # aux types + tree/list/graph builders (shared, no deps)
problems/<n>/solution.cpp      # the LeetCode submission snippet (moved from root <n>.cpp)
problems/<n>/test.cpp          # GoogleTest cases (future problems only)
tests/harness_test.cpp         # self-test of harness builders (NOT a solution test)
```

- Every existing solution at repo root (`<n>.cpp`, ~140 files) is migrated with
  `git mv <n>.cpp problems/<n>/solution.cpp`. File content is unchanged.
- A `test.cpp` includes `"solution.cpp"` from the same directory. One
  translation unit per test binary, so `class Solution` never collides.
- Solution files must remain paste-ready LeetCode snippets: no includes, no
  main. They are never modified for the harness.

## Build system

- CMake minimum 3.24, C++17 (3.24 so FetchContent URL downloads can set
  `DOWNLOAD_EXTRACT_TIMESTAMP` without configure warnings).
- GoogleTest pinned via `FetchContent` at a specific tag (v1.17.0, the latest
  stable release; verify the tag exists when implementing). Fetched once at
  configure time; requires network on first build.
- Helper `add_leetcode_test(<n>)`:
  - executable `lc_<n>` from `problems/<n>/test.cpp`
  - `target_include_directories` = repo root (so `#include "harness/leet.h"` works)
  - links `gtest_main`, registers with CTest
- Initial targets: `lc_harness` (from `tests/harness_test.cpp`) only.
- Commands:

```sh
cmake -S . -B build
cmake --build build -j
./build/lc_<n>                    # one problem (once tests exist)
ctest --test-dir build            # all registered tests
```

- `.gitignore` gains `build/`.

## Harness (`harness/leet.h`)

- `TreeNode`, `ListNode` with the constructors LeetCode provides
  (`val`, `left/right` or `next`; `nullptr` defaults).
- Both `Node` variants used across problems:
  - `GraphNode` (val + `vector<Node*> neighbors`)
  - `RandomListNode` (val, next, random)
  A test that needs one does `#define Node GraphNode` **before** including the
  solution. (LeetCode calls both of these `Node`, so they cannot share a name
  in a single header.)
- Builders/converters matching LeetCode's serialization:
  - `TreeNode* buildTree(std::vector<std::optional<int>>)`,
    `std::vector<std::optional<int>> toVector(TreeNode*)` (level-order)
  - `ListNode* buildList(std::vector<int>)`, `std::vector<int> toVector(ListNode*)`

## Pattern for a problem test (future problems)

```cpp
#include "gtest/gtest.h"
#include "harness/leet.h"
#include "solution.cpp"

TEST(TwoSum, Example1) {
  Solution s;
  std::vector<int> nums{2, 7, 11, 15};   // lvalue: solutions take non-const refs
  EXPECT_EQ(s.twoSum(nums, 9), (std::vector<int>{0, 1}));
}
```

Known quirk: solutions take non-const references (`vector<int>&`), so tests
must pass lvalues, not temporaries.

## AGENTS.md updates

Replace the "do not add build files / try to compile" rule with:

- the new layout description
- the build/test commands
- the rule that `solution.cpp` stays a paste-ready snippet
- test-writing conventions (lvalues for non-const refs, `#define Node` shim)

## Commits

1. `refactor: move solutions to problems/` — pure `git mv` renames.
2. `feat: local build and test harness` — CMakeLists.txt, harness, harness self-test, AGENTS.md update.

## Verification

- Fresh configure + build succeeds on this machine (macOS).
- `ctest --test-dir build` green (harness self-test only).
- `git status` clean; migrated files show as renames with no content change
  (spot-check with `git diff --summary` / `--find-renames`).
