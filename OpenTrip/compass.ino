  int calculaRumbo(){
    int rumboCalculado=rumbo;
    int x,y,z,rumboSS;      // variables de los 3 ejes
    int rumboMedia=0;
    float acimut,geografico;  // variables para acimut magnetico y geografico
    float declinacion = -0.75;    // declinacion desde pagina: http://www.magnetic-declination.com/
    qmc.read(&x,&y,&z,&acimut);   // lectura de los ejes y acimut magnetico
   
    geografico = acimut + declinacion;  // acimut geografico como suma del magnetico y declinacion
    if(geografico < 0)      // si es un valor negativo
    geografico = geografico + 360;  // suma 360 y vuelve a asignar a variable
  
    //pasamos el rumbo a entero, para quitar decimales
    rumboSS=(int)geografico;

    rumbos[contadorRumbo]=rumboSS;
   // Serial.print("ContadorRumbo: ");
    //Serial.println(contadorRumbo);
    contadorRumbo++;
    if(contadorRumbo>(numMedidasRumbo-1)){
 
      for(int i=0;i<numMedidasRumbo;i++){
        rumboMedia+=rumbos[i];
      }
      rumboCalculado=rumboMedia/numMedidasRumbo;
      contadorRumbo=0;
     // Serial.print("Rumbo: ");
     // Serial.println(rumboCalculado);
    }
    
    
  return rumboCalculado;
  }
