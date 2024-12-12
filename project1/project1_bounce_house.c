//
//  project1_practice_4.c
//  
//
//  Created by Lauren Song on 9/9/24.
//
//
// COP3514 Project #1
// Lauren Song U79789182
// This C program does calculate the total retal cost for bounce houses.
// The program named project1_bounce_house consider a flat fee for the first three hours of the rental even if the actual time was less then the first three hours.
// If the rental time exceed 3 hours, an additional hourly rate which each bounce houses have applies.
// If calculated hourly charge exceeds maximum charge per day, the charge for that day will be capped at the maximum. 

#include <stdio.h>

// Define the structure "Bounce House"
struct Bounce_House{
    int first_3h; // Flat fee for the first 3 hours of the rental
    int hourly_rate; // Hourly rate per additional hour
    int day_max; // Maximum charge per day
};

// Function to calculate the total rental cost
int CalculateRentalCost(struct Bounce_House bouncehouse, int days, int hours){
    int totalcharge = 0;
    
    // If the rental is a single day
    if (days == 0) {
        if (hours <= 3) {
            // Charge for up to 3 hours with a flat fee
            totalcharge = bouncehouse.first_3h;
        } else {
            // Calculate hourly charge after the first 3 hours
            int hourly_charge = (hours - 3) * bouncehouse.hourly_rate;
            // Total charge including the flat fee for the first 3 hours
            int total = bouncehouse.first_3h + hourly_charge;
            // Cap the total charge at day_max if it exceeds day_max
            if (total > bouncehouse.day_max) {
                totalcharge = bouncehouse.day_max;
            } else {
                totalcharge = total;
            }
        }
    } else {
        // If the rental is for multiple days
        // Charge per day is capped at day_max
        int daily_charge = bouncehouse.day_max * days;
        // Calculate the additional hourly charge for the user given the hours
        int hourly_charge = (hours * bouncehouse.hourly_rate);
        
        // Cap the hourly charge at day_max if it exceeds day_max
        if(hourly_charge > bouncehouse.day_max){
            hourly_charge = bouncehouse.day_max;
        }
        // Total charge: daily charge for all days plus hourly charges
        totalcharge = daily_charge + hourly_charge;
    }

    return totalcharge;
}

int main(){
    int selection;
    int days;
    int hours;
    int Charge;
    
    // Declare variables for four bounce houses
    // {a, b, c}: {first 3 hour, hourly rate, per day maximum}
    struct Bounce_House mc = {58, 8, 80}; // mc: magic castle
    struct Bounce_House gj = {85, 12, 120}; //gj: gigantic jump
    struct Bounce_House wads = {100, 15, 150}; //wads: wet and dry slide
    struct Bounce_House ocwp = {180, 20, 250}; //ocwp: obstacle combo with pool
    
    printf("Please select from four bounce houses: 1, 2, 3, and 4\nEnter bounce house selection:");
    scanf("%d", &selection);
    
    // Make user select between 1 and 4; otherwise, the program prints "Invalid"
    if(selection < 1 || selection > 4){
        printf("Invalid selection. Select from 1 to 4.\n");
    }else{
        printf("Enter days:");
        scanf("%d", &days);
        
        if(days < 0){
            printf("Invalid days.\n");
        }else{
            printf("Enter hours:");
            scanf("%d", &hours);
            
            if(hours < 0 || hours >= 24){
                printf("Invalid hours.\n");
            }else{
                switch(selection){
                    case 1:
                        Charge = CalculateRentalCost(mc, days, hours);
                        break;
                    case 2:
                        Charge = CalculateRentalCost(gj, days, hours);
                        break;
                    case 3:
                        Charge = CalculateRentalCost(wads, days, hours);
                        break;
                    case 4:
                        Charge = CalculateRentalCost(ocwp, days, hours);
                        break;
                }
                printf("Charge($): %d\n", Charge);
            }
        }
    }
    
    return 0;
}
