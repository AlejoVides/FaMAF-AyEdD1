data MarcaMicro = Intel | AMD deriving (Show)
data Nucleos = DualCore | QuadCore | HexaCore | OctaCore deriving (Show)
type MaxFrec = Float

data MarcaRAM = Kingston | Markvision | Patriot deriving (Show)
type Gigas = Int

data MarcaPMadre =  Asus | Asrock | MSI deriving (Show)
data Chipset = A630 | B650 | B660 | B760 deriving (Show)

data ComponentesPC = Micro MarcaMicro Nucleos MaxFrec | RAM MarcaRAM Gigas | PlacaMadre MarcaPMadre Chipset deriving (Show)

cuantosMicros :: [ComponentesPC] -> MarcaMicro -> Int
cuantosMicros [] _ = 0
cuantosMicros ((Micro Intel _ _ ):cs) Intel = 1 + cuantosMicros cs Intel
cuantosMicros ((Micro AMD _ _ ):cs) AMD = 1 + cuantosMicros cs AMD
cuantosMicros (_:cs) x = cuantosMicros cs x

--2.c

mismosNucleos :: Nucleos -> Nucleos -> Bool
mismosNucleos DualCore DualCore = True
mismosNucleos QuadCore QuadCore = True
mismosNucleos HexaCore HexaCore = True
mismosNucleos OctaCore OctaCore = True
mismosNucleos _ _ = False

mismoChipset :: Chipset -> Chipset -> Bool
mismoChipset A630 A630 = True
mismoChipset B650 B650 = True
mismoChipset B660 B660 = True
mismoChipset B760 B760 = True
mismoChipset _ _ = False

instance Eq ComponentesPC where 
    Micro _ n1 _ == Micro _ n2 _ = mismosNucleos n1 n2
    RAM _ g1 == RAM _ g2 = g1 == g2
    PlacaMadre _ c1 == PlacaMadre _ c2 = mismoChipset c1 c2