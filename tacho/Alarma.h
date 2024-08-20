class Alarma{
    private:
        int alarma;

    public:
        Alarma(int alarma){
            this->alarma = alarma;
            pinMode(alarma, OUTPUT);
        }

        void prenderPitido(){
            digitalWrite(this->alarma, HIGH);
        }
        void apagarPitido(){
            digitalWrite(this->alarma, LOW);
        }
};