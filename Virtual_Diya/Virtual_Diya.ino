/*
 * Copyright 2017 Er. Rahul Rathi.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Simple Diya Using Arduino & Bluethoot (IOT).
 * Implimented For BMCET diya lighting ceremony IOT Project.
 * @author Er. Rahul Rathi (BMCET/CSE).
 */


// CMD Holder
char data = 0;

// PINS
int p1=8,
  p2=9,
  p3=10,
  p4=11,
  err=13;
  
void setup()
{
  // LED 1
  pinMode(p1,OUTPUT);
  // LED 2
  pinMode(p2,OUTPUT);
  // LED 3
  pinMode(p3,OUTPUT);
  // LED 4
  pinMode(p4,OUTPUT);
  // Runtime Error & Debug Cheacker Executor
  pinMode(err,OUTPUT);
  pinMode(LED_BUILTIN,OUTPUT);
  // Serial Comm
  Serial.begin(9600); 
}

void loop() 
{
  if(Serial.available() > 0)      
   {
      data = Serial.read();
      Serial.print(data);        
      if(data == '0')
      {              
         digitalWrite(p1, HIGH); 
      } 
      else if(data == '1')  
      {       
         digitalWrite(p2, HIGH);    
      }
       else if(data == '2')  
      {       
         digitalWrite(p3, HIGH);    
      }
       else if(data == '3')  
      {       
         digitalWrite(p4, HIGH);    
      }
       else if(data > '3')  
      {       
         digitalWrite(err, HIGH);    
         digitalWrite(LED_BUILTIN, HIGH);
      }
      else
      {
        digitalWrite(LED_BUILTIN, LOW);
        digitalWrite(err, LOW); 
      }
   }
}

            



