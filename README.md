# Demonstrate a SIMDE mis-translation

```
git submodule update --init --recursive
cmake -Bbuild
cmake --build build
```

on an ARM mac will fail. If you change CMakeLists to just do x86 it will work and run.
