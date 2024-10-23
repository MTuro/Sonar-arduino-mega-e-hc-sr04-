long duration;
int distance;

const int TRIG = 22;
const int ECHO = 2;

void setup() {
  // Configuração dos pinos
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.begin(115200);
  Serial.println("iniciado...");
}

void loop() {
  // Enviar pulso para o sensor
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Ler o tempo de duração do pulso no pino ECHO
  duration = pulseIn(ECHO, HIGH);

  // Calcular a distância = duracao do pulso x velocidade do som (em cm) / 2 pela ida e volta 
  distance = duration * 0.034 / 2;

  // Exibir a distância no Serial Monitor
  Serial.print("Distância: ");
  Serial.println(distance);
}
