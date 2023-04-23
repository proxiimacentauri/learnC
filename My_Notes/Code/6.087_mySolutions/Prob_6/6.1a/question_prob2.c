////////////////////////////////////////
//
// Data structure for storing lots of strings is the 'trie'
//
////////////////////////////////////////

================ Problem 6.2 =====================

This tree structure has the special property that a nodes key:
    - Is a prefix of the keys of its children

    Example:
        - If we associate a node with the string 'a'
        - That node may have a child node with the key 'an'
        - which in turn may have a child node 'any'

    Consequences:
        - When many strings share a common prefix, this structure is a very inexpensive
    way to store them.
        - Trie supports very fast searching the complexity of finding a string with 'm' characters is O(m).


----------------------------------------------------------------------------
(a)