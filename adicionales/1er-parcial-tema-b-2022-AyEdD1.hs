-- 1a)
type Titulo = String 
type Artista = String
type Duracion = Int
data Genero = Rock | Blues | Pop | Jazz
data Cancion = Tema Titulo Artista Genero Duracion
             | Publicidad Duracion

-- 1b)
mismo_genero :: Genero -> Genero -> Bool
mismo_genero Rock Rock   = True
mismo_genero Blues Blues = True
mismo_genero Pop Pop     = True
mismo_genero Jazz Jazz   = True
mismo_genero (_)(_) = False

-- 1c)
cancionEj1 :: Cancion
cancionEj1 = Tema("Titulo")("Artista")(Jazz)(150)

cancionEj2 :: Cancion
cancionEj2 = Publicidad(25)

duracion_de :: Cancion -> Duracion
duracion_de (Tema _ _ _ d) = d
duracion_de (Publicidad d) = d
-- duracion_de cancionEj1 = 150
-- duracion_de cancionEj2 = 25

-- 1d)
instance Eq Cancion
    where
        c1 == c2 = duracion_de c1 == duracion_de c2

instance Ord Cancion
    where
        c1 <= c2 = duracion_de c1 <= duracion_de c2


-- 2a)
listaDeCancionesEj :: [Cancion]
listaDeCancionesEj = [Tema("ASD")("A")(Rock)(120), Tema("FGH")("B")(Blues)(90), Publicidad(25)]

solo_genero :: [Cancion] -> Genero -> [Titulo]
solo_genero [] _ = []
solo_genero (Publicidad(_):cs) g = solo_genero cs g
solo_genero ((Tema(ti)(_)(gi)(_)):cs) g | (mismo_genero gi g) = ti : solo_genero cs g
                                        | otherwise = solo_genero cs g
-- solo_genero listaDeCancionesEj Rock = ["ASD"]
-- solo_genero listaDeCancionesEj Blues = ["FGH"]
-- solo_genero listaDeCancionesEj Pop = []


-- 3)
data ListaAsoc a b = Vacia | Nodo a b (ListaAsoc a b) deriving Show

listaAsocEj :: ListaAsoc(Char)(Int)
listaAsocEj = Nodo 'A' 12 (Nodo 'B' 7 (Nodo 'C' 4 (Nodo 'D' 17 Vacia)))

la_suma_mayores :: (Num b, Ord b) => ListaAsoc a b -> b -> b
la_suma_mayores Vacia x = 0
la_suma_mayores (Nodo a b la) x | (b>x) = b + la_suma_mayores la x
                                | otherwise = la_suma_mayores la x
-- la_suma_mayores listaAsocEj 10 = 29
-- la_suma_mayores listaAsocEj 6  = 36
-- la_suma_mayores listaAsocEj 3  = 40


-- 4a)
data Arbol a = Hoja | Rama (Arbol a) a (Arbol a) deriving Show

a_listar :: Arbol a -> [a]
a_listar Hoja = []
a_listar (Rama as d as1) = d : (a_listar as) ++ (a_listar as1)

-- 4b)
arbolEj1 :: Arbol(Int)
arbolEj1 = Rama (Rama Hoja 1 Hoja) 3 (Rama Hoja 2 Hoja)
-- a_listar arbolEj1 = [3,1,2]

-- 4c)
{-
a_listar arbolEj1 = 3 : (a_listar (Rama Hoja 1 Hoja)) ++ (a_listar (Rama Hoja 2 Hoja))
                  = 3 : (1:[]) ++ (2:[])
                  = 3 : [1,2]
                  = [3,1,2]
-}  