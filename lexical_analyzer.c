#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Token types - Represents different types of tokens in the expression.
typedef enum
{
    TOKEN_NUMBER,      // Numbers (e.g., 12, 25, 15)
    TOKEN_OPERATOR,    // Operators (+, -, *, /)
    TOKEN_IDENTIFIER,  // Identifiers (variables like x, y, z)
    TOKEN_PARENTHESIS, // Parentheses ( ( , ) )
    TOKEN_MODULO,      // Modulo operator (%)
    TOKEN_UNKNOWN      // Unknown character
} 
TokenType;

// Token structure - Holds a token's type and its string value
typedef struct
{
    TokenType type;  // The type of the token (e.g., number, operator)
    char value[50];  // The actual string value of the token
} 
Token;

// Function to classify characters - Identifies the type of character in the expression
TokenType classify_character(char c)
{
    if (isdigit(c))                // Check if it's a number
        return TOKEN_NUMBER;       
    if (isalpha(c))                // Check if it's an identifier (a variable)
        return TOKEN_IDENTIFIER;   
    if (c == '+' || c == '-' || c == '*' || c == '/')   // Check if it's an operator
        return TOKEN_OPERATOR;
    if (c == '(' || c == ')')     // Check if it's a parenthesis
        return TOKEN_PARENTHESIS;
    if (c == '%')                 // Check if it's a modulo operator
        return TOKEN_MODULO;
    return TOKEN_UNKNOWN;        // Return unknown if none of the above
}

// Function to tokenize input expression - Tokenizes the given expression into tokens
void tokenize_expression(const char *expression) 
{
    int i = 0, j = 0;         // i: index for the expression, j: index for the current token
    char current_token[50] = {0}; // Buffer to store the current token

        // Loop through each character in the expression
    while (expression[i] != '\0') 
    {
        char c = expression[i];                    // Get current character
        TokenType type = classify_character(c);   // Classify the character

        // If the character is part of a number or identifier, add it to the current token
        if (type == TOKEN_NUMBER || type == TOKEN_IDENTIFIER) 
        {
            current_token[j++] = c;      // Add character to the token
        } 
        else {
            if (j > 0) 
            { // End of a token (e.g., when encountering an operator or parenthesis)
                current_token[j] = '\0';         // Null-terminate the token
                // Print the current token and its type (either a number or identifier)
                printf("Token: %-10s Type: %s\n", current_token, 
                       type == TOKEN_NUMBER ? "NUMBER" : "IDENTIFIER");
                j = 0;    // Reset current token index for next token
            }
            if (type != TOKEN_UNKNOWN && !isspace(c)) 
            {
                 // Print the operator, parenthesis, or modulo token
                printf("Token: %-10c Type: %s\n", c, 
                       type == TOKEN_OPERATOR ? "OPERATOR" :
                       type == TOKEN_PARENTHESIS ? "PARENTHESIS" : "MODULO");
            }
        }
        i++;    // Move to the next character in the expression
    }
    // Print the last token if there is any remaining
    if (j > 0) 
    {
        current_token[j] = '\0';  // Null-terminate the last token
        printf("Token: %-10s Type: %s\n", current_token, "IDENTIFIER/NUMBER");
    }
}

int main() 
{
    // Sample expression to analyze
    const char *expression = "(12 + x * (y - 25) / z) %15";
    printf("Analyzing Expression: %s\n", expression); 
    // Call the function to tokenize the expression
    tokenize_expression(expression);
    return 0;
}
