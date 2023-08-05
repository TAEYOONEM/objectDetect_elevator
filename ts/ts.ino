void setup()

{

  Serial.begin(9600);

}

 

void loop()

{

  if (Serial.available()){                 // 만약 시리얼 통신이 온다면

          char data = Serial.read();  // 시리얼 통신 값을 문자형변수 data에 저장

          Serial.println(data);                     // 그 값을 출력

  }

 

  delay(100);

 

}
