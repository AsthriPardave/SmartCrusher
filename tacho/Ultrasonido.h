class Ultrasonido{
    private: 
        int echo;
        int trigger;
    
        void disparar(){
            digitalWrite(trigger, HIGH);
            delayMicroseconds(10);          //Enviamos un pulso de 10us
            digitalWrite(trigger, LOW);
        }

    public:

        Ultrasonido(int echo, int trigger){
            this->echo = echo;
            this->trigger = trigger;
            pinMode(trigger, OUTPUT);
            pinMode(echo, INPUT);
        }

        int obtenerDistancia(){
            disparar();
            int t;
            int d;
            t = pulseIn(this->echo, HIGH); //obtenemos el ancho del pulso
            d = t/59;
            return d;
        }
};