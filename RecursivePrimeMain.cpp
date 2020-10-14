/**
 * Kimi Holsapple
 * Description: Creates  an array of user-specified size and values and checks them for prime integers using a recursion and iteration.
 * RecursivePrimeMain.cpp
 */

#include <iostream>
#include <cmath>

using namespace std;

const int SORT_MAX_SIZE = 16;

/**
 *purpose: through iteration determine if an array is composed of only prime numbers
 *pre: int *array - non empty user-specified array of integers through reference
 *     int arraySize - user-specified array size
 *post: stores return value in "statusIter" to be used for printing
 *return: bool isPrime
 */
bool IsArrayPrimeIter (int *array, int arraySize);

/**
 *purpose: recursively determine if an array is composed of only prime numbers
 *pre: int *array - non empty user-specified array of integers through reference
 *     int arraySize - user-specified array size
 *post: stores return value in "statusRecur" to be used for printing
 *return: bool isPrime
 */
bool IsArrayPrimeRecur (int *array, int arraySize);

/**
 *purpose: recursive helper function to IsArrayPrimeRecur to determine if specified array index is prime
 *pre: int &arrayVal - array integer element passed through reference
 *     int divisor - array integer element to be subtracted each recursion to divide against arrayVal
 *post: stores return value in "statusIter" to be used for printing
 *return: bool isPrimeR
 */
bool IsPrimeRecur (int &arrayVal, int divisor);

int main() {
    
    int key = 1;
    while (key != 0) {
        int arraySize;
        cout << "--------Welcome to Prime Checker------" << endl;
        cout << "Please enter an Array Size: " << endl;
        cin >> arraySize;
        while (arraySize > SORT_MAX_SIZE || arraySize < 0) {
            arraySize = 0;
            cout << "Max size exceeded" << endl << "please enter an array size less than or equal to size 16: " << endl;
            cin >> arraySize;
        }
        int *array = new int[arraySize];
        
        cout << endl << "-----Now entering values for Array-----" << endl;
        int i = 0;
        while ( i < arraySize ) {
            cout << "what value will be in the " << i << "th index?:" << endl;
            cin >> array[i];
            while ( array[i] < 1 || array[i] > 99) {
                cout << "make sure input is between 1 - 99 inclusive" << endl;
                cout << "reinput value: " << endl;
                cin >> array[i];
            }
            i++;
        }
        
        cout << endl << "-------checking for prime numbers-------" << endl;
        bool statusIter = IsArrayPrimeIter(array, arraySize);
        cout << endl;
        bool statusRecur = IsArrayPrimeRecur(array, arraySize);
         
        cout << endl << "------------Results----------" << endl;
        if (statusIter == true) {
            cout << endl << "Prime Array using iteration" << endl << endl;
        } if (statusIter == false) {
            cout << endl << "Not a Prime Array using iteration" << endl << endl;
        }
        if (statusRecur == true) {
            cout << endl << "Prime Array using recursion" << endl << endl;
        } if (statusRecur == false) {
            cout << endl << "Not a Prime Array using recursion" << endl << endl;
        }
        delete[] array;
        
        cout << "-------------Continue?------------" << endl;
        cout << "This is a pause" << endl;
        cout << "If user would like to quit program please push 0" << endl;
        cout << "Otherwise, push any number: " << endl;
        cin >> key;
        cout << endl;
        
    }
    return 0;
}

/**
    bool IsArrayPrimeIter (int* array, int arraySize)
        print out "Entering IsArrayPrimeIter"
        create return value bool isPrime = true
 
        i = 0
        while (i < arraySize)
            indexAt = array[1]
            if ( indexAt == 0 or == 1)
                print out "Leaving IsArrayPrimeIter"
                return isPrime = false
            n = indexAt --
            while (n > 1)
                if (indexAt % n == 0)
                    print out "Leaving IsArrayPrimeIter"
                    return isPrime = false
                n-- // allow 2nd while to end
 
            i++ // to allow 1st while to end
 
        print out "Leaving IsArrayPrimeIter"
        return isPrime
 */

