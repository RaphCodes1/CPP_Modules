#include "iter.hpp"

// char toUpper(char a){
//     return (a + 32);
// }
int main(){
    char charArr[] = {'a','b','c','d','e'};
    int intArr[] = {1,2,3,4,5};
    int length = 5;
    ::iter(charArr, length, &toPrint);
    ::iter(intArr, length, &toPrint);
}