# LeetCode Local Build & Test Harness Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [x]`) syntax for tracking.

**Goal:** Add a CMake + GoogleTest build system so LeetCode solutions can be compiled and tested locally.

**Architecture:** Migrate all root-level `<n>.cpp` solutions into `problems/<n>/solution.cpp` (content unchanged). A shared header `harness/leet.h` provides the aux types (`TreeNode`, `ListNode`, two `Node` variants) and LeetCode-style builders. CMake builds one test binary per problem that has a `test.cpp`, plus a harness self-test that verifies the builders work.

**Tech Stack:** C++17, CMake ≥3.24, GoogleTest v1.17.0 (FetchContent, downloaded once at configure time), CTest.

**Spec:** `docs/superpowers/specs/2026-09-01-leetcode-build-system-design.md`

---

### Task 1: Migrate solutions into problems/ directories

**Files:**
- Move: every root-level `<n>.cpp` → `problems/<n>/solution.cpp` (via `git mv`, content unchanged)

- [x] **Step 1: Run the migration loop**

```bash
for f in [0-9]*.cpp; do n="${f%.cpp}"; mkdir -p "problems/$n"; git mv "$f" "problems/$n/solution.cpp"; done
```

- [x] **Step 2: Verify renames only, no content change**

```bash
git diff --cached --stat | tail -1
git diff --cached -M --summary | grep -c 'rename'
```

Expected: stat shows the same number of files as `problems/*/solution.cpp` count; every entry in the summary is `rename` (no create/delete rows), count equals the number of `.cpp` files at root before the move (use `ls problems | wc -l` as the count).

- [x] **Step 3: Verify root is now clean of solution files**

```bash
ls [0-9]*.cpp 2>/dev/null
```

Expected: no output (only README.md, AGENTS.md, docs/, harness-less dirs remain at root).

- [x] **Step 4: Commit the migration**

```bash
git commit -m "refactor: move solutions to problems/"
```

Note: AGENTS.md still describes the old layout until Task 5; that is expected between the two commits.

---

### Task 2: Build system scaffolding

**Files:**
- Create: `CMakeLists.txt`
- Create: `.gitignore`

- [x] **Step 1: Check the installed CMake version**

```bash
cmake --version
```

Expected: 3.24 or newer (required for `DOWNLOAD_EXTRACT_TIMESTAMP` in FetchContent).

- [x] **Step 2: Verify the GoogleTest tag exists**

```bash
curl -sIL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip | head -1
```

Expected: an HTTP 2xx/3xx line (not 404).

- [x] **Step 3: Create `.gitignore`**

```gitignore
build/
```

- [x] **Step 4: Create `CMakeLists.txt`**

```cmake
cmake_minimum_required(VERSION 3.24)
project(leet-code LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)
enable_testing()

function(add_leetcode_test n)
  add_executable(lc_${n} problems/${n}/test.cpp)
  target_include_directories(lc_${n} PRIVATE ${CMAKE_SOURCE_DIR})
  target_link_libraries(lc_${n} PRIVATE gtest_main)
  gtest_discover_tests(lc_${n})
endfunction()
```

- [x] **Step 5: Smoke-check configure works (no targets yet)**

```bash
cmake -S . -B build
```

Expected: configure completes with no errors. GoogleTest is downloaded and configured. (First run needs network.)

- [x] **Step 6: Commit the build scaffolding**

```bash
git add CMakeLists.txt .gitignore
git commit -m "feat: add CMake build scaffolding"
```

Note: the spec calls for one `feat:` commit at the end; this intermediate commit is a safe checkpoint (frequent commits) and will be followed by the remaining work. If a single feat commit is preferred, skip this commit and add these files at Task 6 instead — but keep the rest of the steps unchanged.

---

### Task 3: Harness self-test (failing first)

**Files:**
- Create: `tests/harness_test.cpp`

- [x] **Step 1: Write the test file**

```cpp
#include "gtest/gtest.h"
#include "harness/leet.h"

TEST(BuildTree, Empty) {
  EXPECT_EQ(buildTree({}), nullptr);
}

TEST(BuildTree, SingleNull) {
  EXPECT_EQ(buildTree({std::nullopt}), nullptr);
}

TEST(BuildTree, Example) {
  TreeNode* root = buildTree({1, std::nullopt, 2, 3});
  ASSERT_NE(root, nullptr);
  EXPECT_EQ(root->val, 1);
  EXPECT_EQ(root->left, nullptr);
  ASSERT_NE(root->right, nullptr);
  EXPECT_EQ(root->right->val, 2);
  ASSERT_NE(root->right->left, nullptr);
  EXPECT_EQ(root->right->left->val, 3);
}

TEST(ToVectorTree, Example) {
  TreeNode* root = buildTree({1, std::nullopt, 2, 3});
  EXPECT_EQ(toVector(root), (std::vector<std::optional<int>>{1, std::nullopt, 2, 3}));
}

TEST(BuildList, Empty) {
  EXPECT_EQ(buildList({}), nullptr);
}

TEST(BuildList, Example) {
  ListNode* head = buildList({1, 2, 3});
  ASSERT_NE(head, nullptr);
  EXPECT_EQ(head->val, 1);
  ASSERT_NE(head->next, nullptr);
  EXPECT_EQ(head->next->val, 2);
  ASSERT_NE(head->next->next, nullptr);
  EXPECT_EQ(head->next->next->val, 3);
  EXPECT_EQ(head->next->next->next, nullptr);
}

TEST(ToVectorList, Example) {
  ListNode* head = buildList({1, 2, 3});
  EXPECT_EQ(toVector(head), (std::vector<int>{1, 2, 3}));
}

TEST(NodeVariants, BothExist) {
  GraphNode g(1);
  g.neighbors.push_back(new GraphNode(2));
  EXPECT_EQ(g.neighbors[0]->val, 2);
  RandomListNode r(7);
  EXPECT_EQ(r.next, nullptr);
  EXPECT_EQ(r.random, nullptr);
}
```

