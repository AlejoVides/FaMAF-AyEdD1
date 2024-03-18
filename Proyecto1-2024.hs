-- 1. Programa las siguientes funciones:
-- 1a) esCero :: Int -> Bool, que verifica si un entero es igual a 0.
esCero :: Int -> Bool
esCero x = (x == 0)
-- esCero 7 = False
-- esCero 0 = True


-- 1b) esPositivo :: Int -> Bool, que verifica si un entero es estrictamente mayor a 0.
esPositivo :: Int -> Bool
esPositivo x = (x > 0)
-- esPositivo 7 = True
-- esPositivo 0 = False


-- 1c) esVocal :: Char -> Bool, que verifica si un caracter es una vocal en minuscula.
esVocal :: Char -> Bool
esVocal c = (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u')
-- esVocal 'b' = False
-- esVocal 'u' = True


-- 1d) valorAbsoluto :: Int -> Int, que devuelve el valor absoluto de un entero ingresado.
valorAbsoluto :: Int -> Int
valorAbsoluto x | (x >= 0) = x
                | otherwise = (-x)
-- valorAbsoluto 9 = 9
-- valorAbsoluto (-14) = 14


-- 2. Programa las siguientes funciones usando recursion o composicion:
-- 2a) todos.xs = {∀i : 0 ≤ i < #xs : xs.i} (derivar en el teorico primero) 
-- paratodo :: [Bool] -> Bool, que verifica que todos los elementos de una lista sean True.
paratodo :: [Bool] -> Bool
paratodo [] = True
paratodo (x:xs) | (x == True) = paratodo xs
                | otherwise = False
-- paratodo [True, True, False] = False
-- paratodo [True, True] = True


-- 2b) sumatoria :: [Int] -> Int, que calcula la suma de todos los elementos de una lista de enteros.
sumatoria :: [Int] -> Int
sumatoria [] = 0
sumatoria (x:xs) = x + sumatoria xs
-- sumatoria [6,8,10] = 24
-- sumatoria [7,11,13] = 31


-- 2c) productoria :: [Int] -> Int, que calcula el producto de todos los elementos de la lista de enteros.
productoria :: [Int] -> Int
productoria [] = 1
productoria (x:xs) = x * productoria xs
-- productoria[3,4,5] = 60
-- productoria[7,9] = 63


-- 2d) factorial :: Int -> Int, que toma un numero n y calcula n!.
factorial :: Int -> Int
factorial 0 = 1
factorial x = x * factorial (x-1)
-- factorial 4 = 24
-- factorial 7 = 5040


-- 2e) Utiliza la funcion sumatoria para definir, promedio :: [Int] -> Int, que toma una lista de numeros no vacia y calcula el valor promedio (truncado, usando division entera).
promedio :: [Int] -> Int
promedio xs = div (sumatoria xs) (length xs)
-- promedio [3,5,6] = 4
-- promedio [7,3,15] = 8


-- 3. Programa la funcion pertenece :: Int -> [Int] -> Bool, que verifica si un numero se encuentra en una lista.
pertenece :: Int -> [Int] -> Bool
pertenece y [] = False
pertenece y (x:xs) | (y == x) = True
                   | otherwise = pertenece y xs
-- pertenece 4 [1,2,3] = False
-- pertenece 4 [2,3,4] = True


