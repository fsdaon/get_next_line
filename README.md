# get_next_line

A C function to read a file or input stream line by line, returning one line per call. Written as part of the 42 Vienna curriculum.

## What is it?

`get_next_line` reads from a file descriptor until it hits a newline or EOF and returns the line as a string. It handles multiple file descriptors at once and manages the internal buffer efficiently.

## Highlights

- Supports reading from multiple file descriptors simultaneously
- Handles partial reads and leftover data correctly
- Manages memory allocation and cleanup to avoid leaks
- Works with different buffer sizes

## Why I built this

This project was great for learning how to work with file descriptors, buffers, and dynamic memory. It helped me improve my problem-solving skills, especially for edge cases.
