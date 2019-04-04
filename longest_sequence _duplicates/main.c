#include <stdio.h>

/*********************************
The algorithm finds the longest sequence of the same value.

 Running time: O(n), because it loops the array only once.
For hver element gør vi konstant nummer af skridt
***********************************/

int longest_sequence(int *array, int count)
{
    int length;
    int longest;
    longest = length = 0;
    for (int i = 0 ; i < count - 1 ; i++)
    {
        if (array[i + 1] == array[i])
            length++;
        else {
             // length + 1 to count the last element too
            if (longest < length + 1)
                longest = length + 1;
            length = 0;
        }
    }
    return longest;
}




int
main()
{
    int array[] = {2, 2, 4, 4, 4, 4, 4, 5, 2, 2, 1, 3};
    int count = sizeof(array) / sizeof(array[0]);

    printf("The longest sequence has %d elements\n",
        longest_sequence(array, count));
    return 0;
}
