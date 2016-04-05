
// original code from http://reprap.org/wiki/RAMPS_1.4
// adapted for Makers of Norrköping, TinyBoy and the mamma/barn 3d printer project...
//

// x axis pins...
#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define X_MIN_PIN           3
#define X_MAX_PIN           2

// y axis pins...
#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15

// z axis pins...
#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19

// extruder pins...
#define E_STEP_PIN         26
#define E_DIR_PIN          28
#define E_ENABLE_PIN       24

// note: not used...
#define Q_STEP_PIN         36
#define Q_DIR_PIN          34
#define Q_ENABLE_PIN       30

#define SDPOWER            -1
#define SDSS               53
#define LED_PIN            13

#define FAN_PIN            9

#define PS_ON_PIN          12
#define KILL_PIN           -1

#define HEATER_0_PIN       10

// note: not used...
#define HEATER_1_PIN       8

#define TEMP_0_PIN          13   // note: ANALOG NUMBERING

// note: not used...
#define TEMP_1_PIN          14   // note: ANALOG NUMBERING
#define TEMP_2_PIN          15   // note: ANALOG NUMBERING

void setup() 
{
  Serial.begin(9600);          //  setup serial

  // setup pin modes for all used pins...
  pinMode(FAN_PIN,      OUTPUT);
  pinMode(HEATER_0_PIN, OUTPUT);
  pinMode(HEATER_1_PIN, OUTPUT);
  pinMode(LED_PIN,      OUTPUT);
  
  pinMode(X_STEP_PIN,   OUTPUT);
  pinMode(X_DIR_PIN,    OUTPUT);
  pinMode(X_ENABLE_PIN, OUTPUT);
  
  pinMode(Y_STEP_PIN,   OUTPUT);
  pinMode(Y_DIR_PIN,    OUTPUT);
  pinMode(Y_ENABLE_PIN, OUTPUT);
  
  pinMode(Z_STEP_PIN,   OUTPUT);
  pinMode(Z_DIR_PIN,    OUTPUT);
  pinMode(Z_ENABLE_PIN, OUTPUT);
  
  pinMode(E_STEP_PIN,   OUTPUT);
  pinMode(E_DIR_PIN,    OUTPUT);
  pinMode(E_ENABLE_PIN, OUTPUT);

  // note: not used...
  pinMode(Q_STEP_PIN,   OUTPUT);
  pinMode(Q_DIR_PIN,    OUTPUT);
  pinMode(Q_ENABLE_PIN, OUTPUT);

  // suitable start values...
  // disable all motor drivers...
  digitalWrite(X_ENABLE_PIN, LOW);
  digitalWrite(Y_ENABLE_PIN, LOW);
  digitalWrite(Z_ENABLE_PIN, LOW);
  digitalWrite(E_ENABLE_PIN, LOW);
  digitalWrite(Q_ENABLE_PIN, LOW);

  // turn everything else off.
  digitalWrite(FAN_PIN,      0);
  digitalWrite(HEATER_0_PIN, 0);
  digitalWrite(HEATER_1_PIN, 0);
  digitalWrite(LED_PIN,      0);
}

void loop () 
{
  //*****************
  // led blinking...
  //*****************
  if (millis() %1000 < 500)
  {
    digitalWrite(LED_PIN, HIGH);
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
  }

  //******************************
  // excercise heaters and fan...
  //******************************
  if (millis() %1000 < 300) 
  {
    digitalWrite(HEATER_0_PIN, HIGH);
    digitalWrite(HEATER_1_PIN, LOW);
    digitalWrite(FAN_PIN, LOW);
  } 
  else if (millis() %1000 < 600) 
  {
    digitalWrite(HEATER_0_PIN, LOW);
    digitalWrite(HEATER_1_PIN, HIGH);
    digitalWrite(FAN_PIN, LOW);
  } 
  else  
  {
    digitalWrite(HEATER_0_PIN, LOW);
    digitalWrite(HEATER_1_PIN, LOW);
    digitalWrite(FAN_PIN, HIGH);
  }

  //*************************
  // excercise the motors...
  //*************************

  // set direction...
  if (millis() %10000 < 5000) 
  {
    digitalWrite(X_DIR_PIN, HIGH);
    digitalWrite(Y_DIR_PIN, HIGH);
    digitalWrite(Z_DIR_PIN, HIGH);
    digitalWrite(E_DIR_PIN, HIGH);
    digitalWrite(Q_DIR_PIN, HIGH);
  }
  else 
  {
    digitalWrite(X_DIR_PIN, LOW);
    digitalWrite(Y_DIR_PIN, LOW);
    digitalWrite(Z_DIR_PIN, LOW);
    digitalWrite(E_DIR_PIN, LOW);
    digitalWrite(Q_DIR_PIN, LOW);
  }

  // stepping...
  digitalWrite(X_STEP_PIN, HIGH);
  digitalWrite(Y_STEP_PIN, HIGH);
  digitalWrite(Z_STEP_PIN, HIGH);
  digitalWrite(E_STEP_PIN, HIGH);
  digitalWrite(Q_STEP_PIN, HIGH);
  delay(1);

  digitalWrite(X_STEP_PIN, LOW);
  digitalWrite(Y_STEP_PIN, LOW);
  digitalWrite(Z_STEP_PIN, LOW);
  digitalWrite(E_STEP_PIN, LOW);
  digitalWrite(Q_STEP_PIN, LOW);

  // read temperature values...
//  if (millis() %1000 < 0)
  {
    int val = analogRead(TEMP_0_PIN);
    Serial.println(val);
  } 
  
}


