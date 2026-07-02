# RSA Cryptography Toolkit

A C++ command-line toolkit that demonstrates RSA key generation, encryption, decryption, file encryption, file decryption, and key saving/loading.

This project was built to explore the mathematics behind RSA cryptography and practice modular C++ design.

## Features

- Generate RSA public/private key pairs
- Encrypt plaintext files
- Decrypt ciphertext files
- Save RSA keys to `keys.txt`
- Load saved RSA keys
- Use Miller-Rabin primality testing
- Modular project structure with header and source files

## Algorithms Implemented

- Euclidean Algorithm
- Extended Euclidean Algorithm
- Modular Inverse
- Fast Modular Exponentiation
- Miller-Rabin Primality Test
- Random Prime Generation
- RSA Key Generation
- RSA Encryption
- RSA Decryption

## Project Structure

```text
rsa-cryptography-toolkit/
├── include/
│   ├── math_utils.h
│   └── rsa.h
├── src/
│   ├── math_utils.cpp
│   └── rsa.cpp
├── examples/
│   └── sample_message.txt
├── main.cpp
├── README.md
├── LICENSE
└── .gitignore