bool IsArrayPrimeIter (int* array, int arraySize) {
    cout << "Entering IsArrayPrimeIter" << endl;
    
    bool isPrime = true;

    //iterate through the array
    int i = 0;
    while (i < arraySize ) {
        int indexAt = array[i];
        if (indexAt == 0 || indexAt == 1) {
            cout << "Leaving IsArrayPrimeIter" << endl;
            return isPrime = false;
        }
        
        int n = indexAt - 1;
        // loop to do the calculation for the prime number
        while (n > 1) {
            if ((indexAt % n) == 0) {
                //if prime number isn't found then say is false the array has composites
                cout << "Leaving IsArrayPrimeIter" << endl;
                return isPrime = false;
            } // while calculation
            n --;
        } // while array iteration
        i++;
    };
    cout << "Leaving IsArrayPrimeIter" << endl;
    return isPrime;
};


/**
 bool IsArrayPrimeRecur (int* array, int arraySize)
    print out "Entering IsArrayPrimeRecur"
    create return value bool isPrime = false
    arraySize-- // will process array elements backwards & this gives the index
    indexAt = array[arraySize]
 
    //BASE CASE to stop if a single composite value has been found
    if (IsPrimeRecur(indexAt, indexAt) != true)
        isPrime = false
        return isPrime
 
    //Recursion
    if ( IsPrimeRecur(indexAt, indexAt) == true && arraySize > 0)
        isPrime = IsArrayPrimeRecur (array, arraySize)
        return isPrime
 
    //BASE CASE to stop when we have gone through entire array and last index is prime
    if (IsPrimeRecur(indexAt, indexAt) == true && arraySize == 0)
        isPrime = true;
        return isPrime;
 
    print out "Leaving IsArrayPrimeRecur"
    return isPrime
*/

bool IsArrayPrimeRecur (int* array, int arraySize) {
    cout << "Entering IsArrayPrimeRecur" << endl;
    bool isPrime = false;
    arraySize --;
    int indexAt = array[arraySize];
    
    //stop if composite is found
    if (IsPrimeRecur(indexAt, indexAt) != true) {
        //BASE CASE: array is NOT prime
        isPrime = false;
        cout << "Leaving IsArrayPrimeRecur" << endl;
        return isPrime;
    }
    
    //iterate through array
    if ( IsPrimeRecur(indexAt, indexAt) == true && arraySize > 0) {
        isPrime = IsArrayPrimeRecur (array, arraySize);
        cout << "Leaving IsArrayPrimeRecur" << endl;
        return isPrime;
    }
    
    if (IsPrimeRecur(indexAt, indexAt) == true && arraySize == 0) {
        //BASE CASE: array is prime since we reached the end
        cout << "Leaving IsArrayPrimeRecur" << endl;
        isPrime = true;
        return isPrime;
    }
    
    cout << "Leaving IsArrayPrimeRecur" << endl;
    return isPrime;
};

/**
  bool IsPrimeRecur (int &arrayVal, int divisor)
    print out "Entering isPrimeRecur"
    create return value bool isPrimeR
    divisor --
 
    //BASE CASE: value is 1 who is not a prime number
    if (arrayVal == 1)
        return isPrimeR = false;
     
    //BASE CASE: if only 1 divides value is prime (returning true)
    if (arrayVal % divisor == 0)
         if (divisor == 1)
             isPrimeR = true;
             return isPrimeR;
         if (divisor != 1) {
             isPrimeR = false;
             return isPrimeR;

     //Recursive call
     if (arrayVal % divisor != 0) {
         isPrimeR = IsPrimeRecur(arrayVal, divisor)
         return isPrimeR
 
    print out "Leaving isPrimeRecur"
    return isPrimeR
 */

bool IsPrimeRecur (int &arrayVal, int divisor){
    cout << "Entering isPrimeRecur" << endl;
    bool isPrimeR;
    divisor --;
    
    if (arrayVal == 1) {
        //BASE CASE: value is 1 who is not a prime number
        return isPrimeR = false;
    }
    
    if (arrayVal % divisor == 0) {
        //BASE CASE
        if (divisor == 1) {
            isPrimeR = true;
            cout << "Leaving isPrimeRecur" << endl;
            return isPrimeR;
        } if (divisor != 1) {
            isPrimeR = false;
            cout << "Leaving isPrimeRecur" << endl;
            return isPrimeR;
        }
    }

    if (arrayVal % divisor != 0) {
        isPrimeR = IsPrimeRecur(arrayVal, divisor);
        cout << "Leaving isPrimeRecur" << endl;
        return isPrimeR;
    }
    
    cout << "Leaving isPrimeRecur" << endl;
    return isPrimeR;
}
