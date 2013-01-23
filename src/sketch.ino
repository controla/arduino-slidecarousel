// Control 4 Kodak Carousel slide projectors with timing for each slide
// (cc) 2012-2013
// by: Gonzalo Ramírez Restucci (gonzalo@resist.cl)
// for "Eigenlicht" by Regina de Miguel.

//  pulse duration
int relayPulse = 700;

unsigned long seconds;

// array with pins for each relay
int cPin[4] = {7,6,5,4};

// position counter for each carousel with initial positions (1-1-1-1)
int cPos[4] = {1,1,1,1};

// arrays with intervals for each carousel
int cTime[4][81] = {
// 00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,60,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80
  {00,05,05,05,05,05,05,05,05,00,05,05,05,05,05,05,05,05,05,00,05,05,05,05,05,05,05,05,00,05,05,05,05,05,05,05,05,00,05,05,05,05,05,05,05,05,05,00,05,05,05,05,05,05,05,05,05,05,00,05,05,05,05,05,05,05,05,05,00,05,05,05,05,05,05,05,05,05,05,05,00},
  {00,05,05,05,05,05,05,05,05,00,05,05,05,05,05,05,05,05,05,00,05,05,05,05,05,05,05,05,00,05,05,05,05,05,05,05,05,00,05,05,05,05,05,05,05,05,05,00,05,05,05,05,05,05,05,05,05,05,00,05,05,05,05,05,05,05,05,05,00,05,05,05,05,05,05,05,05,05,05,05,00},
  {00,05,05,05,05,05,05,05,05,00,05,05,05,05,05,05,05,05,05,00,05,05,05,05,05,05,05,05,00,05,05,05,05,05,05,05,05,00,05,05,05,05,05,05,05,05,05,00,05,05,05,05,05,05,05,05,05,05,00,05,05,05,05,05,05,05,05,05,00,05,05,05,05,05,05,05,05,05,05,05,00},
  {60,05,05,05,05,05,05,05,05,60,05,05,05,05,05,05,05,05,05,60,05,05,05,05,05,05,05,05,60,05,05,05,05,05,05,05,05,60,05,05,05,05,05,05,05,05,05,60,05,05,05,05,05,05,05,05,05,05,60,05,05,05,05,05,05,05,05,05,60,05,05,05,05,05,05,05,05,05,05,05,00}
};

void setup() {
  pinMode(cPin[0], OUTPUT);
  pinMode(cPin[1], OUTPUT);
  pinMode(cPin[2], OUTPUT);
  pinMode(cPin[3], OUTPUT);
  Serial.begin(9600);
  delay(5000); // wait 5 seconds until everything's running.
}

void loop() {       
  for(int i=0;i<4;i++) {
    advanceSlide(i);
  }
}

void advanceSlide(int thisCar) {
  seconds = cTime[thisCar][cPos[thisCar]] * 1000; // duration of next step

  Serial.print("Moving carousel #");
  Serial.println(thisCar);

  digitalWrite(cPin[thisCar],HIGH);
  delay(relayPulse);
  digitalWrite(cPin[thisCar],LOW);

  cPos[thisCar]++;  // advance position for current car
  if (cPos[thisCar] > 80) { cPos[thisCar] = 0; }

  Serial.print("now at: ");
  Serial.println(cPos[thisCar]);

  Serial.print("waiting: ");
  Serial.print(seconds/1000);
  Serial.println(" seconds.");
  Serial.println("--");     

  delay(seconds);
}
