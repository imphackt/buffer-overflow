#include <stdio.h>

void saluer(void) { puts("Bonjour."); }
void secret(void) { puts("imphackt{...}"); }

static void lire(char *s) { int c; while ((c = getchar()) != EOF && c != '\n') *s++ = (char)c; *s = 0; }

int main(void) {
    struct { char nom[32]; void (*action)(void); } s;
    s.action = saluer;

    printf("Votre nom : "); fflush(stdout);
    lire(s.nom);

    s.action();
    return 0;
}
