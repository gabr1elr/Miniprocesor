Mini Processor - Bit-Level Instruction Interpreter

This project implements a simplified processor that operates directly on bit-encoded instructions. The goal is to decode and execute a compact binary instruction format, simulating how a basic processor separates instructions from data and performs arithmetic operations.

The implementation is structured in multiple tasks, each extending the functionality of the previous one.

Features

Instruction decoding from a 32-bit unsigned integer

Support for basic arithmetic operations:

Addition (+)

Subtraction (-)

Multiplication (*)

Division (/)

Dynamic operand size handling (from 1 to 16 bits)

Sequential execution of operations (with optional operator precedence)

Bit-level manipulation without using bit arrays

Instruction Format

An instruction is encoded as a binary sequence with the following structure:

N (3 bits) – number of operations to execute (N = value + 1, max 8)

Op codes (2 × N bits) – operation codes:

00 → +

01 → -

10 → *

11 → /

Dim (4 bits) – operand size in bits (Dim = value + 1, range 1–16)

The total instruction size fits within a 32-bit unsigned integer.
