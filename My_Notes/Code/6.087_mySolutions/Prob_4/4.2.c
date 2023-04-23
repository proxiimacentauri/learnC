////////////////////////////////////////////////////////
//
// use our knowledge of strings to duplicate the functionality of the C standard library’s strtok() function.
//  Which extracts “tokens” from a string.
//
////////////////////////////////////////////////////////

In this problem, we will
    - The string is split using a set of delimiters, such as whitespace and punctuation.
    - Each piece of the string, without its surrounding delimiters, is a token.
    - The process of extracting a token can be split into 2 parts:
        - Finding the beginning of the token (the first character that is not a delimiter),
        - Finding the end of the token (the next character that is a delimiter).

    The first call of strtok() looks like this:

        char *strok(char *str, const char *delims);

        - The string str is the string to be tokenized
        - The delims is a string containing all the single characters to use as delimiters (e.g. " \t\r\n")
        - The return value is the first token in str.
        - Additional tokens can be obtained by calling strtok() with NULL passed for the str argument:

        char *strok(NULL, const char *delims);

    Because strtok()
    - Uses a static variable to store the pointer to the beginning of the next token
    - Calls to strtok() for different strings cannot be interleaved.
    - The code for strtok() is provided below:

        char *strok(char *text, const char *delims){
            // init
            if(!text)
                text = pnexttoken;

            // find start of token in text
            test += strspn(text, delims);
            if(*text == '\0')
                return NULL;

            // find end of token in text
            pnexttoken = text + strcspn(text, delims);

            // insert null-terminator at the end
            if(*pnexttoken != '\0')
                *pnexttoken++ = '\0';

            return text;
        }
--------------------------------------------------------
(a) In the context of our string tokenizer:
    - The function strspn() computes the index of the first non-delimiter character in our string.
    - Using pointers or array indexing (your choice), implement the strspn() function.
    - In order to locate a character in another string, you may use the function strpos(), which is declared below:

        int strpos(const char *str, const char *ch);

        - This function returns the index of the first occurrence of the character ch in the string str, or -1 if ch is not found.

    The declaration of strspn() is provided below:
        unsigned int strspn(const char *str, const char *delims){
            // insert code here
        }

        - Here, delims is a string containing the set of delimiters
        - The return value is the index of the first non-delimiter character in the string str.

        Example:
                strspn(" . This", " .") == 3.

            - If the string contains only delimiters, strspn() should return the index of the null-terminator(\0).
            - Assume \0 is not a delimiter.

>>

    unsigned int strstr(const char *str, const char *delims)
    {
        // insert code here
        unsigned int flag;

        for(flag = 0; *str != '\0'; flag++, str++)
        {
            if(strpos(str, delims) == -1)
                break;
        }
        return flag;
    }





--------------------------------------------------------
(b) The function strcspn() computes the index of the first delimiter character in our string.

    Heres the declaration of strcspn():
        unsigned int strspn(const char *str, const char *delims){
            // insert code here
        }

    If the string contains no delimiters:
    - return the index of the null-terminator (\0).
    - Implement this function using either pointers or array indexing.


>>
        unsigned int mot(const char *str, const char *delims)
        {
            // insert code here
            unsigned int flag;

            for(flag = 0; str != NULL; str++, flag++)
            {
                if(*str == *delims)
                    break;
            }
            return flag;
        }