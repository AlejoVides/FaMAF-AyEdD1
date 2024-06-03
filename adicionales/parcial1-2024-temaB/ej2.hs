--2a
type Ciudad = String
type Distancia = Int

data Tramo = DefinicionDelTramo Ciudad Ciudad Distancia deriving Show
data Viaje = Unico Tramo | ConEscala Tramo Viaje deriving Show


--2b
tramoPasaPor :: Tramo -> Ciudad -> Bool
tramoPasaPor (DefinicionDelTramo c1 c2 d) c = (c1==c)||(c2==c)

viajePasaPor :: Viaje -> Ciudad -> Bool
viajePasaPor (Unico t) c = tramoPasaPor t c
viajePasaPor (ConEscala t v) c = tramoPasaPor t c || viajePasaPor v c

{-
ghci> viajePasaPor (Unico(DefinicionDelTramo("Argentina")("Brazil")(12))) "Argentina"
True

ghci> viajePasaPor (Unico(DefinicionDelTramo("Argentina")("Brazil")(12))) "Chile"
False
-}


--2c
distanciaDeTramo :: Tramo -> Distancia
distanciaDeTramo (DefinicionDelTramo c1 c2 d) = d

tramoMasLargo :: Viaje -> Tramo
tramoMasLargo (Unico t) = t
tramoMasLargo (ConEscala t v) | distanciaDeTramo t > distanciaDeTramo(tramoMasLargo v) = t
                              | otherwise = tramoMasLargo v


--2d
instance Eq Tramo
    where
        DefinicionDelTramo c1 c2 _ == DefinicionDelTramo c3 c4 _ = ((c1 == c3) && (c2 == c4)) || ((c1 == c4) && (c2 == c3))

{-
ghci> DefinicionDelTramo "Argentina" "Chile" == DefinicionDelTramo "Argentina" "Brazil"
False

ghci> DefinicionDelTramo "Argentina" "Brazil" == DefinicionDelTramo "Brazil" "Argentina"
True
-}