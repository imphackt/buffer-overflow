# Débordement de tampon — challenge imphackt

Quatre petits programmes en C, volontairement vulnérables. À vous de les
exploiter pour faire afficher un **drapeau** de la forme `imphackt{...}`, que
vous soumettez ensuite sur le site du challenge.

Tout se joue **dans le navigateur**, sans rien installer : ouvrez ce dépôt dans
un **GitHub Codespace** (environnement Linux prêt à l'emploi avec `gdb`).

## Démarrer

1. Bouton vert **`< > Code`** → onglet **Codespaces** → **Create codespace on
   main**.
2. Attendez que l'environnement se construise (~1 min la première fois), puis un
   terminal VS Code s'ouvre dans le navigateur.
3. Vous êtes prêt·e.

> L'environnement est du Linux Debian 12 **64 bits** avec le runtime **32 bits**
> (`libc6:i386`) et `gdb` déjà installés : les binaires 32 bits s'exécutent
> directement.

## Les niveaux

| # | Dossier | Binaire | Thème |
|---|---------|---------|-------|
| 1 | `niveau1-login`   | `login`   | mot de passe |
| 2 | `niveau2-session` | `session` | droits admin |
| 3 | `niveau3-appel`   | `appel`   | pointeur de fonction |
| 4 | `niveau4-secret`  | `secret`  | fonction cachée (ret2win) |

Chaque dossier contient le binaire **et son code source `.c`** : lisez-le, c'est
là que se trouve la faille (le drapeau y est masqué par `imphackt{...}`, mais le
binaire, lui, affiche le vrai).

## Utilisation

Lancer un binaire :

```sh
cd niveau1-login
./login
```

L'inspecter avec `gdb` (syntaxe Intel déjà configurée) :

```sh
gdb ./login
(gdb) break main
(gdb) run
(gdb) disassemble vuln     # ou main
```

Lister les symboles (utile pour les niveaux 3 et 4) :

```sh
nm ./appel | grep secret
```

Envoyer une charge construite en Python :

```sh
python3 -c 'import sys; sys.stdout.buffer.write(b"A"*40)' | ./secret
```

## Protections

Tous les binaires sont compilés en **32 bits**, **sans PIE**, **sans canari**,
**NX activé** (pile non exécutable). Les adresses sont donc fixes d'une
exécution à l'autre — pratique pour les niveaux 3 et 4.

## Soumettre le drapeau

Récupérez la chaîne `imphackt{...}` affichée par le binaire et collez-la sur la
page du challenge sur le site imphackt. Bonne chasse.
