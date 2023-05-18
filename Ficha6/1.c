#define Max 1000

struct staticStack {
    int sp;
    int values [Max];
};

typedef struct staticStack * SStack;

void SinitStack (SStack s) {
    s->sp = 0;
}

int SisEmpty (SStack s) {
    if (s->sp == 0) {
        return 1;
    }
}

int Spush (SStack s, int x) {
    if (s->sp < Max) {
        s->values[s->sp] = x;
        s->sp++;
        return 0;
    }
    else {
        return 1;
    }
}

int Spop (SStack s, int *x) {
    if (s->sp > 0) {
        *x = s->values[s->sp-1];
        s->sp--;
        return 0;
    } else {
        return 1;
    }
}

int Stop (SStack s, int *x) {
    if (s->sp > 0) {
        *x = s->values[s->sp];
        return 0;
    } 
    else {return 1;}
}