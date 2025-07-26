#include <reg51.h>

sbit fan = P0 ^ 0;
sbit light = P0 ^ 1;
sbit television = P0 ^ 2;
sbit machine = P0 ^ 3;

#define display_port P1
sbit rs = P2 ^ 0;
sbit rw = P2 ^ 1;
sbit e  = P2 ^ 2;

void msdelay(unsigned int time) {
    unsigned int i, j;
    for (i = 0; i < time; i++)
        for (j = 0; j < 1275; j++);
}

void lcd_cmd(unsigned char command) {
    display_port = command;
    rs = 0;
    rw = 0;
    e = 1;
    msdelay(1);
    e = 0;
}

void lcd_data(unsigned char disp_data) {
    display_port = disp_data;
    rs = 1;
    rw = 0;
    e = 1;
    msdelay(1);
    e = 0;
}

void lcd_init() {
    lcd_cmd(0x38);
    msdelay(10);
    lcd_cmd(0x0F);
    msdelay(10);
    lcd_cmd(0x01);
    msdelay(10);
    lcd_cmd(0x80);
    msdelay(10);
}

void lcd_print(char *str) {
    while (*str) {
        lcd_data(*str++);
    }
}

void main() {
    unsigned char x;

    SCON = 0x50;
    TMOD = 0x20;
    TH1 = -3;
    TR1 = 1;

    lcd_init();
    lcd_print("WELCOME");
    msdelay(500);
    lcd_cmd(0x01);

    while (1) {
        while (RI == 0);
        x = SBUF;
        RI = 0;

        SBUF = x;
        while (TI == 0);
        TI = 0;

        lcd_cmd(0x01);
        if (x == '1') { fan = 1; lcd_print("FAN ON"); }
        else if (x == '2') { fan = 0; lcd_print("FAN OFF"); }
        else if (x == '3') { light = 1; lcd_print("LIGHT ON"); }
        else if (x == '4') { light = 0; lcd_print("LIGHT OFF"); }
        else if (x == '5') { television = 1; lcd_print("TV ON"); }
        else if (x == '6') { television = 0; lcd_print("TV OFF"); }
        else if (x == '7') { machine = 1; lcd_print("MC ON"); }
        else if (x == '8') { machine = 0; lcd_print("MC OFF"); }
        else if (x == '0') { fan = light = television = machine = 0; lcd_print("ALL OFF"); }
        else if (x == '9') { fan = light = television = machine = 1; lcd_print("ALL ON"); }

        msdelay(500);
    }
}
