#include <stdio.h>
#include "string.h"

const float VAT = 7.7f;

// Funktion: um Trennlinien auszugeben
void printSpaces(int sum){
    for(int i = 0; i<=sum; i++){
        printf("%c", 196);
    }
}


// Funktion: um den Nettopreis des Artikels zu ermitteln
float get_end_price(float price, float discount){
    float endprice = price - (price / 100) * discount;
    return endprice;
}


//Funktion: Fügt einen "Datensatz" hinzu. *type artikelname *price Preis des Artikels *discount %Rabatt
void get_article(char type[], float price, float discount){


    char distanceType = 1;
    char distancePrice = 4;
    char distanceDiscount = 11;
    char distanceDiscountsum = 9;

    float discountsum = (price / 100 ) * discount;

    if(discountsum >= 10){
        distanceDiscount = 11;
    }



    printf("%s%*.2f%*.1f%%%*.2f%*.2f\n", type,30 - strnlen(type,40) - distanceType,
           price, 30-sizeof(price) - distancePrice, discount, distanceDiscountsum, discountsum,
           30 - sizeof(discount) - distanceDiscount, get_end_price(price, discount));
}


//  Main function
int main() {

    //Variable declaration

    //Article prices and discount
    float hardwarePrice = 1000;
    float hardwareDiscount = 15.8f;

    float softwarePrice = 9000;
    float softwareDiscount = 0.8f;

    float servicesPrice = 4000;
    float servicesDiscount = 0.8f;

    // end price the sum from all articles
    float endPriceHard = 0;
    float endPriceSoft = 0;
    float endPriceSer = 0;
    float totalPrice = 0;

    // Invoiceprice and distance format
    float vatAmout = 0;
    float invoiceAmout = 0;
    char invoiceDistance = 23;

    char nextStep = 'n';

    do{/*

        #uncomment to activate userinputs

        printf("Bruttobetrag Hardware");
        scanf("%f", &hardwarePrice);
        while (getchar() != '\n');
        printf("Rabatt Hardware\n");
        scanf("%f", &hardwareDiscount);
        while (getchar() != '\n');
        printf("Bruttobetrag Software\n");
        scanf("%f", &softwarePrice);
        while (getchar() != '\n');
        printf("Rabatt Software\n");
        scanf("%f", &softwareDiscount);
        while (getchar() != '\n');
        printf("Bruttobetrag Dienstleistungen\n");
        scanf("%f", &servicesPrice);
        while (getchar() != '\n');
        printf("Rabatt Dienstleistungen\n");
        scanf("%f", &servicesDiscount);
        while (getchar() != '\n');
        */
        char sum = (30 - sizeof("Artikel")) + (30 - sizeof("Brutto")) + (30 - sizeof("Rabatt")) + sizeof("Betrag");
        printf("Rechnung\n");
        printSpaces(sum);
        printf("\n");
        printf("%s%*s%*s%*s\n", "Artikel", 30 - sizeof("Artikel"), "Brutto",
               30 - sizeof("Brutto"), "Rabatt", 30 - sizeof("Rabatt"), "Betrag");
        printSpaces(sum);
        printf("\n");

        //get and show article
        get_article("Hardware", hardwarePrice,hardwareDiscount);
        get_article("Software", softwarePrice,softwareDiscount);
        get_article("Dienstleistungen", servicesPrice,servicesDiscount);

        printSpaces(sum);
        printf("\n");

        // calculate and print total price
        endPriceHard = get_end_price(hardwarePrice, hardwareDiscount);
        endPriceSoft = get_end_price(softwarePrice, servicesDiscount);
        endPriceSer = get_end_price(servicesPrice, servicesDiscount);
        totalPrice = endPriceHard + endPriceSoft + endPriceSer;

        printf("%s%*.2f", "summe", 76 - strnlen("Summe",40),totalPrice);
        printf("\n");

        // calculate and print vat amout
        vatAmout = (totalPrice / 100) * VAT;
        printf("Mehrwertsteuer%*.1f%%%*.2f\n", 38, VAT, invoiceDistance, vatAmout);
        printSpaces(sum);
        printf("\n");

        // calculate and print invoice amout
        invoiceAmout = totalPrice + vatAmout;
        printf("Rechnungsbetrag%*.2f\n\n", 61, invoiceAmout);
        printSpaces(sum);
        printf("\n\n");

        printf("Wollen sie noch eine Rechnung durchfueren ? y/n\n");
        scanf("%c", &nextStep);
        getchar();


    } while (nextStep != 'n');
    return 0;

}
