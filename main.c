#include <stdio.h>


int main(){
    char names[5][11];       // 5 elever, varje namn max 10 bokstäver
    int scores;              // inläsning av en poäng i taget
    float avg[5];            //  medelvärdet för varje elev
    float max_avg =0;    //högsta medelvärdet  jag känner till från start
    float group_sum = 0;  //totalpoängen för  hela gruppen från start 
    int elev, prov;      

    //inläsning och beräkningar
    for (elev = 0; elev < 5; elev++) {           //looper igenom alla 5 elever
        int sum = 0;                             // börja räkningen från 0 för varje elev 
        scanf ("%10s", names[elev]);             //läser in elevens namn(max 10 bokstäver)
        for (prov = 0; prov < 13; prov++) {      //looper igenom alla 13 prov resultat för den aktuella eleven
            scanf("%d", &scores);                //läser in en prov poäng och sparar den i variabbel scores
            sum = sum + scores;                  //lägger till poängen från provet till elevens total summa
            group_sum = group_sum + scores;      //lägger ihopp det gamla värdet med den nya group poängen
        }
        avg[elev] = (float)sum / 13;             // medelvärdet för eleven = totalsumma /13
        if (avg[elev] > max_avg) {               //om detta medel är högre än högsta hittils
            max_avg = avg[elev];                 // uppdatera högsta medelvärde
        }
    }

    //gruppens medel (alla 65 poäng)
    float group_avg = group_sum / 65;            //gruppens medelvärde= (65=5 elever * 13 prov)

    // utskrift: 1) elev/elever med högst medel ---
    for (elev = 0; elev < 5; elev++) {           //looper igenom alla 5 elever
        if (avg[elev] == max_avg) {              //om elevens medelvärde är högst 
            char first = names[elev][0];         //ta första bokstaven i namnet
            if (first >= 'a' && first <= 'z') {
                first = (char)(first - 'a' + 'A');  //versal första bokstav
            }
            printf("%c%s\n", first, names[elev] + 1); //skriv ut namnet med första bokstaven versal
        }
    }

     // --- utskrift: 2) elever under gruppens medel (inmatningsordning) ---
     for (elev = 0; elev < 5; elev++) {               //looper igenom alla 5 elever
        if (avg[elev] < group_avg) {                  //om elevens medelvärde är lägre än gruppens
            char first = names[elev][0];              //ta första bokstaven i namnet
            if (first >= 'a' &&first <= 'z') {        // om första bokstaven är liten
                first = (char)(first - 'a' + 'A');    //gör den till stor bokstav
            }
            printf("%c%s\n", first, names[elev] + 1); //skriv ut namnet med stor första bokstav
        }
     }


    return 0;
}

