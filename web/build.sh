#!/bin/bash
set -e

echo "Building static site..."

# Criar diretório de build
mkdir -p dist

# Copiar arquivos
for file in web/*; do
    if [ -f "$file" ]; then
        cp "$file" dist/
    fi
done

# Copiar diretórios
for dir in web/*/; do
    if [ -d "$dir" ]; then
        cp -r "$dir" dist/
    fi
done

echo "Build completed successfully!"
