#include <Wire.h>



  int comunica;
  bool a = 1;
  bool b = 1;
  int rele_1 = 2;
  int rele_2 = 3;
  int pos;
  String lampadas_status[] = {"lamp.1 desligada","lamp.2 desligada"};

void setup() {

  pinMode (rele_1, OUTPUT);
  pinMode (rele_2, OUTPUT);

  digitalWrite(rele_1,1);
  digitalWrite(rele_2,1);

}

/////////////////////////////////////////////////////////////
 if (comunica == 97){
     a = !a;
    digitalWrite(rele_1,a);

  
 }

 if (comunica == 98){
     b = !b;
    digitalWrite(rele_2,b);

 }
///////////////////////////////////////////////////////////////
delay(1000);

}
