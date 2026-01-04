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

## Compile the program

After you downloaded a compiler, you need to configure clang, if you already did, you can skip the process.

In my case, I had to specify and format the code.

In my case, this are my configuration. To install clang in your computer, run the following command in the terminal:

> With Scoop:
```sh
scoop install llvm
```

```clangd
CompileFlags:
  Add:
    - -std=gnu99
    - -target
    - x86_64-w64-windows-gnu
    - -IC:/Users/{user}/scoop/apps/gcc/current/include
    - -IC:/Users/{user}/scoop/apps/gcc/current/x86_64-w64-mingw32/include
```

I actually use a custom format, so if you want to, check out the .clang-format

```clang-format
BasedOnStyle: LLVM
IndentWidth: 3
UseTab: Never
BreakBeforeBraces: Attach
AllowShortFunctionsOnASingleLine: none
ColumnLimit: 100
DerivePointerAlignment: true
```
After this, everything should be set and ready to go
> If you have any issue, please report them the the issue. Please be clear as possible.
