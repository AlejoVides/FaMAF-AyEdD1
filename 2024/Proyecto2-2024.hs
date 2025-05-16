{-# LANGUAGE NPlusKPatterns #-}
-- 1a) Implementa el tipo Carrera como esta definido arriba.
data Carrera = Matematica | Fisica | Computacion | Astronomia deriving Eq

-- 1b) Defini la siguiente funcion, usando pattern matching: titulo :: Carrera -> String que devuelve el nombre completo de la carrera en forma de string. Por ejemplo, para el constructor Matematica, debe devolver ”Licenciatura en Matematica”.
titulo :: Carrera -> String
titulo carrera | (carrera == Matematica)  = "Licenciatura en Matematica"
               | (carrera == Fisica)      = "Licenciatura en Fisica"
               | (carrera == Computacion) = "Licenciatura en Computacion"
               | (carrera == Astronomia)  = "Licenciatura en Astronomia"
-- titulo Matematica = "Licenciatura en Matematica"
-- titulo Astronomia = "Licenciatura en Astronomia"


-- 1c) Definir el tipo NotaBasica con constructores Do, Re, Mi, Fa, Sol, La y Si.
data NotaBasica = Do | Re | Mi | Fa | Sol | La | Si deriving (Eq, Ord, Show)


-- 1d) Programar usando pattern matching la funcion: cifradoAmericano :: NotaBasica −> Char que relaciona las notas Do, Re, Mi, Fa, Sol, La y Si con los caracteres ’C’ , ’D’, ’E’, ’F’, ’G’, ’A’ y ’B’ respectivamente.
cifradoAmericano :: NotaBasica -> Char
cifradoAmericano Do  = 'C'
cifradoAmericano Re  = 'D'
cifradoAmericano Mi  = 'E'
cifradoAmericano Fa  = 'F'
cifradoAmericano Sol = 'G'
cifradoAmericano La  = 'A'
cifradoAmericano Si  = 'B'
-- cifradoAmericano Re = 'D'
-- cifradoAmericano La = 'A'


-- 2a) Completar la definicion del tipo NotaBasica para que las expresiones *Main> Do <= Re *Main> Fa `min` Sol sean validas y no generen error.
-- Do <= Re = True
-- Fa `min` Sol = Fa


-- 3a) Definir usando polimorfismo ad hoc la funcion minimoElemento que calcula (de manera recursiva) cual es el menor valor de una lista de tipo [a]. Asegurarse que solo este definida para listas no vacias.
minimoElemento :: Ord a => [a] -> a
minimoElemento [elemento] = elemento
minimoElemento (elemento:xs) = min elemento (minimoElemento xs)
-- minimoElemento [6,12,3] = 3
-- minimoElemento ['z','f','g'] = 'f'


-- 3b) Definir la funcion minimoElemento’ de manera tal que el caso base de la recursion sea el de la lista vacia. Para ello revisar la clase Bounded.
minimoElemento' :: (Bounded a, Ord a) => [a] -> a
minimoElemento' [] = minBound
minimoElemento' [elemento] = elemento
minimoElemento' (elemento:xs) = min elemento (minimoElemento' xs)
-- minimoElemento' ([1,5,10]::[Int]) = 1
-- minimoElemento' ([]::[Bool]) = False


-- 3c) Usar la funcion minimoElemento para determinar la nota mas grave de la melodia: [Fa, La, Sol, Re, Fa].
-- minimoElemento [Fa, La, Sol, Re, Fa] = Re


-- 4a) Implementa el tipo Deportista y todos sus tipos accesorios (NumCamiseta, Altura, Zona, etc) tal como estan definidos arriba.
-- Sinonimos de tipo
type Altura = Int
type NumCamiseta = Int
-- Tipos algebraicos sin parametros (aka enumerados)
data Zona = Arco | Defensa | Mediocampo | Delantera deriving (Show, Eq)
data TipoReves = DosManos | UnaMano deriving Show
data Modalidad = Carretera | Pista | Monte | BMX deriving Show
data PiernaHabil = Izquierda | Derecha deriving Show
-- Sinonimo
type ManoHabil = PiernaHabil
-- Deportista es un tipo algebraico con constructores parametricos
data Deportista = Ajedrecista                                      -- Constructor sin argumentos
                | Ciclista Modalidad                               -- Constructor con un argumento
                | Velocista Altura                                 -- Constructor con un argumento
                | Tenista TipoReves ManoHabil Altura               -- Constructor con tres argumentos
                | Futbolista Zona NumCamiseta PiernaHabil Altura deriving Show -- Constructor con ...


