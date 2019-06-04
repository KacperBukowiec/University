#lang racket
;; Program bazuje na programie przedstawionym podczas pierwszego wykładu
;; Używany jest błąd względny zamiast bezwzględnego
                       
(define (cube x) (* x x x))

(define (cube-root x)
  ;;błąd względny ustawiony jest na  5%
  (define (good-enough? approx)
    (< (abs(/ (abs (- (expt approx 3) x)) x)) 0.05))
  (define (improve approx)
    (/ (+ (/ x (* approx approx)) (* 2 approx)) 3 ))
  (define (iter approx)
    (if (good-enough? approx) approx (iter (improve approx))))
  (if (= x 0 ) 0 (iter 1.0)
  )
  )

(cube-root 0)
(cube-root 111111111110)
(cube-root 125)
(cube 5.01)
(cube-root 2)
(cube-root -8)
(cube-root 1)
(cube-root 0.9)
(cube-root 0.1)
(cube-root -0.1)
(cube 0.464)