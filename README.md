# NETWORK-LAB-S6

> ⚠️ **WARNING**: Use this code at your own risk. We are not responsible for any errors or issues that may occur in the lab.

## Table of Contents

- [Project Structure](#project-structure)
- [How to Compile and Run](#how-to-compile-and-run)
- [Contributors](#contributors)

---

## Project Structure

- [FTP](./FTP)
- [Leaky Bucket](./Leaky%20Bucket)
- [TCP/EvenOROdd](./TCP/EvenOROdd)
- [TCP/factorial](./TCP/factorial)
- [TCP/palindrome](./TCP/palindrome)
- [TCP](./TCP)
- [UDP/length_of_string](./UDP/length_of_string)
- [UDP](./UDP)

```text
.
├── FTP
│   ├── client.c
│   ├── server.c
│   └── demo.txt
│
├── Leaky Bucket
│   └── leaky.c
│
├── TCP
│   ├── EvenOROdd
│   │   ├── client.c
│   │   └── server.c
│   ├── factorial
│   │   ├── client.c
│   │   └── server.c
│   ├── palindrome
│   │   ├── client.c
│   │   └── server.c
│   └── client.c
│   └── server.c
│
├── UDP
│   ├── length_of_string
│   │   ├── client.c
│   │   └── server.c
│   ├── client.c
│   └── server.c
│
└── README.md
```

---

## How to Compile and Run

To compile and run any of the C programs:

```bash
# Compile the server
$ gcc server.c -o server

# Compile the client
$ gcc client.c -o client

# Run the server (in one terminal)
$ ./server

# Run the client (in another terminal)
$ ./client
```

---

## Contributors

- [Jithu-9847](https://github.com/Jithu-9847)
- [Grey-Ashh](https://github.com/Grey-Ashh)

---


