--1a
type Ejes = Int
type Altura = Float
type Peso = Int

data Auto = SoloA | ConTrailer Ejes Altura deriving (Show)

data Rodado = Moto 
            | Automovil Auto
            | Bus Ejes Altura
            | Camion Ejes Altura Peso deriving (Show) 


--1b
cantidadDeEjes :: Rodado -> Int
cantidadDeEjes Moto = 0
cantidadDeEjes (Automovil SoloA) = 2
cantidadDeEjes (Automovil (ConTrailer e a)) = e
cantidadDeEjes (Bus e a) = e
cantidadDeEjes (Camion e a p) = e

instance Eq Rodado
    where 
        ro1 == ro2 = cantidadDeEjes ro1 == cantidadDeEjes ro2

{-
ghci> cantidadDeEjes(Camion 1 2.2 3) == cantidadDeEjes(Bus 2 2.2)
False

ghci> cantidadDeEjes(Automovil SoloA) == cantidadDeEjes(Automovil(ConTrailer 2 1.8))
True
-}


--1c
autosConTrailer :: [Rodado] -> Altura -> [Rodado]
autosConTrailer [] a = []
autosConTrailer (Automovil(ConTrailer e a):lr) al | a > al = Automovil(ConTrailer e a) : autosConTrailer lr al
                                                 | otherwise = autosConTrailer lr al
autosConTrailer (_:lr) al = autosConTrailer lr al

ej1 :: [Rodado]
ej1 = [Automovil(ConTrailer 4 2), Automovil(ConTrailer 3 4), Automovil(ConTrailer 2 3)]

{-
ghci> autosConTrailer ej1 2.4
[Automovil(ConTrailer 3 4.0), Automovil(ConTrailer 2 3.0)]

ghci> autosConTrailer ej1 4
[]
-}


--1d
dosIguales :: [Rodado] -> Bool
dosIguales [] = False
dosIguales [r] = False
dosIguales(r1:r2:lr) = (r1 == r2) || dosIguales(r2 : lr)

ej2 :: [Rodado]
ej2 = [Bus 3 5, Bus 4 6, Bus 3 5]

ej3 :: [Rodado]
ej3 = [Bus 3 5, Bus 3 5, Bus 4 6]

{-
ghci> dosIguales ej2
False

ghci> dosIguales ej3
True
-}