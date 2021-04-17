void actualizaPantalla(int sat,double distancia,int rumbo){
   //preparamos la pantalla
      display.clearDisplay();
  
      display.setTextSize(3);             // Normal 1:1 pixel scale
      display.setTextColor(SSD1306_WHITE);        // Draw white text
      display.setCursor(70,0);             // Start at top-left corner
      display.println(rumbo);

     // Serial.print("Rumbo: ");
      //Serial.println(rumbo);
      if(sat<6){
          display.setTextSize(1);
          display.setCursor(0,0);             // Start at top-left corner
          display.println("Sat:");
          
          display.setCursor(25,0);             // Start at top-left corner
          display.println(sat);
        }
      
    
      display.setTextSize(4);             // Draw 2X-scale text
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0,32);
      display.println(distancia);
      
     // Serial.print("Distancia: ");
     // Serial.println(distancia);
      
      display.display();
  
  } 
