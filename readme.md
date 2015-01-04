## Time Checker

A small utility program which computes the amount of time your program will take on some input.

### USAGE

##### Instructions for Linux users:

Compile the code with the following syntax:

  ```
    g++ -Wall -o tc.out tc.cpp
  ``` 

After executing this you'll have tc.out file in your present working directory. This is the barebone of all the following computations. 

Now you can check the time taken by your program on any input like this:

* Compile the source of the program like this: 
  `g++ sample.cpp`
* Have a input.txt or similar file for input in the directory. If you don't have one you can either `touch` the file or just create it in a old-fashioned way.
  `touch input.txt`
* Execute the program 
  `./tc.out a.out input.txt` 

##### Instructions for Windows users:

Compile the code with the following syntax:

  ```
    g++ -Wall -o tc.exe tc.cpp
  ```

After executing this you'll have tc.exe file in your present working directory. This is the barebone of all the following computations.

Now you can check the time taken by your program on any input like this:

* Compile the source of the program like this: 
  `g++ sample.cpp`
* Have a input.txt or similar file for input in the directory. If you don't have one you can either `touch` the file or just create it in a old-fashioned way.
  `touch input.txt`
* Execute the program 
  `./tc a.exe input.txt`  (__For Cygwin Users__)
  `tc.exe a.exe input.txt` (__For Command Line Users__)

###### NOTE:

tc.out expects two arguments and input.txt is mandatory even if program does not expect standard input. I'll fix this in the future.

