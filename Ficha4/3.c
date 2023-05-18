#include <stdio.h>

#define BUFFER 1000

int eVogal (char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int duplicaVogais (char *s) {
    char s_aux[BUFFER];
    int k = 0;
    int vogaisAcresc = 0;

    for (int i = 0; i != '\0'; i++) {
        s_aux[k] = s[i];
        k++;
        if (eVogal(s[i])) {
            s_aux[k] = s[i];
            k++;
            vogaisAcresc++;
        }
    }
    s_aux[k] = '\0';
    for (int j = 0; s_aux[j] != '\0'; j++) {
        s[j] = s_aux[j];
    }
    return vogaisAcresc;
}

int main () {
    char s[] = "Ola mundo";
    int vogais = duplicaVogais(s);
    printf("String: %s\n", s);
    printf("Foram acrescentadas %d vogais\n", vogais);
    return 0;
}