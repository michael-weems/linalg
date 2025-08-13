# LinAlg

Literally just me applying what I'm learning for linear algebra. May come in handy if I'm using linear algebra directly in C at some point.

## Usage

In a `.c` file, do:

```c
#define MDW_LINALG_IMPLEMENTATION
#include "../path/to/linalg.h"
```

## Developing in this repo

- The deliverable is `linalg.h`, very loosely modeled after STB-style header libraries. Will want to make it more robust for various platforms and such if this ever gets used anywhere.
- At the root of the repo, you can run `./tests/run` to run the test suite. Plan is to keep the test suite in-line with the implemented API.
