#include <stdio.h>


int main (void){
int sek, min, timer, dag, uge; /*opretter variabler for sekunder, minnuter, timer, dage og uger*/

printf("Indtast din tid i sekunder: "); /*ber bruger om input som er antallet sekunder*/
scanf("%d", &sek); /*smider den indtasted værdi i variablen sek */

/*udføre det på krævede matematik for at udrenge hvor meget det er i timer, dag ovs*/
min = sek/60;
sek = sek%60;
timer = min/60;
min = min%60;
dag = timer/24;
timer = timer%24;
uge = dag/7;
dag = dag%7;

/*printer hvor meget den intastede værdi er i minnuter, dage ovs*/
printf("%d uger, %d dage, %d timer, %d minnutter og %d sekunder", uge, dag, timer, min, sek);

return 0;
}
