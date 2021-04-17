void botonMas(){
   unsigned long  masMilis=millis();
                int tiempoMas=0;
                // contador++;
                Serial.println("Boton Mas ");
                incrementaContador();
                distancia= (double)contador/escala;
                delay(300);
                buttonStateMas = digitalRead(buttonPinMas);
                while(buttonStateMas == HIGH){
                  
                  tiempoMas=(millis()-masMilis)/escala;
                  
                  Serial.println("Boton Massss ");
                  incrementaContador();
                  distancia= (double)contador/escala;
                  if(tiempoMas<tiempoEsperaDistancia){
                      delay(100);
                    }else if(tiempoEsperaDistancia<tiempoMas<tiempoEsperaDistancia10){
                       delay(10); 
                    }else{
                      delay(1); 
                     }
                   
                  buttonStateMas = digitalRead(buttonPinMas);
                  actualizaPantalla(sat,distancia,rumbo);
                  
                 }
          }
void botonMenos(){
  unsigned long  menosMilis=millis();
                int tiempoMenos=0;
                // contador--:
                Serial.println("Boton Menos ");
                decrementaContador();
                distancia=(double)contador/escala;
                  delay(300);
                  buttonStateMenos = digitalRead(buttonPinMenos);
                while(buttonStateMenos == HIGH){
                  tiempoMenos=(millis()-menosMilis)/escala;
                  Serial.println("Boton Menossssssssssss ");
                  decrementaContador();
                  distancia= (double)contador/escala;
                  if(tiempoMenos<tiempoEsperaDistancia){
                      delay(100);
                     }else if(tiempoEsperaDistancia<tiempoMenos<tiempoEsperaDistancia10){
                       delay(10); 
                    }else{
                      delay(1); 
                     }
                  buttonStateMenos = digitalRead(buttonPinMenos);
                  actualizaPantalla(sat,distancia,rumbo);
                 }
                
  
  }


void botonSelect(){
   // SELECTED
                Serial.println("SELECT");
                
                unsigned long  selectMilis=millis();
               
                int tiempo=0;
                //delay(150);
                while(buttonStateSelect == HIGH){
                  //Serial.println(millis());
                  tiempo=(millis()-selectMilis)/1000;
                  Serial.print("seleccionado: ");
                  Serial.println(tiempo);

                  if(tiempo>tiempoEsperaDistancia){
                    buttonStateMenos = digitalRead(buttonPinMenos);
                     if (buttonStateMenos == HIGH) {
                        resetearContador();
                        actualizaPantalla(sat,distancia,rumbo);
                      }
                  }
                  buttonStateSelect = digitalRead(buttonPinSelect);
                 }
                Serial.println("                  SELECT OFF");
  
  }
