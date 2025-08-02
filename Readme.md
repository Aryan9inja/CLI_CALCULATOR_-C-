# 🧮 CLI Calculator in C

A command-line calculator built in C that:

* Accepts **infix expressions** (e.g. `3 + 4 * 2 / (1 - 5)`)
* Converts them to **postfix notation** using the **Shunting Yard algorithm**
* Evaluates the postfix expression using a **stack-based approach**

---

## 📂 Project Structure

```
.
├── main.c               # CLI entry point
├── parser.c/h           # Infix to Postfix converter
├── tokenizer.c/h        # Tokenizer for input expression
├── stack.c/h            # Stack for numeric evaluation
├── token_stack.c/h      # Stack for operator tokens (used in parser)
├── evaluator.c/h        # Evaluates postfix expressions
├── Makefile             # Build script
└── README.md
```

---

## ⚙️ How It Works

### Step 1: Tokenization

Parses a string like `3 + 4 * 2` into structured tokens:

```
[TOKEN_NUMBER: 3, TOKEN_PLUS, TOKEN_NUMBER: 4, TOKEN_MULTIPLY, TOKEN_NUMBER: 2]
```

### Step 2: Infix to Postfix

Uses the **Shunting Yard Algorithm** to convert to:

```
3 4 2 * +
```

### Step 3: Postfix Evaluation

A simple stack is used to evaluate the postfix expression:

```
3 + (4 * 2) → 11
```

---

## 🚀 Shunting Yard Diagram

```
Infix:     3 + 4 * 2 / (1 - 5)
Tokens:    [3, +, 4, *, 2, /, (, 1, -, 5, )]

Operators Stack        Output Queue
----------------     ----------------
                   | 3                   |
+                  | 3                   |
+ *                | 3 4                 |
+ *                | 3 4 2               |
+ /                | 3 4 2 *             |
+ / (              | 3 4 2 *             |
+ / (              | 3 4 2 * 1           |
+ / ( -            | 3 4 2 * 1           |
+ / ( -            | 3 4 2 * 1 5         |
+ /                | 3 4 2 * 1 5 -       |
+                  | 3 4 2 * 1 5 - /     |
                   | 3 4 2 * 1 5 - / +   |
```

---

## 💪 How to Build & Run

### 🛠️ Prerequisites:

* GCC compiler

### 🔧 Build:

```bash
make
```

### ▶️ Run:

```bash
make run
```

### 💪 Clean:

```bash
make clean
```

---

## 🔢 Example Usage

```
CLI Calculator (Enter 'exit' to quit)

Enter expression: 3 + 4 * 2 / (1 - 5)
Result: 1.000000

Enter expression: 10 + 2 * 6
Result: 22.000000

Enter expression: exit
Goodbye!
```

---

## ✨ Features

* Supports `+`, `-`, `*`, `/`, and parentheses `()`
* Handles floating point numbers
* Uses dynamic stack memory allocation
* Modular structure with clean separation of tokenizer, parser, and evaluator

---

## 👨‍💻 Author

Built with C and love for the command line by Aryan Singh Thakur.