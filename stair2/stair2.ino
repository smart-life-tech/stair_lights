int set_dis = 8;      // Set distance for human read
int set_step = 14;    // Set step for Stairs Limt
int set_shift = 5000; // Set shifting time for step to step MilliSecond
int set_timer = 5000; // Set on stay time for light on Second

#define pir1 A0 // pir1 pin
#define pir2 A1 // pir2 pin

long dis_a = 0, dis_b = 0;
int flag1 = 0, flag2 = 0;

int i = 0;

int Second = 0;
word MilliSecond = 0;
bool timerStart = false;

int OutPins[] = {21, 20, 19, 18, 17, 16, 15, 14, 2, 3, 4, 5, 6};
bool first, second = true;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600); // initialize serial communication at 9600 bits per second:

  for (i = 0; i < set_step; i++)
  {
    pinMode(OutPins[i], OUTPUT);
  }

  pinMode(pir1, INPUT);
  pinMode(pir2, INPUT);
  /*
    noInterrupts();         // disable all interrupts
    TCCR1A = 0;             // set entire TCCR1A register to 0  //set timer1 interrupt at 1kHz  // 1 ms
    TCCR1B = 0;             // same for TCCR1B
    TCNT1  = 0;             // set timer count for 1khz increments
    OCR1A = 1999;           // = (16*10^6) / (1000*8) - 1
    //had to use 16 bit timer1 for this bc 1999>255, but could switch to timers 0 or 2 with larger prescaler
    // turn on CTC mode
    TCCR1B |= (1 << WGM12); // Set CS11 bit for 8 prescaler
    TCCR1B |= (1 << CS11);  // enable timer compare interrupt
    TIMSK1 |= (1 << OCIE1A);
    interrupts();           // enable
  */
  delay(1000); // Waiting for a while
  Serial.println("code started");
}

void loop()
{
  // put your main code here, to run repeatedly:
  Serial.print("sensor reading1: ");
  Serial.print(analogRead(pir1));
  Serial.print("   sensor reading2: ");
  Serial.println(analogRead(pir2));
  delay(1000);
  if (analogRead(pir1) >= 500)
  {
    second = true;
    if (first)
    {
      Serial.println(analogRead(A0));
      for (i = 0; i < 14; i++)
      {
        digitalWrite(OutPins[i], HIGH);
        delay(set_shift);
      }
      delay(4000);
      for (i = 0; i < 14; i++)
      {
        digitalWrite(OutPins[i], LOW);
      }
      Serial.println("going off");
      first = false;
    }
  }

  if (analogRead(pir2) >= 500)
  {
    first = true;
    if (second)
    {
      Serial.println(analogRead(A1));
      for (i = 13; i >= 0; i--)
      {
        digitalWrite(OutPins[i], HIGH);
        delay(set_shift);
      }
      delay(4000);
      for (i = 0; i < 14; i++)
      {
        digitalWrite(OutPins[i], LOW);
      }
      Serial.println("going on");
      second = false;
    }
  }
}
