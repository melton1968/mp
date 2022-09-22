
# cxx-core-mp

Primitives for structured metaprogramming along with convenience
functions for runtime-type information.

# Brief Tour

Concepts and the related C++20 features generally allow for the
concise expression of intent when working with types. This simplifies
many type oriented tasks and reduces the need for a separate
metaprogramming library. This library targets common patterns which
are either complex or awkward to implement directly and attempts to
provide a simple, ergonomic option.

```c++
#include "core/pp/mp.h"
```

# Installation

## cxx-depends

```bash
git clone git@github.com:melton1968/cxx-depends
mkdir cxx-depends/build && cd cxx-depends/build
CC=clang-mp-11 CXX=clang++-mp-11 cmake -DCMAKE_INSTALL_PREFIX=$HOME/opt -DCORE_TESTS=ON ..
make cxx_core_mp-check  # Run the tests
make cxx_core_mp        # Do the install
```

To build the documentation (requires doxygen and sphinx-build to be installed):

```bash
CC=clang-11 CXX=clang++11 cmake -DCORE_DOCS ..
make cxx_core_mp_docs # root of html tree is docs/html/index.html
```

# Background

*cxx-core-mp* is part of the *cxx-core** family of C++20 based
libraries. The *cxx-core* libraries have two primary goals:

- **Ergonomics**. In the spirit of the `CppCoreGuideLines`, cxx-core
  aspires to facilitate writing concise, idiomatic code not by force,
  but by providing a clear path that produces robust, easy to read
  code. Good code should be fun to write.
  
- **Components**. Modern language platforms provide broad support for
  first-class library components, while C++ has traditionally only
  provided a very minimal standard library. *cxx-core* aspires to
  provide support for a broad range of libraries that feel like part
  of the language.

# License

This software is licensed under the BSD 3-clause license. See the LICENSE file for details.

# Appendix

```{toctree}
---
caption: API REFERENCE
---
api/intro
api/construct
api/query
api/operate
api/predicate
api/enableif
api/utility
```

```{toctree}
---
caption: FILE REFERENCE
maxdepth: 5
---
include/ <generated/include/dir>
test/ <generated/test/dir>
```