-- 4b) ¿Cual es el tipo del constructor Ciclista?.
-- :t Ciclista = Ciclista :: Modalidad -> Deportista


-- 4c) Programa la funcion contar_velocistas :: [Deportista] -> Int que dada una lista de deportistas xs, devuelve la cantidad de velocistas que hay dentro de xs.
contar_velocistas :: [Deportista] -> Int
contar_velocistas [] = 0
contar_velocistas (Velocista _:xs) = 1 + contar_velocistas xs
contar_velocistas (_:xs) = contar_velocistas xs
-- contar_velocistas [Ajedrecista, Velocista(172), Velocista(165)] = 2
-- contar_velocistas [Ciclista(Monte), Futbolista(Defensa)(17)(Derecha)(176)] = 0


-- 4d) Programa la funcion contar_futbolistas :: [Deportista] -> Zona -> Int que dada una lista de deportistas xs, y una zona z, devuelve la cantidad de futbolistas incluidos en xs que juegan en la zona z. Programa contar_futbolistas sin usar igualdad, utilizando pattern matching.
contar_futbolistas :: [Deportista] -> Zona -> Int
contar_futbolistas [] z = 0
contar_futbolistas (Futbolista zona _ _ _:xs) z | (zona == z) = 1 + contar_futbolistas' xs z
contar_futbolistas (_:xs) z = contar_futbolistas xs z
-- contar_futbolistas [Futbolista(Arco)(1)(Izquierda)(179), Velocista(182)] Arco = 1
-- contar_futbolistas [Ciclista(Pista), Futbolista(Delantera)(8)(Derecha)(169)] Defensa = 0


-- 4e) ¿La funcion anterior usa filter? Si no es asi, reprogramala para usarla.
contar_futbolistas' :: [Deportista] -> Zona -> Int
contar_futbolistas' xs z = length (filter misma_zona xs)
    where
        misma_zona (Futbolista zona _ _ _) = (zona == z)
        misma_zona _ = False
-- contar_futbolistas' [Futbolista(Defensa)(11)(Derecha)(166), Futbolista(Defensa)(15)(Derecha)(171)] Defensa = 2
-- contar_futbolistas' [Futbolista(Arco)(2)(Derecha)(177), Futbolista(Delantera)(13)(Derecha)(170)] Arco = 1


-- 5a) Implementa la funcion sonidoNatural como esta definida arriba.
sonidoNatural :: NotaBasica -> Int
sonidoNatural Do  = 0
sonidoNatural Re  = 2
sonidoNatural Mi  = 4
sonidoNatural Fa  = 5
sonidoNatural Sol = 7
sonidoNatural La  = 9
sonidoNatural Si  = 11


-- 5b) Definir el tipo enumerado Alteracion que consta de los constructores Bemol, Natural y Sostenido.
data Alteracion = Bemol | Natural | Sostenido

-- 5c) Definir el tipo NotaMusical que consta de un unico constructor que toma dos parametros. El primer parametro es de tipo NotaBasica y el segundo de tipo Alteracion. De esta manera cuando se quiera representar una nota alterada se puede usar como segundo parametro del constructor un Bemol o Sostenido y si se quiere representar una nota sin alteraciones se usa Natural como segundo parametro.
data NotaMusical = Nota NotaBasica Alteracion


-- 5d) Defini la funcion sonidoCromatico :: NotaMusical -> Int que devuelve el sonido de una nota, incrementando en uno su valor si tiene la alteracion Sostenido, decrementando en uno si tiene la alteracion Bemol y dejando su valor intacto si la alteracion es Natural.
sonidoCromatico :: NotaMusical -> Int
sonidoCromatico (Nota nb Sostenido) = (sonidoNatural nb) + 1
sonidoCromatico (Nota nb Bemol)     = (sonidoNatural nb) - 1
sonidoCromatico (Nota nb Natural)   = (sonidoNatural nb)
-- sonidoCromatico (Nota Fa Sostenido) = 6
-- sonidoCromatico (Nota La Bemol) = 8