-- 4. Programa las siguientes funciones que implementan los cuantificadores generales. Nota que el segundo parametro de cada funcion, es otra funcion!.
-- 4a) paratodo.xs.T = {∀i : 0 ≤ i < #xs : T.(xs.i)} (derivar en el teorico primero)
-- paratodo’ :: [a] -> (a -> Bool) -> Bool, dada una lista xs de tipo [a] y un predicado T :: a -> Bool, determina si todos los elementos de xs satisfacen el predicado T.
paratodo' :: [a] -> (a -> Bool) -> Bool
paratodo' [] t = True
paratodo' (x:xs) t = t x && paratodo' xs t
-- paratodo' [0,1,2] esCero = False
-- paratodo' [0] esCero = True


-- 4b) existe.xs.T = {∃i : 0 ≤ i < #xs : T.(xs.i)} (derivar en el teorico primero)
-- existe’ :: [a] -> (a -> Bool) -> Bool, dada una lista xs de tipo [a] y un predicado T :: a -> Bool, determina si algun elemento de xs satisface el predicado T.
existe' :: [a] -> (a -> Bool) -> Bool
existe' [] t = False
existe' (x:xs) t = t x || existe' xs t
-- existe' [-1,0,1] esPositivo = True
-- existe' [-5] esPositivo = False


-- 4c) sumatoria.xs.T = {Σi : 0 ≤ i < #xs : T.(xs.i)} (derivar en el teorico primero)
-- sumatoria’ :: [a] -> (a -> Int) -> Int, dada una lista xs de tipo [a] y una funcion T :: a -> Int (toma elementos de tipo a y devuelve enteros), calcula la suma de los valores que resultan de la aplicacion de T a los elementos de xs.
sumatoria' :: [a] -> (a -> Int) -> Int
sumatoria' [] t = 0
sumatoria' (x:xs) t = t x + sumatoria' xs t
-- sumatoria' [3,7,17] valorAbsoluto = 27
-- sumatoria' [3,7,-17] valorAbsoluto = 27


-- 4d) productoria.xs.T = {Πi : 0 ≤ i < #xs : T.(xs.i)} (derivar en el teorico primero)
-- productoria’ :: [a] -> (a -> Int) -> Int, dada una lista de xs de tipo [a] y una funcion T :: a -> Int, calcula el producto de los valores que resultan de la aplicacion de T a los elementos de xs.
productoria' :: [a] -> (a -> Int) -> Int
productoria' [] t = 1
productoria' (x:xs) t = t x * productoria' xs t
-- productoria' [2,3] factorial = 12
-- productoria' [4,5] factorial = 2880


-- 5. Defini nuevamente la funcion paratodo, pero esta vez usando la funcion paratodo’ (sin recursion ni analisis por casos!).
paratodo'' :: [a] -> (a -> Bool) -> Bool
paratodo'' xs f = paratodo' xs f
-- paratodo'' ['a','b'] esVocal = False
-- paratodo'' [14,25] esPositivo = True


-- 6. Utilizando las funciones del ejercicio 4, programa las siguientes funciones por composicion, sin usar recursion ni analisis por casos.
-- 6a) todosPares :: [Int] -> Bool verifica que todos los numeros de una lista sean pares.
todosPares :: [Int] -> Bool
todosPares xs = paratodo' xs even
-- todosPares [4,6,8] = True
-- todosPares [3,4,6] = False


-- 6b) hayMultiplo :: Int -> [Int] -> Bool verifica si existe algun numero dentro del segundo parametro que sea multiplo del primer parametro.
hayMultiplo :: Int -> [Int] -> Bool
hayMultiplo n [] = False
hayMultiplo n (x:xs) = (mod x n == 0) || hayMultiplo n xs
-- hayMultipo 3 [4,5] = False
-- hayMultipo 4 [6,8] = True

{-
-- funcion auxiliar para hayMultiplo.
modulo :: Int -> Int -> Bool
modulo n x = (mod x n) == 0

hayMultiplo :: Int -> [Int] -> Bool
hayMultiplo n xs = existe' xs (modulo n)
-}


-- 6c) sumaCuadrados :: Int -> Int, dado un numero no negativo n, calcula la suma de los primeros n cuadrados, es decir {Σi : 0 ≤ i < n : i^2}.
sumaCuadrados :: Int -> Int
sumaCuadrados x = sumatoria' [0..x] (^2)
-- sumaCuadrados 5 = 55
-- sumaCuadrados 7 = 140


