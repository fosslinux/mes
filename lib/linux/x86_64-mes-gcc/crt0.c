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

// no clue what crt0.o is and why gcc-2.6.3 needs it

// instead of calling main, it seems to call either _main or ___main,
// let's try _main first

#include <mes/lib-mini.h>
int main (int argc, char *argv[]);

// gcc x86_64 calling convention:
// rdi, rsi, rdx, rcx, r8, r9, <stack0>, <stack1>

// *INDENT-OFF*
void
_start ()
{
  asm (
       "movq    %%rbp,%%rax\n\t"
       "add     $8,%%rax\n\t"
       "movq    (%%rax),%%rax\n\t"
       "add     $3,%%rax\n\t"
       "shl     $3,%%rax\n\t"
       "add     %%rbp,%%rax\n\t"
       "mov     %%rax,%0\n\t"
       : "=r" (environ)
       : //no inputs ""
       );
  asm (
       "mov     %rbp,%rax\n\t"
       "add     $16,%rax\n\t"
       "mov     %rax,%rsi\n\t"

       "mov     %rbp,%rax\n\t"
       "add     $8,%rax\n\t"
       "mov     (%rax),%rax\n\t"
       "mov     %rax,%rdi\n\t"
       "call    _main\n\t"

       "mov     %rax,%rdi\n\t"
       "mov     $0x3c,%rax\n\t"
       "syscall \n\t"
       "hlt     \n\t"
       );
}