-- 5e) Inclui el tipo NotaMusical a la clase Eq de manera tal que dos notas que tengan el mismo valor de sonidoCromatico se consideren iguales.
instance Eq NotaMusical
    where
        nb1 == nb2 = sonidoCromatico(nb1) == sonidoCromatico(nb2)
-- Nota(Sol)(Sostenido) == Nota(La)(Bemol) = True
-- Nota(Re)(Natural) == Nota(Do)(Sostenido) = False


-- 5f) Inclui el tipo NotaMusical a la clase Ord definiendo el operador <=. Se debe definir que una nota es menor o igual a otra si y solo si el valor de sonidoCromatico para la primera es menor o igual al valor de sonidoCromatico para la segunda.
instance Ord NotaMusical
    where
        nb1 <= nb2 = sonidoCromatico(nb1) <= sonidoCromatico(nb2)
-- Nota(Fa)(Bemol) <= Nota(Si)(Sostenido) = True
-- Nota(Sol)(Sostenido) <= Nota(Mi)(Natural) = False


-- 6a) Definir la funcion primerElemento que devuelve el primer elemento de una lista no vacia, o Nothing si la lista es vacia.
primerElemento :: [a] -> Maybe a
primerElemento [] = Nothing
primerElemento xs = Just (head xs)
-- primerElemento [] = Nothing
-- primerElemento [5,19,13] = Just 5


-- 7a) Programa las siguientes funciones:
-- 7a1) atender :: Cola -> Maybe Cola, que elimina de la cola a la persona que esta en la primer posicion de una cola, por haber sido atendida. Si la cola esta vacia, devuelve Nothing.
data Cola = VaciaC | Encolada Deportista Cola deriving Show

atenderEj1 :: Cola
atenderEj1 = Encolada (Velocista 181) (Encolada (Ciclista BMX) VaciaC)
atenderEj2 :: Cola
atenderEj2 = Encolada Ajedrecista (Encolada (Tenista UnaMano Derecha 174) VaciaC)

atender :: Cola -> Maybe Cola
atender VaciaC = Nothing
atender (Encolada dep cola) = Just cola
-- atender atenderEj1 = Just (Encolada (Ciclista BMX) VaciaC)
-- atender atenderEj2 = just (Encolada (Tenista UnaMano Derecha 174) VaciaC)


-- 7a2) encolar :: Deportista -> Cola -> Cola, que agrega una persona a una cola de deportistas, en la ultima posicion.
encolarEj1 :: Cola
encolarEj1 = Encolada (Ciclista Pista) VaciaC
encolarEj2 :: Cola
encolarEj2 = Encolada (Velocista 168) VaciaC

encolar :: Deportista -> Cola -> Cola
encolar nuevoDep VaciaC = (Encolada nuevoDep VaciaC)
encolar nuevoDep (Encolada dep cola) = Encolada dep (encolar nuevoDep cola)
-- encolar Ajedrecista encolarEj1 = Encolada (Ciclista Pista) (Encolada Ajedrecista VaciaC)
-- encolar (Ciclista Monte) encolarEj2 = Encolada (Velocista 168) (Encolada (Ciclista Monte) VaciaC)


-- 7a3) busca :: Cola -> Zona -> Maybe Deportista, que devuelve el/la primera futbolista dentro de la cola que juega en la zona que se corresponde con el segundo parametro. Si no hay futbolistas jugando en esa zona devuelve Nothing.
buscaEj1 :: Cola
buscaEj1 = Encolada (Futbolista Delantera 21 Derecha 173) VaciaC
 
busca :: Cola -> Zona -> Maybe Deportista
busca VaciaC z = Nothing
busca (Encolada (Futbolista zona n p a) cola) z | (z == zona) = Just (Futbolista zona n p a)
                                                | otherwise = busca cola z
