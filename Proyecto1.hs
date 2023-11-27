-- 1) Programa las siguientes funciones:
-- 1a) esCero::Int->Bool, que verifica si un entero es igual a 0.
esCero :: Int -> Bool
esCero x = (x==0)
-- esCero 5 = False
-- esCero 0 = True 


-- 1b) esPositivo::Int->Bool, que verifica si un entero es estrictamente mayor a 0.
esPositivo :: Int -> Bool
esPositivo x = (x>0)
-- esPositivo (-12) = False
-- esPositivo 5 = True


-- 1c) esVocal::Char->Bool, que verifica si un caracter es una vocal en minuscula.
esVocal :: Char -> Bool
esVocal ch = (ch=='a')||(ch=='e')||(ch=='i')||(ch=='o')||(ch=='u')
-- esVocal 'z' = False
-- esVocal 'a' = True


-- 1d) valorAbsoluto::Int->Int, que devuelve el valor absoluto de un entero ingresado.
valorAbsoluto :: Int -> Int
valorAbsoluto x | (x>=0) = x
                | otherwise = (-x)
-- valorAbsoluto 7 = 7
-- valorAbsoluto (-7) = 7


-- 2) Programa las siguientes funciones usando recursion o composicion:
-- 2a) paratodo::[Bool]->Bool, que verifica que todos los elementos de una lista sean True.
paratodo :: [Bool] -> Bool
paratodo [] = True
paratodo (x:xs) | (x==True) = paratodo xs
                | otherwise = False
-- paratodo [True, False] = False
-- paratodo [True, True]  = True


-- 2b) sumatoria::[Int]->Int, que calcula la suma de todos los elementos de una lista de enteros.
sumatoria :: [Int] -> Int
sumatoria [] = 0
sumatoria (n:xs) = n + sumatoria xs
-- sumatoria [2,3,4] = 9
-- sumatoria [12,13,15] = 40  


-- 2c) productoria::[Int]->Int, que calcula el producto de todos los elementos de la lista de enteros.
productoria :: [Int] -> Int
productoria [] = 1
productoria (n:xs) = n * productoria xs
-- productoria [2,3] = 6
-- productoria [2,3,2] = 12


-- 2d) factorial::Int->Int, que toma un numero n y calcula n!.
factorial :: Int -> Int
factorial 0 = 1
factorial n = n * factorial(n-1)
-- factorial 3 = 6
-- factorial 6 = 720


-- 2e) Utiliza la funcion sumatoria para definir, promedio::[Int]->Int, que toma una lista de numeros no vacia y calcula el valor promedio (truncado, usando division entera).
promedio :: [Int] -> Int
promedio [] = 0
promedio xs = div (sumatoria xs) (length xs)
-- promedio [4,5,6] = 5
-- promedio [2,4,12] = 6


-- 3) Programa la funciin pertenece::Int->[Int]->Bool, que verifica si un numero se encuentra en una lista.
pertenece :: Int -> [Int] -> Bool
pertenece p [] = False
pertenece p (x:xs) | (p==x) = True
                   | otherwise = pertenece p xs
-- pertenece 5 [2,3,4] = False
-- pertenece 4 [2,3,4] = True


-- 4) Programa las siguientes funciones que implementan los cuantificadores generales. Nota que el segundo parametro de cada funcion, es otra funcion!
-- 4a) paratodo’::[a]->(a->Bool)->Bool, dada una lista xs de tipo [a] y un predicado t::a->Bool, determina si todos los elementos de xs satisfacen el predicado t.
paratodo' :: [a] -> (a -> Bool) -> Bool
paratodo' [] t = True
paratodo' (x:xs) t = t x && paratodo' xs t
-- paratodo' [1,0] esCero = False
-- paratodo' [0] esCero = True


-- 4b) existe’::[a]->(a->Bool)->Bool, dada una lista xs de tipo [a] y un predicado t::a->Bool, determina si algun elemento de xs satisface el predicado t.
existe' :: [a] -> (a -> Bool) -> Bool
existe' [] t = False
existe' (x:xs) t = t x || existe' xs t
-- existe' [-1,-2,-3] esPositivo = False
-- existe' [-1,0,1] esPositivo = True


