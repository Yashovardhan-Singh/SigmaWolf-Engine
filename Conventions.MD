# Code Conventions:

1) Struct names in PascalCase

2) Functions operating on structs in camelCase

4) variables in snake_case

5) struct members in snake_case

6) Enum names in PascalCase with prefix E

7) Enum members in ALL_CAPS

8) Macros in ALL_CAPS with prefix M

9) private functions which are not exposed have prefix _ with  
snake case always

10) public functions should have the following prefix:  
<1 to 3 letter name for module>_ with PascalCase

11) any functions not operating on structs will be snake case

# Cases Explained:

* PascalCase: First letter of every word is capital with no  
spaces in between. Ex: HelloWorld

* camelCase: First letter of every word except first word is  
capital with no spaces in between: helloWorld

* snake_case: all letters in lowercase, '_' used in place of  
spaces. Ex: hello_world

* PascalCase with prefix E: E is capital and then regular  
PascalCase. Ex: EHelloWorld

* ALL_CAPS: All letters are uppercase with '_' used in place  
of spaces. Ex: HELLO_WORLD

* ALL_CAPS with prefix M: Same as ALL_CAPS with prefix M_.  
ex: M_HELLO_WORLD

* private functions ex: _hello_world()

* public functions ex: cr_HelloWorld()