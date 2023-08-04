#define MAX_FLOOR 5

int input;
int now_floor = 1;
int up_floors[MAX_FLOOR];
int up_cnt;
int down_floors[MAX_FLOOR];
int down_cnt;

bool first_flag = true;

void sort();
void rev_sort();

void setup(){
 Serial.begin(9600); 
 for(int i=0;i<MAX_FLOOR;i++){
  up_floors[i] = 0;
  down_floors[i] = 0; 
 }
 Serial.println("Elevator on");
}

void loop(){  
  char ch;
  ch = Serial.read();  
  
  delay(100);
  // 올라갈 층 입력 받기
  if(ch == 'u' and now_floor== 1){
    Serial.println("got_up");
    while(true){      
      if(Serial.available()){
        input = Serial.parseInt();
        if(input == -1)
          break;
        if(input > 0){
          Serial.println(input);
          *(up_floors+up_cnt) = input; 
          up_cnt ++;      
        }
      }
    }
    // up_cnt 는 up_arr의 실질적 길이와 같은 크기
//    up_sort();  
  }       
  delay(100);
  if(up_cnt != 0){  
    if(up_floors[up_cnt-1] != 0){
      now_floor= up_floors[up_cnt-1];
      up_floors[up_cnt-1] = 0;
      up_cnt --;
      Serial.print("Now floor is");
      Serial.println(now_floor);
    } 
  }
  
  else{
    delay(100);
    if(ch == 'd'){     
      Serial.println("got_down");
      if(first_flag){
        while(true){
          if(Serial.available()){
            input = Serial.parseInt();
            if(input == -1 )
              break;
            if(input > 0){
              Serial.println(input);
              *(down_floors+down_cnt) = input; 
              down_cnt ++;      
            }
          }
          first_flag = false;
        }
      }
      else {
        while(true){
          if(Serial.available()){
            input = Serial.parseInt();
            if(input == 0 )
              break;
            if(input < now_floor){
              Serial.println(input);
              *(down_floors+down_cnt) = input; 
              down_cnt ++;                  
            }
          }
        }
      }
//      rev_sort();
    }
    delay(100);
    // down_cnt 는 down_arr의 실질적 길이    
    if(down_cnt != 0){
      if(down_floors[down_cnt-1] != 0){
        now_floor = down_floors[down_cnt-1];
        down_floors[down_cnt-1] = 0;
        down_cnt --;
        Serial.print("Now floor is");
        Serial.println(now_floor);       
        if(down_cnt == 0){      
          now_floor= 1;
          Serial.print("Now floor is");
          Serial.println(now_floor);
          first_flag = true;
        }  
      }     
    }    
  }       
}     
                
void up_sort(){
  for(int a=0; a<up_cnt-1; a++){
    for(int b=a+1; b<up_cnt; b++){          
      if(up_floors[a]<up_floors[b]){ 
        int temp = up_floors[a];
        up_floors[a] = up_floors[b];
        up_floors[b] = temp;  
      }
    }
  }
}
 
void rev_sort(){
  for(int a=0; a<down_cnt-1; a++){
    for(int b=a+1; b<down_cnt; b++){          
      if(down_floors[a]>down_floors[b]){ 
        int temp = down_floors[a];
        down_floors[a] = down_floors[b];
        down_floors[b] = temp;  
      }
    }
  }
}
