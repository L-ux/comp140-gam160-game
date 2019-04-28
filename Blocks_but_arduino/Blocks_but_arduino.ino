#define sliderOne A0 // Horizontal X
#define sliderTwo A1 // Vertical Y
int sliderOnePosition;
int sliderTwoPosition;

#define encoderOne 3
#define encoderTwo 4
int rotationCount = 0;
int encoderState;
int encoderPriorState;

#define buttonOne 6
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
      

//      Serial.print(intToString(sliderOnePosition));
//      Serial.print("-");
//      Serial.print(intToString(sliderTwoPosition));
//      Serial.print("-");
//      Serial.print(intToString(rotationCount));
//      Serial.print("-");
//      Serial.println(buttonPressed);


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
