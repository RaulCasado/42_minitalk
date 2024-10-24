Process Communication with Signals in C
=======================================

This project implements a client and a server in C that communicate using UNIX signals. The client sends a message to the server, which receives it and prints it to the console. The signal `SIGUSR1` is used to indicate a bit value of `1`, and `SIGUSR2` is used to indicate a bit value of `0`.

Table of Contents
-----------------

*   [Description](#description)
*   [Requirements](#requirements)
*   [Installation](#installation)
*   [Usage](#usage)
*   [Code Explanation](#code-explanation)

Description
-----------

The project consists of two programs:

1.  **Client**: Sends a message to the server using signals.
2.  **Server**: Receives the message and prints it to the console.

The client sends each character of the message as a series of signals, using the UNIX signal system to indicate the bits of the character. The server listens for these signals and reconstructs the message.

Requirements
------------

*   A C development environment (gcc, make, etc.)
*   UNIX/Linux operating system that supports signals

Installation
------------

1. Once you have cloned the repository:

         cd 42_minitalk
    
2. Compile the server and client:
    
        make
    
3. Run the server and client as described in the next section.
    
Usage
-----

1. Start the server in one terminal:
    
       ./server
    
       The server will display its PID in the console.

2. In another terminal, run the client by providing the server's PID and the message to send:

       ./client <server_pid> "Your message here"

       Replace <server_pid> with the PID displayed by the server.
    
Code Explanation
----------------

### Client (`client.c`)

*   **Main Functions**:
    *   `ack_handler(int sig)`: Handles the acknowledgment signal `SIGUSR1`.
    *   `send_char(int pid, char c)`: Sends a character to the server bit by bit.
    *   `send_string(int pid, char *str)`: Sends a string of characters to the server.
*   **Flow**:
    1.  Checks if the number of arguments is correct.
    2.  Sets up the signal handler.
    3.  Converts the server's PID from string to integer.
    4.  Sends the message to the server.

### Server (`server.c`)

*   **Main Functions**:
    *   `handler_sigusr(int sig, siginfo_t *info, void *context)`: Handles received signals and reconstructs the message.
*   **Flow**:
    1.  Prints the server's PID.
    2.  Sets up the signal handler.
    3.  Enters an infinite loop, waiting for signals.

### Testing

1.  Run the server in one terminal:

        ./server

2.  In another terminal, run the client with the server's PID and a message:
    
        ./<use any of the given tests> <server_pid>