/*
** my_pipe.c for 42Sh in /home/blackbird/work/42Sh/eval
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May  6 17:56:59 2014 romaric
** Last update Tue May  6 18:15:08 2014 romaric
*/

int	my_pipe(char **cmd, int fd)
{
  int	pipefd[2];
  int	pid;

  if (pipe(pipefd) == -1)
    return (-1);
  if ((pid = fork()) == 0)
    {
      close(pipefd[1]);
      dup2(pipefd[0], 0);
      dup2(fd, 1);
      my_exec(cmd);
    }
  else
    {
      close(pipefd[0]);
      close(fd);
    }
  return (0);
}
