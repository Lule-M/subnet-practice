# IP Subnet Practice

A simple CLI tool used for generating subnetting problems. Intended for students to practice.

## How to install

Just compile from source (until a makefile is made or something)

> [!CAUTION]
> Builds currently fail on Windows systems.

## How to use

You can just run the program from the terminal, which writes to standard output. You can use the shell to save the output to a file.

### Examples

```Shell
./ipsp | pandoc -f textile -o practice.pdf
```

This runs the program, and saves its output to a pdf.

Alternatively, you can use the following code to save the output of the program and open it in notepad on Windows.

```Shell
\main.exe > practice.txt && notepad.exe practice.txt 
```

## To do

As of 4.10.2024:

- [ ] implement support for windows systems (issues with rand_r calls)
- [ ] implement language specifier
- [ ] implement a solver/generation of a solutions file

