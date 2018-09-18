# File reader (finding longest word, counting words, counting words repetition)

PL:

Program czytający plik tekstowy
1. W pliku jest zapisany tekst w języku angielskim (nie ma znaków diakrytycznych, ale są
znaki interpunkcyjne, nawiasy, cudzysłowy itp.).
2. Program czyta zawartość pliku i zapamiętuje wszystkie wyrazy wraz z krotnością ich
powtórzeń.
3. Program tworzy listę (ew. listy) jednokierunkową:
- w wersji A dla każdego nowego wyrazu jest tworzony nowy węzeł,
- w wersji B jest utworzona tablica 26 adresów – „nagłówków” list wyrazów zaczynających
się na kolejne litery alfabetu (26 liter) – w rezultacie powstaje 26 list, każda dla wyrazów
zaczynających się od tej samej litery.
4. W wersji uproszczonej (1) polem struktury węzła jest tablica znakowa.
W wersji rozszerzonej (2) – w strukturze zapisywany jest adres dynamicznie przydzielanej
pamięci, do której wyraz jest kopiowany,
W wersji B możliwe jest dalsze rozszerzenie (3) – można pominąć pamiętanie pierwszej
litery wyrazu.
5. „Na początku” lub „na końcu” wyrazu (ściślej: przed pierwszą lub za ostatnią literą wyrazu)
mogą znaleźć się znaki inne niż litery, np.:.,()” itp. Stąd:
- w wersji (a) wyraz z „doklejonym” znakiem jest traktowany jako inny niż bez
„doklejenia”,
- w wersji (b) ww. przypadki traktowane są jako ten sam wyraz.
Wyrazy połączone znakiem '-' (bez spacji) np. high-level traktujemy jako nowy, pojedynczy
wyraz, niezależnie od tego czy pojawiają się też wyrazy high lub level.
6. Ostatnie rozróżnienie:
- wersja (NS) oznacza, że kolejność wyrazów w liście/listach jest dowolna,
- wersja (S) oznacza, że wyrazy są zapisywane w liście/listach w kolejności alfabetycznej.
Program zawiera funkcję czytającą plik, funkcję obliczającą liczbę wszystkich wyrazów (z
powtórzeniami) i liczbę różnych wyrazów oraz funkcję znajdującą i zwracającą najdłuższy wyraz
(wyprowadzenie wszystkich tych informacji na ekran powinno być zrealizowane w segmencie
głównym - main).
Uwagi:
- Nie należy używać zmiennych zewnętrznych (globalnych) ani tablic VLA – preferowany standard:
C90.
- Proszę racjonalnie podzielić cały program na funkcje (generalnie: w main wywołujemy tylko
kolejne procedury).
- Należy stosować odpowiedni styl (wcięcia, położenia klamer itp.).
- Nazwy zmiennych powinny „podpowiadać” ich znaczenie.
- Na początku pliku z programem źródłowym, w komentarzu piszemy swoje Imię i Nazwisko, datę
i godzinę zajęć, wybraną wersję np. B-1-a-NS (wersje dalsze są wyżej oceniane).
