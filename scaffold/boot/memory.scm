;;; GNU Mes --- Maxwell Equations of Software
;;; Copyright © 2018 Jan (janneke) Nieuwenhuizen <janneke@gnu.org>
;;;
;;; This file is part of GNU Mes.
;;;
;;; GNU Mes is free software; you can redistribute it and/or modify it
;;; under the terms of the GNU General Public License as published by
;;; the Free Software Foundation; either version 3 of the License, or (at
;;; your option) any later version.
;;;
;;; GNU Mes is distributed in the hope that it will be useful, but
;;; WITHOUT ANY WARRANTY; without even the implied warranty of
;;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;;; GNU General Public License for more details.
;;;
;;; You should have received a copy of the GNU General Public License
;;; along with GNU Mes.  If not, see <http://www.gnu.org/licenses/>.

;; ,expand (let loop ((i 10)) (if (eq? i 0) 0 (begin (core:display-error i) (core:display-error "\n") (loop (- i 1)))))
;; (let loop ((i 10)) (if (eq? i 0) 0 (begin (display i) (display "\n") (loop (- i 1)))))

((lambda (loop)
   (set! loop
         (lambda (i)
           (if (eq? i 0) 0
               (begin
                 (core:display i)
                 (core:display "\n")
                 (loop (- i 1))))))
   (loop 10))
 *unspecified*)

;; ((lambda (loop)
;;    (set! loop
;;          (lambda (i)
;;            (if (eq? i 0) 0
;;                (begin (display i)
;;                       (display "\n")
;;                       (loop (- i 1))))))
;;    (loop 10))
;;  *unspecified*)
