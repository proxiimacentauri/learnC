////////////////////////////////////////
//
// Four Function calculator using Stacks and Queues
//
////////////////////////////////////////

================ Problem 6.1 =====================

- This calculator takes as input a space-delimited infix expression:
        3 + 4 * 7

- Which you will convert to postfix notation and evaluate.
- There are four (binary) operators your calculator must handle:
    - addition (+)
    - subtraction (-)
    - multiplication (*)
    - division (/)
    - unary negation operator (also -)

- The usual order of operations is in effect:
    - The unary negation operator '-' has higher precedence than the binary operators
    - Evaluated right-to-left (right-associative)
    - All binary operators are evaluated left-to-right (left-associative)

- To start, we will NOT consider parentheses in our expressions.
- The code is started for you in prob1.c.

- Read over the file, paying special attention to:
    - data structures used for tokens
    - the stack
    - and queue
    - as well as the functions you will complete

----------------------------------------------------------------------------
(a) We have provided code to translate the string to a queue of tokens:
    - Arranged in infix (natural) order.

    You must:
        - fill in the infix_to_postfix() function to construct a queue of tokens arranged in postfix order
        - The infix queue should be empty when youre done
        - Complete the evaluate_postfix() function to evaluate the expression stored in the postfix queue and return the answer

    - You may assume the input is a valid infix expression, but it is good practice to make your code robust by handling possible errors (e.g. not enough tokens) .


----------------------------------------------------------------------------
(b) Now, an infix calculator really is not complete if parentheses are not allowed.
    - So, in this part, update the function infix_to_postfix() to handle parentheses as we discussed in class.
    - Note: your postfix queue should contain no parentheses tokens.