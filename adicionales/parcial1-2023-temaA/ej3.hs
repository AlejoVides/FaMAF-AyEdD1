--3a
type Nombre = String
data Estado = Seco | EnFlor | Verde | ConFrutos deriving Show
type Alto = Int
type Diametro = Int
type General = Int
data ArbolesNativos = EvolucionDelArbol Nombre Estado Alto Diametro General ArbolesNativos | NoHayMasArboles deriving Show


--3b
condicionesDeVenta :: Estado -> Alto -> Diametro -> General -> Bool
condicionesDeVenta ConFrutos _ _ _  = True
condicionesDeVenta EnFlor alt dia gen  = (dia >= 7 || alt >= 7) && (gen >= 8)
condicionesDeVenta Verde alt dia gen  = (dia >= 9) && (alt >= 9) && (gen >= 9)

paraVender :: ArbolesNativos -> String -> Bool
paraVender NoHayMasArboles n = False
paraVender (EvolucionDelArbol nom est alt dia gen arbNat) n | n == nom = condicionesDeVenta est alt dia gen || paraVender arbNat n
                                                            | otherwise = paraVender arbNat n

ej1 :: ArbolesNativos
ej1 = EvolucionDelArbol "pepe" ConFrutos 4 5 6 (EvolucionDelArbol "juan" EnFlor 3 6 8 NoHayMasArboles)

{-
ghci> paraVender ej1 "pepe"
True

ghci> paraVender ej1 "juan"
False
-}


--3c
devolverAltura :: ArbolesNativos -> String -> Maybe Int
devolverAltura NoHayMasArboles n = Nothing
devolverAltura (EvolucionDelArbol nom _ alt _ _ arbNat) n | n == nom = Just alt
                                                          | otherwise = devolverAltura arbNat n

ej2 :: ArbolesNativos
ej2 = EvolucionDelArbol "martin" Seco 4 2 1 (EvolucionDelArbol "francisco" ConFrutos 9 9 9 NoHayMasArboles)

{-
ghci> devolverAltura ej2 "martin"
Just 4

ghci> devolverAltura ej2 "francisco"
Just 9

ghci> devolverAltura ej2 "pepe"     
Nothing
-}