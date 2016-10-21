// Access to the ethernet

#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

EthernetClient client;
IPAddress ip(192, 168, 0, 177);

int eth_init()
{
    int res = Ethernet.begin(mac);
    if (res==0) Ethernet.begin(mac,ip);
    delay(1000);
    return res;
}

int get(char* server,String qry)
{
  Serial.println("Connecting");
  if (client.connect(server, 80)) {
    Serial.println("Sending qry");
    client.println("GET / HTTP/1.1");
    client.print("Host: "); client.println(server);
    client.println("Connection: close");
    client.println();
    client.flush();
    delay(500);
    char buf[1024];
    int i=0;
    Serial.println("Getting response");
    while(client.available()&&i<1023) 
    { 
      char c = client.read();
      Serial.print(c);
      buf[i++]=c;
      if (c=='\n'||c=='\r')
      {
        buf[i-1]=0;
        break; 
      }
    }
    client.stop();
    String res(buf);
    if (!res.startsWith(String("HTTP/1.1 "))) return 0;
    Serial.println(res.substring(9,12));
    int x = res.substring(9,12).toInt();
    return x;
  }
  else
  {
    Serial.println("Cannot connect");
    return 0;
  }
}

