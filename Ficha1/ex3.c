#include <stdio.h>



int linha (int n) {
    int i,count;
    i=0; count = 0;
    while (i<n) {
        putchar('#');
        count++;
        i+=1;
    }
return count;
}

int main (int n){
    int i,count;
    i=0; count = 0;
    while (i<n) {
        count+=linha(n);
        linha(n);
        i++;
        putchar('\n');
    }   
}