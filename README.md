# CPluPy
Python keywords in your C/C++ Alert! But why? (Working, but some kind of joke)

## Q&A
 **Q**:*is it working?*
 **A**:*of course! compile well*
 **Q**:*should i use it?*
 **A**:*rather not*
 ... other's latter

## Possibilieties
  #### Main:
  ```cpp
  #include <cplupy.h>
  ```
  No need it I/O system?
  ```cpp
  #define NO_IO
  #include <cplupy.h>
  ```
  No need in Python like types?
  ```cpp
  #define NO_TYPENAME
  #include <cplupy.h>
  ```
  #### Diferences:
  alright, what it can do?
  ##### Types
  ```py_str```
  ```py_dict``` (raw)
  ```py_list``` (also raw)
  ```str()``` (broken)
  ##### Operators
  ```is```
  ```not```
  ```elif```
  ##### I/O system
  ```print()```
  ```println()```
  ```input()```
## Examples
  ```cpp
  #include <cplupy.h>
#include <string>

int main() {
	println("Hello", "W"); // newline
	py_str a = input();
	print(a); // no newline
}
  ```
  
