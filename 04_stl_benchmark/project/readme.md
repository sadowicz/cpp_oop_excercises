# STL Benchmarks - Report
---
## 1. Operatory i funkcje haszujące
### Wstęp
W typach użytywanych w projekcie: **Small**, **Medium** oraz **Large**, jedynym polem jakie może zawierać różne dane w różnych instancjach tych struktur jest tablica `data[]`. Z tego powodu to na niej oparta została implementacja operatorów mniejszości i równości, oraz funkcji haszujących.
### A. Operator mniejszości
Poprawny operator mniejszości powinien umożliwiać jednoznaczne rozpoznanie czy instancja danego typu jest mniejsza od innej instancji tego typu. W przypadku struktur zdefiniowanych w projekcie, sprowadza się on do orzeczenia tego, czy tablica `data[]` danej instancji jest 'mniejsza' od tablicy innej instancji.

W strukturze **Small** , `data[]` jest jednoelementową tablicą przechowującą pojedynczy znak typu `char`. Z tego powodu najlepszym sposobem na zaimplementowanie operatora mniejszości, jest zwracanie wyniku porównania wartości `data[0]` obu instancji za pomocą wbudowanego `operator<` dla typu `char`.

W strukturach **Medium** i **Large** tablica `data[]` zawiera więcej elementów. Stwierdzenie mniejszości jednej instancji względem drugiej odbywa się na zasadzie porównania leksykograficznego ich tablic `data[]`. W tym celu użyta została funkcja `std::lexicographical_compare`. Funkcja ta zwraca wynik porównania pierwszej pary różniących się od siebie elementów dwóch zasięgów danych. Wykonuje tym samym maksymalnie *2\*N* porównań, gdzie *N* to liczba elementów krótszego z dwóch zasięgów. Taka sytuacja ma miejsce tylko wtedy, gdy wszystkie elementy w dwóch zasięgach są sobie równe. W innym wypadku funkcja kończy działanie po napotkaniu pierwszej pary różniących się elementów i zwróceniu wyniku ich porównania. Tablice `data[]` w strukturach **Medium** i **Large** są zwykle inicjalizowane na potrzeby benchmarków losowymi wartościami, stąd duże prawdopodobieństwo, że pierwsze różniące się elementy zostaną napotkane po jednym lub kilku porównaniach. Z tego powodu funkcja ta jednoznacznie oraz w optymalny sposób orzeka o mniejszości instancji. 
### B. Operator równości
Poprawny operator równości powinien umożliwiać jednoznaczne rozpoznanie czy dwie instancje tego samego typu mają tę samą wartość.

W przypadku typu **Small**, analogicznie jak w operatorze mniejszości, operator porównania został zaimplementowany poprzez zwracanie wyniku porównania wartości `data[0]` obu instancji za pomocą wbudowanego `operator==` dla typu `char`.

W strukturach **Medium** i **Large** do implementacji operatora równości posłużyła funkcja `std::equal`. Porównuje ona kolejne elementy dwóch zasięgów. W przypadku gdy osiągnęła koniec któregoś z zasięgów zwraca `true`. W sytuacji znalezienia pierwszej pary elementów o różnych wartościach zwraca `false` i kończy działanie. W wariancie pesymistycznym, który ma miejsce gdy wszystkie elementy są równe, wykonanych zostanie maksymalnie *N* porównań elementów, gdzie *N* to długość krótszego zasięgu. W losowo wypełnianych tablicach `data[]` pierwsze różniące się od siebie elementy zostaną zazwyczaj napotkane po co najwyżej kilku porównaniach. Dlatego ta implementacja jest zarówno jednoznaczna jak i optymalna.
### C. Funkcje haszujące
Funkcja haszująca ma za zadanie przyporządkować dowolnie dużym danym, krótką, posiadającą stały rozmiar wartość. Wartości te można później wykorzystywać między innymi w celu zoptymalizowania dostępu w strukturach danych. Ze względu na to zastosowanie, funkcje haszujące wykorzystywane są w tym projekcie - pozwalają na używanie instancji typów **Small**, **Medium** lub **Large** jako kluczy w kontenerze asocjacyjnym `std::unordered_multimap`. 

