# gpa\_calc

This GPA calculator conforms (as far as I can tell) to the GPA system at
Rutgers University, where each student receives a letter grade for each course
taken and each letter grade corresponds to some number of grade points.
The grade point average is an average of the grade points from each course,
weighted by the number of credits that course carries.
Grades of P (pass) and F (fail) to not contribute to a student's GPA.

| letter grade | grade points |
| --- | --- |
| A | 4.0 |
| B+ | 3.5 |
| B | 3.0 |
| C+ | 2.5 |
| C | 2.0 |
| D | 1.0 |
| P | N/A |
| F | N/A |

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
