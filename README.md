# CodeBlocks Opener

This tiny program can be used to allow opening URIs in the form of `codeblocks:path_to_codeblocks_project.cbp` in CodeBlocks.

# Usage

Follow these simple steps:

1. Edit `main.cpp` to match the local paths of your codeblocks installation and the examples folder
1. Compile it and get the absolute path to the `codeblocks-opener.exe`
1. Edit `registrar-uri-scheme.reg` and provide the correct path to the executable
1. Execute `registrar-uri-scheme.reg`
