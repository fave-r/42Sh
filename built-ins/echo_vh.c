/*
** echo_vh.c for 42sh in /home/leo/rendu/42Sh/built-ins
** 
** Made by bourrel
** Login   <leo@epitech.net>
** 
** Started on  Wed May 21 14:15:06 2014 bourrel
** Last update Wed May 21 14:58:55 2014 bourrel
*/

#include "my.h"

void    echo_help(int fd)
{
  my_putstr("Usage: /bin/echo [SHORT-OPTION]... [STRING]...\n  or:  /bin", fd);
  my_putstr("/echo LONG-OPTION\nEcho the STRING(s) to standard output.\n", fd);
  my_putstr("\n  -n             do not output the trailing newline\n  ", fd);
  my_putstr("-e             enable interpretation of backslash escapes\n", fd);
  my_putstr("  -E             disable interpretation of backslash escap", fd);
  my_putstr("es (default)\n      --help     display this help and exit\n", fd);
  my_putstr("      --version  output version information and exit\n\nIf ", fd);
  my_putstr("-e is in effect, the following sequences are recognized:\n", fd);
  my_putstr("\n  \\\\\tbackslash\n  \\a\talert (BEL)\n  \\b\tba", fd);
  my_putstr("ckspace\n  \\c\t", fd);
  my_putstr("produce no further output\n  \\e\tes", fd);
  my_putstr("cape\n  \\f\tform feed\n  \\n\tnew line\n  \\r\tc", fd);
  my_putstr("arriage return\n  \\t      horizontal tab\n  \\v\tvertic", fd);
  my_putstr("al tab\n  \0NNN   byte with octal value NNN (1 to 3 digits)", fd);
  my_putstr("\n  \\", fd);
  my_putstr("xHH    byte with hexadecimal value HH (1 to 2 digits)", fd);
  my_putstr("\n\nNOTE: your shell may have its own version of echo, whic", fd);
  my_putstr("h usually supersedes\nthe version described here.  Please r", fd);
  my_putstr("efer to your shell's documentation for details about the op", fd);
  my_putstr("tions it supports.\n\nReport echo bugs to bug-coreutils@gnu", fd);
  my_putstr(".org\nGNU coreutils home page: <http://www.gnu.org/software", fd);
  my_putstr("/coreutils/>\nGeneral help using GNU software: <http://www.", fd);
  my_putstr("gnu.org/gethelp/>\nFor complete documentation, run: info co", fd);
  my_putstr("reutils 'echo invocation'\n", fd);
}

void	echo_version(int fd)
{
  my_putstr("echo (GNU coreutils) 8.17\nCopyright (C) 2012 Free Software", fd);
  my_putstr("Foundation, Inc.\nLicense GPLv3+: GNU GPL version 3 or late", fd);
  my_putstr("r <http://gnu.org/licenses/gpl.html>.\nThis is free softwar", fd);
  my_putstr("e: you are free to change and redistribute it.\nThere is NO", fd);
  my_putstr(" WARRANTY, to the extent permitted by law.\n\n", fd);
  my_putstr("Written by Brian Fox and Chet Ramey.\n", fd);
}

void	echo_vh(char **tab, int fd)
{
  if (strcmp(tab[1], "--version") == 0 && !tab[1][10])
    echo_version(fd);
  else if (strcmp(tab[1], "--help") == 0 && !tab[1][7])
    echo_help(fd);
  else
    my_putchar('\n', fd);
}
