# Environnement du challenge « Débordement de tampon » : Debian 12 amd64
# avec le runtime 32 bits (i386) pour exécuter les binaires, et gdb.
FROM mcr.microsoft.com/devcontainers/base:bookworm

RUN dpkg --add-architecture i386 \
 && apt-get update \
 && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
      libc6:i386 gdb gcc-multilib binutils file \
      python3 python3-pip xxd \
 && rm -rf /var/lib/apt/lists/*

# gdb : pas de téléchargement de symboles, syntaxe Intel, pas de pagination.
RUN printf 'set debuginfod enabled off\nset disassembly-flavor intel\nset pagination off\nset confirm off\n' \
      > /etc/gdb/gdbinit.d/challenge.gdb
