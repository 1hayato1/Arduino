int data;
float L;
//  圧電スピーカー
#define SPK_PIN 13
//  圧力センサー
const int vol_pin = 0;//圧力センサ用アナログピン

// 音
//tone(pin,262,melo); // ド
//tone(pin,294,melo); // レ
//tone(pin,330,melo); // ミ
//tone(pin,349,melo); // ファ
//tone(pin,392,melo); // ソ
//tone(pin,440,melo); // ラ
//tone(pin,494,melo); // シ
//tone(pin,523,melo); // ド

void setup() {
    //pinMode(SPK_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    // 距離センサー
    // 距離センサーからの読み込み
    data = analogRead(5);
    L = 21000 * pow(data, -1.252);
    Serial.println(L);
    delay(300);

    // 圧力センサー
    // アナログピンの入力値を読み込み
    int sensorValue = analogRead(vol_pin);
    //Serial.println(sensorValue);
    //遅延
    delay(300);

    //センサーの値が950未満になったら音をならす
    if (sensorValue < 950) {
        if (L <= 18) {
            tone(SPK_PIN, 262);//低いド
        }
        else if (L <= 25) {
            tone(SPK_PIN, 294);//レ
        }
        else if (L <= 33) {
            tone(SPK_PIN, 330);//ミ
        }
        else if (L <= 41) {
            tone(SPK_PIN, 349);//ファ
        }
        else if (L <= 49) {
            tone(SPK_PIN, 392);//ソ
        }
        else if (L <= 57) {
            tone(SPK_PIN, 440);//ラ
        }
        else if (L <= 65) {
            tone(SPK_PIN, 494);//シ
        }
        else if (L <= 73) {
            tone(SPK_PIN, 523);//高いド
        }
    }
    else {
        noTone(SPK_PIN);//鳴らさない
    }
}