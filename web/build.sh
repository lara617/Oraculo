#!/bin/bash
set -e

echo "Building static site..."
mkdir -p dist
cp -r web/* dist/

echo "Build completed successfully!"
