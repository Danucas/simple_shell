# Simple Shell.

# Description.
This is a customized Simple Shell designed for Holberton School as a mandatory task.

# What is "the Shell".
Is a program that takes commands from the keyboard and gives them to the operating system to perform.

![AppVeyor tests](https://img.shields.io/appveyor/tests/NZSmartie/coap-net-iu0to.svg?passed_label=good&failed_label=bad&skipped_label=n%2Fa)

# Requirements
# General
-Allowed editors: vi, vim, emacs.

-All your files will be compiled on Ubuntu 14.04 LTS.

-Your C programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic.

-All your files should end with a new line.

-A README.md file, at the root of the folder of the project is mandatory.

-Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl.

-No more than 5 functions per file.

-All your header files should be include guarded.

-Use system calls only when you need to.

###List of allowed functions and system calls
 access (man 2 access)
 chdir (man 2 chdir)
 close (man 2 close)
 closedir (man 3 closedir)
 execve (man 2 execve)
 exit (man 3 exit)
 _exit (man 2 _exit)
 fflush (man 3 fflush)
 fork (man 2 fork)
 free (man 3 free)
 getcwd (man 3 getcwd)
 getline (man 3 getline)
 isatty (man 3 isatty)
 kill (man 2 kill)
 malloc (man 3 malloc)
 open (man 2 open)
 opendir (man 3 opendir)
 perror (man 3 perror)
 read (man 2 read)
 readdir (man 3 readdir)
 signal (man 2 signal)
 stat (__xstat) (man 2 stat)
 lstat (__lxstat) (man 2 lstat)
 fstat (__fxstat) (man 2 fstat)
 strtok (man 3 strtok)
 wait (man 2 wait)
 waitpid (man 2 waitpid)
 wait3 (man 2 wait3)
 wait4 (man 2 wait4)
 write (man 2 write)

### Run.
```bash
$ ./concha
```

### Usage.
```bash
$ ls
#man_1_simple_shell#	    Simple_Shell_Flowchart.jpg	comp	      fork.c		ls		    put.c	    tokens.c
AUTHORS			    					          a.out				    		    concha       free.c  man_1_simple_shell  remove_deleted  tty
```

### Support.
1299@holbertonschool.com, danrodcastillo1994@gmail.com

### Our Flowchart.

![Flowchart](Simple_Shell_Flowchart.jpg)

#### Contributing.
State if you are open to contributions and what your requirements are for accepting them.

For people who want to make changes to your project, it's helpful to have some documentation on how to get started. Perhaps there is a script that they should run or some environment variables that they need to set. Make these steps explicit. These instructions could also be useful to your future self.

You can also document commands to lint the code or run tests. These steps help to ensure high code quality and reduce the likelihood that the changes inadvertently break something. Having instructions for running tests is especially helpful if it requires external setup, such as starting a Selenium server for testing in a browser.

### Authors and acknowledgment
Mauricio Drada Dávila 1299@holbertonschool.com
Daniel Rodríguez Castillo danrodcastillo1994@gmail.com

#### License
MIT License
Copyright (c) [2019] [Mauricio Drada Dávila - Daniel Rodríguez Castillo]

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
### Project status
If you have run out of energy or time for your project, put a note at the top of the README saying that development has slowed down or stopped completely. Someone may choose to fork your project or volunteer to step in as a maintainer or owner, allowing your project to keep going. You can also make an explicit request for maintainers.

**Simple Shell, Hello World!**