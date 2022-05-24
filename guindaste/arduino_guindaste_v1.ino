
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;
const int afwd = A0;
const int abwd = A1;
const int bfwd = A2;
const int bbwd = A3;
const int M1 = 9;
const int M2 = 10;
int af = 0;  
int ab = 0;  
int bf = 0;  
int bb = 0;  

int m1 = 130; 
int m2 = 255; 

void setup()
{

 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
 pinMode(afwd, INPUT);
 pinMode(abwd, INPUT);
 pinMode(bfwd, INPUT);
 pinMode(bbwd, INPUT);
 pinMode(M1, OUTPUT);
 pinMode(M2, OUTPUT);
}
  
void loop()
{
 
af = digitalRead(afwd);  
ab = digitalRead(abwd);  
bf = digitalRead(bfwd);  
bb = digitalRead(bbwd);  
analogWrite(M1, m1);  
analogWrite(M2, m2);
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, HIGH);
digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW); 
 m1=100; m2=100;
 
 while (af == HIGH) {     
m1=70; analogWrite(M1, m1); 
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
 delay(100);
 af = digitalRead(afwd);} 
 
while (ab == HIGH) {     
 m1=70; analogWrite(M1, m1); 
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH);
 delay(100);
 ab = digitalRead(abwd);} 
  
 while (bf == HIGH) {     
  m2=255; analogWrite(M2, m2);    
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, HIGH);
 delay(100);
bf = digitalRead(bfwd);} 
    
 while (bb == HIGH) {     
 m2=255; analogWrite(M2, m2);   
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW);
 delay(100);  
bb = digitalRead(bbwd); }  
}
