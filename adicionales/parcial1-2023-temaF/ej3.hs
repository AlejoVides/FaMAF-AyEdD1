type Titulo = String
type Rank = Int
type Duracion = Int
data Estado = Reproducido | SinReproducir deriving (Show)

data PlayList = Tema Titulo Rank Duracion Estado PlayList | SinTemas deriving (Show)

segundosRestantes :: PlayList -> Rank -> Duracion
segundosRestantes SinTemas r = 0
segundosRestantes (Tema _ r0 d Reproducido pls) r1 = segundosRestantes pls r1
segundosRestantes (Tema _ r0 d SinReproducir pls) r1 | r0>=r1 = d + segundosRestantes pls r1 
                                                     | otherwise = segundosRestantes pls r1

estadoDelTema :: Titulo -> PlayList -> Maybe Estado
estadoDelTema _ SinTemas = Nothing
estadoDelTema t0 (Tema t1 _ _ e pls) | t0 == t1 = Just e
                                     | otherwise = estadoDelTema t0 pls