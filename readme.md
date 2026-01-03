# My own simple database

## Setting up my editor

How did I set up my editor? Here I will show how to set up the editor for this project. Since setting up an IDE to manage C/CPP code requires to set up some external compilers like msys2 or minGW, I will share and explain the process I took.

### Download the compiler

Yeah, first we need to download it. I will provide the links to download msys2 as well as minGW.

* [msys2](https://www.msys2.org/)
* [MinGW](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/10.2.0/threads-posix/seh/x86_64-10.2.0-release-posix-seh-rt_v6-rev0.7z/download)

If you downloaded, proceed with the installation process. For [msys2](#msys2) in windows we need to do the following steps:

## MSYS2

1. Open the MSYS2 terminal.
2. Update the package database by running the following command:
   ```sh
   pacman -Syu
   ```
3. Install the required packages by running the following command:
   ```sh
   pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-clang
   ```
4. Verify the installation by running the following command:
   ```sh
   gcc --version
   clang --version
   ```
5. Add the MSYS2 bin directory to your system PATH environment variable.

## MinGW

To use mingGW, we just do this:

1. Extract the downloaded MinGW archive to a directory of your choice.
2. Add the MinGW bin directory to your system PATH environment variable.

If you want to try and modify my code, you likely done the hard part, now just open the ".c" file and start editing.
To run the program, you can compile the program:

```sh
gcc -std=gnu99 -o myOwn_sqlite.exe main.c
```
