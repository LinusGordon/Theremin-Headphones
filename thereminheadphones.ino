/*
 * Theremin Headphones
 * By: Linus Gordon
 * 
 * This program uses an ultrasonic sensor, two buzzers, and the Light 
 * Blue Bean Arduino to create a personal theremin. The two buzzers
 * are inserted into earbuds so the user can play the theremin by themselves.
 */

#define TRIG 2 
#define ECHO 0
#define BUZZER_L 1 // left earbud
#define GROUND_3 3
#define BUZZER_R 4 // right earbud
#define GROUND_2 5
#define MAX_FREQ 1048 // highest note
#define MIN_FREQ 131  // lowest note

long int pitch;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600); 
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  
  pinMode(BUZZER_R, OUTPUT);
  pinMode(BUZZER_L, OUTPUT);
  
  pinMode(GROUND_2, OUTPUT);
  pinMode(GROUND_3, OUTPUT);

  /* Three grounds were needed because of the way the hardware and
     PCB circuit board were originally configured */
  digitalWrite(GROUND_2, 0);
  digitalWrite(GROUND_3, 0);
  
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

  /* Calculate note to play based on distance from
   * hand from UltraSonic sensor
   */
  pitch = MIN_FREQ + (duration / 4);
  
  if(pitch > MAX_FREQ) {
    pitch = MAX_FREQ;
  }

  /* play notes on both buzzers */
  tone(BUZZER_R, pitch);
  tone(BUZZER_L, pitch);

  delay(100); 
}
