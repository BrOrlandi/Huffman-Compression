Huffman Compression Algorithm
==============================

This compression works better in text files without any compression, Bitmap images(BMP).

Usage: 
```shell
<input file> [optional -d] <output file>
```
 -d  The input file will be decompressed to output file

Example:
```shell
Huffman.exe "sample.txt" "sample.txt.hff"

Huffman.exe "sample.txt.hff" -d "decompressed sample.txt"
```

Developed using Code Blocks 13.12 on Windows