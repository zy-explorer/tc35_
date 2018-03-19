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

#include"reg52.h"
#include "1602.h"
#include "uart.c"
#include "tc35.c"

//#define RsBuf_N   50

//char RsBuf[RsBuf_N]; //定义串口接收数据缓冲区
//uchar RsPoint=0;

sbit MQ2=P2^7;
sbit HUOYAN=P2^3;
sbit HONGWAI=P2^0;

sbit huang=P2^6;
sbit hong=P2^5;
sbit lv=P2^4;
sbit buzz=P2^2;
sbit jk=P2^1;

uchar code PhoneNO[]= "+8618011461069";
uchar code Text1[]= "Harmfulgases";
uchar code Text2[]= "Fire";
uchar code Text3[]= "Theft";

uchar code center[]="+8613800451500";

void main()
{ 
    jk=0;
//  TC35_init(); 
    Uart_init(); 
    init_1602();
    
    Send_AT(); 
    
    Set_MODE(1);    //设置短消息模式                  
    Set_CENTER(center);  // 设置短消息中心     AT+CSCA=“+8613800531500”回车
    while(1)
    {  
        if(MQ2==0) 
        {   
             lv=0;  
             buzz=0;
             
             TransmitText(PhoneNO,Text1);      
             
             jk=1;   
             while(1);  
         }  
         if(HUOYAN==0) 
         {   
             huang=0;   
             buzz=0;
             
             TransmitText(PhoneNO,Text2);    
             jk=1;  
             while(1); 
          }  
          if(HONGWAI==0) 
          {  
             hong=0;  
             buzz=0;   
             TransmitText(PhoneNO,Text3);   
             while(1);  
           }
       }
  //lcd_disp_str(RsBuf ,2);  
 }
  
