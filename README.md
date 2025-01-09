# Minitalk
Minitalk is a project at 42 School that introduces to the UNIX world and prepares you for bigger UNIX projects thats will appear later on the cursus. 
The purpose of this project is to code a small data exchange program between server and client using UNIX signals. To acomplish that you will have to learn about them.

## Understanding the project
Basically you have to create a server file that when executed will be listening for any signal and a client file that will send an encripted message using signals. This message will be passed as arguments by the user and when the server finishes receiving the whole message, it has to print it in the terminal.
We are only allowed to use SIGUSR1 and SIGUSR2, so the only alternative is to send the message in binary code. In my case I looped throw the message and every char I looped throw its bits. If bit equal 1, I send SIGUSR1 and if bit equal 0, I send SIGUSR2.

## What are UNIX signals?
....

## `signal` library
....
### Utils Functions for this project
....