- [x] **Step 2: Add the harness target to CMakeLists.txt (end of file)**

```cmake
add_executable(lc_harness tests/harness_test.cpp)
target_include_directories(lc_harness PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(lc_harness PRIVATE gtest_main)
gtest_discover_tests(lc_harness)
```

- [x] **Step 3: Build and confirm it fails (missing header)**

```bash
cmake -S . -B build
cmake --build build -j
```

Expected: FAIL — compile error: `'harness/leet.h' file not found`.

---

### Task 4: Implement the harness header

**Files:**
- Create: `harness/leet.h`

- [x] **Step 1: Write the header** (repo style: 2-space indent, brace on same line)

```cpp
#pragma once

#include <optional>
#include <queue>
#include <vector>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct GraphNode {
  int val;
  std::vector<GraphNode*> neighbors;
  GraphNode() : val(0), neighbors({}) {}
  GraphNode(int v) : val(v), neighbors({}) {}
  GraphNode(int v, std::vector<GraphNode*> n) : val(v), neighbors(n) {}
};

struct RandomListNode {
  int val;
  RandomListNode* next;
  RandomListNode* random;
  RandomListNode() : val(0), next(nullptr), random(nullptr) {}
  RandomListNode(int v) : val(v), next(nullptr), random(nullptr) {}
};

TreeNode* buildTree(const std::vector<std::optional<int>>& values) {
  if (values.empty() || !values[0]) return nullptr;
  auto* root = new TreeNode(*values[0]);
  std::queue<TreeNode*> q;
  q.push(root);
  size_t i = 1;
  while (i < values.size()) {
    TreeNode* node = q.front();
    q.pop();
    if (values[i]) {
      node->left = new TreeNode(*values[i]);
      q.push(node->left);
    }
    ++i;
    if (i < values.size() && values[i]) {
      node->right = new TreeNode(*values[i]);
      q.push(node->right);
    }
    ++i;
  }
  return root;
}

std::vector<std::optional<int>> toVector(TreeNode* root) {
  std::vector<std::optional<int>> out;
  if (!root) return out;
  std::queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode* n = q.front();
    q.pop();
    if (n) {
      out.push_back(n->val);
      q.push(n->left);
      q.push(n->right);
    } else {
      out.push_back(std::nullopt);
    }
  }
  while (!out.empty() && !out.back()) out.pop_back();
  return out;
}

ListNode* buildList(const std::vector<int>& values) {
  if (values.empty()) return nullptr;
  auto* head = new ListNode(values[0]);
  ListNode* cur = head;
  for (size_t i = 1; i < values.size(); ++i) {
    cur->next = new ListNode(values[i]);
    cur = cur->next;
  }
  return head;
}

std::vector<int> toVector(ListNode* head) {
  std::vector<int> out;
  for (; head; head = head->next) out.push_back(head->val);
  return out;
}
```

- [x] **Step 2: Build and run the harness tests**

```bash
cmake -S . -B build
cmake --build build -j
ctest --test-dir build --output-on-failure
```

Expected: PASS — all 8 tests green (BuildTree 3, ToVectorTree 1, BuildList 2, ToVectorList 1, NodeVariants 1).

---

### Task 5: Update AGENTS.md

**Files:**
- Modify: `AGENTS.md` (replace whole file)

- [x] **Step 1: Replace AGENTS.md with this content**

```markdown
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
- Solutions take non-const references (`vector<int>&`): pass lvalues, not temporaries.
- If the problem's `Node` is a graph node, put `#define Node GraphNode` before including the solution; for `next`/`random` list nodes use `RandomListNode` (see `harness/leet.h`). Tree problems use `buildTree` / `toVector`, list problems `buildList` / `toVector` for input/output construction.
- Register new tests by calling `add_leetcode_test(<n>)` in `CMakeLists.txt`.

## Conventions

- Commit message format: `feat: <problem number>` (older commits sometimes use `feat: exercise N` or `feat: improve N`). Use `feat: <N>` for new solutions.
- If multiple problems are solved in one session, commit each file separately with its number in the message.
```

- [x] **Step 2: Sanity-check the file**

```bash
head -5 AGENTS.md
```

Expected: shows the `# AGENTS.md` title and the Repo layout section.

---

### Task 6: Final verification and commit

**Files:**
- None new (verifies Tasks 1-5)

- [x] **Step 1: Clean configure + build + test from scratch**

```bash
rm -rf build
cmake -S . -B build
cmake --build build -j
ctest --test-dir build --output-on-failure
```

Expected: clean configure; build succeeds; all 8 harness tests pass.

- [x] **Step 2: Verify working tree state**

```bash
git status --short
git log --oneline -3
```

Expected: only the changes from Tasks 2-5 are uncommitted (CMakeLists.txt, .gitignore if not committed in Task 2 Step 6, tests/harness_test.cpp, harness/leet.h, AGENTS.md). Root contains no `[0-9]*.cpp` files.

- [x] **Step 3: Commit the harness work**

```bash
git add CMakeLists.txt .gitignore harness/leet.h tests/harness_test.cpp AGENTS.md
git commit -m "feat: local build and test harness"
```

(If Task 2 Step 6 was committed separately, omit `.gitignore` and `CMakeLists.txt` from this commit and adjust the message accordingly.)

- [x] **Step 4: Confirm final history**

```bash
git log --oneline -4
```

Expected: migration commit, harness/build commits, and the spec commits on top of previous history.
