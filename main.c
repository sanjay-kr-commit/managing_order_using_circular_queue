#include <stdio.h>
#include "circular_queue.h"

int main(void) {
    int serving_limit , order_id , serving_count ;
    char choice;

    printf( "Enter limit of servings : " ) ;
    scanf("%d",&serving_limit); // NOLINT(*-err34-c)
    circular_queue *serving_queue = create_circular_queue(serving_limit);

    printf( "\nHere's the menu \n's' for servings , \n'o' for ordering , \n'q' for quiting\n" ) ;

    do {
        // solves weird runtime behaviour where the first loop is executed without any input
        getchar() ;
        printf( "\nChoose one from menu : " ) ;
        choice = getchar() ; // NOLINT(*-narrowing-conversions)

        switch ( choice ) {
            case 'o' : {
                printf( "Current Serving Queue : " ) ;
                print_circular_queue( serving_queue ) ;
                printf( "Enter order id (int) : " ) ;
                scanf( "%d", &order_id ) ; // NOLINT(*-err34-c)
                printf( "Added order to serving list %d \n" , order_id ) ;
                push_circular_queue( serving_queue, order_id ) ;
                printf( "Updated Serving Queue : " ) ;
                print_circular_queue( serving_queue ) ;
            } break;
            case 's' : {
                printf( "Current Serving Queue : " ) ;
                print_circular_queue( serving_queue ) ;
                printf( "Enter Number of order's to be served ( int <= %d) : " , size_circular_queue( serving_queue ) ) ;
                scanf( "%d", &serving_count ) ; // NOLINT(*-err34-c)
                for ( int i = 0 ; i < serving_count ; i++ ) {
                    printf( "Served Order id : %d\n" , pop_circular_queue( serving_queue ) ) ;
                    printf( "Updated Serving Queue : " ) ;
                    print_circular_queue( serving_queue ) ;
                }
                printf( "Serving Complete\n" ) ;
            } break;
            case 'q' :
            default:break;
        }

    } while ( choice != 'q' ) ;

    printf( "\nServing's Cancelled\n" ) ;
    printf( "Cancelling Remaining Serving's : " ) ;
    print_circular_queue( serving_queue ) ;

    return 0;
}
