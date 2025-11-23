# Building Unit Tests

This repository contains source code as well as two test-harnesses used throughout the book: 

- `Unity`
- `cpputest`

Each project is tracked as a **Git submodule**, preserving its independent history.

---

## Cloning the Repository

To clone this repository along with all submodules:

```bash
git clone <current-repo-url>
cd <current-repo-folder>
git submodule update --init --recursive
