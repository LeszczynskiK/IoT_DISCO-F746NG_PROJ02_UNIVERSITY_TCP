
#include "EthernetInterface.h"
#include "mbed.h"
//#include "nucleo_weather.h"


#include <cstring>
#include <chrono>


DigitalOut led1(LED1);
AnalogIn adc_temp(ADC_TEMP);


EthernetInterface net;
TCPSocket server;
TCPSocket *clientSocket;
SocketAddress clientAddress;
char rxBuf[512] = {0};
char txBuf[512] = {0};


//nucleo_weather *nw;


Thread serverThread;


void webServer() {


 //nw = new nucleo_weather();
 net.connect(); // wlaczenie i polaczenie interfejsu ethernet
 // odczyt parametrow
 SocketAddress ip;      // przechowuje adres IP
 SocketAddress netmask; // maska sieci
 SocketAddress gateway; // brama


 net.get_ip_address(&ip);   // poobranie info o IP
 net.get_netmask(&netmask); // pobranie info o masce
 net.get_gateway(&gateway); // pobranie info o bramie


 ip.set_port(80); // HTTP port = 80


 printf("IP address: %s\r\n", ip.get_ip_address());
 printf("Netmask: %s\r\n", netmask.get_ip_address());
 printf("Gateway: %s\r\n\r\n", gateway.get_ip_address());


 // Otwarcie gniazda reprezentujacego serwer (nasluhiwanie)
 server.open(&net);


 // bindowanie adresu IP i portu 80 do gniazda repr serwer
 server.bind(ip);


 // maksymalna liczna jednoczesnych zapytan
 server.listen(5);


 // czekanie na http GET request
 while (true) {
   printf("***********************\r\n");


   nsapi_error_t error = 0;


   clientSocket = server.accept(&error);
   if (error != 0) {
     printf("Connection failed!\r\n");
   } else {
     clientSocket->set_timeout(200);
     clientSocket->getpeername(&clientAddress);
     printf("Klient o adresie IP %s polaczony.\r\n\r\n",
            clientAddress.get_ip_address());
     error = clientSocket->recv(rxBuf, sizeof(rxBuf));


     printf("Odebrano: %d\n\r%.*s\n\r", strlen(rxBuf), strlen(rxBuf), rxBuf);
     if (rxBuf[0] == 'G' && rxBuf[1] == 'E' && rxBuf[2] == 'T') {
       // Odpowiedz serwera WWW
       sprintf(rxBuf,
               "Temperatura: %d\r\n"
               "Cisnienie: %d\r\n",
              23, 1015);
               //nw->STLM75_ReadTemp(), nw->LPS331_PressRead());
       sprintf(txBuf,
               "HTTP/1.1 200 OK\nContent-Length: %d\r\nContent-Type: "
       "text\r\nConnection: Close\r\n\r\n ",
               strlen(rxBuf));
       clientSocket->send(txBuf, strlen(txBuf));
       printf("\r\n%s\r\n", txBuf);
       printf("Wyslano:\r\n%d\r\n", strlen(txBuf));
       clientSocket->send(rxBuf, strlen(rxBuf));
       printf("Wyslano:\r\n%d\r\n", strlen(rxBuf));
       printf("\r\n%s\r\n", rxBuf);
       printf("***********************\r\n");
     }
   }


   clientSocket->close();
   printf("Client socket closed\r\n");
 }
}


int main(void) {
 printf("Connecting...\r\n");
 serverThread.start(callback(webServer));


 while (true) {


   led1 = !led1;


   ThisThread::sleep_for(3000);
 }
}
