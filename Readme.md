# CSE 210: The Best Operating System

In this course, we will learn how to use the Linux operating system and its functions. We will study the commands and their usages, as well as batch scripting for automating OS-related operations directly through code.

Since most of us use Windows in our workstations, here are three ways to run Linux on Windows:

-   Virtual Box or VMWare
-   Windows Subsystem for Linux (**WSL**)
-   Dual-booting Windows and Linux (**Not Recommended**)

Windows Subsystem for Linux (**WSL**) is baked into newer versions of Windows 10 and 11. To install it, we will run the following command:

```bash
wsl --install
```

> [!IMPORTANT]
> We must run Command Prompt with administrative privileges; otherwise, the installation will throw an error.

Having done that, we need to restart Windows. Once we restart, WSL will automatically download and install Ubuntu. We can then launch Ubuntu with the following command:

```bash
wsl -d Ubuntu
```
