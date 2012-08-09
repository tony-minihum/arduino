/* -*- mode: c++ -*- */

// LED sample

const int	R    =  9;    // the pin LED connected
const int	G    = 10;    // the pin LED connected
const int	B    = 11;    // the pin LED connected

int val = 0;

void setup()
{
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  val = analogRead(0);

  int max = 580 - 190;
  int _min = 190;
  Serial.print(max);
  Serial.print(" ");

  Serial.print(_min);
  Serial.print(" ");

  Serial.print(val);
  Serial.print(" ");
  val = val - _min;
  if (val < 0) {
    val = 0;
  }
  Serial.print(val);
  Serial.print(" ");
  if (val > max) {
    val = max;
  }
  Serial.print(val);
  Serial.print(" ");

  if (val < max / 3) {
    analogWrite(R, 255 * ((float)val/max));
    analogWrite(G, 255 * (1-((float)val/max)));
    analogWrite(B, 0);
  } else if (val < max * 2 / 3) {
    analogWrite(R, 0);
    analogWrite(G, 255 * ((float)val/max));
    analogWrite(B, 255 * (1-((float)val/max)));
  } else if (val < max ) {
    analogWrite(R, 255 * (1-((float)val/max)));
    analogWrite(G, 0);
    analogWrite(B, 255 * ((float)val/max));
  } 

  Serial.print((float)val / max);
  Serial.print(" ");
  Serial.println(1-((float)val/max));

  delay(10);
}

