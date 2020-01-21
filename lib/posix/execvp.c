/* -*-comment-start: "//";comment-end:""-*-
 * GNU Mes --- Maxwell Equations of Software
 * Copyright © 2017,2018 Jan (janneke) Nieuwenhuizen <janneke@gnu.org>
 *
 * This file is part of GNU Mes.
 *
 * GNU Mes is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or (at
 * your option) any later version.
 *
 * GNU Mes is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Mes.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <mes/lib.h>
#include <errno.h>
#include <unistd.h>

int
execvp (char const *file_name, char *const argv[])
{
  if (file_name[0] != '/')
    file_name = search_path (file_name);
  if (!file_name)
    {
      errno = ENOENT;
      return -1;
    }
  if (__mes_debug ())
    {
      eputs (" EXEC: ");
      eputs (file_name);
      eputs ("\n");
      int i = 0;
      while (argv[i])
        {
          eputs (" arg[");
          eputs (itoa (i));
          eputs ("]: ");
          eputs (argv[i]);
          eputs ("\n");
          i++;
        }
    }
  return execve (file_name, argv, environ);
}
