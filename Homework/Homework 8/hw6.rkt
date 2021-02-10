;Part A

(- (+ 3 5) 7) ; (1)

(- (* 2 (+ 8 5 4)) 25); (2)

(- 10 (+ (* 3 5 ) (+ 2 (* 0 5)))); (3)

(* 5(+ 4 (/ (+ (+ 10 10) (* 5 8)) (+ 10 2)))); (4)

(+ (/(-(/ (/ (*(+ 3 5)(+ 6 4)) 2) 2) 5) 3) (+(/ (+(* 2 10)(* 5 4)) 2) (* 4 5))) ;(5)

(newline)

;Part B

(define two 2)
(define three 3)
(define four 4)
(define five 5)
(define six 6)
(define ten 10)

(+ (/(-(/ (/ (*(+ three five)(+ six four)) two) two) five) three) (+(/ (+(* two ten)(* five four)) two) (* four five)))

(newline)

;Part C
(define subtract(lambda(x y)
                  (- x y);end definition
                  );end lambda
  );end define

(subtract 120 50)

(newline)

;Part D
(define IntDivide(lambda(x y)
                   (if(= y 0)
                      0;return 0
                    (if(< x y)
                       0
                       (+ 1 (IntDivide(- x y) y))
                       )
)                       )
                      )
  

(IntDivide 10 5)
(newline)

;part E
(define ReadForInt(lambda()
                    (define x (read));define x and read input
                    (define y (read)); define y and read input 
                    (IntDivide x y); return the value of Intdivide with x and y as parameters
                    ); end lambda
 
  );end define

(ReadForInt)

(newLine)

;Part F
(define Multiply(lambda(x y)
  (if(or(zero? x  )(zero? y))        ;if x or y are zero return 0 base case
     0                               ;return 0
     (if(> y 0)                      ;if y > 0 
      (+ x (Multiply x (- y 1)))     ;multiply recursively using addition with x and y-1
      (+ (- x) (Multiply x (+ y 1))) ;else take add the negative x and  y+1
        )                            ;end inner if
     )                               ;end outer if
                  )                  ;end function
  );end define

(Multiply -9 -9)

(newline)

;Part G

(define DiffDivide(lambda( x y)
                    (Subtract x (Multiply y (IntDivide x y))); (x-(x/y)*y)
                      ); end lambda
  ); end define


(DiffDivide 8 3)

(newline)

;Part H
(define explode(lambda (str)
                 (if(eq?(string-length str) 0); if the string is empty return an empty list
                    '()
                    (cons(substring str 0 1);else construct a pair with the first character of the string and add to list
                    (explode(substring str 1(string-length str)));call the explode function again with the substring of 1 and the rest of the string
                    );end con
                    );end if
                 );end lambda
  ); end define
(explode "hello")
(newline)

;part I
(define implode(lambda(list)(if(null? list)
                               ""    ;if list is empty retutn closed parenthesis
                               (string-append(car list); else take the car of the list and append it to the string
                               (implode(cdr list) );call the implode function again with the cdr of the list 
                               ); end string append
                               ); end if
                 ); end lambda
  ); end define


(implode '("h" "e" "l" "l" "o"))