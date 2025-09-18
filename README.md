## A small C library for common utilities

A minimal standard lib for ISO C17 and C++17 tested on gcc/clang. It wraps some widely used open-source libraries (with patches) in a convenient macro-based API and provides support for dynamic strings, dynamic arrays, hashmaps, hashsets, error handling, memory and filesystem operations.  
<!---->
It powers my C compiler [wheelcc](https://github.com/romainducrocq/wheelcc) written in C from scratch. <ins>See this project for code examples</ins>.

### Usage

Add `#include "c_std.h"` in your project  
- and build in C with:
```
gcc -std=c17 -Wall -Wextra -Werror -Wpedantic -pedantic-errors -Ilib/ lib/sds/sds.c lib/stb_ds/stb_ds.c main.c -o main
``` 
- or in C++ with:
```
g++ -std=c++17 <...>
```

### Credits

This header includes the following open-source libraries:

- Dynamic strings: [antirez/sds](https://github.com/antirez/sds) (BSD-2-Clause license)
- Dynamic arrays, hashmaps: [nothings/stb_ds](https://github.com/nothings/stb/blob/master/stb_ds.h) (MIT License)
- Filesystem reader: [cxong/tinydir](https://github.com/cxong/tinydir) (BSD-2-Clause license)

****

@romainducrocq
