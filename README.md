# rshell

rshell is a program that functions like the Unix terminal but with limitations. The rshell program is able to excute simple commands such as: `ls, pwd, mkdir, rm,` and `echo`. 

rshell has a command prompt that looks like: `$`

rshell is able to execute commands with connectors such as: `&&, ||,` and`;`

It can also execute with commands with comments buy using the `#`

To exit rshell, type `exit` into the command line

We designed rshell by creating a UML diagram:

![uml](https://cloud.githubusercontent.com/assets/23230349/25933635/286c87ca-35cd-11e7-85ea-9c5d6e026796.png)

We ended up not using everything on the UML diagram. We did not use double command and comment. We renamed execute to main.

# test function

We added the test function of the rshell. We used the cmd and a vector of strings to implement the test function. We used the `stat()` function with the `S_ISDIR` and `S_ISREG` macros to implement the `test` function of rshell with the use of the `-e`, `-f`, and the `-d` flags.

# Known rshell bugs

If there is nothing before the connector, it does not print out an error message. For example: `&& echo a` does not print out an error and `|| echo b` does not print out an error. It executes `echo b`

There is a segfault if you leave the second argument empty for `&&`. Example: `echo a &&` gives a segfault

The `||` does not require a second argument. `echo a ||` works
