# C Code Generation

Basic attempt at code generation for C. Generates 2D, 3D and 4D vector structs for int, float and double primitive types, as well as functions to print the values of the dimensions of each struct. It also creates two macros `VEC(TYPE, COUNT)` which can be used to declare a variable of any of the defined vector types and `PRINT_VEC(TYPE, COUNT)` which can be used to call the respective print function for each vector type.

The `main.c` includes examples of using the macros.

`codegen.c` is where the code generation happens. The file includes 2 static arrays that control the code that will be generated. The `elem_names` array controls the largest vector that will be generated for each type. Currently, there are 4 element names defined, so the largest vector would be 4D.

The `elem_types` array defines the element base types for which vector structs will be generated.
