#include <stdio.h>

void print_flag(void) { puts("imphackt{...}"); }

static void lire(char *s) { int c; while ((c = getchar()) != EOF && c != '\n') *s++ = (char)c; *s = 0; }

int main(void) {
    struct { char nom[8]; int niveau; } s;
    s.niveau = 1;

    printf("Identifiant : "); fflush(stdout);
    lire(s.nom);

    printf("Niveau : 0x%08x\n", s.niveau);
    if (s.niveau == (int)0x746f6f72) { puts("Bienvenue, administrateur."); print_flag(); }
    else puts("Acces refuse.");
    return 0;
}
