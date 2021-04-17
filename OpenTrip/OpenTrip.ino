/**************************************************************************
 
 **************************************************************************/
#include <Wire.h>    // incluye libreria bus I2C
#include <MechaQMC5883.h> // incluye libreria para magnetometro QMC5883L
#include <Adafruit_GFX.h>   // libreria para pantallas graficas
#include <Adafruit_SSD1306.h>   // libreria para controlador SSD1306

#include <EEPROM.h>   //

//inicio librerias GPS
 
#include <TinyGPS.h>
#include <SoftwareSerial.h>
//Fin Librerias GPS

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
//Fin de declaración de la pantalla




//configuracio GPS
//TinyGPS gps;
//SoftwareSerial softSerial(9, 8);//pines de comunicacion del GPS



// Brujula
MechaQMC5883 qmc;   // crea objeto. direccion I2C 0x0D 

// set pin numbers:
const int buttonPinMas = 12;     // the number of the pushbutton pin +
const int buttonPinMenos = 11;   // the number of the pushbutton pin -
const int buttonPinSelect = 10;  // the number of the pushbutton pin select
const int ledPin =  13;      // the number of the LED pin

long contador=0; //EEPROM
double distancia=0.0; // distancia inicial, 
int metrosEscala=100;// metros del pulsador, 
int escala=1000; //escala aplicada
int eeAddress = 10; //dirección de memoria con los datos.


// variables will change:
int buttonStateMas = 0;         // variable for reading the pushbutton status
int buttonStateMenos = 0;         // variable for reading the pushbutton status
int buttonStateSelect = 0;         // variable for reading the pushbutton status

unsigned long duracion;

int tiempoEsperaDistancia=3; //tiempo que tiene que estar un boton pulsado para acelerar el incremento o decremento de disntacia.
int tiempoEsperaDistancia10=5; // segundo incremento, 10 veces más rapido
const int numMedidasRumbo=6;
int contadorRumbo=0;
int rumbos[numMedidasRumbo];
int rumbo=0;

int sat=1;


void setup() {
  Wire.begin();     // inicializa bus I2C
  Serial.begin(115200);
  //softSerial.begin(4800);
  
  qmc.init();     // inicializa la brujula

//inicio configuración display
 display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
 //findo configuración de la pantalla   

 // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPinMas, INPUT);
  pinMode(buttonPinMenos, INPUT);
  pinMode(buttonPinSelect, INPUT);
  Serial.println("    Inicializamos la EEprom");
  inicializaEEPROM();
}

void loop() {

//definición de variables
 //distancia=125.8;
  
  
    //una vez que arranca, para que no pase mas por el loop, ejecuta un loop infinito con este while
 Serial.println("Entramos en Bucle infinito");
  while(1){

      rumbo=calculaRumbo();
      
       // read the state of the pushbutton value:
        buttonStateMas = digitalRead(buttonPinMas);
        buttonStateMenos = digitalRead(buttonPinMenos);
        buttonStateSelect = digitalRead(buttonPinSelect);

        // check if the pushbutton is pressed.
              // if it is, the buttonState is HIGH:
              if (buttonStateMas == HIGH) {
               botonMas();
              } else {
                // nothing;
              }
              if (buttonStateMenos == HIGH) {
                botonMenos();
              } else {
                // nothing:
              }
              if (buttonStateSelect == HIGH) {
               botonSelect();
              } else {
                //
              }


      //Actualizamos Pantalla
      actualizaPantalla(sat,distancia,rumbo);
    
      
      //Serial.println("suma y sigue");
     // distancia++;
     // sat++;
      delay(150);
    }
}
