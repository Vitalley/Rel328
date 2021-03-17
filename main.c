#include <xc.h>

#define input GPIO4	// ����
#define output GPIO5	// ����������
#define delay_on 1000	// �������� ����� ���������� (��)
#define delay_off 1000	// ����� ������ (��)
#define delay_dl 10000	// ������ �� ���������� ��������� (��)
#define _XTAL_FREQ 4000000
#pragma  config  FOSC = INTRCIO, MCLRE = OFF, PWRTE = ON, WDTE = OFF
void main()
{
static unsigned long CNT_ON=0,CNT_OFF=0,CNT_DL=0;
	OPTION_REG=0b100011111;
	INTCON=0;
	WPU=0;
	TRISIO = 0b0010000; // ����������� ������ �����
	GPIO = 0;
	ANSEL=0;
	ADCON0=0;
	CMCON=0b00000111;
	__delay_us(1000);
while(1)
{
	
if(input==0)
	{
	CNT_ON++; //������� ��������� ������	
	}	
if(input==1)
	{
	CNT_ON=0;	
	}	
if(CNT_ON > delay_on)
	{
	output=1;
	}	
if(output==1)
	{
	CNT_OFF++; //������� ������� ������ ������
	CNT_ON=0;	
	}	
if (CNT_OFF > delay_off)
	{
	output=0;
	CNT_DL=1;
	CNT_OFF=0;
	}	
if (CNT_DL != 0)
	{
	CNT_DL++; //������� ���������� ��������� ������
	CNT_ON=0;
	}	
if (CNT_DL > delay_dl)
	{
	CNT_DL=0;
	}	
	
__delay_us(1000);

}

} 