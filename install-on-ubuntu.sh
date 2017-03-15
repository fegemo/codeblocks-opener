#!/bin/bash

# Este script faz 2 coisas:
# 1. Copia o codeblocks-opener.desktop para a pasta do usuário que armazena os
#    atalhos, modificando ele para que ele saiba onde encontrar o executável
#    do codeblocks-opener
# 2. Modifica o arquivo mimeapps.list, que contém os registros de URI schemes
#    do usuário
#
CWD=$pwd
CODEBLOCKS_OPENER_DIR="$(dirname "$CWD")"
CODEBLOCKS_OPENER_DIR="$(realpath "$CODEBLOCKS_OPENER_DIR")"
DESKTOP_ENTRY_NAME=codeblocks-opener.desktop
DESKTOP_ENTRY_PATH=scripts/$DESKTOP_ENTRY_NAME
DESKTOP_ENTRY_OUTPUT_PATH=~/.local/share/applications/$DESKTOP_ENTRY_NAME

# copia o arquivo codeblocks-opener.desktop para o destino
cp $DESKTOP_ENTRY_PATH $DESKTOP_ENTRY_OUTPUT_PATH > $DESKTOP_ENTRY_OUTPUT_PATH
chmod +x $DESKTOP_ENTRY_OUTPUT_PATH

# modifica o arquivo codeblocks-opener.desktop para conter o caminho do executável
sed -i -e "s:CODEBLOCKS_OPENER_PATH:$CODEBLOCKS_OPENER_DIR\/bin\/Linux\/:" $DESKTOP_ENTRY_OUTPUT_PATH
sed -i -e "s:CODEBLOCKS_OPENER_BIN:codeblocks-opener:" $DESKTOP_ENTRY_OUTPUT_PATH
echo "Atalho codeblocks-opener instalado em $DESKTOP_ENTRY_OUTPUT_PATH"

MIMEAPPS_PATH=~/.local/share/applications/mimeapps.list

# modifica o arquivo mimeapps.list para registrar o URI scheme "codeblocks:"
if grep -q "codeblocks-opener.desktop" "$MIMEAPPS_PATH"; then
  echo "codebocks-opener.desktop ja estava presente"
else
  if ! grep -q "\[Added Associations\]" "$MIMEAPPS_PATH"; then
    echo "" >> $MIMEAPPS_PATH
    echo "[Added Associations]" >> $MIMEAPPS_PATH
  fi
  echo "x-scheme-handler/codeblocks=codeblocks-opener.desktop" >> $MIMEAPPS_PATH
fi
echo "URI scheme registrado em $MIMEAPPS_PATH"
