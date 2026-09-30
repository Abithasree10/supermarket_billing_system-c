#include <stdio.h>

#define NUM_PRODUCTS 5

struct Product
{
    char name[20];
    float price;
    int quantity;
};

int main()
{
    struct Product products[NUM_PRODUCTS] =
    {
        {"Rice",    60, 10},
        {"Milk",    30, 20},
        {"Bread",   40, 15},
        {"Biscuit", 20, 25},
        {"Soap",    35, 12}
    };

    int choice, quantity, payment;
    char again;

    float total = 0;
    float discount = 0;
    float finalAmount;
    float paid, change;

    printf("========== SUPERMARKET ==========\n");
    printf("\nAvailable Products:\n");

    for (int i = 0; i < NUM_PRODUCTS; i++)
    {
        printf("%d. %-10s Rs. %-8.2f (Stock: %d)\n",
               i + 1,
               products[i].name,
               products[i].price,
               products[i].quantity);
    }

    do
    {
        printf("\nEnter product number: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > NUM_PRODUCTS)
        {
            printf("Invalid product choice!\n");
        }
        else
        {
            struct Product *item = &products[choice - 1];

            printf("Enter quantity: ");
            scanf("%d", &quantity);

            if (quantity <= 0)
            {
                printf("Quantity must be positive!\n");
            }
            else if (quantity > item->quantity)
            {
                printf("Not enough stock! Only %d left.\n", item->quantity);
            }
            else
            {
                total += item->price * quantity;
                item->quantity -= quantity;
                printf("%s added to cart!\n", item->name);
            }
        }
          do{

        printf("Do you want to buy another product? (y/n): ");
        scanf(" %c", &again);
         while(getchar()!= '\n');
           if(again !='y' && again !='Y' && again !='n' && again !='N')
              { printf("Invalid input.Enter correctly.\n");
                 }
          } while(again !='y' && again !='Y' && again !='n' && again !='N');

    } while (again == 'y' || again == 'Y');


    /* Tiered Discount */

    if (total >= 2000)
    {
        discount = total * 0.20;
    }
    else if (total >= 1000)
    {
        discount = total * 0.10;
    }
    else if (total >= 500)
    {
        discount = total * 0.05;
    }
    else
    {
        discount = 0;
    }

    finalAmount = total - discount;


    /* Final Bill */

    printf("\n========== BILL ==========\n");
    printf("Total Amount : Rs. %.2f\n", total);
    printf("Discount     : Rs. %.2f\n", discount);
    printf("Final Amount : Rs. %.2f\n", finalAmount);
    printf("==========================\n");


    /* Payment */

    printf("\nSelect Payment Method:\n");
    printf("1. Cash\n");
    printf("2. Card\n");
    printf("3. UPI\n");
     int validpayment = 0;
     while (!validpayment)
     {
    printf("Enter your choice: ");
    scanf("%d", &payment);

    switch (payment)
    {
        case 1:
            printf("Enter Cash: Rs. ");
            scanf("%f", &paid);

            if (paid >= finalAmount)
            {
                change = paid - finalAmount;
                printf("Payment Successful!\n");
                printf("Change to return: Rs. %.2f\n", change);
            }
            else
            {
                printf("Insufficient Cash!\n");
                printf("Remaining Amount: Rs. %.2f\n", finalAmount - paid);
            }
                validpayment = 1;
            break;

        case 2:
            printf("Payment Method: Card\n");
            printf("Amount Paid: Rs. %.2f\n", finalAmount);
               validpayment = 1;
            break;

        case 3:
            printf("Payment Method: UPI\n");
            printf("Amount Paid: Rs. %.2f\n", finalAmount);
              validpayment = 1;
            break;

        default:
            printf("Invalid payment method!Try again bitch!\n");
       }
    }
    printf("\You did a great shopping!\n");
    printf("\nThank you for shopping with us!\n");
    printf("Come again!\n");

    return 0;
}
