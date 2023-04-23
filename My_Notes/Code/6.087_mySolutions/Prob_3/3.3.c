/////////////////////////////////////////////////////
//
// Both the for loop and the do-while loop can be transformed into a simple while loop.
// For each of the following examples, write equivalent code using a while loop instead.
//
/////////////////////////////////////////////////////


-------------------------------------------------------------
(a) int factorial(int n)
    {
        int i, ret = 1;
        for (i = 2; i <= n; i++)
            ret *= i;

        return ret;
    }


>>
    int factorial(int n)
    {
        int i = 2, ret = 1;
        while(i <= n)
        {
            ret *= i;
            i++;
        }
        return ret;
    }

    Another Short way to do it:

    int factorial(int n)
    {
        int i = 1, ret = 1;
        while(++i <= n)
            ret *= i;
        return ret;
    }




-------------------------------------------------------------
(b)
     #include <stdlib.h>

    double rand_double()
    {
        /*  generate randon number in [0,1) */
        double ret = (double)rand();
        return ret/(RAND_MAX + 1);
    }

    int sample_geo_rv(double p)
    {
        double q;
        int n = 0;
        do
        {
            q = rand_double();
            n++;
        }while (q >= p);
        return n;
    }


>>  int sample_geo_rv(double p)
    {
        double q;
        int n = 0;

        q = rand_double();
        n++;

        while(q >= p)
        {
            q = rand_double();
            n++;
        }
        return n;
    }