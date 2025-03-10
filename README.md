# IoT_DISCO-F746NG_PROJ02_UNIVERSITY_TCP

Opis projektu  

Projekt obejmuje budowę komunikacji typu klient-serwer przy użyciu gniazd sieciowych w MBedOS oraz płyty DISCO-F746.  
W ramach projektu zaimportowano przykład obsługi połączenia TCP do kompilatora Mbed na podstawie dokumentacji MBedOS dotyczącej obiektu TCPSocket.   
Następnie dodano bibliotekę BSP_DISCO_F746NG do obsługi peryferiów płyty DISCO-F746, co pozwoliło na wyświetlanie informacji o adresie IP połączonej płytki na ekranie LCD.   
W celu rozszerzenia funkcjonalności zaimplementowano mechanizm serwera TCP, który został zmodyfikowany tak, aby użytkownik połączony z serwerem otrzymywał informację o aktualnej liczbie przyciśnięć przycisku.  

Wymagania:  
Płytka DISCO-F746NG  
Kompilator Mbed OS  
  
Biblioteki: BSP_DISCO_F746NG, EthernetInterface.h  
