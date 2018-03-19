#Copyright [2018] [zy-explorer]
#Licensed under the Apache License, Version 2.0 (the "License");
#you may not use this file except in compliance with the License.You may obtain a copy of the License at
# 
#http://www.apache.org/licenses/LICENSE-2.0
#
#Unless required by applicable law or agreed to in writing, software
#distributed under the License is distributed on an "AS IS" BASIS,
#WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#See the License for the specific language governing permissions andlimitations under the License.

#ifndef _DELAY_H_
#define _DELAY_H_
#define uchar unsigned char
void delay_ms(uchar z)
{ 
     uchar i,j; 
     for(i=z;i>0;i--)   
        for(j=120;j>0;j--);
}
void delayms_100ms()
{  

     delay_ms(100); 
     
}
void delayms_1000ms()
{  
     uchar i;  
     for(i=0;i<10;i++)         
          delayms_100ms();
}
void delayms_10s() 
{   
     uchar i;  
     for(i=0;i<10;i++)         
         delayms_1000ms();
}
#endif
