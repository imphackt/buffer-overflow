#include <stdio.h>
#include <stdlib.h>

void win(void) { puts("imphackt{...}"); exit(0); }

static void lire(char *s) { int c; while ((c = getchar()) != EOF && c != '\n') *s++ = (char)c; *s = 0; }

void vuln(void) {
    char buf[64];
    printf("Votre nom : "); fflush(stdout);
    lire(buf);
}

int main(void) {
    vuln();
    printf("Bonjour.\n");
    return 0;
}
