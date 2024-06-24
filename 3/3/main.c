#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

struct student
{
    char id[10]; // 学籍番号
    int score;   // 評点
};

int main()
{
    struct student seito[10]; // 学生情報格納配列
    int inputFd, outputFd;
    ssize_t bytesRead;
    char buffer[13]; // Buffer of 13 characters
    int totalStudents = 0;
    double averageScore = 0.0;
    int i;

    inputFd = open("input2.dat", O_RDONLY);
    if (inputFd == -1)
    {
        perror("Error opening input2.dat");
        return 1;
    }

    outputFd = open("output2.dat", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (outputFd == -1)
    {
        perror("Error opening output2.dat");
        close(inputFd);
        return 1;
    }

    while ((bytesRead = read(inputFd, buffer, sizeof(buffer) - 1)) > 0)
    {
        buffer[bytesRead] = '\0'; // Null-terminate the buffer
        char id[10];
        int score;
        int numScanned = sscanf(buffer, "%s %d", id, &score);

        if (numScanned == 2)
        {
            strcpy(seito[totalStudents].id, id);
            seito[totalStudents].score = score;
            totalStudents++;
        }

        memset(buffer, 0, sizeof(buffer)); // Initialize the buffer
    }

    for (i = 0; i < totalStudents; i++)
    {
        averageScore += seito[i].score;
    }
    if (totalStudents > 0)
    {
        averageScore /= totalStudents;
    }

    char outputBuffer[256];
    int outputLength = snprintf(outputBuffer, sizeof(outputBuffer), "Total Students: %d\nAverage Score: %.2f\n", totalStudents, averageScore);

    if (write(outputFd, outputBuffer, outputLength) == -1)
    {
        perror("Error writing to output2.dat");
        close(inputFd);
        close(outputFd);
        return 1;
    }

    close(inputFd);
    close(outputFd);

    return 0;
}
