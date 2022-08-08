int data;
float L;
//  ���d�X�s�[�J�[
#define SPK_PIN 13
//  ���̓Z���T�[
const int vol_pin = 0;//���̓Z���T�p�A�i���O�s��

// ��
//tone(pin,262,melo); // �h
//tone(pin,294,melo); // ��
//tone(pin,330,melo); // �~
//tone(pin,349,melo); // �t�@
//tone(pin,392,melo); // �\
//tone(pin,440,melo); // ��
//tone(pin,494,melo); // �V
//tone(pin,523,melo); // �h

void setup() {
    //pinMode(SPK_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    // �����Z���T�[
    // �����Z���T�[����̓ǂݍ���
    data = analogRead(5);
    L = 21000 * pow(data, -1.252);
    Serial.println(L);
    delay(300);

    // ���̓Z���T�[
    // �A�i���O�s���̓��͒l��ǂݍ���
    int sensorValue = analogRead(vol_pin);
    //Serial.println(sensorValue);
    //�x��
    delay(300);

    //�Z���T�[�̒l��950�����ɂȂ����特���Ȃ炷
    if (sensorValue < 950) {
        if (L <= 18) {
            tone(SPK_PIN, 262);//�Ⴂ�h
        }
        else if (L <= 25) {
            tone(SPK_PIN, 294);//��
        }
        else if (L <= 33) {
            tone(SPK_PIN, 330);//�~
        }
        else if (L <= 41) {
            tone(SPK_PIN, 349);//�t�@
        }
        else if (L <= 49) {
            tone(SPK_PIN, 392);//�\
        }
        else if (L <= 57) {
            tone(SPK_PIN, 440);//��
        }
        else if (L <= 65) {
            tone(SPK_PIN, 494);//�V
        }
        else if (L <= 73) {
            tone(SPK_PIN, 523);//�����h
        }
    }
    else {
        noTone(SPK_PIN);//�炳�Ȃ�
    }
}