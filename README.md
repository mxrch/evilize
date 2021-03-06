# Evilize
### Create pairs of executable files with the same MD5 hash
----------------------------------------------------------------

***This is the work of Peter Selinger, I haven't found it on Github, so here is it.***\
Original article : https://www.mscs.dal.ca/~selinger/md5collision/

Here's what you should expect:

```cmd
C:\TEMP> md5sum hello.exe
cdc47d670159eef60916ca03a9d4a007
C:\TEMP> .\hello.exe
Hello, world!

(press enter to quit)
C:\TEMP>
```
```cmd
C:\TEMP> md5sum erase.exe
cdc47d670159eef60916ca03a9d4a007
C:\TEMP> .\erase.exe
This program is evil!!!
Erasing hard drive...1Gb...2Gb... just kidding!
Nothing was erased.

(press enter to quit)
C:\TEMP>
```


## Quick Instructions

Note for Windows users: the below instructions are for Unix/Linux. On
Windows, you may have to append ".exe" to the names of executable
files. Also, to use "make", you must have the GNU tools installed and
working.

1. Unpack the archive and build the library and tools:

    ```bash
    tar zxf evilize-0.1.tar.gz
    cd evilize-0.1
    make
    ```

   This creates the programs "evilize", "md5coll", and the object file
   "goodevil.o".

2. Create a C program with multiple behaviors. Instead of the usual
   top-level function main(), write two separate top-level functions
   main_good() and main_evil(). See the file hello-erase.c for a
   simple example.  

3. Compile your program and link against goodevil.o. For example:

    ```bash
    gcc hello-erase.c goodevil.o -o hello-erase
    ```

4. Run the following command to create an initialization vector:

    ```bash
    ./evilize hello-erase -i
    ```

5. Create an MD5 collision by running the following command (but
   replace the vector on the command line with the one you found in
   step 4):
    
    ```bash
    ./md5coll 0x23d3e487 0x3e3ea619 0xc7bdd6fa 0x2d0271e7 > init.txt
    ```

   Note: this step can take several hours.

6. Create a pair of good and evil programs by running:

    ```bash
    ./evilize hello-erase -c init.txt -g good -e evil
    ```

   Here "good" and "evil" are the names of the two programs generated,
   and "hello-erase" is the name of the program you created in step
   3. 

   NOTE: steps 4-6 can also be done in a single step, as follows:
    
    ```bash
    ./evilize hello-erase -g good -e evil
    ```

   However, I prefer to do the steps separately, since step 5 takes so
   long.

7. Check the MD5 checksums of the files "good" and "evil"; they should
   be the same.

8. Run the programs "good" and "evil" - they should exhibit the two
   different behaviors that you programmed in step 2.

## How does it work?

For an explanation, see http://www.mathstat.dal.ca/~selinger/md5collision/

## Credits 

The md5coll tool was written by Patrick Stach <pstach@stachliu.com>,
based on a paper by Xiaoyun Wang et al. The version distributed with
this file was modified by Peter Selinger. It is distributed under a
Modified BSD License, see MBSD-LICENSE for details.

The evilize tool was written by Peter Selinger, and uses third-party
code by Patrick Stach and others. It is distributed under the GNU
General Public License, see the file COPYING for details.

----------------------------------------------------------------

Copyright (C) 2006 Peter Selinger. This file is distributed under
the terms of the GNU General Public License. See the file COPYING
for details.