-- 4c) sumatoria’::[a]->(a->Int)->Int, dada una lista xs de tipo [a] y una funcion t::a->Int (toma elementos de tipo a y devuelve enteros), calcula la suma de los valores que resultan de la aplicacion de t a los elementos de xs.
sumatoria' :: [a] -> (a -> Int) -> Int
sumatoria' [] t = 0
sumatoria' (x:xs) t = t x + sumatoria' xs t
-- sumatoria' [9,11,13] valorAbsoluto = 33
-- sumatoria' [-9,-11,-13] valorAbsoluto = 33


-- 4d) productoria’::[a]->(a->Int)->Int, dada una lista de xs de tipo [a] y una funcion t::a->Int, calcula el producto de los valores que resultan de la aplicacion de t a los elementos de xs.
productoria' :: [a] -> (a -> Int) -> Int
productoria' [] t = 1
productoria' (x:xs) t = t x * productoria' xs t
-- productoria' [1,2,3] factorial = 12
-- productoria' [2,3,4] factorial = 288


-- 5) Defini nuevamente la funcion paratodo, pero esta vez usando la funcion paratodo’ (sin recursion ni analisis por casos!).
paratodo'' :: [a] -> (a -> Bool) -> Bool
paratodo'' xs f = paratodo' xs f
-- paratodo'' ['a','b'] esVocal = False
-- paratodo'' ['a','e'] esVocal = True


-- 6) Utilizando las funciones del ejercicio 4, programa las siguientes funciones por composicion, sin usar recursion ni analisis por casos.
-- 6a) todosPares::[Int]->Bool verifica que todos los numeros de una lista sean pares.
todosPares :: [Int] -> Bool
todosPares xs = paratodo' xs even
-- todosPares [2,3] = False
-- todosPares [2,4] = True

