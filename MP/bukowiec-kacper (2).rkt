#lang racket

;; expressions

(define (const? t)
  (number? t))

(define (op? t)
  (and (list? t)
       (member (car t) '(+ - * /))))

(define (op-op e)
  (car e))

(define (op-args e)
  (cdr e))

(define (op-cons op args)
  (cons op args))

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

(define (arith/let-expr? t)
  (or (const? t)
      (and (op? t)
           (andmap arith/let-expr? (op-args t)))
      (and (let? t)
           (arith/let-expr? (let-expr t))
           (arith/let-expr? (let-def-expr (let-def t))))
      (var? t)))

;; let-lifted expressions

(define (arith-expr? t)
  (or (const? t)
      (and (op? t)
           (andmap arith-expr? (op-args t)))
      (var? t)))

(define (let-lifted-expr? t)
  (or (and (let? t)
           (let-lifted-expr? (let-expr t))
           (arith-expr? (let-def-expr (let-def t))))
      (arith-expr? t)))

;; generating a symbol using a counter


(define (number->symbol i)
  (string->symbol (string-append "x" (number->string i))))



;; environments (could be useful for something)

(define empty-env
  null)

(define (add-to-env x v env)
  (cons (list x v) env))

(define (find-in-env x env)
  (cond [(null? env) (error "undefined variable" x)]
        [(eq? x (caar env)) (cadar env)]
        [else (find-in-env x (cdr env))]))

;; the let-lift procedure

(define (count-h)
  (let ([n 0])
    (lambda ()
      (set! n (+ n 1))
      n)))
(define next-var (count-h))

(define (rename re-var number t) 
  (define (renam re-var number t)
    (if (let? t)
        (list (append '(let) (renam re-var number (cadr t)) (renam re-var number (caddr t))))
        (if (op? t)
            (list (append (list (car t)) (renam re-var number (cadr t)) (renam re-var number (caddr t))))
            (if (let-def? t)
                (list (append (renam re-var number (car t)) (renam re-var number (cadr t))))
                (if (const? t)
                    (list t)
                    (if (and (symbol? t) (eq? t re-var))
                        (list (number->symbol number))
                        (list t)
                        )
                    )
                )
            )
        )
    )
    (car (renam re-var number t)))              
                  



(define (let-lift r)
  

  (define (let-lift2 e)
    ;;(define e (car ee))
    (if (let? e)
        (let* ([new (rename (let-def-var (let-def e)) (next-var) e)]
               [a-def-expr (let-lift2 (let-def (let-def-expr new)))]
               [a-expr (let-lift2 (let-expr new))])
          (list (append (car a-def-expr) (list (car(cadr new)) (cadr a-def-expr))) (cadr a-expr)))
        (if (op? e)
            (let*
                ([a1 (let-lift2 (cadr e))]
                 [a2 (let-lift2 (caddr e))])
              (list (append (car a1) (car a2)) (append (list (car e)) (list (cadr a1)) (list (cadr a2))) ) )
            (if (or (number? e) (symbol? e))
                (list '() e)
                (write e)
                )
            )
        )
    )
  (define (loop lety wyr)
    (if (eq? lety null)
        wyr
        (list 'let (list (car lety) (cadr lety) ) (loop (cddr lety) wyr))))
  
  (let* ([hell (let-lift2 r)]
         [lets (car hell)]
         [expa (cadr hell)])
    (loop lets expa))
  )

        
    
 ;;W robienu zadania nie użtwałem zewnętrznych materiałów, oprócz funkcji next-var

(let-lift '(let (x (+ 1 (let (z 2) z))) (+ x 2)))
(let-lift '(+ 10 (* (let (x 7) (+ x 2)) 2)))
(let-lift '(+ (let (x 5) x) (let (x 1) x)))

























