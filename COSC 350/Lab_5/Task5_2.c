//Keith Flagg
//COSC 350

#include <time.h>
#include <stdio.h>
#include <string.h>

static char weekday[7][3] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
static char month[12][3] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};

char *myasctime(const struct tm *timeptr){

 static char date[26];

 sprintf(date, "%.3s", weekday[(*timeptr).tm_wday]);
 sprintf(date, "%s %.3s", date, month[(*timeptr).tm_mon]);
 sprintf(date, "%s  %d %.2d:%.2d:%.2d %d\n", date, (*timeptr).tm_mday, (*timeptr).tm_hour, (*timeptr).tm_min, (*timeptr).tm_sec, (*timeptr).tm_year+1900);

 return date;
}

int main(){

 struct tm t;

 t.tm_sec=10;
 t.tm_min=10;
 t.tm_hour=6;
 t.tm_mday=4;
 t.tm_mon=6;
 t.tm_year=100;
 t.tm_wday=5;
 t.tm_yday=200;

 printf("Time: %s\n", myasctime(&t));

 return 0;

}
