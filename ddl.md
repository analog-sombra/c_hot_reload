# Loading DLL in Windows (C Code)

## Example: Dynamic DLL Loading

### plug.h (DLL Header)
```c
__declspec(dllexport) void plug_function(void);
```

### main.c (Loader)
```c
#include <windows.h>
#include <stdio.h>

typedef void (*plug_function_t)(void);

int main() {
    HMODULE dll = LoadLibraryA("plug.dll");
    if (!dll) {
        printf("Failed to load plug.dll\n");
        return 1;
    }

    plug_function_t plug_function =
        (plug_function_t)GetProcAddress(dll, "plug_function");

    if (!plug_function) {
        printf("Could not find plug_function\n");
        FreeLibrary(dll);
        return 1;
    }

    plug_function(); // call the function

    FreeLibrary(dll);
    return 0;
}
```

### Compile
```bash
gcc main.c -o test.exe
```

### Run
```bash
test.exe
```

### Expected Output
```
Plug function called.
```

---

## 📌 Notes

### 1️⃣ Use LoadLibraryA instead of LoadLibrary
It avoids unicode-related issues.

### 2️⃣ DLL must be in:
- the same directory as the .exe, **or**
- in a system PATH directory

### 3️⃣ Your DLL must export functions
Using either:
- **Method A** — `__declspec(dllexport)` (recommended)
- **Method B** — `.def` file

---

## 🔥 Complete Minimal DLL + Loader Example (Working)

### ✔ plug.h
```c
#ifndef PLUG_H
#define PLUG_H

__declspec(dllexport) void plug_function(void);

#endif
```

### ✔ plug.c
```c
#include "plug.h"
#include <stdio.h>

void plug_function(void) {
    printf("Plug function called.\n");
}
```

### ✔ build.bat
```bat
gcc -shared -o plug.dll plug.c
```

### ✔ test_loader.c
```c
#include <windows.h>
#include <stdio.h>

typedef void (*plug_function_t)(void);

int main() {
    HMODULE dll = LoadLibraryA("plug.dll");
    plug_function_t fn = (plug_function_t)GetProcAddress(dll, "plug_function");
    fn();
}
```
