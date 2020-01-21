# GNU Mes --- Maxwell Equations of Software
# Copyright © 2018 Jan (janneke) Nieuwenhuizen <janneke@gnu.org>
#
# This file is part of GNU Mes.
#
# GNU Mes is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or (at
# your option) any later version.
#
# GNU Mes is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GNU Mes.  If not, see <http://www.gnu.org/licenses/>.

LOG=
if [ -z "$V" -o "$V" = 0 ]; then
    trace () {
        echo "  $1"
        shift
        echo "$@" >> build.log
        eval "$@ $LOG"
        cat .log 1>&2
        cat .log >> build.log
    }
    LOG=" >.log 2>&1"
fi
if [ "$V" = 1 ]; then
    trace () {
        shift
        echo "$@"
        echo "$@" >> build.log
        eval "$@ $LOG"
        cat .log 1>&2
        cat .log >> build.log
    }
    LOG=" >.log 2>&1"
fi
if [ "$V" = 2 ]; then
    set -x
    trace () {
        shift
        echo "$@" >> build.log
        eval "$@"
    }
fi
