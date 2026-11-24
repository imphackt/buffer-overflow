#include <stdio.h>
#include <string.h>

void print_flag(void) { puts("imphackt{...}"); }

static void lire(char *s) { int c; while ((c = getchar()) != EOF && c != '\n') *s++ = (char)c; *s = 0; }

static void charge_mdp(char *b) {
    FILE *f = fopen("/dev/urandom", "rb");
    if (f) { if (fread(b, 1, 16, f) != 16) {} fclose(f); }
    for (int i = 0; i < 16; i++) b[i] = (char)(33 + ((unsigned char)b[i]) % 94);
}

int main(void) {
    struct { char saisie[16]; char vrai[16]; } s;
    charge_mdp(s.vrai);

    printf("Mot de passe : "); fflush(stdout);
    lire(s.saisie);

    if (memcmp(s.saisie, s.vrai, 16) == 0) { puts("Acces autorise."); print_flag(); }
    else puts("Mot de passe refuse.");
    return 0;
}
