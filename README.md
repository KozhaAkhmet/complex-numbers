# complex-numbers

A from-scratch C++ implementation of a `ComplexNumber` class, covering construction, copy/move assignment, equality, and arithmetic via operator overloading — no external dependencies.

## Features

- `ComplexNumber(double reel, double img)` construction, plus copy constructor and copy/move assignment operators
- Overloaded `+`, `-`, `*`, `==`, and stream insertion/extraction (`<<` / `>>`) operators
- `to_string()` for formatted `"real imagi"` output
- Every constructor/destructor/assignment prints a trace line (e.g. `"Copy Constructor"`) to `stdout`, useful for observing C++ object lifetime while stepping through `main.cpp`

## Known Issue

The copy constructor currently initializes both components from the source's real part:
```cpp
ComplexNumber::ComplexNumber(const ComplexNumber &source)
    : ComplexNumber{source.reel, source.reel} {  // should be source.reel, source.img
```
This means copy-constructed numbers (e.g. `ComplexNumber c(a);` in `main.cpp`) silently lose their imaginary component. Division (`/`) is also not implemented, only `+`, `-`, and `*`.

## Build & Run

```bash
g++ -o build/demo main.cpp complex_number.hpp complex_number.cpp
./build/demo
```