Zgodnie z zaleceniami dokumentacji, funkcja haszująca powinna zwracać zawsze ten sam hasz dla tej samej wartości. Im prawdopodobieństwo kolizji, czyli przypisania tego samego hasza do różnych wartości, jest mniejsze, tym wydajniejsze jest odwoływanie się do elementów kontenera. W przypadku odpowiednio dobrze skonstruowanej funkcji haszującej, dostęp do elementów kontenera może się odbywać ze złożonością *O(1)*.
### D. Implementacja funkcji haszujących
Dla typu **Small** funkcja haszująca opiera się na zwracaniu wyniku `std::hash<char>{}(data[0])`. Zwracanie hasza do elementu `data[0]` jest wystarczające, gdyż jest to jedyny element na podstawie którego można rozróżnić instancje struktury **Small**. Zastosowanie powyższej funkcjonalności zapewnia bezkolizyjność, oraz jest proste w użyciu.

W typach **Medium** i **Large** wyliczanie hasza odbywa się poprzez sumowanie iloczynów haszów kolejnych elementów tablicy `data[]` i ich wag. Wagą danego elementu jest jego indeks w tablicy powiększony o jeden. Wagi zostały zastosowane, by zmniejszyć prawdopodobieństwo powtarzania się tych samych haszy dla tablic wypełnionych liczbami o tej samej sumie indywidualnych haszy. Dzięki wprowadzeniu wag, wynik funkcji haszującej jest uzależniony nie tylko od haszów kolejnych elementów, ale też od miejsca tych elementów w tablicy. Ta metoda haszowania zapewnia dużą bezkolizyjność. Poza mało prawdopodobnymi sytuacjami gdy uzyskane zostaną specyficzne kombinacje wartości elementów i ich pozycji, lub gdy w wyniku sumowania kolejnych haszy, hasz wynikowy przekroczy rozmiar `std::size_t` w taki sposób, że da hasz przypisany dla innej tablicy, hasze będą unikatowe dla konkretnych wypełnień tablicy `data[]`. Z tego powodu taka funkcja haszująca została uznana za wystarczającą na potrzeby tego projektu.

## 2. Testy operatorów i funkcji haszujących.
### Wstęp
Do napisania testów jednostkowych użyta została biblioteka googletest. Dla typów **Small** i **Medium** testy dla operatorów (wraz z operatorami) zostały napisane zgodnie z metodyką *Test-Driven_Development*. Dla typu **Large** operatory i testy zostały skopiowane z typu **Medium** i odpowiednio zmodyfikowane.
### A.Sposób sprawdzania poprawności
#### Operatory mniejszości
W przypadku operatora mniejszości dla typu **Small** testowane jest czy zwraca on `true` wtedy gdy `data[0]` instancji po lewej stronie jest mniejsze od `data[0]` instancji po prawej stronie, i czy w przypadku gdy lewa instancja jest równa albo większa zwracane jest `false`.

Dla typów **Medium** i **Large** testowane jest dodatkowo czy `operator<` zwróci `false`, gdy wszystkie elementy tablicy `data[]` instancji po lewej stronie są równe odpowiadającym elementom `data[]` instancji po prawej stronie, oraz czy zwrócone zostanie `true` jeśli napotkano element tablicy lewej instancji mniejszy od odpowiadającego elementu tablicy prawej instancji.
#### Operatory równości
Dla typu **Small** sprawdzane jest, czy `operator==` zwraca `true`, gdy `data[0]` instancji po lewej stronie jest równe `data[0]` instancji po prawej stronie, i czy w przeciwnym przypadku zwracane jest `false`.

W testach dotyczących typów **Medium** oraz **Large** sprawdzane jest dodatkowo, czy zwrócone zostanie `true` gdy wszystkie odpowiadające sobie elementy tablic `data[]` są równe, a `false` gdy napotkane zostaną odpowiadające sobie elementy, które nie są równe.

#### Funkcje haszujące
Podstawowym założeniem dla funkcji haszującej jest to, czy dla tej samej wartości wyznaczony zostanie ten sam hasz. Na tą własność funkcje haszujące są testowane w każdym typie.

