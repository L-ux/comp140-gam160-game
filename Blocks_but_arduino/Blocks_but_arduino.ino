#define sliderOne A0 // Horizontal X
#define sliderTwo A1 // Vertical Y
int sliderOnePosition;
int sliderTwoPosition;

#define encoderOne 9
#define encoderTwo 10
int rotationCount = 0;
int encoderState;
int encoderPriorState;

#define buttonOne 8
bool buttonPressed = false;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sliderOne, INPUT);
  pinMode(sliderTwo, INPUT);
  pinMode(encoderOne, INPUT);
  pinMode(encoderTwo, INPUT);
  pinMode(buttonOne, INPUT);
  encoderPriorState = digitalRead(encoderOne);
}

void loop() 
{
  // put your main code here, to run repeatedly:

  // encoderCheck
  encoderState = digitalRead(encoderOne);
  if (encoderState == encoderPriorState)
  {
  }
  else
  {
    if (encoderState == digitalRead(encoderTwo)) // CCW
    {
      rotationCount--;
    }
    else        // CW
    {
      rotationCount++;
    }
    encoderPriorState == encoderState;
  }
  

  
  // button Check

  if (digitalRead(buttonOne) == HIGH)
  {
    buttonPressed = true;
  }

  // Check for read/write
  
  if(Serial.available() > 0)
  {
    char incoming = Serial.read();
    if (incoming == 'U')
    {
      sliderOnePosition = analogRead(sliderOne);
      sliderTwoPosition = analogRead(sliderTwo);

      String bigString = intToString(sliderOnePosition);
      bigString = bigString + "-" + intToString(sliderTwoPosition);
      bigString = bigString + "-" + intToString(rotationCount);
      bigString = bigString + "-" + buttonPressed;
      Serial.println(bigString);
      buttonPressed = false;
    }
    
  }
}
String intToString(int num)
{
  char buff[5];
  char padded[6];

  sprintf(buff, "%.4u", num); // convert and save it to buffer (buff)
  
  for(int i = 0; i < 5; i++)
    padded[i] = buff[i];
  padded[5] = '\0';

  return String(padded);

}
