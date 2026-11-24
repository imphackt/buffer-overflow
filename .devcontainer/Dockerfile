# Environnement du challenge « Débordement de tampon » : Debian 12 amd64
# avec le runtime 32 bits (i386) pour exécuter les binaires, et gdb.
FROM mcr.microsoft.com/devcontainers/base:bookworm

RUN dpkg --add-architecture i386 \
 && apt-get update \
 && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
      libc6:i386 gdb gcc-multilib binutils file \
      python3 python3-pip xxd \
 && rm -rf /var/lib/apt/lists/*

# nm, objdump, readelf… viennent de binutils (ci-dessus) ; gcc-multilib en dépend aussi.
# gdb : pas de téléchargement de symboles, syntaxe Intel, pas de pagination.
# mkdir -p : le dossier gdbinit.d n'existe pas toujours — sans lui, la build échouait
# et le Codespace démarrait en mode secours (sans gdb ni nm).
RUN mkdir -p /etc/gdb/gdbinit.d \
 && printf 'set debuginfod enabled off\nset disassembly-flavor intel\nset pagination off\nset confirm off\n' \
      > /etc/gdb/gdbinit.d/challenge.gdb \
 && command -v nm && command -v gdb && command -v gcc
