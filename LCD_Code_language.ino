//  LCD_CODE_LANGUAGE
//  Using two switches, we make words on LCD
//  Connect all the connections between LCD and Arduino
//  Connect two buttons to digital pins 6 & 7
//  The code is given below:
//  y,x-> 0 | 1 | 2 | 3 | 4 | 5
//  0     0 | 1 | 2 | 3 | 4 | 5
//  1     6 | 7 | 8 | 9 | A | B
//  2     C | D | E | F | G | H
//  3     I | J | K | L | M | N
//  4     O | P | Q | R | S | T
//  5     U | V | W | X | Y | Z
//  6     s | b | c
//  s=<_space_>
//  b=\b=<_backspace_>
//  c=clrear.screen
//  .Two state buttons are used in this project
//  .Both switches should read 0

#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int t=0,t0=0,p,p0=0,x,y,n=0;        //  t ->no. of button presses
                                    //  t0->previous t-button state
                                    //  p ->pressing of p button
                                    //  p0->previous p-state state
                                    //  x ->which row
                                    //  y ->which coloumn
                                    //  n ->no. of letters printed
char c;                             //  c ->carecter to be printed
void setup() {
  lcd.begin(16,2);
  lcd.cursor();                     //  switching on the cursor
  pinMode(6,INPUT_PULLUP);          //  pullup-> no need to
  pinMode(7,INPUT_PULLUP);          //  connect switch to 5V
  }

void loop()
{
  if(digitalRead(7)!=t0)            //  if switch state is changed
  {
    t++;
    t0=digitalRead(7);
  }

  if(digitalRead(6)!=p0)
  {
    if(digitalRead(6)==1) {x=t;t=0;}//  if switch is pressed once
    else                            //  if it is pressed twice
    {
      y=t;t=0;
      
      if(x==0)
      {
        if(y==0) c='0';
        else if(y==1) c='6';
        else if(y==2) c='C';
        else if(y==3) c='I';
        else if(y==4) c='O';
        else if(y==5) c='U';
        else if(y==6) c=' ';
      }
      
      else if(x==1)
      {
        if(y==0) c='1';
        else if(y==1) c='7';
        else if(y==2) c='D';
        else if(y==3) c='J';
        else if(y==4) c='P';
        else if(y==5) c='V';
        else if(y==6)               //  backspace
        {
          lcd.setCursor(n-1,0);
          lcd.print(" ");
          lcd.setCursor(n-1,0);
          n--;
        }
      }
  
      else if(x==2)
      {
        if(y==0) c='2';
        else if(y==1) c='8';
        else if(y==2) c='E';
        else if(y==3) c='K';
        else if(y==4) c='Q';
        else if(y==5) c='W';
        else if(y==6)
        {
          lcd.clear();
          n=0;
        }
      }
  
      else if(x==3)
      {
        if(y==0) c='3';
        else if(y==1) c='9';
        else if(y==2) c='F';
        else if(y==3) c='L';
        else if(y==4) c='R';
        else if(y==5) c='X';
      }
  
      else if(x==4)
      {
        if(y==0) c='4';
        else if(y==1) c='A';
        else if(y==2) c='G';
        else if(y==3) c='M';
        else if(y==4) c='S';
        else if(y==5) c='Y';
      }
  
      else if(x==5)
      {
        if(y==0) c='5';
        else if(y==1) c='B';
        else if(y==2) c='H';
        else if(y==3) c='N';
        else if(y==4) c='T';
        else if(y==5) c='Z';
      }


      if(!((x==1&&y==6)||(x==2&&y==6)))
      {
        lcd.print(c);
        n++;
      }
    if(n==17) {lcd.clear();n=0;}
    }
    p0=digitalRead(6);
  }
  delay(100);
}

