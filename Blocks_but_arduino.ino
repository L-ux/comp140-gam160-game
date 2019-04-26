#define sliderOne A0
#define sliderTwo A1
int sliderOnePosition;
int sliderTwoPosition;

#define encoderOne 3
#define encoderTwo 4
int rotationCount = 0;
int encoderState;
int encoderPriorState;

#define buttonOne 6
bool buttonPressed = false;

char incoming;


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
  if (encoderState != encoderPriorState) // encoder has moved
  {
    if (encoderState != digitalRead(encoderTwo)) // encoder has moved clockwise
    {
      rotationCount++;
    }
    else // encoder has moved counter clockwise
    {
      rotationCount--;
    }
  }
  encoderPriorState = encoderState;

  // button Check
  if (digitalRead(buttonOne) == HIGH)
  {
    buttonPressed = true;
  }



  // Check for read/write

  if(Serial.available() > 0)
  {
    incoming = Serial.read();

    if (incoming = 'A')
    {
      sliderOnePosition = analogRead(sliderOne);
      sliderTwoPosition = analogRead(sliderTwo);


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
