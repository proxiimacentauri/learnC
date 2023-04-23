/////////////////////////////////////////////////////
// Determine if the following statements have any errors. If so, highlight them and explain why
//
//  - int 2nd_value=10;
//  - Assume (x=0,y=0,alliszero=1). alliszero =(x=1) && (y=0);
//  - Assume (x=10,y=3,z=0;). y=++x+y;z=z−−>x;
//  - Assume that we want to test if last four bits of x are on. (int MASK=0xF;ison=x&MASK==MASK)
//
/////////////////////////////////////////////////////

-----------------------------------

    Expr: int 2nd_value=10;

    The variable initialization cant start with a number

    Correct: int value_2nd = 10;

-----------------------------------

    Expr: x=0, y=0, alliszero=1
          alliszero = (x=1) && (y=0);

        Expression CANT contain Assignments

        x = 1; y = 0;
        alliszero = x && y;

    Correction: alliszero = (x==1) && (y==0);


-----------------------------------

    Expr: x=10, y=3, z=0
          y = ++x + y;
          z = z−−>x;

    The last expression is not right '-->' is NOT an operator

           z = (z−−) > x;

    Correction: '-->' looks suspicious but it still works

-----------------------------------

    Expr: Test if last four bits of x are on
          MASK = 0xF;
          ison = x & MASK == MASK;

        == has higher priority than &

        ison = (x & MASK) == MASK;


-----------------------------------