-- 6d) Programar la fucion existeDivisor :: Int -> [Int] -> Bool, que dado en entero n y una lista ls, devuelve True si y solo si, existe algun elemento en ls que divida a n.
existeDivisor :: Int -> [Int] -> Bool
existeDivisor n [] = False
existeDivisor n (l:ls) = (mod n l == 0) || existeDivisor n ls
-- existeDivisor 6 [1,2,3] = True
-- existeDivisor 6 [4] = False


-- 6e) Utilizando la funcion del apartado anterior, defin´i la funcion esPrimo :: Int -> Bool, que dado un entero n, devuelve True si y solo si n es primo.
esPrimo :: Int -> Bool
esPrimo n = (n>1) && not(existeDivisor n [2..(n-1)])
-- esPrimo 6 = False
-- esPrimo 7 = True


-- 6f) ¿Se te ocurre como redefinir factorial (ej. 2d) para evitar usar recursion?
factorial' :: Int -> Int
factorial' n = productoria [1..n]
-- factorial 5 = 120
-- factorial 8 = 40320

{-
factorial' :: Int -> Int
factorial' n = n * factorial (n-1)
-}

-- 6g) Programar la funcion multiplicaPrimos :: [Int] -> Int que calcula el producto de todos los numeros primos de una lista.
-- funcion auxiliar para multiplicaPrimos.
primos :: Int -> Int
primos n | esPrimo n = n
         | otherwise = 1

multiplicaPrimos :: [Int] -> Int
multiplicaPrimos xs = productoria' xs primos
--  multiplicaPrimos [1,2,3,4] = 6
--  multiplicaPrimos [2,3,4,6] = 6


-- 6h) Programar la funcion esFib :: Int -> Bool, que dado un entero n, devuelve True si y solo si n esta en la sucesion de Fibonacci.
-- funcion auxiliar para esFib.
fib :: Int -> Int
fib n | (n<=1) = n
      | otherwise = fib(n-1) + fib(n-2)

esFib :: Int -> Bool
esFib n = pertenece n (map fib [1..(n+1)])
-- esFib 13 = True
-- esFib 14 = False


--6i) Utilizando la funcion del apartado anterior, defini la funcion todosFib :: [Int] -> Bool que dada una lista xs de enteros, devuelva si todos los elementos de la lista pertenecen (o no) a la sucesion de Fibonacci.
todosFib :: [Int] -> Bool
todosFib [] = False
todosFib xs = paratodo' xs esFib
-- todosFib [1,1,2,3,5,8] == True
-- todosFib [1,1,2,3,5,8,12] == False


-- 7. Indaga en Hoogle sobre las funciones map y filter. Tambien podes consultar su tipo en ghci con el comando :t.
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


-- 8. Programa una funcion que dada una lista de numeros xs, devuelve la lista que resulta de duplicar cada valor de xs.
-- 8a) Definila usando recursion.
duplica :: [Int] -> [Int]
duplica [] = []
duplica (x:xs) = (x+x) : duplica xs
-- duplica [2,3,4,5] = [4,6,8,10]
-- duplica [-6,-5,-4] = [-12,-10,-8]


-- 8b) Definila utilizando la funcion map.
duplica' :: [Int] -> [Int]
duplica' xs = map (*2) xs


-- 9. Programa una funcion que dada una lista de numeros xs, calcula una lista que tiene como elementos aquellos numeros de xs que son primos.
-- 9a) Definila usando recursion.
sonPrimos :: [Int] -> [Int]
sonPrimos [] = []
sonPrimos (x:xs) | (esPrimo x) = x : sonPrimos xs
                 | otherwise = sonPrimos xs
-- sonPrimos [3,4,5] = [3,5]
-- sonPrimos [7,8,9] = [7]


-- 9b) Definila utilizando la funcion filter.
sonPrimos' :: [Int] -> [Int]
sonPrimos' xs = filter esPrimo xs
-- sonPrimos' [5,6,7] = [5,7]
-- sonPrimos' [9,10,11] = [11]


