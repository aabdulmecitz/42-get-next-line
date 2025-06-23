<div align="center">

  # 42 get_next_line Project

  <p align="center"><a href="https://github.com/aabdulmecitz/42-get-next-line" target="_blank"><img align="center" alt="get_next_line" src="https://github.com/mcombeau/mcombeau/blob/main/42_badges/get_next_linem.png?raw=true"></a></p>

  [![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)
  [![forthebadge](https://forthebadge.com/images/badges/built-with-love.svg)](https://forthebadge.com)

   <a img src="https://img.shields.io/badge/score-125%20%2F%20100-success?style=for-the-badge"/></a>
   <a img src="https://img.shields.io/badge/circle-2-magenta?style=for-the-badge"/></a>
   <a img src="https://img.shields.io/badge/42-Evaluation-red?style=for-the-badge"/></a>

  <p align="center"><a href="https://https://42istanbul.com.tr/" target="_blank"><img src="https://img.shields.io/static/v1?label=&message=Istanbul&color=000&style=for-the-badge&logo=42""></a></p>

  <p align="center">125/100 :white_check_mark:</p>
</div>

## About the Project

`get_next_line` is a project at 42 school that requires us to write a function that returns a line read from a file descriptor.

Function prototype:
```c
char *get_next_line(int fd);
```

- **`fd`**: The file descriptor to read from.
- **Return value**: The line that was read. `NULL` if there is nothing else to read, or an error occurred.

## Core Features

- **Static variables**: The function uses a static variable to keep track of the data read across multiple calls.
- **Buffer size**: Reading is buffered with the `BUFFER_SIZE` macro. This can be changed at compile time.
- **Multiple file descriptors**: The bonus part of the project handles multiple file descriptors at the same time.

## How To Use

1. Clone the repository.
2. Include the `get_next_line.h` header in your C file.
3. Compile your project with `get_next_line.c` and `get_next_line_utils.c` (and with the bonus files if you need them).

Example usage is in `gnl_test/main.c`.

## Compilation

To compile the tester, go to the `gnl_test` directory and run `make`:

```bash
cd gnl_test
make
```

This will create an executable named `gnl.out`. You can run it with `./gnl.out`. The `Makefile` compiles with a `BUFFER_SIZE` of -1 to test error handling, you might want to change this.

## Bonus

The bonus part of the project consists of making the `get_next_line` function work with multiple file descriptors at the same time. The files for the bonus part are:
- `gnl/get_next_line_bonus.c`
- `gnl/get_next_line_bonus.h`
- `gnl/get_next_line_utils_bonus.c`

To use the bonus version, you need to compile your project with these files instead of the mandatory ones.
