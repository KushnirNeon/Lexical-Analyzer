# Lexical Analyzer

## Description

This C++ program is a **lexical analyzer** for an assembly-like language. It reads a source code file and identifies lexemes such as numbers, identifiers, constants, reserved words, operators, comments, directives, and punctuation marks.

The analyzer uses **regular expressions** to match different types of lexemes and prints each lexeme along with its type.

## Features

* Recognizes decimal, float, and hexadecimal numbers.
* Detects string and character constants.
* Identifies preprocessor and assembler directives.
* Recognizes reserved words and operators.
* Detects comments and punctuation marks.
* Identifies valid identifiers.
* Marks unknown lexemes as `Error`.

## Supported Lexemes

| Lexeme Type            | Example                   |
| ---------------------- | ------------------------- |
| Decimal number         | `123`                     |
| Float number           | `12.34`                   |
| Hexadecimal number     | `0x1F`                    |
| String constant        | `"Hello"`                 |
| Char constant          | `'a'`                     |
| Preprocessor directive | `#define`                 |
| Comment                | `; this is a comment`     |
| Reserved word          | `MOV`, `ADD`, `SUB`, etc. |
| Operator               | `AND`, `OR`, `XOR`, etc.  |
| Punctuation mark       | `,`, `;`, `[`, `]`        |
| Identifier             | `myVar`                   |
| Assembler directive    | `.data`, `.text`          |

## Usage

1. Compile the program using a C++ compiler supporting C++11 or later:

   g++ -std=c++11 lexical_analyzer.cpp -o lexical_analyzer

2. Run the program:

   ./lexical_analyzer

3. Enter the path to the source code file to analyze.

4. The program will output all lexemes with their corresponding types:

   < MOV - Reserved word >
   < AX - Identifier >
   < 10 - Decimal number >
   < ; initialize register - Comment >

5. To exit, type `exit` when prompted for a filename.
