# Inter-Process Communication (IPC) Examples

This project demonstrates various types of inter-process communication (IPC) mechanisms in C++. Each directory contains an implementation of a different IPC technique.

## Project Structure

```
.
├── ipc-fifo
│   ├── CMakeLists.txt
│   ├── sender.cpp
│   └── receiver.cpp
├── ipc-files
│   ├── CMakeLists.txt
│   ├── sender.cpp
│   └── receiver.cpp
├── ipc-memory-map
│   ├── build
│   ├── CMakeLists.txt
│   ├── sender.cpp
│   └── receiver.cpp
├── ipc-message
│   ├── CMakeLists.txt
│   ├── sender.cpp
│   └── receiver.cpp
├── ipc-message-posix
│   ├── CMakeLists.txt
│   ├── sender.cpp
│   └── receiver.cpp
├── ipc-pipe
│   ├── CMakeLists.txt
│   └── pipe.cpp
├── ipc-shared-memory
│   ├── CMakeLists.txt
│   ├── sender.cpp
│   └── receiver.cpp
├── ipc-shared-memory-posix
│   ├── CMakeLists.txt
│   ├── sender.cpp
│   └── receiver.cpp
├── ipc-shared-memory-semaphore
│   ├── CMakeLists.txt
│   ├── sender.cpp
│   ├── receiver.cpp
│   └── shm_sem.h
├── ipc-socket
│   ├── CMakeLists.txt
│   ├── receiver.cpp
│   └── sender.cpp
└── README.md
```

## IPC Methods Implemented

1. **FIFO (Named Pipes)** (`ipc-fifo/`): Uses named pipes for unidirectional communication between processes.
2. **File-Based IPC** (`ipc-files/`): Uses files as a medium to exchange data between processes.
3. **Memory-Mapped Files** (`ipc-memory-map/`): Maps a file into memory for efficient shared access.
4. **Message Queues** (`ipc-message/`): Uses System V message queues for structured message passing.
5. **Message Queues POSIX** (`ipc-message-posix/`): Uses POSIX message queues for structured message passing.
6. **Pipes** (`ipc-pipe/`): Uses anonymous pipes for communication between parent and child processes.
8. **Shared Memory** (`ipc-shared-memory/`): Uses System V shared memory for inter-process communication.
9. **Shared Memory POSIX** (`ipc-shared-memory-posix/`): Uses POSIX shared memory and semaphores for inter-process communication.
10. **Shared Memory with Semaphores** (`ipc-semaphore-shared-memory/`): Uses shared memory with semaphores to synchronize access.
11. **Sockets** (`ipc-socket/`): Uses UNIX domain sockets for bi-directional communication between processes.

## Prerequisites

- A Linux-based operating system.
- CMake (version 3.10 or later).
- A C++ compiler (e.g., `g++`).

## Building the Project

Each IPC method can be built separately. For example, to build `ipc-fifo`:

```sh
cd ipc-fifo
mkdir build && cd build
cmake ..
make
```

## Running the Programs

Each IPC mechanism has different execution requirements. Typically, the receiver (or server) must be started first, followed by the sender (or client). For example, to run `ipc-fifo`:

```sh
./receiver &
./sender
```

Refer to the source files in each directory for details on execution order and expected output.

## Cleanup

To remove compiled files:

```sh
find . -type d -name build | xargs rm -rf
```

## Notes

- Some IPC mechanisms require special permissions (e.g., shared memory and semaphores).
- UNIX domain sockets and named pipes create files that should be cleaned up after execution.
