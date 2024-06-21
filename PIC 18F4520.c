void main()
{
int var = 0;
int lig = 0;
TRISB=0XFF;//PORTB É ENTRADA
TRISC=0X00;//PORTC É SAIDA
PORTC=0X00;//INICIA DESLIGADO
ADCON1=15;//SOMENTE I0 DIGITAIS

while(1)
{
portc.rc6=1; // LED painel vermelho liga
if(portb.rb0==0) //Se o botão liga for acionado
{
portc.rc0=1; //Jato de ar liga
delay_ms(2000); //Temporizador
portc.rc0=0; //Jato de ar desliga
lig = 1; //Variável “lig” se tornará 1
delay_ms(100);
portc.rc7=lig; //LED painel verde será o valor estipulado na variável “lig”
delay_ms(100);
}
        while(lig==1) //Enquanto a variável “lig” for 1
        {
         if(portc.rc2==0) //Se a solenóide do contraponto for 0
         {
         delay_ms(500); //Temporizador
                       while(var < 800) //Enquanto a variável “var” for menor que 800
                       {
                       portc.rc1=1; //Pulso no driver, cima
                       delay_ms(1); //Temporizador
                       portc.rc1=0; //Pulso no driver, cima
                       delay_ms(1); //Temporizador
                       var++; //Adiciona +1 na variável “var”
                       }
         portc.rc2=1; //Se a solenóide do contraponto for 1
         }
              if(portb.rb1==0) //Se o fim de curso do contraponto estiver ligado
              {
              delay_ms(700);
              portc.rc3=1; //Inversor liga

                             while(portc.RC3==1)
                             {
                             delay_ms(900); //Temporizador
                             portc.rc4=1; //Solenoide da ferramenta liga
                             delay_ms(2000); //Temporizador
                             portc.rc4=0; //Solenoide da ferramenta desliga
                             delay_ms(300); //Temporizador
                             portc.rc3=0; //Desliga inversor
                             }
              delay_ms(1000); //Temporizador
              portc.rc2=0; //Solenoide contra ponto desliga
              delay_ms(2000); //Temporizador
              portc.rc0=1; //Jato de ar liga
              delay_ms(2000); //Temporizador
              portc.rc0=0; //Jato de ar desliga
              var = 0;
              delay_ms(500);
                                  if(portb.rb3==1 || portb.rb4==1) //Se a chave auto/man e o sensor capacitivo estiverem ligados
                                  {
                                  lig = 0; //Variável "lig" se torna 0
                                  }



                            }

              if(portb.rb1==1) //Caso contrário de portb rb1  0
              {
                              while(portb.rb1==1) //Enquanto Fim de curso do contraponto estiver Desligado
                              {
                              }
              }
              }
         }
}

