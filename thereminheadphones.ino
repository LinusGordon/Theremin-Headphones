#define TRIG 2 
#define ECHO 0
#define BUZZER 4
#define GROUND_2 5
#define MAX_FREQ 1048
#define MIN_FREQ 131

long int pitch;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600); 
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, 4);
  pinMode(GROUND_2, OUTPUT);
  digitalWrite(GROUND_2, 0);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration; 

  // Start low 
   digitalWrite(TRIG, LOW);

  // Wait before going high 
  delay(15); 

  // Go high 
  digitalWrite(TRIG, HIGH);

  // Pulse in to read time 
  duration = pulseIn(ECHO, HIGH);

  Serial.print(duration); 

  pitch = MIN_FREQ + (duration / 4);
  if(pitch > MAX_FREQ) {
    pitch = MAX_FREQ;
  }
  
  tone(BUZZER, pitch);

  delay(100); 
}
