////////////////////////////////////////////////////////
//
// Implement Shell Sort
//
////////////////////////////////////////////////////////

This sort is built upon the insertion sort:
    - But attains a speed increase by comparing far-away elements against each other before comparing closer-together elements.
    - The distance between elements is called the “gap”.
    - In the shell sort, the array is sorted by sorting gap sub-arrays, and then repeating with a smaller gap size.

    As written here, the algorithm sorts in O(n^2) time.
    - However, by adjusting the sequence of gap sizes used, it is possible to improve the performance to O(n^(3/2)), O(n^(4/3)), or even O(n(log n)^2) time.
    - You can read about a method for performing the shell sort in O(n(log n)2) time on RobertSedgewick’s page at Princeton:
            http://www.cs.princeton.edu/~rs/shell/paperF.pdf

    Note that you can find complete C code for the shell sort at the beginning of the paper, so please wait until you have finished this exercise to read it.


--------------------------------------------------------
(a) First, we will modify the shift_element() function from the insertion sort code for the shell sort.
    - The new function, started for you below, should start at index i and shift by intervals of size gap.

    Write the new function, using array indexing or pointers. Assume that i ≥ gap.

        void shift_element_by_gap(unsigned int i, unsigned int gap){
            // insert code here
        }

>>

    /* move prev ele down until insertion point is reached */
    void shift_element_by_gap (unsigned int i, unsigned int gap)
    {
        int ival;
        // guard against going outside the array
        for (ival = arr[i]; i && arr[i + gap] > ival; i--)
        {
            arr[i] = arr[i-1];  // move element down
            arr[i] = ival;      // insert element
        }
    }


--------------------------------------------------------
(b) Now, we need to write the main shell sort routine. Using the template below:
    Fill in the missing code so that the insertion sort in the inner loop compares every element to the element gap spaces before it.

    void shell_sort(void){
        unsigned int gap, i, len = array_length(arr);

        // sort, comparing against farther away elements first, then closer elements
        for(gap = len/2; gap > 0; gap /=2){
            // do insertion-like sort, but comparing and shifting elements in multiples of gap
            for(/* insert code here*/){
                if(/* insert code here*/){
                    // out of order, do shift
                    shift_element_by_gap(i, gap);
                }
            }
        }
    }

>>