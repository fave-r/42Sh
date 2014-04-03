/*
** get_char.c for get_char in /home/blackbird/work
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Fri Mar 14 14:30:48 2014 romaric
** Last update Fri Mar 14 15:41:29 2014 romaric
*/

char    get_char(int fd)
{
  static char	buff[4096];
  static int i;
  static int s;
  char  c;

  i = 0;
  s = 0;
  if (i == s)
    {
      s = read(fd, buff, 4096);
      i = 0;
    }

  if (s <= 0)
    return (-1);

  c = buff[i];
  i = i + 1;

  return (c);
}
