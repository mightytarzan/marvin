
int up = 3;
int down = 2;
int left = 5;
int right = 10;
int power = 7;
int clean = 8;
int dock = 9;

char inData[20]; 
char inChar=-1; 
byte index = 0; 

char Comp(char* This) {
    while (Serial.available() > 0)
                                  
    {
        if(index < 19) 
        {
            inChar = Serial.read(); 
            inData[index] = inChar; 
            index++; 
            inData[index] = '\0'; 
        }
    }

    if (strcmp(inData,This)  == 0) {
        for (int i=0;i<19;i++) {
            inData[i]=0;
        }
        index=0;
        return(0);
    }
    else {
        return(1);
    }
}


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(up, OUTPUT);  
  pinMode(down, OUTPUT);  
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);
  pinMode(power, OUTPUT);
  pinMode(clean, OUTPUT);
  pinMode(dock, OUTPUT);
  Serial.begin(9600); 
  Serial.println("Power On");  
}

void go(int button) {
    digitalWrite(button, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(2000);               // wait for a second
    digitalWrite(button, LOW);    // turn the LED off by making the voltage LOW
}

// the loop routine runs over and over again forever:
void loop() {
      if (Comp("down")==0) {
        Serial.write("down\n");
        go(down);
        Serial.write("down end\n");
        
      } else if (Comp("up")==0) {
        Serial.write("up\n");
        go(up);
        Serial.write("up end\n");
        
      } else if (Comp("left")==0) {
        Serial.write("left\n");
        go(left);
        Serial.write("left end\n");
        
      } else if (Comp("right")==0) {
        Serial.write("right\n");
        go(right);
        Serial.write("right end\n");
        
      } else if (Comp("power")==0) {
        Serial.write("power\n");
        go(power);
        Serial.write("power end\n");
        
      } else if (Comp("clean")==0) {
        Serial.write("clean\n");
        go(clean);
        Serial.write("clean end\n");
      
      } else if (Comp("dock")==0) {
        Serial.write("dock\n");
        go(dock);
        Serial.write("dock end\n");
      }
  
}
