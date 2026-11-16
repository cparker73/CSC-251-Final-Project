#include <stdio.h>
#include <stdbool.h>

int addToOrder();
int editOrder();
int completeOrder();
int printBill();

    const float TAX_RATE = 1.0725;

    const float FOOD1_COST = 0.00;
    const float FOOD2_COST = 0.00;
    const float FOOD3_COST = 0.00;
    // ...

    const float DRINK1_COST = 0.00;
    const float DRINK2_COST = 0.00;
    const float DRINK3_COST = 0.00;
    // ...

    int food1Count, food2Count, food3Count = 0;
    int drink1Count, drink2Count, drink3Count = 0;

int main(void)
{
    bool systemActive = true;
    int userInput = 0;

    printf("Welcome to ___ Restaurant!\n");

    while(systemActive)
    {
        printf("What would you like to do?\n");
        printf("1) Add to Order\n2) Edit Order\n3) Complete Order\n0) Exit\n\n");
        scanf("%d", &userInput);

        switch(userInput)
        {
            case 1:
                addToOrder();
                break;
            case 2:
                editOrder();
                break;
            case 3:
                completeOrder();
                break;
            case 0:
                printf("Have a nice day!\n");
                systemActive = false;
                break;
            default:
                printf("Error: Invalid Input! Please Try Again\n\n");
                break;
        }
    }
    return 0;
}


int addToOrder()
{
    int choice, item, quantity;
    char again = 'y';

    while (again == 'y' || again == 'Y')
    {
        printf("\nWould you like Food or Drink?\n");
        printf("1) Food\n");
        printf("2) Drink\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("\n--- Food Menu ---\n");
            printf("1) Burger - $%.2f\n", FOOD1_COST);
            printf("2) Pizza - $%.2f\n", FOOD2_COST);
            printf("3) Fries - $%.2f\n", FOOD3_COST);

            printf("Choose a food item: ");
            scanf("%d", &item);

            if (item < 1 || item > 3)
            {
                printf("Invalid food choice!\n");
                continue;
            }

            printf("How many would you like? ");
            scanf("%d", &quantity);

            if (quantity <= 0)
            {
                printf("Invalid quantity!\n");
                continue;
            }

            switch (item)
            {
                case 1:
                    food1Count += quantity;
                    break;
                case 2:
                    food2Count += quantity;
                    break;
                case 3:
                    food3Count += quantity;
                    break;
            }

            printf("Food added to order!\n");
        }
        else if (choice == 2)
        {
            printf("\n--- Drink Menu ---\n");
            printf("1) Water - $%.2f\n", DRINK1_COST);
            printf("2) Soda - $%.2f\n", DRINK2_COST);
            printf("3) Juice - $%.2f\n", DRINK3_COST);

            printf("Choose a drink: ");
            scanf("%d", &item);

            if (item < 1 || item > 3)
            {
                printf("Invalid drink choice!\n");
                continue;
            }

            printf("How many would you like? ");
            scanf("%d", &quantity);

            if (quantity <= 0)
            {
                printf("Invalid quantity!\n");
                continue;
            }

            switch (item)
            {
                case 1:
                    drink1Count += quantity;
                    break;
                case 2:
                    drink2Count += quantity;
                    break;
                case 3:
                    drink3Count += quantity;
                    break;
            }

            printf("Drink added to order!\n");
        }
        else
        {
            printf("Invalid choice! Please try again.\n");
            continue;
        }

        printf("\nWould you like to add another item? (y/n): ");
        scanf(" %c", &again);
    }

    printf("\nReturning to main menu...\n\n");

    return 0;
}



int editOrder()
{
    // TODO
    // Let user either..
    //    1) Edit quantity of an item
    //        a) Item to modify
    //        b) New quantity
    //    2) Remove an item
    //        a) Item to remove
    //        b) Confirm y/n
}


int completeOrder()
{
    // TODO
    // Call printBill() to display user's current order
    // Prompt to Complete Order y/n
    // Prompt to make another order or exit
}


int printBill()
{
    // TODO
    // Print out the user's current order
    // Should include:
    //    1) Food/Drink Name
    //    2) Quantity of Item
    //    3) Price of Item(s)
    //    4) Subtotal
    //    5) Tax
    //    6) Total (Subtotal + Tax)
}
