void setup() {
  Serial.begin(9600); // "Serial.begin(9600) es una instrucción que le indica al Arduino que se comunique con la computadora, con una velocidad serial de 9,600 bits por segundos (baudios)".

  // Modo "entrada/salida" de los pines.
  pinMode(13, OUTPUT);  
}

// Declaración de varaibles.
// Variable que contiene el valor del Voltaje del sensor en "Voltios". En este caso, se le asigna un valor de "5" ya que son los voltios que se le van a pasar a dicho sensor.
float VoltajeSensor = 5;

void loop() {
// Declaración de variables.
  // Variable que almacenará el valor obtenido por el sensor de temperatura.
  float ValorSensor = analogRead(A0); // "analogRead(A0) indica que se leerá el "pin A0" del Arduino".
  float TemperaturaC = (ValorSensor/1023) * VoltajeSensor * 100; // Fórmula encargada de calcular la temperatura en °C.
  
  // Condición que sólo se activará sí y sólo sí la temperatura es mayor o igual a "35 °C".
  if(TemperaturaC >= 35){
    // <--- Todo este código de aquí permitirá que el sensor envíe una alarma y prenda el LED rojo indicando que la temperatura es muy alta. ---> //
    // Modo "entrada/salida" de los pines.
    digitalWrite(13, HIGH);
    delay(300); // Se hace una pausa de 300 ms.
    // Modo "entrada/salida" de los pines.
    digitalWrite(13, LOW);
    delay(300); // Se hace una pausa de 300 ms.
  }
// Se imprimen los valores de la distancia en "cm"
  Serial.print("La temperatura ambiente es: " + String(TemperaturaC));
  Serial.print(" °C");
  Serial.println(); // Salto de línea.
  delay(500); // Se hace una pausa de 500 ms.
}