-- 9c) Revisa tu definicion del ejercicio 6g. ¿Como podes mejorarla?
multiplicaPrimos' :: [Int] -> Int
multiplicaPrimos' [] = 0
multiplicaPrimos' (x:xs) = productoria (filter esPrimo (x:xs))
-- multiplicaPrimos' [2,3,4] = 6
-- multiplicaPrimos' [5,6,7,8,9] = 35


-- 10. La funcion primIgualesA toma un valor y una lista, y calcula el tramo inicial mas largo de la lista cuyos elementos son iguales a ese valor.
-- 10a) Programa primIgualesA por recursion.
primIgualesA :: Eq a => a -> [a] -> [a]
primIgualesA e [] = []
primIgualesA e (x:xs) | (e == x) = x : primIgualesA e xs
                      | otherwise = []
-- primIgualesA 3 [3,3,4,1] = [3,3]
-- primIgualesA 3 [4,3,3,4,1] = []


-- 10b) Programa nuevamente la funcion utilizando takeWhile.
primIgualesA' :: Eq a => a -> [a] -> [a]
primIgualesA' n [] = []
primIgualesA' n xs = takeWhile (== n) xs
-- primIgualesA' 3 [] = []
-- primIgualesA' 'a' "aaadaa" = "aaa"


-- 11. La funcion primIguales toma una lista y devuelve el mayor tramo inicial de la lista cuyos elementos son todos iguales entre si.
-- 11a) Programa primIguales por recursion.
primIguales :: Eq a => [a] -> [a]
primIguales [] = []
primIguales (x:xs) | (x == head xs) = x : primIguales xs
                   | otherwise = x : []
-- primIguales [3,3,4,1] = [3,3]
-- primIguales [4,3,3,4,1] = [4]


-- 11b) Usa cualquier version de primIgualesA para programar primIguales. Esta permitido dividir en casos, pero no usar recursion.
primIguales' :: Eq a => [a] -> [a]
primIguales' xs = primIgualesA' (head xs) xs
-- primIguales' [] = []
-- primIguales' "aaadaa" = "aaa"


-- 12(*) Reescribir todas las funciones del punto 4 utilizando el cuantificador generalizado (sin usar induccion y en una linea por funcion).
-- funcion auxiliar para redefinir las funciones del punto 4.
cuantGen :: (b -> b -> b) -> b -> [a] -> (a -> b) -> b
cuantGen op z [] t = z
cuantGen op z (x:xs) t = op (t x) (cuantGen op z xs t)

paratodoGen :: [a] -> (a -> Bool) -> Bool
paratodoGen xs t = cuantGen (&&) True xs t
{- paratodoGen [2,3,4] even = cuantGen (&&) True [2,3,4] even
                            = && (even 2) (cuantGen && True [3,4] even)
                            = True && (even 3) (cuantGen && True [4] even)
                            = True && False && (even 4) (cuantGen && True [] even)
                            = True && False && True && True
                            = True && False && True
                            = True && False
                            = False 
-}

existeGen :: [a] -> (a -> Bool) -> Bool
existeGen xs t = cuantGen (||) False xs t
{- existeGen [7,8,9] esPrimo = cuantGen (||) False [7,8,9] esPrimo
                             = || (esPrimo 7) (cuantGen || False [8,9] esPrimo)
                             = True || (esPrimo 8) (cuantGen || False [9] esPrimo)
                             = True || False || (esPrimo 9) (cuantGen || False [] esPrimo)
                             = True || False || False || False
                             = True || False || False
                             = True || False
                             = True
-}

sumatoriaGen :: [a] -> (a -> Int) -> Int
sumatoriaGen xs t = cuantGen (+) 0 xs t
{- sumatoriaGen [2,3,4] (+2) = cuantGen (+) 0 [2,3,4] (+2)
                             = + (+2 2) (cuantGen + 0 [3,4] +2)
                             = 4 + (+2 3) (cuantGen + 0 [4] +2)
                             = 4 + 5 + (+2 4) (cuantGen + 0 [] +2)
                             = 4 + 5 + 6 + 0
                             = 4 + 5 + 6
                             = 4 + 11
                             = 15
-}

