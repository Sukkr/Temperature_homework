int ThermistorPin = 0;
int B = 3435;
float data;
float Rth, T;
float R0 = 10000;
float T0 = 298.15;

void setup() 
{
  Serial.begin(9600);
}

void loop () 
{
  data = analogRead(ThermistorPin);
  Serial.println(data);
  Rth = R0*1024/data - R0;
  Serial.println(Rth);
  T = 1/(log(Rth/R0)/B+1/T0) - 273.15;

  /*** Result printed ***/
  Serial.print("temperature : ");
  Serial.print(T);
  Serial.println(" °C"); 

  delay(600);
}