{- todosPares [6,8] = paratodo’ [6,8] even
                    = even 6 && (paratodo' [8] even)
                    = True && (even 8 && paratodo' [] even)
                    = True && (True && True)
                    = True && True
                    = True
-}


-- 6b) hayMultiplo::Int->[Int]->Bool verifica si existe algun numero dentro del segundo parametro que sea multiplo del primer parametro.
-- funcion auxiliar para hayMultiplo.
modulo :: Int -> Int -> Bool
modulo n x = (mod n x) == 0

hayMultiplo :: Int -> [Int] -> Bool
hayMultiplo n xs = existe' xs (modulo n)
-- hayMultiplo 3 [1,2] = False
-- hayMultiplo 4 [6,8] = True

{- hayMultiplo 2 [1,2] = existe' [1,2] modulo 2
                     = modulo 2 1 || (existe' [2] modulo 2)
                     = False || (modulo 2 2 || existe' [] modulo 2)
                     = False || (True || False)
                     = False || True
                     = True
-}


-- 6c) sumaCuadrados::Int->Int, dado un numero no negativo n, calcula la suma de los primeros n cuadrados, es decir <sum i : 0 ≤ i < n : i^2>.
-- funcion auxiliar para sumaCuadrados.
cuadrado :: Int -> Int
cuadrado n = n^2

sumaCuadrados :: Int -> Int
sumaCuadrados n = sumatoria' [0..n] cuadrado
-- sumaCuadrados 6 = 91
-- sumaCuadrados 6 = 140

{- sumaCuadrados 3 = Sumatoria' [0,1,2,3] cuadrado
                   = cuadrado 0 + sumatoria' [1,2,3] cuadrado
                   = 0 + cuadrado 1 + sumatoria' [2,3] cuadrado
                   = 0 + 1 + cuadrado 2 + sumatoria' [3] cuadrado
                   = 0 + 1 + 4 + cuadrado 3 + sumatoria' [] cuadrado
                   = 0 + 1 + 4 + 9 + 0
                   = 14
-}


-- 6d) Programar la fucion existeDivisor::Int->[Int]->Bool, que dado en entero n y una lista ls , devuelve True si y solo si, existe algun elemento en ls que divida a n*a.
existeDivisor :: Int -> [Int] -> Bool
existeDivisor n ls = existe' ls (modulo n)
-- existeDivisor 2 [1,3] = False
-- existeDivisor 2 [1,4] = True

{- existeDivisor 3 [4,6] = existe' [4,6] modulo 3
                         = modulo 3 4 || (existe' [6] modulo 3)
                         = False || (modulo 3 6 || existe' [] modulo 3)
                         = False || (False || False)
                         = False || False
                         = False
   
   existeDivisor 4 [2,3] = existe' [2,3] modulo 4
                         = modulo 4 2 || (existe' [3] modulo 4)
                         = True || (modulo 4 3 || existe' [] modulo 4)
                         = True || (False || False)
                         = True || False
                         = True
-}


-- 6e) Utilizando la funcion del apartado anterior, defini la funcion esPrimo::Int->Bool, que dado un entero n, devuelve True si y solo si n es primo.
esPrimo :: Int -> Bool
esPrimo n = (n>1) && not (existeDivisor n [2..(n-1)])
-- esPrimo 6 = False
-- esPrimo 7 = True

{- esPrimo 3 = (3>1) && not (exiteDivisor 3 [2..(3-1)])
             = True && not (existe' [2] modulo 3)
             = True && not (modulo 3 2 || existe' [] modulo 3)
             = True && not (False || False)
             = True && not False
             = True && True
             = True

   esPrimo 4 = (4>1) && not (exiteDivisor 4 [2..(4-1)])
             = True && not (existe' [2,3] modulo 4)
             = True && not (modulo 4 2 || existe' [3] modulo 4)
             = True && not (True || (modulo 4 3 || existe' [] modulo 4))
             = True && not (True || (False || False))
             = True && not (True || False)
             = True && not True
             = True && False
             = False
-}


-- 6f) ¿Se te ocurre como redefinir factorial (ej.2d) para evitar usar recursion?
factorial' :: Int -> Int
factorial' n = n * factorial (n-1)
-- factorial' 4 = 24
-- factorial' 7 = 5040


-- 6g) Programar la funcion multiplicaPrimos::[Int]->Int que calcula el producto de todos los numeros primos de una lista.
-- funcion auxiliar para multiplicaPrimos.
primos :: Int -> Int
primos n | esPrimo n = n
         | otherwise = 1

multiplicaPrimos :: [Int] -> Int
multiplicaPrimos xs = productoria' xs primos
--  multiplicaPrimos [1,2,3,4] = 6
--  multiplicaPrimos [2,3,4,6] = 6

{- multiplicaPrimos [3,4,5] = productoria' [3,4,5] primos
                            = primos 3 * (productoria' [4,5] primos)
                            = 3 * (primos 4 * (productoria' [5] primos))
                            = 3 * (1 * (primos 5 * (productoria' [] primos)))
                            = 3 * (1 * (5 * (1)))
                            = 15
-}


-- 6h) Programar la funcion esFib::Int->Bool, que dado un entero n, devuelve True si y solo si n esta en la sucesion de Fibonacci.
-- funcion auxiliar para esFib.
fib :: Int -> Int
fib n | (n<=1) = n
      | otherwise = fib(n-1) + fib(n-2)

esFib :: Int -> Bool
esFib n = pertenece n (map fib [1..(n+1)])
-- esFib 13 = True
-- esFib 14 = False

{- esFib 4 = pertenece 4 (map fib [1..4])
           = pertenece 4 [1,1,2,3]
           = pertenece 4 1
           = pertenece 4 1
           = pertenece 4 2
           = pertenece 4 3
           = pertenece 4 []
           = False

   esFib 5 = pertenece 5 (map fib [1..5])
           = pertenece 5 [1,1,2,3,5]
           = pertenece 5 1
           = pertenece 5 1
           = pertenece 5 2
           = pertenece 5 3
           = pertenece 5 5
           = True
-}


-- 6i) Utilizando la funcion del apartado anterior, defini la funcion todosFib::[Int]->Bool que dada una lista xs de enteros, devuelva si todos los elementos de la lista pertenecen (o no) a la sucesion de Fibonacci.
todosFib :: [Int] -> Bool
todosFib xs = paratodo' xs esFib
-- todosFib [1,2,3,4] = False
-- todosFib [1,2,3,5] = True

{- todosFib [3,4,5] = paratodo' [3,4,5] esFib
                  = esFib 3 && (paratodo' [4,5] esFib)
                  = True && (esFib 4 && (paratodo' [5] esFib))
                  = True && (False && (esFib 5 && (paratodo' [] esFib)))
                  = True && (False && (True && (True)))
                  = False

   todosFib [2,3,5] = paratodo' [2,3,5] esFib
                  = esFib 2 && (paratodo' [3,5] esFib)
                  = True && (esFib 3 && (paratodo' [5] esFib))
                  = True && (True && (esFib 5 && (paratodo' [] esFib)))
                  = True && (True && (True && (True)))
                  = True
-}


-- 7) Indaga en Hoogle sobre las funciones map y filter. Tambien podes consultar su tipo en ghci con el comando :t.
{- 7a) ¿Que hacen estas funciones?

    [map f xs] aplica f a cada elemento de xs.

       map :: (a -> b) -> [a] -> [b]

       map f [x1, x2, ..., xn] == [f x1, f x2, ..., f xn]
       map f [x1, x2, ...] == [f x1, f x2, ...]

       >>> map (+1) [1, 2, 3]
       [2,3,4]

    [filter p xs] aplica p a la lista, y devuelve los elementos que cumplen el predicado.

       filter :: (a -> Bool) -> [a] -> [a]

       filter p xs = [ x | x <- xs, p x]

       >>> filter odd [1, 2, 3]
       [1,3]

   7b) ¿A que equivale la expresion map succ [1, -4, 6, 2, -8], donde succ n = n+1?

   succ :: Int -> Int
   succ n = n+1

   map succ [1,-4,6,2,-8] = succ 1:(succ (-4):(succ 6:(succ 2:(succ (-8):[]))))
                              = 1+1:((-4)+1:(6+1:(2+1:((-8):[]))))
                              = 2:((-3):(7:(3:((-8):[]))))
                              = [2,(-3),7,3,(-7)]

    7c) ¿Y la expresion filter esPositivo [1, -4, 6, 2, -8]?

   esPositivo :: Int -> Bool
   esPositivo x = (x>0)

   filter esPositivo [1,-4,6,2,-8] = esPositivo 1:(esPositivo (-4):(esPositivo 6:(esPositivo 2:(esPositivo (-8):[]))))
                                   = 1:(6:(2:[]))
                                   = [1,6,2]
-}


-- 8) Programa una funcion que dada una lista de numeros xs, devuelve la lista que resulta de duplicar cada valor de xs.
-- 8a) Definila usando recursion.
duplica :: [Int] -> [Int]
duplica [] = []
duplica (x:xs) = (x+x) : duplica xs
-- duplica [3,4,5] = [6,8,10]
-- duplica [6,7,8] = [12,14,16]


-- 8b) Definila utilizando la funcion map.
duplica' :: [Int] -> [Int]
duplica' xs = map (*2) xs
-- duplica' [7,11,13] = [14,22,26]
-- duplica' [17,19,23] = [34,38,46]


-- 9) Programa una funcion que dada una lista de numeros xs, calcula una lista que tiene como elementos aquellos numeros de xs que son primos.
-- 9a) Definila usando recursion.
sonPrimos :: [Int] -> [Int]
sonPrimos [] = []
sonPrimos (x:xs) | (esPrimo x) = x:sonPrimos xs
                 | otherwise = sonPrimos xs
-- sonPrimos [3,4,5] = [3,5]
-- sonPrimos [4,6,8] = []


-- 9b) Definila utilizando la funcion filter.
sonPrimos' :: [Int] -> [Int]
sonPrimos' xs = filter esPrimo xs
-- sonPrimos' [5,7,9] = [5,7]
-- sonPrimos' [1,11,111] = [11]


-- 9c) Revisa tu definicion del ejercicio 6g. ¿Como podes mejorarla?
multiplicaPrimos' :: [Int] -> Int
multiplicaPrimos' xs = productoria (filter esPrimo xs)
-- multiplicaPrimos' [3,5,11] = 165
-- multiplicaPrimos' [3,5,9,11] = 165


{- 10) La funcion primIgualesA toma un valor y una lista, y calcula el tramo inicial mas largo de la lista cuyos elementos son iguales a ese valor. Por ejemplo:
       primIgualesA 3 [3,3,4,1] = [3,3]
       primIgualesA 3 [4,3,3,4,1] = []
       primIgualesA 3 [] = []
       primIgualesA ’a’ "aaadaa" = "aaa" -}
-- 10a) Programa primIgualesA por recursion.
primIgualesA :: Eq a => a -> [a] -> [a]
primIgualesA e [] = []
primIgualesA e (x:xs) | (e==x) = x : primIgualesA e xs
                      | otherwise = []


-- 10b) Programa nuevamente la funcion utilizando takeWhile.
primIgualesA' :: Eq a => a -> [a] -> [a]
primIgualesA' n [] = []
primIgualesA' n xs = takeWhile (==n) xs


{- 11) La funcion primIguales toma una lista y devuelve el mayor tramo inicial de la lista cuyos elementos son todos iguales entre sı. Por ejemplo:
       primIguales [3,3,4,1] = [3,3]
       primIguales [4,3,3,4,1] = [4]
       primIguales [] = []
       primIguales "aaadaa" = "aaa" -}
-- 11a) Programa primIguales por recursion.
primIguales :: Eq a => [a] -> [a]
primIguales [] = []
primIguales (x:xs) | (x == head xs) = x : primIguales xs
                   | otherwise = x : []


-- 11b) Usa cualquier version de primIgualesA para programar primIguales. Esta permitido dividir en casos, pero no usar recursion.
primIguales' :: Eq a => [a] -> [a]
primIguales' xs = primIgualesA' (head xs) xs


-- 12(*) Reescribir todas las funciones del punto 4 utilizando el cuantificador generalizado (sin usar induccion y en una linea por funcion).
-- funcion auxiliar para redefinir las funciones del punto 4.
cuantGen :: (b -> b -> b) -> b -> [a] -> (a -> b) -> b
cuantGen op z xs t = foldr op z (map t xs)

{-
foldr :: (a -> b -> b) -> b -> [a] -> b
foldr op z [] = z
foldr op z (x:xs) = op x (foldr op z xs)
-}

paratodoGen :: [a] -> (a -> Bool) -> Bool
paratodoGen xs t = cuantGen (&&) True xs t
{- paratodoGen [2,3,4] even = cuantGen (&&) True [2,3,4] even
                            = foldr (&&) True (map even [2,3,4])
                            = foldr (&&) True [True, False, True]
                            = True (foldr (&&) True [False, True])
                            = True && False (foldr (&&) True [True])
                            = True && False && True (foldr (&&) True [])
                            = True && False && True && True
                            = False
-}

existeGen :: [a] -> (a -> Bool) -> Bool
existeGen xs t = cuantGen (||) False xs t
{- existeGen [7,8,9] esPrimo = cuantGen (||) False [7,8,9] esPrimo
                             = foldr (||) False (map esPrimo [7,8,9])
                             = foldr (||) False [True, False, False]
                             = True (foldr (||) False [False, False])
                             = True || False (foldr (||) False [False])
                             = True || False || False (foldr (||) False [])
                             = True || False || False || False
                             = True
-}

sumatoriaGen :: [a] -> (a -> Int) -> Int
sumatoriaGen xs t = cuantGen (+) 0 xs t
{- sumatoriaGen [2,3,4] (+2) = cuantGen (+) 0 [2,3,4] (+2)
                             = foldr (+) 0 (map (+2) [2,3,4])
                             = foldr (+) 0 [4,6,8]
                             = 4 (foldr (+) 0 [6,8])
                             = 4 + 6 (foldr (+) 0 [8])
                             = 4 + 6 + 8 (foldr (+) 0 [])
                             = 4 + 6 + 8 + 0
                             = 15
-}

productoriaGen :: [a] -> (a -> Int) -> Int
productoriaGen xs t = cuantGen (*) 1 xs t
{- productoriaGen [7,8,9] (+3) = cuantGen (*) 1 [7,8,9] (+3)
                               = foldr (*) 1 (map (+3) [7,8,9])
                               = foldr (*) 1 [10,11,12]
                               = 10 (foldr (*) 1 [11,12])
                               = 10 * 11 (foldr (*) 1 [12])
                               = 10 * 11 * 12 (foldr (*) 1 [])
                               = 10 * 11 * 12 * 1
                               = 1320
-}


-- 13(*) Definir una funcion que se denomina distancia de edicion. Que toma como entrada dos strings (lista de caracteres). distanciaEdicion::[Char]->[Char]->Int.
distanciaEdicion :: [Char] -> [Char] -> Int
distanciaEdicion [] ys = length ys
distanciaEdicion xs [] = length xs
distanciaEdicion (x:xs) (y:ys) | (x==y) = distanciaEdicion xs ys
                               | otherwise = 1 + distanciaEdicion xs ys
-- distanciaEdicion "laboratorio" "ayedd1" = 11
-- distanciaEdicion "hablar" "hablaba" = 2


-- 14(*) Definı una funcion primeros que cumplen, primQueCumplen::[a]->(a->Bool)->[a], tal que, dada una lista ls y un predicado p, devuelve el tramo inicial de ls que cumple p.
primQueCumplen :: [a] -> (a -> Bool) -> [a]
primQueCumplen [] p = []
primQueCumplen (l:ls) p | (p l) = l : primQueCumplen ls p
                        | otherwise = primQueCumplen ls p
-- primQueCumplen [2,3,4] even = [2,4]
-- primQueCumplen [-1,-2,-3] esPositivo = []


-- 15(*) Para cada uno de los siguientes patrones, decidı si estan bien tipados, y en tal caso da los tipos de cada subexpresion.
{- a) f :: (a, b) -> ...
      f (x, y) = ...

    (x,y) :: (a,b)
    x :: a
    y :: b

    Si cubre todos los casos.


   b) f :: [(a, b)] -> ...
      f (a, b) = ...

    Mal tipado, cubre tuplas pero requiere lista de tuplas.


   c) f :: [(a, b)] -> ...
      f (x:xs) = ...

    Buen tipado pero no cubre el caso de lista vacía.


   d) f :: [(a, b)] -> ...
      f ((x, y) : ((a, b) : xs)) = ...

    Buen tipado pero no cubre el caso de lista vacía ni el caso de un solo elemento.


   e) f :: [(Int, a)] -> ...
      f [(0, a)] = ...

    Buen tipado pero no cubre el caso de lista vacía ni ningún caso en donde el primer elemento no sea 0.


   f) f :: [(Int, a)] -> ...
      f ((x, 1) : xs) = ...

    Buen tipado pero no cubre el caso de lista vacía ni ningún caso en donde el segundo elemento no sea 1.


   g) f :: (Int -> Int) -> Int -> ...
      f a b = ...

    (a, b) :: ((Int -> Int), Int)
    a :: (Int -> Int)
    b :: Int

    Si cubre todos los casos.


   h) f :: (Int -> Int) -> Int -> ...
      f a 3 = ...

    Buen tipado pero no cubre ningún caso en donde el segundo elemento no sea 3.


   i) f :: (Int -> Int) -> Int -> ...
      f 0 1 2 = ...

    Mal tipado, cubre el caso Int -> Int -> Int pero f requiere (Int -> Int) -> Int.
-}


-- 16(*) Para las siguientes declaraciones de funciones, da al menos una definicion cuando sea posible. ¿Podes dar alguna otra definicion alternativa a la que diste en cada caso?
{- a) f :: (a, b) -> b
      f (x, y) = y

   b) f :: (a, b) -> c
      f (x, y) = x*y

   c) f :: (a -> b) -> a -> b
      f p x = y

   d) f :: (a -> b) -> [a] -> [b]
      f p xs = filter p xs
-}
