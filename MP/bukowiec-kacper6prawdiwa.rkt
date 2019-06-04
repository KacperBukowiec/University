#lang racket

;;do zadania użyłem informacji z wykładu 

(define (const? t)
  (number? t))

(define (binop? t)
  (and (list? t)
       (= (length t) 3)
       (member (car t) '(+ - * /))))

(define (binop-op e)
  (car e))

(define (binop-left e)
  (cadr e))

(define (binop-right e)
  (caddr e))

(define (binop-cons op l r)
  (list op l r))

(define (op->proc op)
  (cond [(eq? op '+) +]
        [(eq? op '*) *]
        [(eq? op '-) -]
        [(eq? op '/) /]))

(define (let-def? t)
  (and (list? t)
       (= (length t) 2)
       (symbol? (car t))))

(define (let-def-var e)
  (car e))

(define (let-def-expr e)
  (cadr e))

(define (let-def-cons x e)
  (list x e))

(define (let? t)
  (and (list? t)
       (= (length t) 3)
       (eq? (car t) 'let)
       (let-def? (cadr t))))

(define (let-def e)
  (cadr e))

(define (let-expr e)
  (caddr e))

(define (let-cons def e)
  (list 'let def e))

(define (var? t)
  (symbol? t))

(define (var-var e)
  e)

(define (var-cons x)
  x)

(define (hole? t)
  (eq? t 'hole))

(define (arith/let/holes? t)
  (or (hole? t)
      (const? t)
      (and (binop? t)
           (arith/let/holes? (binop-left  t))
           (arith/let/holes? (binop-right t)))
      (and (let? t)
           (arith/let/holes? (let-expr t))
           (arith/let/holes? (let-def-expr (let-def t))))
      (var? t)))

(define (num-of-holes t)
  (cond [(hole? t) 1]
        [(const? t) 0]
        [(binop? t)
         (+ (num-of-holes (binop-left  t))
            (num-of-holes (binop-right t)))]
        [(let? t)
         (+ (num-of-holes (let-expr t))
            (num-of-holes (let-def-expr (let-def t))))]
        [(var? t) 0]))

(define (arith/let/hole-expr? t)
  (and (arith/let/holes? t)
       (= (num-of-holes t) 1)))




(define (hole-context e)
  
  (define (loop e lis)
    (if (let? e)
        (if (hole? (let-def-expr (let-def e)))
            lis
            (loop (let-expr e) (append lis (list (let-def-var (let-def e))))))
        (if (binop? e)
            (if (or (hole? (binop-left e)) (hole? (binop-left e)))
                lis
                (if (= (num-of-holes (binop-left e)) 1)
                    (loop (binop-left e) lis)
                    (loop (binop-right e) lis)
                    ))
            lis)
        ))
    (remove-duplicates (loop e '())))
                
        
            
;; funkja ta nie zadziała dla każdego porgramu, ponieważ wynik
;;   '(piesek kotek chomik profesor) w zależności od programu może się różnić
(define (test)
  (and (equal?  (hole-context '(let (x 4) (let (y 5) (let (z hole) 3)))) '(x y))
       (equal?  (hole-context '(let (x 4) (+ (let (y 5) 2) (let (z 6) (let (t 5) hole))))) '(x z t))
       (equal?  (hole-context '(+ 3 (+ 42 hole))) '())
       (equal?  (hole-context '(let (piesek  1)(let (kotek  7)(let( piesek  9)(let (chomik  5) (let (profesor 2) hole)))))) '(piesek kotek chomik profesor))
       (equal?  (hole-context '(+ (let (x 3) 5) hole)) '()) ))
(test)