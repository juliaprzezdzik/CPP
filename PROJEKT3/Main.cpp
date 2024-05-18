//Specyfikacja projektu:
//Zaprogramujemy działający asynchronicznie monitor zasobów dyskowych.
//1. Monitor śledzi wybrane zasoby dyskowe i informuje o zmienie ich stanu
//(w praktyce: utworzenie, usunięcie, zmiana zawartości) i czasie, w którym ta zmiana nastąpiła.
//2. Możliwymi zasobami do monitorowania są pliki i foldery, z opcją monitorowania podfolderów.
//3. Program zapewnia interfejs tekstowy do zarządzania monitorowaniem z poleceniami:
//addmonitor path [-r] - rozpoczęcie monitorowania zasobu. Opcjonalny parametr -r oznacza rekursywne
//monitorowanie podfolderów.
//endmonitor path - zaprzestanie monitorowania zasobu o ścieżce path.
//printmonitor path - wypisanie dotychczasowej historii zasobu o ścieżce path.
//printmonitors - wypisanie ścieżek wszystkich aktualnie monitorowanych zasobów
// (z informacją o ewentualnym rekursywnym monitorowaniu podzasobów.)
//4. Każdy zasób jest monitorowany w oddzielnym wątku (trzeba wymyśleć jakiś rozsądny czas próbkowania
//by nadmiernie nie obciążać systemu).
//5. Proszę dobrać struktury danych/kontenery odpowiednie do realizowania ww. funkcji.
//6. Dla uproszczenia załóżmy, że program przechowuje wszystkie informacje w pamięci, co na dłuższą metę
//jest nie do utrzymania.
//7. Na zajęciach podam konkretne polecenia do wykonania przy pomocy naszego systemu więc proszę zadbać o
//elastyczność implementacji, by była podtna na modyfikacje i rozszerzenia.
#include <iostream>
#include <Monitor.h>

int main() {
    std::cout << "Nasz wspaniały monitor zasobów !" << std::endl;
    return 0;
}
