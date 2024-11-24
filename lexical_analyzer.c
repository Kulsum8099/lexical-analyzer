#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Token types
typedef enum {
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_IDENTIFIER,
    TOKEN_PARENTHESIS,
    TOKEN_MODULO,
    TOKEN_UNKNOWN
} TokenType;

// Token structure
typedef struct {
    TokenType type;
    char value[50];
} Token;

// Function to classify characters
TokenType classify_character(char c) {
    if (isdigit(c)) return TOKEN_NUMBER;
    if (isalpha(c)) return TOKEN_IDENTIFIER;
    if (c == '+' || c == '-' || c == '*' || c == '/') return TOKEN_OPERATOR;
    if (c == '(' || c == ')') return TOKEN_PARENTHESIS;
    if (c == '%') return TOKEN_MODULO;
    return TOKEN_UNKNOWN;
}

// Function to tokenize input
void tokenize_expression(const char *expression) {
    int i = 0, j = 0;
    char current_token[50] = {0};

    while (expression[i] != '\0') {
        char c = expression[i];
        TokenType type = classify_character(c);
        
        if (type == TOKEN_NUMBER || type == TOKEN_IDENTIFIER) {
            current_token[j++] = c;
        } else {
            if (j > 0) { // End of a token
                current_token[j] = '\0';
                printf("Token: %-10s Type: %s\n", current_token, 
                       type == TOKEN_NUMBER ? "NUMBER" : "IDENTIFIER");
                j = 0;
            }
            if (type != TOKEN_UNKNOWN && !isspace(c)) {
                printf("Token: %-10c Type: %s\n", c, 
                       type == TOKEN_OPERATOR ? "OPERATOR" :
                       type == TOKEN_PARENTHESIS ? "PARENTHESIS" : "MODULO");
            }
        }
        i++;
    }
    // Print the last token if any
    if (j > 0) {
        current_token[j] = '\0';
        printf("Token: %-10s Type: %s\n", current_token, "IDENTIFIER/NUMBER");
    }
}

int main() {
    const char *expression = "(12 + x * (y - 25) / z) %15";
    printf("Analyzing Expression: %s\n", expression);
    tokenize_expression(expression);
    return 0;
}