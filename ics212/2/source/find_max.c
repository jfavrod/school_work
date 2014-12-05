/**********************************************************************
//
// NAME:        Jason Favrod
//
// HOMEWORK:    2 Part A
//
// CLASS:       ICS 212
//
// INSTRUCTOR:  Ravi Narayan
//
// DATE:        6 Sept 2014
//
// FILE:        find_max.c
//
// DESCRIPTION: A function which returns the index of the largest number
//              in an array of floats.
//
***********************************************************************/

int find_index_of_max(float float_array[], int size_of_array)
/**********************************************************************
//
//  Function name:      find_index_of_max
//
//  DESCRIPTION:        Finds the index of the largest float in an
//                      array of floats.
//
//  Parameters:         float_array (float[]) : The array to be
//                      scanned for the largest value.
//                      size_of_array (int) : The size of the array
//
//        
//  Return values:      int : The index of the largest float in
//                      the array.
//
***********************************************************************/
{
    short i, index_of_max = 0;
    float max = 0.0;

    for (i = 0; i < size_of_array; i++)
    {
        if (float_array[i] > max)
        {
            max = float_array[i];
            index_of_max = i;
        }
    }

    return index_of_max;
}
