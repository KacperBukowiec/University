#lang racket
;Korzystałem z kodu prezentowanego na wykładzie
(define (cond-iter-up num den base)
    (define (next-a i) (+ (* (den i) a-0) (* (num i) a-1)))
    (define (next-b i) (+ (* (den i) b-0) (* (num i) b-1)))
    (define (next-f i) (/ (next-a i) (next-b i)))
    (if (< (abs(- (next-f k) last-f)) 0.00001)
        (+ last-f base)
        (approx a-0 (next-a k) b-0 (next-b k) (next-f k) (+ k 1))))
  (approx 1.0 0 0 1.0 0 1)
  )

;Sprawdzenie arxtgx jest opcjonalne (według listy zadań) , więc sprawdzam pi i złoty podział
(cond-iter-up (lambda (i) (* (- (* i 2) 1) (- (* i 2) 1))) (lambda (i) 6) 3.0)
(cond-iter-up (lambda (i) 1.0) (lambda (i) 1.0) 0)
