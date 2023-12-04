#include <stdio.h>
#include <stdlib.h>

/*9.Se lucreaza la un nou sistem de operare numit Poliubuntu. Ca in orice sistem de operare, permisiunile fisierelor
este un aspect important. In acest sistem de operare, permisiunile unui fisier sunt stocate intr un numar pe 8 biti fara semn,
in 2 nibble-uri de 4 biti: primul nibble reprezinta permisiunile detinatorului(user), iar al doilea nibble reprezinta permisiunile celorlalti useri(other).
Cel mai semnificativ bit din nibble nu reprezinta nimic, iar urm 3 reprezinta in ordine dreptul de read, write, execute. De exemplu:
-rwx -rwx
0111 0100
In exemplul de mai sus, user-ul are dreptul de read, write execute, iar restul userilor pot doar citi acel fisier.
Sa se creeze urm functii:
- o functie care primeste ca parametru un nr intreg pe 8 biti reprezentand permisiunile unui fizier. Functia va afisa acele permisiuni sub forma -rwx -rwx.
De exemplu pt nr 0111 0100 se va afiza -rwx -r--.
- o functie care primeste ca parametru un tablou de astfel de permisiuni, un intreg N reprezentand nr de elem, un nr reprezentand permisiunea care va fi
resetata fiecarui nr din tablou fara a modifica restul permisiunilor, si un nr care va determina daca permisiunea se adauga la nibble ul user sau la
nibble ul other. De exemplu daca resetam dreptul de write pt other pt nr 0111 0110, el va deveni 0111 0100.
*/

int main()
{
    printf("Hello world!\n");
    return 0;
}
