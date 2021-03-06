# rshell

rshell is a program that functions like the Unix terminal but with limitations. The rshell program is able to excute simple commands such as: `ls, pwd, mkdir, rm,` and `echo`. 

rshell has a command prompt that looks like: `$`

rshell is able to execute commands with connectors such as: `&&, ||,` and`;`

It can also execute with commands with comments buy using the `#`

To exit rshell, type `exit` into the command line

We designed rshell by creating a UML diagram:

![uml](https://cloud.githubusercontent.com/assets/23230349/25933635/286c87ca-35cd-11e7-85ea-9c5d6e026796.png)

We ended up not using everything on the UML diagram. We did not use double command and comment. We renamed execute to main.

# test Command

We added the test function of the rshell. We used the cmd and a vector of strings to implement the test function. We used the `stat()` function with the `S_ISDIR` and `S_ISREG` macros to implement the `test` function of rshell with the use of the `-e`, `-f`, and the `-d` flags.

# Precedence Operators

`rshell` has the precedence operators: `(` and `)`. You can use it with conjunction with the `test` command.

# Redirection

`rshell` is able to handle the input redirection by using `<` in the command line. `rshell` also can handle output redirection by using the `>` and `>>` in the command line.

# Piping

`rshell` is able to handle piping by using `|` in the command line. 

# Known rshell bugs

If there is nothing before the connector, it does not print out an error message. For example: `&& echo a` does not print out an error and `|| echo b` does not print out an error. It executes `echo b`

There is a segfault if you leave the second argument empty for `&&`. Example: `echo a &&` gives a segfault

The `||` does not require a second argument. `echo a ||` works

For the symbolic test, `[` and `]`, there has to be a space after `[` and a space before `]`

The `||` operator does work propertly
