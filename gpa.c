#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void compute_gpa(const char *filename);
float l2p(const char *letter_grade);

int main(int argc, char **argv)
{
	int i;
	for (i = 1; i < argc; i++) {
		compute_gpa(argv[i]);
	}
	return 0;
}

void compute_gpa(const char *filename)
{
	FILE *file;
	float credits, grade_points, total_credits, total_points;
	char letter_grade[4];
	char *l;
	size_t n;
	if (strcmp(filename, "-") == 0) {
		file = stdin;
	} else if ((file = fopen(filename, "r")) == NULL) {
		fprintf(stderr, "could not open file \"%s\" for reading\n",
				filename);
		return;
	}
	total_credits = 0.0f;
	total_points = 0.0f;
	l = NULL;
	n = 0lu;
	while (feof(file) == 0) {
		if (fscanf(file, "%f %3[ABCD+]", &credits, letter_grade) == 2
				&& (grade_points = l2p(letter_grade))) {
			total_credits += credits;
			total_points += credits * grade_points;
		}
		getline(&l, &n, file);
	}
	fprintf(stdout, "%s: credits %f, points %f, average %f\n",
			filename, total_credits, total_points,
			total_points / total_credits);
	fclose(file);
	free(l);
}

float l2p(const char *letter_grade)
{
	float points;
	if (strcmp(letter_grade, "A") == 0)
		points = 4.0f;
	else if (strcmp(letter_grade, "B+") == 0)
		points = 3.5f;
	else if (strcmp(letter_grade, "B") == 0)
		points = 3.0f;
	else if (strcmp(letter_grade, "C+") == 0)
		points = 2.5f;
	else if (strcmp(letter_grade, "C") == 0)
		points = 2.0f;
	else if (strcmp(letter_grade, "D") == 0)
		points = 1.0f;
	else
		points = 0.0f;
	return points;
}