busca _ _ = Nothing
-- busca buscaEj1 Mediocampo = Nothing
-- busca buscaEj1 Delantera = Just (Futbolista Delantera 21 Derecha 173)


-- 7b) ¿A que otro tipo se parece Cola?.
-- Se parece a una lista, ya que posee un elemento vacio y un constructor.


-- 8a) ¿Como se debe instanciar el tipo ListaAsoc para representar la informacion almacenada en una guia telefonica?.
data ListaAsoc a b = Vacia | Nodo a b (ListaAsoc a b) deriving Show
type Diccionario = ListaAsoc String String
type Padron = ListaAsoc Int String
type GuiaTelefonica = ListaAsoc String Int


-- 8b) Programa las siguientes funciones:
-- 8b1) la_long :: ListaAsoc a b -> Int que devuelve la cantidad de datos en una lista.
listaAsocEj1 :: ListaAsoc(Int)(Int)
listaAsocEj1 = Nodo 1 10 (Nodo 2 20 Vacia)
listaAsocEj2 :: ListaAsoc(Char)(Int)
listaAsocEj2 = Nodo 'A' 6 (Nodo 'B' 7 (Nodo 'C' 8 Vacia))

la_long :: ListaAsoc a b -> Int
la_long Vacia = 0
la_long (Nodo a b (xs)) = 1 + la_long(xs)
-- la_long listaAsocEj1 = 2
-- la_long listaAsocEj2 = 3


-- 8b2) la_concat :: ListaAsoc a b -> ListaAsoc a b -> ListaAsoc a b, que devuelve la concatenacion de dos listas de asociaciones.
listaAsocEj3 :: ListaAsoc(Char)(Int)
listaAsocEj3 = Nodo 'A' 1 (Nodo 'B' 2 Vacia)
listaAsocEj4 :: ListaAsoc(Char)(Int)
listaAsocEj4 = Nodo 'C' 3 (Nodo 'D' 4 Vacia)

la_concat :: ListaAsoc a b -> ListaAsoc a b -> ListaAsoc a b
la_concat xs Vacia = xs
la_concat Vacia ys = ys
la_concat (Nodo a b xs) ys = (Nodo a b(la_concat xs ys))
-- la_concat listaAsocEj3 listaAsocEj4 = Nodo 'A' 1 (Nodo 'B' 2 (Nodo 'C' 3 (Nodo 'D' 4 Vacia)))
-- la_concat listaAsocEj4 listaAsocEj3 = Nodo 'C' 3 (Nodo 'D' 4 (Nodo 'A' 1 (Nodo 'B' 2 Vacia)))


-- 8b3) la_agregar :: Eq a => ListaAsoc a b -> a -> b -> ListaAsoc a b, que agrega un nodo a la lista de asociaciones si la clave no esta en la lista, o actualiza el valor si la clave ya se encontraba.
listaAsocEj5 :: ListaAsoc(String)(Int)
listaAsocEj5 = Nodo "ID1" 123 (Nodo "ID2" 456 Vacia)

la_agregar :: Eq a => ListaAsoc a b -> a -> b -> ListaAsoc a b
la_agregar Vacia clave dato = Nodo clave dato Vacia
la_agregar (Nodo a b xs) clave dato | (a == clave) = Nodo a dato xs
                                    | otherwise  = Nodo a b (la_agregar xs clave dato)
-- la_agregar listaAsocEj5 "ID3" 789 = Nodo "ID1" 123 (Nodo "ID2" 456 (Nodo "ID3" 789 Vacia))
-- la_agregar listaAsocEj5 "ID2" 789 = Nodo "ID1" 123 (Nodo "ID2" 789 Vacia)
-- la_agregar listaAsocEj5 "ID1" 789 = Nodo "ID1" 789 (Nodo "ID2" 456 Vacia)


-- 8b4) la_pares :: ListaAsoc a b -> [(a, b)] que transforma una lista de asociaciones en una lista de pares clave-dato.
la_pares :: ListaAsoc a b -> [(a, b)]
la_pares Vacia = []
la_pares (Nodo a b xs) = (a, b):la_pares xs
-- la_pares listaAsocEj1 = [(1,10),(2,20)]
-- la_pares listaAsocEj5 = [("ID1",123),("ID2",456)]


