(define factorial(lambda(n)
         (if(zero? n)
            1
            (if(= n 1)
               1
               (* n (factorial(- n 1)))))))


(define fibonnacci(lambda(n)
                    (if(<= n 0)
                       0
                       (if(= n 1)
                          1
                          (+ (fibonnacci (- n 1)) (fibonnacci(- n 2)))))))

(fibonnacci -1)