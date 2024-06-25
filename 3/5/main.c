#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    int fd[2];
    pid_t pid;
    if (pipe(fd) == -1)
        perror("pipe"), exit(EXIT_FAILURE);
    pid = fork();
    if (pid == -1)
        perror("fork"), exit(EXIT_FAILURE);
    else if (pid == 0)
    {
        // 子プロセス: ls -l の実行とパイプ出力
        close(fd[0]);                   // パイプの読み取り側を閉じる
        dup2(fd[1], STDOUT_FILENO);     // 標準出力をパイプの書き込み側にリダイレクト
        close(fd[1]);                   // 不要なファイル記述子を閉じる
        execlp("ls", "ls", "-l", NULL); // ls -l コマンドの実行
        perror("execlp");
        exit(EXIT_FAILURE);
    }
    else
    {
        // 親プロセス: grep コマンドの実行
        close(fd[1]);                       // パイプの書き込み側を閉じる
        dup2(fd[0], STDIN_FILENO);          // 標準入力をパイプの読み取り側にリダイレクト
        close(fd[0]);                       // 不要なファイル記述子を閉じる
        execlp("grep", "grep", ".c", NULL); // grep コマンドの実行
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    return 0;
}
