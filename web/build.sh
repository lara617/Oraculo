#!/bin/bash
set -e

echo "Building static site..."

# Criar diretório de build
mkdir -p dist

# Copiar arquivos específicos do diretório web
files_to_copy=("index.html" "style.css" "script.js")
for file in "${files_to_copy[@]}"; do
    if [ -f "web/$file" ]; then
        echo "Copying file: $file"
        cp "web/$file" dist/
    fi
done

# Verificar se o diretório de build não está vazio
if [ -z "$(ls -A dist)" ]; then
    echo "Error: Output directory 'dist' is empty!"
    exit 1
fi

echo "Build completed successfully!"
echo "Files in dist directory:"
ls -R dist/
