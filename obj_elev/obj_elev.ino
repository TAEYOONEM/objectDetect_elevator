#define MAX_FLOOR 5

int seg[7] = {2,3,4,5,6,7,8};
int num[10][7] = {
  {1,1,1,1,1,1,0}, //0
  {0,1,1,0,0,0,0}, //1
  {1,1,0,1,1,0,1}, //2
  {1,1,1,1,0,0,1}, //3
  {0,1,1,0,0,1,1}, //4
  {1,0,1,1,0,1,1}, //5
  {1,0,1,1,1,1,1}, //6
  {1,1,1,0,0,0,0}, //7
  {1,1,1,1,1,1,1}, //8
  {1,1,1,0,0,1,1}  //9
};

String state = "STOP";

long input;
long now_floor = 1;
long up_floors[MAX_FLOOR];
long up_cnt;

bool up_done = false;

void set_state();
void get_upfloors(char ch); 
void up_floor();
void get_downfloors(char ch);
void down_floor();
void set_nowfloor();

void setup() {
  Serial.begin(9600); 

  for(int i = 0; i < 7; i++)
    pinMode(seg[i],OUTPUT);
  
  for(int i=0;i<MAX_FLOOR;i++){
    up_floors[i] = 0;
  }

}

void loop() {
  set_state();
  get_upfloors(ch);
  up_floor();
  delay(500);
  set_nowfloor();
}

void set_state(){
  if(state == "STOP"){
    if(Serial.available())
      char ch = Serial.read()  
  }
  switch(ch) :
    case 'u' :
      state = "UP";
      break;
    case 'd' :
      state = "DOWN";
      break;
    default :
      return;  
}

void get_upfloors(char ch){
  if(ch == 'u' and now_floor== 1){
    Serial.println("o");
    while(true){      
      if(Serial.available()){
        input = Serial.parseInt();
        if(input == -1)
          break;
        if(input > 0){
          *(up_floors+up_cnt) = input; 
          up_cnt ++;      
        }
      }
    }       
  }
}

void up_floor(){
  if(up_cnt != 0){  
    if(up_floors[up_cnt-1] != 0){
      now_floor= up_floors[up_cnt-1];
      up_floors[up_cnt-1] = 0;
      up_cnt --;
    } 
    if(up_cnt==0)
      up_done = true;
  }
}

void get_downfloors(char ch){
  if(ch == 'd'){
    Serial.println('o');
    if(Serial.available()){
      
      
    }  
  }

}

void set_nowfloor(){
  for(int j = 0; j < 7; j++)
    digitalWrite(seg[j], num[now_floor][j]);      
}
