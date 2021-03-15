#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char **argv)
{
  int pipefd1[2], pipefd2[2];
  int pid;

  char *wc_args[] = {"wc", NULL};
  char *grep_args[] = {"grep", "--binary-files=text", "-i", "hai",  NULL};

  pipe(pipefd1);
  pipe(pipefd2);

  pid = fork();

  if (pid < 0)
    perror("Fork failed!");
  else if (pid > 0)
  {
    char c;
    close(pipefd1[0]);
    close(pipefd2[1]);

    dup2(pipefd2[0], 0);
    close(pipefd2[0]);

    FILE *fptr = fopen("/mnt/e/Labmain1/\"Sem 4\"/os/file.txt", "r");
    while ((c = fgetc(fptr)) != EOF)
      write(pipefd1[1], &c, 1);
    close(pipefd1[1]);
    
    wait(NULL);  

    execvp(*wc_args, wc_args);
  }
  else
  {
    close(pipefd1[1]);
    close(pipefd2[0]);

    dup2(pipefd1[0], 0);
    dup2(pipefd2[1], 1);

    close(pipefd1[0]);
    close(pipefd2[1]);

    execvp(*grep_args, grep_args);
  }
}