-- 8b5) la_busca :: Eq a => ListaAsoc a b -> a -> Maybe b que dada una lista y una clave devuelve el dato asociado, si es que existe. En caso contrario devuelve Nothing.
la_busca :: Eq a => ListaAsoc a b -> a -> Maybe b
la_busca Vacia clave = Nothing
la_busca (Nodo a b xs) clave | (a == clave) = Just b
                             | otherwise  = la_busca xs clave
-- la_busca listaAsocEj3 'C' = Nothing
-- la_busca listaAsocEj4 'C' = Just 3


-- 8b6) la_borrar :: Eq a => a -> ListaAsoc a b -> ListaAsoc a b que dada una clave a elimina la entrada en la lista.
la_borrar :: Eq a => a -> ListaAsoc a b -> ListaAsoc a b
la_borrar clave Vacia = Vacia
la_borrar clave (Nodo a b xs) | (a == clave) = xs
                              | otherwise  = Nodo a b (la_borrar clave xs)
-- la_borrar 'A' listaAsocEj2 = Nodo 'B' 7 (Nodo 'C' 8 Vacia)
-- la_borrar 'D' listaAsocEj2 = Nodo 'A' 6 (Nodo 'B' 7 (Nodo 'C' 8 Vacia))


-- 9(*) Programa las siguientes funciones:
data Arbol a = Hoja | Rama (Arbol a) a (Arbol a) deriving (Eq, Show)


-- 9a) a_long :: Arbol a -> Int que dado un arbol devuelve la cantidad de datos almacenados.
arbolEj1 :: Arbol(Int)
arbolEj1 = Rama (Rama (Hoja) 1 (Hoja)) 2 (Rama (Hoja) 3 (Hoja))
arbolEj2 :: Arbol(Char)
arbolEj2 = Rama (Rama (Rama (Hoja) 'A' (Hoja)) 'B' (Rama (Hoja) 'C' (Hoja))) 'D' Hoja

a_long :: Arbol a -> Int
a_long Hoja = 0
a_long (Rama ar1 _ ar2) = 1 + a_long ar1 + a_long ar2
-- a_long arbolEj1 = 3
-- a_long arbolEj2 = 4


-- 9b) a_hojas :: Arbol a -> Int que dado un arbol devuelve la cantidad de hojas.
a_hojas :: Arbol a -> Int
a_hojas Hoja = 1
a_hojas (Rama ar1 _ ar2) = a_hojas ar1 + a_hojas ar2
-- a_hojas arbolEj1 = 4
-- a_hojas arbolEj2 = 5


-- 9c) a_inc :: Num a => Arbol a -> Arbol a que dado un arbol que contiene numeros, los incrementa en uno.
arbolEj3 :: Arbol(Int)
arbolEj3 = Rama (Rama (Hoja) (-1) (Hoja)) 0 Hoja

a_inc :: Num a => Arbol a -> Arbol a
a_inc Hoja = Hoja
a_inc (Rama ar1 n ar2) = Rama (a_inc ar1) (n+1) (a_inc ar2)
-- a_inc arbolEj1 = Rama (Rama Hoja 2 Hoja) 3 (Rama Hoja 4 Hoja)
-- a_inc arbolEj3 = Rama (Rama Hoja 0 Hoja) 1 Hoja


-- 9d) d) a_map :: (a -> b) -> Arbol a -> Arbol b que dada una funcion y un arbol, devuelve el arbol con la misma estructura, que resulta de aplicar la funcion a cada uno de los elementos del arbol. Revisa la definicion de la funcion anterior y reprogramala usando a_map.
a_map :: (a -> b) -> Arbol a -> Arbol b
a_map f Hoja = Hoja
a_map f (Rama ar1 n ar2) = Rama (a_map f ar1) (f n) (a_map f ar2)
-- a_map (*12) arbolEj1 = Rama (Rama Hoja 12 Hoja) 24 (Rama Hoja 36 Hoja)
-- a_map (+13) arbolEj3 = Rama (Rama Hoja 12 Hoja) 13 Hoja

