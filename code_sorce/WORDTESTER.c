#include <mega128.h>
#include <delay.h>
#include <alcd.h>

//PORTF=LED,PORTA=switch,PORTD=FND
unsigned char i=0, sw, k;
//1:1,2:2,3:1,4:2,5:2     
char num1[]="Talk";
char num1_1[]="1.Conversation";
char num1_2[]="2.Conservation";
char num2[]="Influence";
char num2_1[]="1.Effect";
char num2_2[]="2.Affect";
char num3[]="Counsel";
char num3_1[]="1.Advise";
char num3_2[]="2.Advice";
char num4[]="Develop";
char num4_1[]="1.Revolution";
char num4_2[]="2.Evolution";
char num5[]="Overseas";
char num5_1[]="1.Abroad";
char num5_2[]="2.Aboard";
char grade1[]="Genius!";
char grade2[]="Excellent!";
char grade3[]="Good!";

void main(void)
{
PORTA=0xFF;
DDRA=0x00;
PORTF=0x00;
DDRF=0xFF;
PORTD=0x00;
DDRD=0xFF;


lcd_init(16);



while (i<3) //맞은 개수가 3개 미만일때 반복
      {
        i=0;
        PORTD=0x00; 
        lcd_gotoxy(3,0);
        lcd_putsf("WORD TEST");
        delay_ms(3000);
        lcd_clear();
       
        //no.1 : 1
        lcd_gotoxy(6,0);
        lcd_putsf("No.1");
        lcd_gotoxy(6,1);
        lcd_puts(num1);
        delay_ms(3000);
        lcd_clear();
        while(1)
        {       
        sw=~PINA&0x0F;
        lcd_gotoxy(0,0);
        lcd_puts(num1_1);
        lcd_gotoxy(0,1);
        lcd_puts(num1_2);
        delay_ms(500);
        lcd_clear();
        
        if(sw==0x01){
            PORTF=0x01;
            delay_ms(500);
            i++;
            PORTD=i;
            delay_ms(500);
            lcd_clear();
            PORTF=0x00;
            break;
            }
        else if(sw==0x02){
            PORTF=0x02;
            delay_ms(500);
            lcd_clear();
            PORTF=0x00;
            break;
            }
        }
            
        //no.2 : 2
        lcd_gotoxy(6,0);
        lcd_putsf("No.2");
        lcd_gotoxy(3,1);
        lcd_puts(num2);
        delay_ms(3000);
        lcd_clear();
        while(1)
        {       
        sw=~PINA&0x0F;
        lcd_gotoxy(0,0);
        lcd_puts(num2_1);
        lcd_gotoxy(0,1);
        lcd_puts(num2_2);
        delay_ms(500);
        lcd_clear();
        
        if(sw==0x02){
            PORTF=0x01;
            delay_ms(500);
            i++;
            PORTD=i;
            delay_ms(500);
            lcd_clear();
            PORTF=0x00;
            break;
            }
        else if(sw==0x01){
            PORTF=0x02;
            delay_ms(500);
            lcd_clear();
            PORTF=0x00;
            break;
            }
        }
            
        //no.3  : 1
        lcd_gotoxy(6,0);
        lcd_putsf("No.3");
        lcd_gotoxy(5,1);
        lcd_puts(num3);
        delay_ms(3000);
        lcd_clear();
        while(1)
        {       
        sw=~PINA&0x0F;
        lcd_gotoxy(0,0);
        lcd_puts(num3_1);
        lcd_gotoxy(0,1);
        lcd_puts(num3_2);
        delay_ms(500);
        lcd_clear();
        
        if(sw==0x01){
            PORTF=0x01;
            delay_ms(500);
            i++;
            PORTD=i;
            delay_ms(500);
            lcd_clear();
            PORTF=0x00;
            break;
            }
        else if(sw==0x02){
            PORTF=0x02;
            delay_ms(500);
            lcd_clear();
            PORTF=0x00;
            break;
            }
        } 
            
        //no.4  : 2
        lcd_gotoxy(6,0);
        lcd_putsf("No.4");
        lcd_gotoxy(5,1);
        lcd_puts(num4);
        delay_ms(3000);
        lcd_clear();
        while(1)
        {       
        sw=~PINA&0x0F;
        lcd_gotoxy(0,0);
        lcd_puts(num4_1);
        lcd_gotoxy(0,1);
        lcd_puts(num4_2);
        delay_ms(500);
        lcd_clear();
        
        if(sw==0x02){
            PORTF=0x01;
            delay_ms(500);
            i++;
            PORTD=i;
            delay_ms(500);
            lcd_clear();
            PORTF=0x00;
            break;
            }
        else if(sw==0x01){
            PORTF=0x02;
            delay_ms(500);
            lcd_clear();
            PORTF=0x00;
            break;
            }
        }
            
        //no.5  : 1
        lcd_gotoxy(6,0);
        lcd_putsf("No.5");
        lcd_gotoxy(4,1);
        lcd_puts(num5);
        delay_ms(3000);
        lcd_clear();
        while(1)
        {       
        sw=~PINA&0x0F;
        lcd_gotoxy(0,0);
        lcd_puts(num5_1);
        lcd_gotoxy(0,1);
        lcd_puts(num5_2);
        delay_ms(500);
        lcd_clear();
        
        if(sw==0x01){
            PORTF=0x01;
            delay_ms(500);
            i++;
            PORTD=i;
            delay_ms(500);
            lcd_clear();
            PORTF=0x00;
            break;
            }
        else if(sw==0x02){
            PORTF=0x02;
            delay_ms(500);
            lcd_clear();
            PORTF=0x00;
            break;
            }
        }
            
        if(i==5)
        {   
            lcd_puts(grade1);
            for(k=0;k<9;k++){
                _lcd_write_data(0x1c);
                delay_ms(500);
            }
            for(k=0;k<9;k++){
                _lcd_write_data(0x18);
                delay_ms(500);
            }
            lcd_clear();
            lcd_gotoxy(4,0);
            lcd_puts(grade1);
            delay_ms(2000);
            lcd_clear();
        }
        else if(i==4)
        {
            lcd_puts(grade2);
            for(k=0;k<6;k++){
                _lcd_write_data(0x1c);
                delay_ms(500);
            }
            for(k=0;k<6;k++){
                _lcd_write_data(0x18);
                delay_ms(500);
            }
            lcd_clear();
            lcd_gotoxy(3,0);
            lcd_puts(grade2);
            delay_ms(2000);
            lcd_clear();
        }
        else if(i==3)
        {
            lcd_puts(grade3);
            for(k=0;k<11;k++){
                _lcd_write_data(0x1c);
                delay_ms(500);
            }
            for(k=0;k<11;k++){
                _lcd_write_data(0x18);
                delay_ms(500);
            }
            lcd_clear();
            lcd_gotoxy(6,0);
            lcd_puts(grade3);
            delay_ms(2000);
            lcd_clear();
        }
        else if(i<3)
        {   
            lcd_gotoxy(6,0);
            lcd_putsf("Again");
            delay_ms(1000);
            lcd_clear();
            delay_ms(500);
            lcd_gotoxy(6,0);
            lcd_putsf("Again");
            delay_ms(1000);
            lcd_clear();
            delay_ms(500);
            lcd_gotoxy(6,0);
            lcd_putsf("Again");
            delay_ms(1000);
            lcd_clear();
            delay_ms(500); 
        }
      }
}