W typie **Small**, ze względu na specyfikę tablicy `data[]`, możliwe jest uzyskanie bezkolizyjności w funkcji haszującej, dlatego również pod tym względem testowana jest funkcja haszująca. W typach **Medium** i **Large** uzyskanie całkowitej bezkolizyjności nie jest możliwe, więc funkcja haszująca nie jest testowana w tym kierunku.
### B. Inicjalizacja testowanych obiektów
Testowane obiekty nie powinny być inicjalizowane losowymi wartościami. Uniemożliwiałoby to kontrolowanie przebiegu testów. Przykładowo w teście który ma wykazać, że zwracane jest `true` gdy jeden obiekt jest mniejszy od drugiego, w wyniku losowej inicjalizacji to pierwszy obiekt mógłby być czasami większy, a wówczas test czasem by przchodził, a czasem nie. Uniemożliwiałoby to powiązanie wyniku testu ze sposobem implementacji operatora, gdyż nie tylko ona wpływałaby na powodzenie testu.

## 3. Benchmarki dla operatorów i funkcji haszujących
### Wstęp
Do napisania mikro-benchmarków użyta została biblioteka benchmark pochodząca od Google. Benchmarki były uruchamiane na maszynie wirtualnej na laptopie z procesorem Intel Core i5-4200M 2 x 2.5GHz (2 rdzenie, 4 wątki) oraz z pamięcią RAM 8GB. Maszynie wirtualnej przydzielone zostało 1 CPU oraz 4GB RAM.
### A. Struktura benchmarku
Benchamrk działa na zasadzie rejestracji funkcji wewnątrz makra `BENCHMARK(...)`. Funkcja ta jest typu `static void` i jako argument przyjmuje referencję do obiektu klasy `State`. Wewnątrz ciała funkcji, najpierw mają miejsce inicjalizacje zmiennych i obiektów, które mają mieć miejsce tylko raz dla danego wywołania funkcji. Dalej znajduje się pętla `for(auto _ : state) {...}`, wewnątrz której znajdują się instrukcje, które mają zostać wykonane określoną ilość iteracji, i których czasy wykonania są mierzone podczas każdej iteracji pętli. W przypadku benchmarków operatorów i funkcji haszujących, wewnątrz tej pętli znajdują się jedynie wywołania operatorów lub funkcji haszujących.

Funkcja zarejestrowana w makrze `BENCHMARK(...)` wywoływana jest wielokrotnie - za każdym razem zwiększając liczbę iteracji dla pętli `for(auto _ : state) {...}`. Dzieje się tak w celu znalezienie odpowienio dużej ilości iteracji, by zapewnić jak najlepszą miarodajność pomiarów, jednocześnie zapobiegając ustanowieniu zbyt dużej ilości iteracji, co doprowadziłoby do długiego oczekiwania na wyniki pomiarów. Czas każdej iteracji pętli jest mierzony, zarówno w kontekście czasu ogólnego jak i czasu CPU, a następnie dodawany do czasów zmierzonych w poprzednich iteracjach. Na koniec działania sumy czasów są dzielone przez ilość iteracji - uzyskiwany jest średni czas. Na wyjściu benchmark wyświetla swoją nazwę, średni czas, średni czas CPU oraz ilość iteracji przy której te czasy zostały uzyskane.
### B. Konsekwencje powolnej implementacji operatorów i funcji haszujących dla kontenerów sekwencyjnych
Źle zaimplementowane operatory mają wpływ na spowolnienie działania tych metod, które odwołują się do zawartości elementów umieszczonych w kontenerze sekwencyjnym, wykonując na nich porównania. Przykładami takich metod dla kontenera `std::forward_list` są `.sort()`, `.unique()` oraz `.remove()`. Powolna implementacja ma wpływ na zwiększenie czasu wykonywania takich metod, ale nie ma wpływu na ich złożoność obliczeniową.
### C. Wpływ powolnej implementacji operatora mniejszości na posortowane kontenery asocjacyjne
W przypadku posortowanych kontenerów asocjacyjnych `operator<` umożliwia umieszczanie kolejnych elementów na drzewie binarnym. Wykorzystywany jest również w funkcjach realizujących dostęp do elementów. Zaimplementowanie powolnego operatora mniejszości doprowadza do spowolnienia większości metod kontenera.
### D. Wpływ powolnej implementacji operatora równości oraz funkcji haszującej na nieuporządkowane kontenery asocjacyjne
Powolna implementacja `operator==` w nieuporządkowanych kontenerach asocjacyjnych powoduje dłuższy czas wykonywania się metod wewnątrz których ma miejsce porównywanie wartości kluczy. Przykładem takiej metody dla kontenera `std::unordered_multimap` jest między innymi `.find()`. Powolny `operator==` zwiększa czas wykonywania się takich metod, ale nie wpływa na ich złożoność obliczeniową.

