//global variables
int led = LED_BUILTIN;
int TASK_1_INTERVAL = 500;  //Blink on for 500 milliseconds

unsigned long time_1 = 0;

// the setup function runs once when you press reset or power the board
void setup() 
{
  //Set up serial port
  Serial.begin(9600);
  delay(500);
  Serial.println("Blink startup");

  // initialize the LED pin as an output.
  pinMode(led, OUTPUT);

  //Set timers to current time.
  time_1 = millis();
  Serial.println("time_1  = " + String(time_1));
}

// the loop function runs over and over again forever
void loop() 
{
  unsigned long timeNow = 0;
  static boolean BlinkOn;

  timeNow = millis();

  if (timeNow > time_1 + TASK_1_INTERVAL)
  {
      Serial.println("timeNow  = " + String(timeNow));
      time_1 += TASK_1_INTERVAL;
      digitalWrite (led, BlinkOn);
      BlinkOn = !BlinkOn;
  }
}