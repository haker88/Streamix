#include <Adafruit_NeoPixel.h>
#define PIN 6
#define PIN2 7

long r1;
long r2;
long r3;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(23, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(23, PIN2, NEO_GRB + NEO_KHZ800);
int x;
void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.show();
  strip.setBrightness(25);
  strip.setPixelColor(0,0,0,255);
  strip.setPixelColor(1,255,0,0);
  strip.setPixelColor(2,255,0,0);
  strip.setPixelColor(3,255,0,0);
  strip.setPixelColor(4,255,0,0);
  strip.setPixelColor(5,255,0,0);
  strip.setPixelColor(6,255,0,0);
  strip.setPixelColor(7,255,0,0);
  strip.setPixelColor(8,255,0,0);
  strip.setPixelColor(9,255,0,0);
  strip.setPixelColor(10,255,0,0);
  strip.setPixelColor(11,255,0,0);
  strip.setPixelColor(12,0,0,255);

  strip2.begin();
  strip2.show();
  strip2.setBrightness(25);
  strip2.setPixelColor(0,0,0,255);
  strip2.setPixelColor(1,255,0,0);
  strip2.setPixelColor(2,255,0,0);
  strip2.setPixelColor(3,255,0,0);
  strip2.setPixelColor(4,255,0,0);
  strip2.setPixelColor(5,255,0,0);
  strip2.setPixelColor(6,255,0,0);
  strip2.setPixelColor(7,255,0,0);
  strip2.setPixelColor(8,255,0,0);
  strip2.setPixelColor(9,255,0,0);
  strip2.setPixelColor(10,255,0,0);
  strip2.setPixelColor(11,255,0,0);
  strip2.setPixelColor(12,0,0,255);
  Serial.begin(115200);
  Serial.setTimeout(1);
}

void loop() {
  // put your main code here, to run repeatedly:
  strip.show();
  strip2.show();
while (!Serial.available());
  x = Serial.readString().toInt();

  switch (x) {
  case 12:
      for(int i=0; i<12; i++) {
    strip.setPixelColor(i,0, 64, 255);             // Draw 'head' pixel
    strip2.setPixelColor(i,0 ,64, 255 ); // Erase 'tail'
    strip.show();
    delay(75);
  }
    break;
  case 13:
    for(int i=0; i<12; i++) {
    strip.setPixelColor(i,255, 20, 147);             // Draw 'head' pixel
    strip2.setPixelColor(i,255 ,20, 147 ); // Erase 'tail'
    strip.show();
    delay(75);
    }
    break;
  case 14:
    for(int i=0; i<12; i++) {
    strip.setPixelColor(i,255, 226, 0);             // Draw 'head' pixel
    strip2.setPixelColor(i,255 ,226, 0 ); // Erase 'tail'
    strip.show();
    delay(75);
    }
    break;
  case 15:
      for(int i=0; i<12; i++) {
    strip.setPixelColor(i,0, 64, 120);             // Draw 'head' pixel
    strip2.setPixelColor(i,0 ,64, 120 ); // Erase 'tail'
    strip.show();
    delay(75);
  }
    break;
  case 16:
      for(int i=0; i<12; i++) {
    strip.setPixelColor(i,25, 0, 255);             // Draw 'head' pixel
    strip2.setPixelColor(i,25 ,0, 255 ); // Erase 'tail'
    strip.show();
    delay(75);
  }
    break;
   case 17:
      for(int i=0; i<12; i++) {
    strip.setPixelColor(i,255, 255,0);             // Draw 'head' pixel
    strip2.setPixelColor(i,255 ,255,0  ); // Erase 'tail'
    strip.show();
    delay(75);
  }
    break;
   case 18:
      for(int i=0; i<12; i++) {
    strip.setPixelColor(i,0,128,0);             // Draw 'head' pixel
    strip2.setPixelColor(i,0 ,128,0  ); // Erase 'tail'
    strip.show();
    delay(75);
  }
    break;
      case 19:
      for(int i=0; i<12; i++) {
    strip.setPixelColor(i,0,0,255);             // Draw 'head' pixel
    strip2.setPixelColor(i,0 ,0,255  ); // Erase 'tail'
    strip.show();
    delay(75);
  }
    break;

        case 20:
      for(int i=0; i<12; i++) {
    strip.setPixelColor(i,192, 192,192);             // Draw 'head' pixel
    strip2.setPixelColor(i,0 ,0,128  ); // Erase 'tail'
    strip.show();
    delay(75);
  }
    break;

          case 0:
      for(int i=0; i<12; i++) {
    strip.setPixelColor(i,255, 102,0);             // Draw 'head' pixel
    strip2.setPixelColor(i,128 ,0,0  ); // Erase 'tail'
    strip.show();
    delay(75);
  }
    break;
  
  default:
  if ((x >= 0) &&(x<12))
  {
    Serial.print(x + 1);
  r1 = random(0, 255);
  r2 = random(10, 255);
  r3 = random(10, 255);
  strip.setPixelColor(x,r1,r2,r3);
  strip2.setPixelColor(x,r1,r2,r3);}
    break;
}
}
  
   
