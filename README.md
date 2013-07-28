CPUID player
===========

CPUID player is a program written entirely in C++, except for a small gcc asm routine, that aims to be an utility to read from CPUID registers and output the result in a readable way.

LICENSE
-----------

This program is free software and is licensed under the MIT license.

HOW TO
-----------

The program requires a minimum of 1 argument and accepts a maximum of 4 arguments.

The input is assumed to be in **hexadecimal notation**, you can use pretty much all the standard conventions for an hexadecimal value such as:

 - leading **0x**
 - **H** and **h** suffix

No particular "filter" is being applied at this point, simply put, anything you input is interpreted as an hex value.

USAGE
----------

`cpuidplayer EAX [EBX] [ECX] [EDX]`

EXAMPLE
----------

`cpuidplayer 1` will output the result of EAX=1

see the table @ http://en.wikipedia.org/wiki/CPUID to interpret the bits

TESTING
---------

Tested with the following compilers

 - g++ 4.8.1 under Ubuntu 13.04 64 bit
 - g++ 4.7.2 under Ubuntu 13.04 64 bit
 - x86_64-w64-mingw32-g++ 4.9.0 20130622 (experimental) (GCC) under Ubuntu 13.04 64 bit
 - clang++ 3.4-1~exp1 (trunk)

Tested under the following environments

 - Windows 7 64 bit ( mingw32 64 bit build )
 - Ubuntu 13.04 64 bit 

ISSUES & BUGS
--------

Nothing to report.

NOTES
-------

To run this program under Windows you should build it with MinGW since it contains gcc asm syntax.
