#include <stdio.h>

double vypocet_df(double m, double T, double H, double g){
    double A = T/m;
    double df = (A-g)*H/A;
    return df;
}

int zistenie_s(double h0, double de, double v0, double vsoft){
    int s;
    if(h0<de&&v0<vsoft)
        {s=1;}
    else
        {s=0;}
    return s;
}
double vyhodnotenie_total(int s,double total, double dt) {
    if (s == 1){
        total+=dt;
    }
    return total;
}

double vypocet_h(double m, double T, double v0, double g, double vsoft, double dt, double h0, double de){
    double A=T/m;
    double a;
    if(h0<de&&v0<vsoft){
        a=A-g;
    }
    else{
        a=(-g);
    }
    double h = h0 + (v0*dt) + (a*dt*dt/2);
    return h;
}

double vypocet_v(double m, double T, double v0, double g, double vsoft, double dt, double h0, double de){
    double A=T/m;
    double a;
    if(h0<de&&v0<vsoft){
        a=A-g;
    }
    else{
        a=(-g);
    }
    double v = v0 + (a * dt);
    return v;
}

//double faza_padu(double m, double T, double v0, double H, double g, double vsoft, double dt){}

//double faza_pristavania(double m, double T, double v0, double H, double g, double vsoft, double dt){}




int main() {
    double m,T,v0,h0,H,g,vsoft,dt,h,v,df,de,t=0,total=0;   //deklaracia premennych
    int s;
    scanf("%lf %lf %lf %lf %lf %lf %lf",&m,&T,&v0,&H,&g,&vsoft,&dt);    //nacitanie hodnot do premennych
    printf("m=%.3f\nT=%.3f\nv0=%.3f\nH=%.3f\ng=%.3f\nvsoft=%.3f\ndt=%.3f\n",m,T,v0,H,g,vsoft,dt); //vypisanie premennych
    df=vypocet_df(m, T, H, g);
    printf("df=%.3f\n",df);
    de=H-df;
    h0=H;

    while(h0>0){

        //printf("t=%.3f h=%.3f v=%.3f s=%d\n",t,h0,v0,s);
        s = zistenie_s(h0, de, v0, vsoft);
        v = vypocet_v(m ,T ,v0 ,g ,vsoft ,dt ,h0 ,de);
        h = vypocet_h(m, T, v0, g, vsoft, dt, h0, de);
        total=vyhodnotenie_total(s,total,dt);
        printf("t=%.3f h=%.3f v=%.3f s=%d\n",t,h0,v0,s);
        t+=dt;
        h0=h;
        v0=v;
        //printf("t=%.3f h=%.3f v=%.3f s=%d\n",t,h0,v0,s);
    }
    printf("t=%.3f h=%.3f v=%.3f\n",t,h0,v0);
    printf("total=%.3f",total);
    return 0;
}
