/* -*-comment-start: "//";comment-end:""-*-
 * GNU Mes --- Maxwell Equations of Software
 * Copyright © 2018 Jan (janneke) Nieuwenhuizen <janneke@gnu.org>
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

struct scm
{
  int type;
  int car;
  int cdr;
};


char g_arena[24];
struct scm *g_cells = (struct scm *) g_arena;

int
main ()
{
  g_cells[0].type = -1;
  g_cells[0].car = 0;
  g_cells[0].cdr = 0;
  g_cells[1].type = -1;
  g_cells[1].car = 0;
  g_cells[1].cdr = 0;

  oputs ("t: TYPE (0) != TYPE (1)\n");
  if (g_cells[0].type == g_cells[1].type)
    goto ok;
  return 1;
ok:

  return 0;
}