productoriaGen :: [a] -> (a -> Int) -> Int
productoriaGen xs t = cuantGen (*) 1 xs t
{- productoriaGen [7,8,9] (+3) = cuantGen (*) 1 [7,8,9] (+3)
                               = * (+3 7) (cuantGen * 1 [8,9] +3)
                               = 10 * (+3 8) (cuantGen * 1 [9] +3)
                               = 10 * 11 * (+3 9) (cuantGen * 1 [] +3)
                               = 10 * 11 * 12 * 1
                               = 1320
-}


-- 13(*) Definir una funcion que se denomina distancia de edicion. Que toma como entrada dos strings (lista de caracteres). distanciaEdicion :: [Char] -> [Char] -> Int.
distanciaEdicion :: [Char] -> [Char] -> Int
distanciaEdicion [] ys = length ys
distanciaEdicion xs [] = length xs
distanciaEdicion (x:xs) (y:ys) | (x == y) = distanciaEdicion xs ys
                               | otherwise = 1 + distanciaEdicion xs ys
-- distanciaEdicion "laboratorio" "ayedd1" = 11
-- distanciaEdicion "hablar" "hablaba" = 2


-- 14(*) Defini una funcion primeros que cumplen, primQueCumplen :: [a] -> (a -> Bool) -> [a], tal que, dada una lista ls y un predicado p, devuelve el tramo inicial de ls que cumple p.
primQueCumplen :: [a] -> (a -> Bool) -> [a]
primQueCumplen [] p = []
primQueCumplen (l:ls) p | (p l) = l : primQueCumplen ls p
                        | otherwise = []
-- primQueCumplen [2,4,5,6,7,8] even = [2,4]
-- primQueCumplen [-1,-2,-3] esPositivo = []


-- 15(*) Para cada uno de los siguientes patrones, decidi si estan bien tipados, y en tal caso da los tipos de cada subexpresion.
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

    Buen tipado pero no cubre el caso de lista vacia.


   d) f :: [(a, b)] -> ...
      f ((x, y) : ((a, b) : xs)) = ...

    Buen tipado pero no cubre el caso de lista vacia ni el caso de un solo elemento.


   e) f :: [(Int, a)] -> ...
      f [(0, a)] = ...

    Buen tipado pero no cubre el caso de lista vacia ni ningun caso en donde el primer elemento no sea 0.


   f) f :: [(Int, a)] -> ...
      f ((x, 1) : xs) = ...

    Mal tipado, usa el tipo polimorfico a pero se define usando la constante 1 sin usar polimorfismo adhoc.


   g) f :: (Int -> Int) -> Int -> ...
      f a b = ...

    (a, b) :: ((Int -> Int), Int)
    a :: (Int -> Int)
    b :: Int

    Si cubre todos los casos.


   h) f :: (Int -> Int) -> Int -> ...
      f a 3 = ...

    Buen tipado pero no cubre ningun caso en donde el segundo elemento no sea 3.


   i) f :: (Int -> Int) -> Int -> ...
      f 0 1 2 = ...

    Mal tipado, cubre el caso Int -> Int -> Int pero f requiere (Int -> Int) -> Int.
-}


-- 16(*) Para las siguientes declaraciones de funciones, da al menos una definicion cuando sea posible. ¿Podes dar alguna otra definicion alternativa a la que diste en cada caso?
{- a) f :: (a, b) -> b
      f (x, y) = y

   b) f :: (a, b) -> c
    No existe funcion tal que pueda cumpir (a, b) -> c, dado que no se pueden comparar elementos de distinto tipo para dar con un tercer tipo.

   c) f :: (a -> b) -> a -> b
      f p x = y

   d) f :: (a -> b) -> [a] -> [b]
      f p xs = map p xs
-}
