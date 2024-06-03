--2a
data TipoLadrillo = Ceramico | Hormigon | Tradicional deriving Show
data UsoDeLadrillo = Pared | Techo deriving Show
data MaterialViga = Hierro | Madera deriving Show
data MarcaCemento = Minetti | LomaNegra deriving Show
type Precio = Int
type Largo = Float

data MaterialesConstruccion = Ladrillo TipoLadrillo UsoDeLadrillo Precio
                            | Vigueta Largo MaterialViga Precio
                            | Cemento MarcaCemento Precio deriving Show

ladrillosDeMenorPrecio :: [MaterialesConstruccion] -> Int -> [MaterialesConstruccion]
ladrillosDeMenorPrecio [] n = []
ladrillosDeMenorPrecio ((Ladrillo t u p):lm) n | p <= n = Ladrillo t u p : ladrillosDeMenorPrecio lm n
                                               | otherwise = ladrillosDeMenorPrecio lm n
ladrillosDeMenorPrecio (_:lm) n = ladrillosDeMenorPrecio lm n

{-
ghci> ladrillosDeMenorPrecio [Ladrillo Ceramico Pared 13, Vigueta 1.4 Hierro 6, Cemento Minetti 10] 14
[Ladrillo Ceramico Pared 13]

ghci> ladrillosDeMenorPrecio [Ladrillo Ceramico Pared 13, Vigueta 1.4 Hierro 6, Cemento Minetti 10] 12
[]
-}

--2b
mismoTipoDeLadrillo :: TipoLadrillo -> TipoLadrillo -> Bool
mismoTipoDeLadrillo Ceramico Ceramico = True
mismoTipoDeLadrillo Hormigon Hormigon = True
mismoTipoDeLadrillo Tradicional Tradicional = True
mismoTipoDeLadrillo _ _ = False

mismoMaterialDeVigueta :: MaterialViga -> MaterialViga -> Bool
mismoMaterialDeVigueta Hierro Hierro = True
mismoMaterialDeVigueta Madera Madera = True
mismoMaterialDeVigueta _ _ = False

mismaMarcaDeCemento :: MarcaCemento -> MarcaCemento -> Bool
mismaMarcaDeCemento Minetti Minetti = True
mismaMarcaDeCemento LomaNegra LomaNegra = True
mismaMarcaDeCemento _ _ = False

instance Eq MaterialesConstruccion
    where
        Ladrillo t1 _ p1 == Ladrillo t2 _ p2 = mismoTipoDeLadrillo t1 t2 && p1 == p2
        Vigueta l1 m1 _ == Vigueta l2 m2 _ = mismoMaterialDeVigueta m1 m2 && l1 == l2
        Cemento m1 _ == Cemento m2 _ = mismaMarcaDeCemento m1 m2

{-
ghci> Ladrillo Ceramico Pared 13 == Ladrillo Hormigon Techo 13
False
ghci> Ladrillo Ceramico Pared 13 == Ladrillo Ceramico Techo 16
False
ghci> Ladrillo Ceramico Pared 13 == Ladrillo Ceramico Techo 13  
True

ghci> Vigueta 4.3 Hierro 13 == Vigueta 4.5 Hierro 15
False
ghci> Vigueta 4.3 Hierro 13 == Vigueta 4.3 Madera 15
False
ghci> Vigueta 4.3 Hierro 13 == Vigueta 4.3 Hierro 15
True

ghci> Cemento Minetti 14 == Cemento LomaNegra 15
False
ghci> Cemento Minetti 14 == Cemento Minetti 15  
True
-}