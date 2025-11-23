# Building Unit Tests

This repository contains source code as well as two test-harnesses used throughout the book: 

- `Unity`
- `cpputest`

Additional test harness(es) are only for testing purposes : 

- `googletest`

Each test-harness is tracked as a Git submodule.

---

## Cloning the Repository

To clone this repository along with all submodules:

```bash
git clone <current-repo-url>
cd <current-repo-folder>
git submodule update --init --recursive
```

## TODO

- Once Mocking has been introduced, add (FFF)[https://github.com/meekrosoft/fff] to the repository