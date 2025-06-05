$files = @('.gitattributes', 'vercel.json', 'web/package.json', 'web/build.sh')

foreach ($file in $files) {
    $content = Get-Content $file -Raw
    $content | Set-Content -Path $file -Encoding UTF8
}
