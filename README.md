# C - Simple Shell

## What's a shell ?

Shell reads commands from stdin and executes them

## How to use it?

1) Download :

```
$ git clone https://github.com/Maynot2/simple_shell.git
```

2) Execute :

```
$ ./hsh
```

3) Example :

```
[user@example]:simple_shell$ ./hsh 
$ ls
README.md	  hsh	 hsh_array_helpers.c  hsh_exec_cmd.c	       hsh_print_helpers.c  hsh_string_helpers1.c
display_prompt.c  hsh.h  hsh_builins.c	      hsh_mem_alloc_helpers.c  hsh_read_helpers.c   main.c
$
```

## What tools can we use ?

You can launch programs directly with the absolute path
This shell has the $PATH env, you can launch binaries of your path from anywhere (like the example)
Some builtins commands are available : exit, env.

## Authors

[Paul Manot](https://github.com/Maynot2)
[Gregory Arthus](https://github.com/garthus23)

