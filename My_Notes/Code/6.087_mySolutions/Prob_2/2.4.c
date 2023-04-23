/////////////////////////////////////////////////////
// Using precedence rules, evaluate the following expressions and determine the value of the variables (without running the code).
// Also rewrite them using parenthesis to make the order explicit.
//
//  - Assume (x=0xFF33,MASK=0xFF00).Expression: c=x & MASK ==0;
//  - Assume (x=10,y=2,z=2;).Expression: z=y=x++ + ++y∗2;
//  - Assume (x=10,y=4,z=1;).Expression: y>>= x&0x2 && z
//
/////////////////////////////////////////////////////

-----------------------------------
    x=0xFF33
    MASK=0xFF00

    Eval: c = x & MASK ==0

    0xFF00 =/= 0 --> False --> 0

    0xFF33 & 0 --> 0x0

    Final Ans: 0x0  /* ’==’ > ’&’ > ’=’ */

-----------------------------------
    x=10
    y=2
    z=2

    Eval: z = y = x++ + ++y ∗ 2

            z = y = x++ + 3 ∗ 2
            z = y = 11 + 3 ∗ 2
            z = y = 11 + 6
            z = y = 17

    Final Ans: z = y = 17  /* ’++’ > ’*’ > ’+’ */

Correction: z = y = x++ + 3 ∗ 2
            z = y = 10 + 3 ∗ 2  (Here y=x++ is y=x and then x++)
            z = y = 10 + 3 ∗ 2
            z = y = 16


-----------------------------------

    x=10
    y=4
    z=1

    Eval: y >>= x & 0x2 && z

            y >>= 10 & 0x2 && z

                0010
              & 0010
              --------
                0010

            y >>= 0x2 && 1
            y >>= 1
            y = y >> 1
            y = 4 >> 1

                0100 >> 1
                0010 --> 0x2

            y = 0x2

    Final Ans: y = 0x2 /* ’&’ > ’&&’ > ’>>=’ */
-----------------------------------