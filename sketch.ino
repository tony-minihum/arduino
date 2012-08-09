/* -*- mode: c++ -*- */

// HSV Color Space

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
  float val = analogRead(0) / 1024.f;

  val = (val - 0.3f) * 2.2f; // 0 - 1 くらいになるように適当に補正

  long l = (millis() / 5) % 1000;
  //  val = sin( 2 * 3.14 * (l / 1000.f));
  //  val = (val + 1.f) / 2.f;
  val = l / 1000.f;

  Serial.print("val=");
  Serial.print(val);
  Serial.print(" ");

  float r, g, b;  

  hueToRGB(val, r, g, b);

  Serial.print("r=");
  Serial.print(r);
  Serial.print(" ");

  Serial.print("g=");
  Serial.print(g);
  Serial.print(" ");

  Serial.print("b=");
  Serial.print(b);
  Serial.println(" ");

  analogWrite(R, 10.f + 170.f * r * 0.5f);
  analogWrite(G, 55.f + 200.f * g);
  analogWrite(B, 1.f + 100.f * b * 0.1f);

  //  delay(100);
}

void hueToRGB(float hue, float& r, float& g, float& b)
{
  float h = hue;
  float s = 1.f;
  float v = 1.f;

  h *= 6.f; // 6 color sections
  const int i = (int)h; //(int)floorf( h );
  const float f = h - i;
  const float p = v * ( 1.f - s );
  const float q = v * ( 1.f - s * f );
  const float t = v * ( 1.f - s * ( 1.f - f ) );

  switch ( i )
  {
    case 0:
      r = v;
      g = t;
      b = p;
      break;
    case 1:
      r = q;
      g = v;
      b = p;
      break;
    case 2:
      r = p;
      g = v;
      b = t;
      break;
    case 3:
      r = p;
      g = q;
      b = v;
      break;
    case 4:
      r = t;
      g = p;
      b = v;
      break;
    default:                // case 5:
      r = v;
      g = p;
      b = q;
      break;
    }
}

