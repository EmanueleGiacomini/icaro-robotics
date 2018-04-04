/**
 * linea.ino
 * Breve guia all'uso dei sensori di linea
 * @author Emanuele Giacomini 4/4/2018
 */

#include <PID_v1.h>

#define NUMERO_SENSORI 5

int pin_linea[NUMERO_SENSORI] = {A0, A1, A2, A3, A4};
int posizione_associata[NUMERO_SENSORI] = {-2, -1, 0, 1, 2};
int soglia[NUMERO_SENSORI] = {500, 500, 500, 500, 500};

// Variabili PID
//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Specify the links and initial tuning parameters
double Kp=0, Ki=0, Kd=0;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

// Variabili motori
#define VELOCITA 100
#define VELOCITA_CURVA_STRETTA 180

int pin_dir_a = 12;
int pin_pwm_a = 11;
int pin_dir_b = 7;
int pin_pwm_b = 8;

void setup() {
  Serial.begin(9600);
  Serial.println("Seriale inizializzata!");

  for(int i = 0; i < NUMERO_SENSORI; i++) {
    pinMode(pin_linea[i], INPUT);
  }

  pinMode(pin_dir_a, OUTPUT);
  pinMode(pin_pwm_a, OUTPUT);
  pinMode(pin_dir_b, OUTPUT);
  pinMode(pin_pwm_b, OUTPUT);

  Input = 0;
  Setpoint = 0;
  myPID.setMode(AUTOMATIC);
  myPID.setOutputLimits(-255, 255);
}

void leggiLineaDigitale(int pin[], int soglia[], int output[]) {
  for(int i = 0; i < NUMERO_SENSORI; i++) {
    if(analogRead(pin[i]) > soglia[i]) {
      output[i] = 1;
    } else {
      output[i] = 0;
    }
  }
}
// Conta elementi in un vettore
int vettoreConta(int vettore[], int dim, int n) {
  int counter = 0;
  for(int i = 0; i < dim; i++) {
    if(vettore[i] == n) counter++;
  }
  return counter;
}

int calcolaSfasamentoLinea(int lettura_digitale[], int posizione_associata[]) {
  static int ultimo_sfasamento = 0;
  int num_sensori_rilevati = vettoreConta(lettura_digitale, NUMERO_SENSORI, 1);
  if(num_sensori_rilevati > 0) {
    ultimo_sfasamento = 0;
    // Attualmente almeno un sensore vede la linea
    for( int i = 0; i < NUMERO_SENSORI; i++) {
      ultimo_sfasamento += lettura_digitale[i] * posizione_associata[i];
    }
    ultimo_sfasamento /= num_sensori_rilevati;
    return ultimo_sfasamento;
    } else {
    // Nessun sensore sta vedendo la linea
    if(ultimo_sfasamento > 0) return posizione_associata[NUMERO_SENSORI-1]+1;
    return posizione_associata[0] - 1;
  }
}

void muoviMotore(int pin_dir, int pin_pwm, int velocita) {
  if(velocita > 0) {
    digitalWrite(pin_dir, HIGH);
    analogWrite(pin_pwm, velocita);
  } else {
    digitalWrite(pin_dir, LOW);
    analogWrite(pin_pwm, -velocita);
  }
}

void loop() {
  int letture_digitali[NUMERO_SENSORI];
  leggiLineaDigitale(pin_linea, soglia, letture_digitali);
  int sfasamento = calcolaSfasamentoLinea(letture_digitali, posizione_associata);

  if(sfasamento < posizione_associata[0]) {
    // Ho perso la linea a sinsitra
    muoviMotore(pin_dir_a, pin_pwm_a, VELOCITA_CURVA_STRETTA);
    muoviMotore(pin_dir_b, pin_pwm_b, -VELOCITA_CURVA_STRETTA);
  }
  if(sfasamento > posizione_associata[NUMERO_SENSORI-1]) {
    // Ho perso la linea a destra
    muoviMotore(pin_dir_a, pin_pwm_a, -VELOCITA_CURVA_STRETTA);
    muoviMotore(pin_dir_b, pin_pwm_b, VELOCITA_CURVA_STRETTA);
  }

  Input = sfasamento;
  myPID.Compute();

  muoviMotore(pin_dir_a, pin_pwm_a, VELOCITA + Output);
  muoviMotore(pin_dir_b, pin_pwm_b, VELOCITA - Output);
}
