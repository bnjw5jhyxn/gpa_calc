# gpa\_calc

Usage:
```
./gpa <file1> <file2> ...
```
where `file1`, `file2`, etc. are text files.

The file format consists of lines of the form
```
<C> <G>...\n
```
where `C` is a number of credits and `G` is a letter grade.

The rest of each line is ignored and any line failing to conform to this
specification is treated as a comment.
