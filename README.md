# Lexical Analyzer for Mathematical Expressions

## Description:
This project implements a **lexical analyzer** in **C** that tokenizes mathematical expressions into numbers, operators, and parentheses. It is designed to process and analyze mathematical expressions, identify different components (tokens), and categorize them accordingly.

### Features:
- Supports numbers and identifiers.
- Handles basic arithmetic operators: `+`, `-`, `*`, `/`, `%`.
- Supports parentheses for grouping expressions.
- Designed for educational purposes to demonstrate lexical analysis in programming languages.

### Example Expression:
(12 + x * (y - 25) / z) % 15

### Example Output:
Token: (         Type: PARENTHESIS <br>
Token: 12        Type: NUMBER <br>
Token: +         Type: OPERATOR <br>
Token: x         Type: IDENTIFIER <br>
Token: *         Type: OPERATOR <br>
Token: (         Type: PARENTHESIS <br>
Token: y         Type: IDENTIFIER <br>
Token: -         Type: OPERATOR <br>
Token: 25        Type: NUMBER <br>
Token: )         Type: PARENTHESIS <br>
Token: /         Type: OPERATOR <br>
Token: z         Type: IDENTIFIER <br>
Token: )         Type: PARENTHESIS <br>
Token: %         Type: MODULO <br>
Token: 15        Type: NUMBER <br>


### How to Run:

1. **Ensure you have a C compiler installed (e.g., GCC or MinGW)**.
   - If you don’t have a C compiler, you can install MinGW or GCC.
   
2. **Clone or download the repository**:
   - Clone the repository to your local machine:
     ```bash
     git clone https://github.com/Kulsum8099/lexical-analyzer.git
     ```
   - Or, you can **download** the ZIP file from GitHub and extract it to a folder.

3. **Navigate to the project folder**:
   - In the terminal, go to the folder where you saved the project:
     ```bash
     cd "path/to/your/project/folder"
     ```
     For example, if your project is in C:/Users/USER/Desktop/CSC 461/Assignment, you would run:  
     ```bash
     "cd "C:/Users/USER/Desktop/CSC 461/Assignment"
     ```

4. **Compile the program**:
   - Use **GCC** (or MinGW) to compile the C source code into an executable:
     ```bash
     gcc lexical_analyzer.c -o lexical_analyzer.exe
     ```

5. **Run the program**:
   - After compiling, run the executable:
     ```bash
     ./lexical_analyzer.exe
     ```

### Project Structure:
- lexical_analyzer.c      # Source code file
- lexical_analyzer.exe     # Compiled executable (generated after build)
- README.md                # Project documentation

