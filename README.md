# MyOctaveSimulator
Copyright Dima Cosmin-Alexandru 314CA 2022-2023

███╗░░░███╗██╗░░░██╗  ░█████╗░░█████╗░████████╗░█████╗░██╗░░░██╗███████╗
████╗░████║╚██╗░██╔╝  ██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗██║░░░██║██╔════╝
██╔████╔██║░╚████╔╝░  ██║░░██║██║░░╚═╝░░░██║░░░███████║╚██╗░██╔╝█████╗░░
██║╚██╔╝██║░░╚██╔╝░░  ██║░░██║██║░░██╗░░░██║░░░██╔══██║░╚████╔╝░██╔══╝░░
██║░╚═╝░██║░░░██║░░░  ╚█████╔╝╚█████╔╝░░░██║░░░██║░░██║░░╚██╔╝░░███████╗
╚═╝░░░░░╚═╝░░░╚═╝░░░  ░╚════╝░░╚════╝░░░░╚═╝░░░╚═╝░░╚═╝░░░╚═╝░░░╚══════╝

Programul de fata utilizeaza limbajul de programare C pentru a efectua calcule
cu matrice alocate dinamic.
Programul are functii precum : incarcare de matrice in memorie, inmultire,
ridicare la putere, transpunere, elberare din memorie, sortare dupa suma
elementelor, afisare elemente, redimensionare, afisare dimensiuni, eliberarea
memoriei folosite de intreg programul.

------------------------INCARCARE MATRICE IN MEMORIE--------------------------

La citirea literei L urmata de nr de linii si coloane ale matricii ce urmeaza
sa fie introdusa, programul aloca dinamica o matrice 3D iar apoi in aceasta
aloca o alta matrice 2D cu elemente introduse de la tastatura. Se calculeaza
suma elementelor din matrice si se stocheaza intr-un vector alocat dinamic.
Dimensiunile matricei sunt stocate intr-o matrice 2D ce are 2 coloane si n
linii, linii care vor fi alocate dinamic. Marimea vectorului de sume si a
matricii de dimensiuni creste la fiecare noua matrice citita. Cu fiecare
matrice introdusa creste si variabila matrix_count care tine evidenta
numarului de matrice introduse.

------------------DETERMINAREA DIMENSIUNILOR UNEI MATRICE---------------------

Se citeste litera D de la tastatura urmata de indexul matricii ale carei
dimensiuni se va afisa pe ecran. Afisez dimensiunile stocate in matricea
de dimensiuni.

----------------------------AFISAREA UNEI MATRICE-----------------------------

Se citeste litera P de la tastatura urmata de indexul matricii care urmeaza
sa fie afisata. Afisarea se face cu ajutorul dimensiunilor stocate in matricea
de dimensiuni.

--------------------------REDIMENSIONAREA UNEI MATRICE------------------------

Se citeste de la tastatura litera C urmata de n linii dupa care se va face
redimensionarea, apoi cele n linii. Acelasi lucru se va face pentru coloane.
Se citeste m si apoi m coloane dupa care se face redimensinarea.
Stochez coloanele si liniile in doi vectori alocati dinamic iar apoi aloc
dinamic o matrice auxiliara de dimensiunile n * m. In aceasta matrice
voi pune toate elementele care vor ramane in noua matrice parcurgand vechea
matrice. La final aloc in matricea originala spatiul necesar pentru
redimensionare si apoi introduc valorile. In final golesc vectorul in care
am stocat indexul liniilor si coloanelor. Suma matricei rezultate se va adauga
in locul sumei matricii originale in vectorul de sume.

----------------------------INMULTIREA A DOUA MATRICE-------------------------

Citesc de la tastatura litera M si doua numere ce reprezinta indexul
matricelor pe care le voi inmulti. Daca indexul este valid si inmultirea intre
cele doua matrici este posibila voi inmulti matricile iar matricea rezultat o
voi adauga la finalul listei de matrici. Cresc astfel variabila matrix_count
si fac spatiu la finalul listei pentru inca o matrice de dimensiunile
rezultate dupa inmultire. Adaug si suma acestei matrici in vectorul de sume si
dimensiunea in matricea ce tine evidenta dimensiunilor.

-----------------------------SORTAREA MATRICELOR------------------------------

La citirea literei O de la tastatura matricele din matricea 3D se vor ordona
crescator dupa suma elementelor mod 10007. Folosesc sortarea prin
interschimbare pentru a schimba matricele intre ele, valorile din matricea de
dimensiuni si valorile din vectorul de sume pentru ca fiecare matrice sa aiba
in continuare suma si dimensiunea stocata corect.

--------------------------TRANSPUNEREA MATRICELOR-----------------------------

Citesc litera T de la tastatura urmata de indexul matricii pe care o transpun
iar apoi aloc dinamic o matrice auxiliara in care voi pune elementele din
matricea transpusa. Dupa ce am transpus matricea in matricea auxiliara,
eliberez spatiul din matricea originala dupa care il aloc din nou cu noile
dimensiuni (se interschimba numarul de linii cu numarul de coloane). Schimb si
in matricea de dimensiuni nr de linii cu nr de coloane. La final eliberez
memoria folosita de matricea auxiliara.

---------------------RIDICAREA LA PUTERE IN TIMP LOGARITMIC-------------------

Pentru ridicarea la putere am alocat dinamic trei matrici auxiliare dintre
care una este matricea identitate. Ridicarea la putere in timp logaritmic
se face prin folosirea ridicarilor la putere pe care deja le-am facut daca
puterea este para, de aceea puterea se imparte la 2 dupa fiecare iteratie.
In cazul in care puterea este impara se face o inmultire intre rezultatul
curent si matricea initiala. La finalul acestei operatii copiez matricea
rezultata in interiorul matricii initiale fara a schimba dimensiunile pt ca
acestea sunt asemanatoare. Dupa acest pas calculez din nou si schimb suma
elementelor din matrice in vectorul de sume si dezaloc spatiul folosit de
cele 3 matrice auxiliare.

---------------------ELIBERAREA DIN MEMORIE A UNEI MATRICE--------------------

Pentru aceasta operatie copiez toate matricele cu un index inapoi incepand de
la indexul unde se face eliminarea matricei si totodata mut cu un index inapoi
si elementele din vectorul de sume si din matricea de dimensiuni. La final
scad numarul de matrici, si realoc spatiul pentru matricea 3D, vectorul de
sume si matricea de dimensiuni astfel incat sa fie cu o marime mai mica.

-------------------------------ELIBERAREA MEMORIEI----------------------------

La citirea literei Q, toata memoria utilizata de program va fi stearsa
complet din memoria HEAP. Programul se va finaliza dupa inchiderea while-ului.

-------------------------------------IN PLUS----------------------------------

Daca se citeste o comanda invalida se va afisa mesajul corespunzator.
In cazul in care se citeste un numar dupa o comanda valida care este invalid,
(ex. putere negativa, index invalid) se afiseaza mesajul corespunzator si
se reia while-ul.
