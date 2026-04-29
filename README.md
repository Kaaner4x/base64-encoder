# Base64 Encoder 🔠

A lightweight and efficient C console application that encodes any given text into **Base64** format.

## 📖 What is Base64 Encoding?

**Base64 Encoding** is a method used to convert binary data (or plain text) into an ASCII string format by translating it into a radix-64 representation. It is widely used in email via MIME, and storing complex data in XML or JSON to ensure that the data remains intact without modification during transport.

The encoding works as follows:
1. Takes the input string and processes it in chunks of 3 bytes (24 bits).
2. Splits the 24 bits into 4 groups of 6 bits.
3. Maps each 6-bit group to a corresponding character in the Base64 alphabet (A-Z, a-z, 0-9, +, /).
4. Pads the end of the output with `=` if the original input length was not a multiple of 3.

## 🎯 Project Purpose

The main objective of this project is to implement a custom **Base64 Encoder** in C without relying on external libraries for the encoding logic. 

When a user runs the application with a text argument:
1. It calculates the necessary memory for the encoded output.
2. **Encodes** the input string using the Base64 algorithm.
3. Outputs both the **original text** and the newly **encoded text** to the console.

## 🚀 How to Run

Follow these steps to run the application on your local machine:

### Prerequisites
- A C compiler such as [GCC](https://gcc.gnu.org/) or MinGW must be installed on your system.

### Steps
1. **Clone the repository** (or download the source code):
   ```bash
   git clone <repository-url>
   ```
2. **Navigate to the project directory**:
   ```bash
   cd Base64Encoder
   ```
3. **Compile the application**:
   ```bash
   gcc encoder.c -o encoder
   ```
4. **Run the application**:
   On Windows:
   ```bash
   encoder.exe "Your text here"
   ```
   On Linux/Mac:
   ```bash
   ./encoder "Your text here"
   ```
5. **Usage**: The program will take the string you provided as an argument and print its Base64 encoded equivalent.

## 📄 License

This project is licensed under the [MIT License](LICENSE). See the `LICENSE` file for details.
