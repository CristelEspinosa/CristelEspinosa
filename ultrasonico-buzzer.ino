//declaración de las variables globales

const int trigPin= 10;
const int ecoPin=9;
int buzz=6;
void setup() {
  //se utiliza serian begin para imprimir en monitor serial los datos que recolecta el sensor
Serial.begin(9600);
// pinMode activar los pines y determinar si son de entrada o salida
pinMode(trigPin, OUTPUT);
pinMode(ecoPin, INPUT);
digitalWrite(trigPin, LOW);
}

void loop() 
{
  //declaración de las variables locales
long t;
long d;
// digitalWrite escritura digital en los pines
digitalWrite(trigPin, HIGH);
//delayMicroseconds tiempo de espera en microsegundo
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// pulseIn Activa eco para escuchar lo que emite el trigPin del sensor ultrasonico que envia el impulso
t=pulseIn(ecoPin, HIGH);
//operación matemática cácular la distancia
d=t/2/29.1;
//impresión de los datos
Serial.print(d);
Serial.print ("cm");
Serial.println();
// delay tiempo de espera de un segundo para verificar la información
delay(1000);
// condición de distancia a la cual la persona podrá acercase o alejarse de un objeto. Sonará la bocina como advertencia de objeto cercano.
if ((d<=23))
{
  // sonido
  tone(buzz,700);
  delay(500);
}
else
{
  //rango comparado de la distancia de aviso previo al choque
  if ((d>=24&& d<=100))
  tone(buzz,800);
  else{
    // no tiene sonido
    noTone(buzz);
    }

}
}