Funkcja haszująca wykorzystywana jest w większości metod kontenerów, do wyliczenia hasza z klucza, dzięki któremu para *{klucz, wartość}* przypisywana jest do określonego wiaderka (*ang. bucket*) w kontenerze. Powolna funkcja haszująca spowalnia więc większość metod dotyczących kontenera. Dodatkowo funkcja haszująca wyliczająca hasze z dużym prawdopodobieństwem kolizji, sprawia że większość metod zamiast złożoności *O(1)* przybiera złożoność *O(N)*, gdzie *N* jest ilością elementów w kontenerze.

### E. Rezultaty benchmarków
Poniższe tabele prezentują zestawienie wyników benchmarków operatorów i funkcji haszujących pomiędzy strukturami **Small**, **Medium** i **Large**:

|    Benchmark    |       Time       |     CPU    | Iterations
|-----------------|------------------|------------|------------
|Small_LessThan   |     26.9 ns      |   26.1 ns  |   26779318
|Medium_LessThan  |      270 ns      |    266 ns  |    2426826
|Large_LessThan   |      259 ns      |    252 ns  |    2875894
*Tab. 1 Zestawienie wyników benchmarków dla operatorów mniejszości.*

|    Benchmark   |       Time       |       CPU   |   Iterations
|----------------|------------------|-------------|--------------
|Small_Equality  |      26.6 ns     |    26.0 ns  |   26596186
|Medium_Equality |       185 ns     |     184 ns  |    3814017
|Large_Equality  |       157 ns     |     151 ns  |    4137865
*Tab. 2 Zestawienie wyników benchmarków dla operatorów równości.*

|Benchmark     |       Time     |      CPU      |  Iterations
|--------------|----------------|---------------|-------------
|Small_Hash    |     25.7 ns    |     25.4 ns   |  27067733
|Medium_Hash   |    4057 ns     |     4048 ns   |   156630
|Large_Hash    |    9252500 ns  |    9203854 ns |   71
*Tab. 3 Zestawienie wyników benchmarków dla funkcji haszujących.*

W przypadku operatorów mniejszości i równości można zauważyć, że różna wielkość typów (czyli wielkość tablicy `data[]` zawartej w nich) nie ma znaczącego wpływu na zmiany szybkości wykonywania tych operatorów. Jedyna zauważalna różnica występuje pomiędzy typem **Small** a typami **Medium** i **Large**. Jest to związane przede wszystkim z większym narzutem wywołania `std::lexicographical_compare` i `std::equal` niż w przypadku wywołania `operator<` i `operator==` dla typu `char`. Przy zainicjowanych losowymi liczbami strukturach **Medium** oraz **Large** wykonanych zostanie zazwyczaj maksymalnie kilka porównań, gdyż po takiej liczbie prawie zawsze zostaną znalezione różne od siebie elementy tablic `data[]`, zaś operatory zakończą swoje wykonywanie. Z tego powodu, mimo znacznej różnicy rozmiarów , czasy dla struktur **Medium** i **Large** są do siebie bardzo podobne, i nie wiele większe od tych zanotowanych dla struktury **Small**.

W benchmarkach funkcji haszujących różnice czasu między typami są znaczące i silnie uzależnione od ich rozmiarów. Dzieje się tak dlatego, że funkcja haszująca musi wykonać określone operacje na wszystkich elementach tablicy `data[]`. Im więcej elementów  zawiera tablica, tym więcej razy zestaw instrukcji jest powtarzany. Skutkuje to dłuższym czasem jaki jest potrzebny funkcji na zakończenie działania
### F. Inicjalizacja obiektów na potrzeby benchmarków
Na potrzeby benchmarków, instancje struktur **Small**, **Medium** oraz **Large** najlepiej jest inicjalizować danymi losowymi. Związane jest to z tym, że benchmarki mają pokazywać uogólniony czas wykonywania konkretnych operacji. Dzięki losowej inicjalizacji, przy wielokrotnych wywoływaniach benchmarka (lub wykonywania inicjalizacji w pętli, a następnie użycia np. metody *baseline* do odfiltrowania jej czasu) , testowane są czasy operacji dla różnych zestawów danych. Symuluje to sytuację gdy użytkownik również stosuje daną funkcjonalność dla różnych danych, oraz zmniejsza prawdopodobieństwo zafałszowania wyniku benchmarka przez wystąpienie jakiegoś przypadku szczególnego.