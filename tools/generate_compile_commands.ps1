param(
    [string]$Root = ".",
    [string]$Compiler = "g++",
    [string]$Std = "gnu++20"
)

$rootPath = (Resolve-Path -LiteralPath $Root).Path
$cppFiles = Get-ChildItem -LiteralPath $rootPath -Recurse -File -Filter "*.cpp" |
    Where-Object {
        $_.FullName -notlike "*\.git\*" -and
        $_.FullName -notlike "*\.vscode\*" -and
        $_.FullName -notlike "*\.cursor\*"
    }

$entries = foreach ($file in $cppFiles) {
    [ordered]@{
        directory = $file.DirectoryName
        file = $file.FullName
        command = "$Compiler -std=$Std -Wall -Wextra -Wshadow -Wconversion -fsyntax-only `"$($file.FullName)`""
    }
}

$target = Join-Path $rootPath "compile_commands.json"
$entries | ConvertTo-Json -Depth 3 | Set-Content -LiteralPath $target -Encoding utf8

Write-Output "Generated $($entries.Count) entries at $target"