a_inc' :: Num a => Arbol a -> Arbol a
a_inc' Hoja = Hoja
a_inc' (Rama ar1 n ar2) = a_map (+1) (Rama ar1 n ar2)
-- a_inc' arbolEj1 = Rama (Rama Hoja 2 Hoja) 3 (Rama Hoja 4 Hoja)
-- a_inc' arbolEj3 = Rama (Rama Hoja 0 Hoja) 1 Hoja


-- 10(*) Programa las siguientes funciones:
-- 10a) Definir el tipo recursivo ABB utilizando los constructores:
data ABB a = VacioABB | RamaABB (ABB a) a (ABB a) deriving (Show)


-- 10b) Definir una funcion insertarABB que tome un valor y un arbol binario como entrada y devuelva un nuevo arbol que contenga el valor insertado en el arbol original. La funcion tiene que tener el siguiente tipado: insertarABB::Ord a=>a->ABB a->ABB a.
insertarABB :: Ord a => a -> ABB a -> ABB a
insertarABB n VacioABB = RamaABB VacioABB n VacioABB
insertarABB n (RamaABB ramaIzq x ramaDer) | (n <= x) = RamaABB (insertarABB n ramaIzq) x ramaDer
                                          | otherwise = RamaABB ramaIzq x (insertarABB n ramaDer)
-- insertarABB 3 (RamaABB VacioABB 4 (RamaABB VacioABB 6 VacioABB)) = RamaABB (RamaABB VacioABB 3 VacioABB) 4 (RamaABB VacioABB 6 VacioABB)
-- insertarABB 5 (RamaABB (RamaABB VacioABB 3 VacioABB) 4 VacioABB) = RamaABB (RamaABB VacioABB 3 VacioABB) 4 (RamaABB VacioABB 5 VacioABB)


-- 10c) Define una funcion llamada buscarEnArbol que tome un valor y un arbol binario como entrada y devuelva True si el valor esta presente en el arbol y False en caso contrario. La funcion tiene que tener el siguiente tipado: buscarABB::Eq a=>a->ABB a->Bool.
buscarEnArbol :: Eq a => a -> ABB a -> Bool
buscarEnArbol n VacioABB = False
buscarEnArbol n (RamaABB ramaIzq x ramaDer) | (n == x) = True
                                            | otherwise = buscarEnArbol n ramaIzq || buscarEnArbol n ramaDer
-- buscarEnArbol 4 (RamaABB VacioABB 5 (RamaABB VacioABB 7 (RamaABB (RamaABB VacioABB 9 VacioABB) 8 VacioABB))) = False
-- buscarEnArbol 9 (RamaABB VacioABB 5 (RamaABB VacioABB 7 (RamaABB (RamaABB VacioABB 9 VacioABB) 8 VacioABB))) = True


-- 10d) Definir la funcion verificarABB que devuelve True si el arbol cumple con la propiedad fundamental o False en caso contrario.
mayor_a_todos :: Ord a => a -> ABB a -> Bool
mayor_a_todos n VacioABB = True
mayor_a_todos n (RamaABB ramaIzq x ramaDer) | (n > x) = mayor_a_todos n ramaIzq && mayor_a_todos n ramaDer
                                            | otherwise = False 

menor_a_todos :: Ord a => a -> ABB a -> Bool
menor_a_todos n VacioABB = True
menor_a_todos n (RamaABB ramaIzq x ramaDer) | (n < x) = menor_a_todos n ramaIzq && menor_a_todos n ramaDer
                                            | otherwise = False 

verificarABB :: Ord a => ABB a -> Bool
verificarABB VacioABB = True
verificarABB (RamaABB ramaIzq n ramaDer) = (mayor_a_todos n ramaIzq) && (menor_a_todos n ramaDer)

ejemplo1 = RamaABB (RamaABB VacioABB 10 VacioABB) 2 (RamaABB VacioABB 11 VacioABB)
ejemplo2 = RamaABB (RamaABB (RamaABB VacioABB 1 VacioABB) 3 (RamaABB VacioABB 7 VacioABB)) 5 (RamaABB VacioABB 8 (RamaABB VacioABB 10 VacioABB))
-- verificarABB ejemplo1 = False
-- verificarABB ejemplo2 = False
