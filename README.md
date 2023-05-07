# Skinny Hash

## How to run test cases

Depending on your C compiler, you will have different commands to compile these
source code. In the case of GCC, run the following commands:

### To Run and Check Skinny AES Algorithm

```bash
gcc skinny.c driver_skinny.c -o skinny.o # compiling
./skinny.o # running
```

### To Run and Check Skinny Hash Algorithm

```bash
gcc skinny.c tk3.c driver_tk3.c -o hash.o
./hash.o
```

## How to port SKINNY encryption to TK3 hash function

* Store skinny-related and tk3-related files in the same directory

* Include `skinny.h` into `tk3.c`: `#include "skinny.h"`

* Whenever you need to use it, call `skinny(c, p, k)`

    - 48-byte tweakey at k

    - 16-byte plaintext at p

    - The 16-byte output at c

## Contributor

* Mohammad Asif Ibtehaz (50366228)
* Henriikka Kaarenpää (292055)
