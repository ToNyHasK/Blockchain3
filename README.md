# Blockchain3

## Įdiegimas (Unix kompiuteryje) 

- `git clone https://github.com/ToNyHasK/Blockchain3.git`
- `cd Blockchainę`

## Užduoties formuluotė
https://github.com/blockchain-group/Blockchain-technologijos/blob/master/pratybos/2uzduotis-Blockchain.md

Pirminė užduotis:
* sugeneruoti ~1000 tinklo vartotojų (vardas, public_key, valiutos balansas (100-1000000)
* sugeneruoti transkacijų pol'ą sudarytą iš 10000 atsitiktinių transakcijų tarp visų vartotojų, kurių metu jie vienas kitam atlikinėtų pinigų pervedimus
* iš šių transakcijų atsitiktinai pasirinkti 100-ą ir jas priskirti naujam sugeneruotam blokui
* realizuoti mining Proof-of-Work (PoW) procesą, kurio tikslas yra surasti naujam blokui hash'ą, tenkinantį Difficulty Targer reikalavimą, t.y., hash'o pradžioje esančių nulių skaičių
* suradus tokį naujo bloko hash'ą, bloką pridėti prie grandinės
* kartoti tol, kol yra laisvų transakcijų

### Užduotis v.01

### [v0.1](https://github.com/ToNyHasK/Blockchain3/releases/tag/v0.1) - (2019-01-07)

* Blockchain struktūra, blokų mininimas
* Nėra tranksakcijų
* Nėra user'ių

### TODO:

# Užduotis v0.2

* Patobulintas blokų kasimas
* Transakcijos
* Patikrinamas balansas
* Perdaryta struktūra
* Transakcijų tikrinimas

# Užduoties v0.3

* Merkel funkcija