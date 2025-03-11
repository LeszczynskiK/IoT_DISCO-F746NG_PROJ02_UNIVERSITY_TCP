# IoT_DISCO-F746NG_PROJ02_UNIVERSITY_TCP

Opis projektu  

Projekt obejmuje budowę komunikacji typu klient-serwer przy użyciu gniazd sieciowych w MBedOS oraz płyty DISCO-F746.  
W ramach projektu zaimportowano przykład obsługi połączenia TCP do kompilatora Mbed na podstawie dokumentacji MBedOS dotyczącej obiektu TCPSocket.   
Następnie dodano bibliotekę BSP_DISCO_F746NG do obsługi peryferiów płyty DISCO-F746, co pozwoliło na wyświetlanie informacji o adresie IP połączonej płytki na ekranie LCD.   
W celu rozszerzenia funkcjonalności zaimplementowano mechanizm serwera TCP, który został zmodyfikowany tak, aby użytkownik połączony z serwerem otrzymywał informację o temperaturze i ciśnieniu(póki co są to wartości wpisane na sztywno, ale w przyszłości można dodac czujniki i będą pobierane wartości za ich pomocą).

Wymagania:  
Płytka DISCO-F746NG  
Kompilator Mbed OS  
Skrętka
Router
  
Biblioteki: BSP_DISCO_F746NG, EthernetInterface.h, mbed.h

Gdy uruchomiono, trzeba sprawdzić IP płytki(po połączeniu się do wifi w które jest ona wpięta): nmap -sn 192.168.0.1/24

Gdy sprawdzono IP płytki, można w przeglądarce wpisac je i będzie widoczna podstawiona strona www
