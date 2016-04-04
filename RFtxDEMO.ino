//  set  pin  numbers :
const  int  buttonPin = 5;
//  N mero  do  pino  que  l i g a  a  t r a s m i   o
const  int  txPin =   3;
//  N mero  do  pino q  i r    transmitir  o  s i n a l
1
//  C d i g o s
serem  enviados :
String  code = String ("INSIRA AQUI O C DIGO  BIN RIO A SER TRANSMITIDO" ) ;  // crinado uma nova  s t r i n g  b i n  r i a
//  v a r i a b l e s  w i l l  change :
int  buttonState = 0;
boolean  txState = HIGH;
int  i = 0;
int  n = 0;
//  Default  config  f o r PPA TOK 433Mhz remote
unsigned  int  space = 10000;  // E s p a o  entre  a  t r a n s m i   o  em us
unsigned  int  p = 500;  // P e r o d o  m nimo  de  pulso em us
void  setup ()  {
//  i n i t i a l i z e  the LED pin  as  an output :
pinMode ( txPin , OUTPUT) ;
//  i n i t i a l i z e  the  pushbutton  pin  as  an  input :
pinMode ( buttonPin , INPUT) ;
//  i n i c i a l i z a  s e r i a l :
S e r i a l . begin (9600);
}
void  loop ()  {
//  read  the  state  of  the  pushbutton  value :
buttonState = digitalRead ( buttonPin ) ;
//  check  i f  the  pushbutton  i s  pressed .
//  i f  i t  is ,  the  buttonState  i s HIGH:
i f  ( buttonState == HIGH)  {
//  S i l  n c i o  ( e s p a  o  em n i v e l  vaixo )  antes  da  t r a n s m i   o
digitalWrite ( txPin , LOW) ;
n = int ( code . length ( ) ) ;
i = 0;
// S e r i a l . pr in t ln (n ) ;
delayMicroseconds ( space ) ;
while ( i < n){
i f  ( code . charAt ( i)==  ’0 ’)  {
// S e r i a l . print ( code . charAt ( i ) ) ;
digitalWrite ( txPin , HIGH) ;
// S e r i a l . pr in t ln ("  Zero " ) ;
}
e l s e  i f ( code . charAt ( i)==  ’1 ’)  {
// S e r i a l . print ( code . charAt ( i ) ) ;
digitalWrite ( txPin , LOW) ;
// S e r i a l . pr i nt ln (" Um" ) ;
2
}
i ++;
delayMicroseconds (p ) ;
// S e r i a l . print ("P" ) ;
}
S e r i a l . pr i nt ln ( ) ;  // Falha uma linha
}
}
