////////////////////////////////////////////////////////
//
// Re-implement the algo using pointers and pointer arithmetic
//
////////////////////////////////////////////////////////

--------------------------------------------------------
(a) The function shift_element() takes as input the index of an array element that has been determined to be out of order.
    The function shifts the element towards the front of the array, repeatedly swapping the preceding element until the out-of-order element is in the proper
location.
    The implementation using array indexing is provided below for your reference:

    /* move prev ele down until insertion point is reached */
    void shift_element (unsigned int i)
    {
        int ival;
        // guard against going outside the array
        for (ival = arr[i]; i && arr[i-1] > ival; i--)
        {
            arr[i] = arr[i-1];  // move element down
            arr[i] = ival;      // insert element
        }
    }

    Re-implement this function using pointers and pointer arithmetic instead of array indexing
    // int *pele - pointer to the element in arr(type int[]) that is out-of-place

    void shift_element(int *pele){
        // insert code here
    }

>>

    void shift_element(int *pele)
    {
        // insert code here
        int ival;
        // guard against going outside the array
        for (ival = *pele; pele && *(pele - 1) > ival; pele--)
        {
            *pele = *(pele - 1);  // move element down
            *pele = ival;
        }
    }



--------------------------------------------------------
(b) The function insertion sort() contains the main loop of the algorithm.
    - It iterates through elements of the array, from the beginning, until it reaches an element that is out-of-order.
    - It calls shift_element() to shift the offending element to its proper location earlier in the array and resumes iterating until the end is reached.
    The code from lecture is provided below:

        /* iterate until out-of-order element found; Shift the element, and continue interating */
        void insertion_sort(void){
            unsigned int i, len = array_length(arr);
            for(i = 1; i < len; i++){
                if(arr[i] < arr[i-1])
                    shift_element(i);
            }
        }
    Re-implement this function using pointers and pointer arithmetic instead of array indexing

>>
    void insertion_sort(void)
    {
        unsigned int i, len = array_length(arr);
        unsigned int *pEle = arr;

        for(i = 1; i < len; i++)
        {
            if(*(pEle + i) < *(pEle + i - 1))
                shift_element(i);
        }
    }
