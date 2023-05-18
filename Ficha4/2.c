#include <stdio.h>

#define BUFFER 1000

int eVogal (char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {return 0;}
           else 
           return 1;
}

int retiraVogaisRep (char *s) {
    char s_aux[BUFFER];
    int j = 0;
    for(int i = 0; s[i] != '\0'; i++) {
            if(!eVogal(s[i] || s[i+1] != s[i])) { //negação
                s_aux[j] = s[i];
                j++;
                }
    }
    s_aux[j] = '\0';
    for(int i = 0; s_aux[i] != '\0';i++) {
        s[i] = s_aux[i];
    }

}

int main () {

    char s[] = "olaaaaaa mundooooo";
    retiraVogaisRep(s);
    printf("String: %s\n", s);
    return 0; 
}