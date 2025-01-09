# Minitalk
Minitalk is a project at 42 School that introduces and prepares you for bigger UNIX projects that will appear later in the curriculum. The purpose of this project is to code a small data exchange program between a server and client using UNIX signals. To accomplish that, you will need to learn about UNIX signals and how to handle them effectively.

## Understanding the project
In this project, you are required to create two files: a server and a client.

- Server: When executed, the server will listen for incoming signals. Upon receiving a signal, it will decode the message and, once the entire message has been received, print it to the terminal.
- Client: The client will send an encrypted message to the server using signals. The message will be passed as arguments, and the client will send each character in binary form by using the signals SIGUSR1 and SIGUSR2.
The process of sending the message is done by converting each character to its binary form. For each bit:

If the bit is 1, the client sends SIGUSR1.
If the bit is 0, the client sends SIGUSR2.
This means that the communication between the server and the client occurs through binary encoding, and SIGUSR1 and SIGUSR2 are the only signals allowed for this exchange.

## But what are UNIX signals?
UNIX signals are a form of inter-process communication (IPC) used to notify processes that an event has occurred. Signals can be sent by a process to another process (or to itself) to communicate information, often triggering specific actions.

In this project, we use signals to send data between the client and server:

- SIGUSR1: This signal is used to represent the binary value 1.
- SIGUSR2: This signal represents the binary value 0.
Signals are asynchronous, which means they can interrupt the normal flow of a program. For example, the server process will be paused until a signal is received, at which point it processes the signal and continues. This project uses signals for both communication and synchronization between the client and server.

### Why Use Signals?
The use of signals allows for efficient and lightweight communication between the server and the client. Instead of relying on more complex methods like sockets or files, signals provide a simple mechanism to convey information. This is particularly suitable for small projects and exercises to understand low-level process management in UNIX systems.

## `signal` library
To manage UNIX signals, the project utilizes the signal library. Here’s a breakdown of the key components used:

- `sigaction`: The `sigaction` structure is used to define the behavior of a process when it receives a signal. It allows you to specify which function should be called to handle the signal, whether additional signal information should be available, and which signals should be blocked while handling the signal.

-`sigemptyset`: This function is used to initialize a signal set to be empty (i.e., no signals are blocked). It’s useful when configuring a signal handler with no restrictions on other signals while the handler is running.

- `signal()` and `sigaction()`: These are used to set up the signal handlers. In this project, `sigaction` is used with the `SA_SIGINFO` flag, which provides more detailed information about the signal, such as the PID of the sender.
### Utils Functions for this project
Several utility functions are essential for the successful operation of the client and server.

- `ft_atoi()`:This function converts a string to an integer. It is used to convert the PID passed as an argument in the client to an integer so that the client can send signals to the correct server.

- `ft_printf()`:A custom function to handle formatted output to the terminal. It is used throughout the project to print messages to the terminal, such as the server PID, debugging information, and the final decoded message.

- `send_message()`:This function is responsible for converting the message into its binary form and sending the corresponding signals (SIGUSR1 and SIGUSR2) to the server. It loops through each character of the message, and for each bit, it sends the appropriate signal.

- `signal_handler()`: The signal handler function, which is executed when the server receives a signal. It decodes the incoming signal (either SIGUSR1 or SIGUSR2) and adds the corresponding bit to the message being received.

- `response_handler()`: In the client, this handler receives feedback from the server, notifying the client that the signal has been received and processed. It’s particularly useful when the server acknowledges each bit sent.

- `sigemptyset()`: This function is used to initialize an empty signal set. In the context of this project, it ensures that no additional signals are blocked while the server is processing a received signal, allowing other signals to be handled as they come in.

---
This project provides hands-on experience with the low-level workings of UNIX signals, which is foundational for understanding process communication, synchronization, and other key concepts used in operating systems. By completing this project, you’ll gain valuable skills for tackling more complex system-level tasks in future assignments.
