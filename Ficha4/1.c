#include <stdio.h>

int contaVogais(char *s) {
    int vogais = 0;
    for(int cursor = 0; s[cursor] != '\0'; cursor++) {
        if (s[cursor] == 'a' || 
            s[cursor] == 'e' || 
            s[cursor] == 'i' || 
            s[cursor] == 'o' || 
            s[cursor] == 'u' || 
            s[cursor] == 'A' || 
            s[cursor] == 'E' || 
            s[cursor] == 'I' || 
            s[cursor] == 'O' || 
            s[cursor] == 'U') {
            vogais++;
        }
    }
    return vogais;
}

int main () {
    char s[] ="Ola mundo!";
    int vogais = contaVogais(s);
    printf("%d vogais.\n", vogais);
}