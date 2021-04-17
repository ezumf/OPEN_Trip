
void inicializaEEPROM(){
  /*int e; //variable con el valor de la EEPROM
  EEPROM.get( eeAddress, e );//leemos de la EEPROM
 if(e<0){//si es menor que 0, inicializamos a 0
    e=0;
    EEPROM.put( eeAddress, e );
  }else{//inicializamos contador
    EEPROM.get( eeAddress, contador );//leemos de la EEPROM
  }*/

// EEPROMWritelong(eeAddress,10300);
 long valorLong=EEPROMReadlong(eeAddress);
  contador=valorLong;
  distancia=(double)contador/escala;
 
 
 
  Serial.print("contador: ");
  Serial.println(contador);
  Serial.print("Distancia: ");
  Serial.println(distancia);
}

void resetearContador(){
    contador=0;
    distancia=0;
  }

void incrementaContador(){
  //distancia=distacia+escala;
  contador=contador+metrosEscala;
 Serial.print("contador: ");
 Serial.println(contador);
  //EEPROM.put( eeAddress, contador );
}

void decrementaContador(){
  if(contador>0){
    //distancia=distacia-escala;
    contador=contador-metrosEscala;
    Serial.print("contador: ");
    Serial.println(contador);
   // EEPROM.put( eeAddress, contador );
  }else{
    contador=0;
  }
  
}



long EEPROMReadlong(int address) {
  long four = EEPROM.read(address);
  long three = EEPROM.read(address + 1);
  long two = EEPROM.read(address + 2);
  long one = EEPROM.read(address + 3);
  
  return ((four << 0) & 0xFF) + ((three << 8) & 0xFFFF) + ((two << 16) & 0xFFFFFF) + ((one << 24) & 0xFFFFFFFF);
}

void EEPROMWritelong(int address, long value) {
  byte four = (value & 0xFF);
  byte three = ((value >> 8) & 0xFF);
  byte two = ((value >> 16) & 0xFF);
  byte one = ((value >> 24) & 0xFF);
  
  EEPROM.write(address, four);
  EEPROM.write(address + 1, three);
  EEPROM.write(address + 2, two);
  EEPROM.write(address + 3, one);
}
