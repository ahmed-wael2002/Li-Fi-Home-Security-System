#include "keypad.h"
#include "DIO.h"

/* Mapping of keypad keys for different configurations */
#if ((NUM_OF_COLS==4)&&(NUM_OF_ROWS==5))
uint8 arr[NUM_OF_ROWS][NUM_OF_COLS] = { {'A', 'B', 'C', 'D'}, 
                                        {'1', '2', '3', '+'}, 
                                        {'4', '5', '6', '-'}, 
                                        {'7', '8', '9', '*'},
                                        {'<', '0', '>', '/'}};
#elif ((NUM_OF_COLS==4)&&(NUM_OF_ROWS==4))
uint8 arr[NUM_OF_ROWS][NUM_OF_COLS] = { {'1', '2', '3', '+'}, 
                                        {'4', '5', '6', '-'}, 
                                        {'7', '8', '9', '*'},
                                        {'.', '0', '=', '/'}};
#endif

void KEYPAD_init(void){
    /* Initialzing Rows Pins */
    DIO_Init(ROWS_PORT_ID, FIRST_ROW_PIN_ID, PIN_INPUT);
    DIO_Init(ROWS_PORT_ID, FIRST_ROW_PIN_ID+1, PIN_INPUT);
    DIO_Init(ROWS_PORT_ID, FIRST_ROW_PIN_ID+2, PIN_INPUT);
    DIO_Init(ROWS_PORT_ID, FIRST_ROW_PIN_ID+3, PIN_INPUT);
    #if (NUM_OF_ROWS==5)
    DIO_Init(ROWS_PORT_ID, FIRST_ROW_PIN_ID+4, PIN_INPUT);
    #endif

    /* Initializing Column Pins */
    DIO_Init(COLS_PORT_ID, FIRST_COL_PIN_ID, PIN_OUTPUT);
    DIO_Init(COLS_PORT_ID, FIRST_COL_PIN_ID+1, PIN_OUTPUT);
    DIO_Init(COLS_PORT_ID, FIRST_COL_PIN_ID+2, PIN_OUTPUT);

    DIO_writePin(COLS_PORT_ID, FIRST_COL_PIN_ID, KEY_RELEASED);
    DIO_writePin(COLS_PORT_ID, FIRST_COL_PIN_ID+1, KEY_RELEASED);
    DIO_writePin(COLS_PORT_ID, FIRST_COL_PIN_ID+2, KEY_RELEASED);
    
    #if (NUM_OF_COLS==4)
    DIO_Init(COLS_PORT_ID, FIRST_COL_PIN_ID+3, PIN_OUTPUT);
    DIO_writePin(COLS_PORT_ID, FIRST_COL_PIN_ID+3, KEY_RELEASED);
    #endif
}


uint8 KeyPad_Read(void){
    uint8 row, col;
    while(1){    
      /* Iterate on all columns */
      for (col=0; col<NUM_OF_COLS; col++){
        /* Let the current column to be pressed */
        DIO_writePin(COLS_PORT_ID, FIRST_COL_PIN_ID+col, KEY_PRESSED);
        /* Iterate on all rows of the current column to check whether a key is pressed */
        for(row=0; row<NUM_OF_ROWS; row++){
          if (ROW_ON)
            return arr[row][col];
        }
        /* Reset column pins */
        DIO_writePin(COLS_PORT_ID, FIRST_COL_PIN_ID+col, KEY_RELEASED);
      }
    }
}