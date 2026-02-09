# MiniShell Project in C | Linux Internals, System Calls & Shell Commands

**YouTube Demo:** [https://youtu.be/e7Awr7HD67Q](https://youtu.be/e7Awr7HD67Q)

# Project Overview
MiniShell is a custom command-line shell implemented in **C** that demonstrates core **Linux internals and operating system concepts**. The project replicates essential functionalities of a Unix/Linux shell, including command parsing, execution of internal and external commands, process management, signal handling, and special shell variables.

This project is intended for:
* Operating Systems coursework
* Linux system programming practice
* Embedded Linux and system software interview preparation
* Academic mini/major projects

# Features
* Custom shell prompt with ANSI color support
* Prompt customization using `PS1`
* Built-in commands implementation:

  * `cd`
  * `pwd`
  * `exit`
* Execution of external commands using process creation
* Parent–child process synchronization
* Signal handling (`SIGINT`, `SIGKILL`)
* Special shell variables:

  * `$?` – Exit status of last command
  * `$$` – Process ID of the MiniShell
  * `$SHELL` – Executable path of the shell
* Command-not-found handling
* Whitespace-sensitive command parsing
* Sleep command with signal interruption
* External command validation using a command list file

# Supported Commands
# Internal Commands
| Command          | Description                          |
| ---------------- | ------------------------------------ |
| `cd <directory>` | Change the current working directory |
| `pwd`            | Display current working directory    |
| `exit`           | Exit the MiniShell                   |

# Special Variables
| Variable | Description                                    |
| -------- | ---------------------------------------------- |
| `$?`     | Exit status of the previously executed command |
| `$$`     | Process ID of the MiniShell                    |
| `$SHELL` | Displays the shell executable path             |

# External Commands
Examples:
```
ls
ls -l
date
sleep 5
mkdir embedded
```

# Working Principle
1. The shell displays a custom prompt.
2. User input is read and parsed.
3. The first token is extracted as the command.
4. The command is classified as:

   * Built-in
   * External
   * Invalid
5. Built-in commands are executed directly.
6. External commands are executed using a child process.
7. The parent process waits for termination.
8. Exit status and signals are handled appropriately.

# Process Management
* External commands are executed using `fork()`
* The child process runs the command via `system()`
* The parent process waits using `wait()`
* Normal and abnormal termination is detected using:

  * `WIFEXITED`
  * `WIFSIGNALED`

# Signal Handling
The MiniShell handles user-generated signals:
* `Ctrl + C` (`SIGINT`) terminates the running child process
* The shell itself remains active
* Signal handling prevents unintended shell termination
* Signal number is reported when a process is killed

## Project Structure
```
mini_shell/
├── main.c
├── scan_input.c
├── get_command.c
├── check_command.c
├── echo.c
├── execute_internal_commands.c
├── extract_external_command.c
├── signal_handler.c
├── main.h
├── external_commands.txt
└── README.md
```

# Concepts Covered
* Linux Shell Internals
* Process Creation and Control
* System Calls
* Signal Handling
* Command Parsing
* Parent–Child Synchronization
* Exit Status Handling

