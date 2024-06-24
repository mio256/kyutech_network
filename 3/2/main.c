#include <stdio.h>
#include <stdlib.h>

struct student
{
    char id[10]; // 学籍番号
    int score;   // 評点
};

int main()
{
    struct student seito[10]; // 学生情報格納配列
    FILE *inputFile, *outputFile;
    int i = 0, totalStudents = 0;
    double averageScore = 0.0;

    inputFile = fopen("input2.dat", "r");
    if (inputFile == NULL)
    {
        fprintf(stderr, "Error: Unable to open input2.dat\n");
        return 1;
    }

    while (fscanf(inputFile, "%s %d", seito[totalStudents].id, &seito[totalStudents].score) != EOF)
    {
        totalStudents++;
    }
    fclose(inputFile);

    for (i = 0; i < totalStudents; i++)
    {
        averageScore += seito[i].score;
    }
    if (totalStudents > 0)
    {
        averageScore /= totalStudents;
    }

    outputFile = fopen("output.dat", "w");
    if (outputFile == NULL)
    {
        fprintf(stderr, "Error: Unable to open output.dat\n");
        return 1;
    }

    fprintf(outputFile, "Total Students: %d\n", totalStudents);
    fprintf(outputFile, "Average Score: %.2f\n", averageScore);
    fclose(outputFile);

    return 0;
}
