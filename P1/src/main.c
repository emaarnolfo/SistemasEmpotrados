#include "log.h"
#include "riscv_types.h"
#include "gpio_drv.h"


//int main()
//{
//uint32_t input[4]={0,0,0,0};
//uint32_t last_input[4]={0,0,0,0};
//
//uint32_t dir;
//
//uint32_t input_mask = BTN_0_MASK ;
//uint32_t output_mask = LED_0_MASK;
//
//// Enable output on bits 19..16
//dir = gpio_get_direction();
//dir |= 0x000F0000;
//gpio_set_direction( dir );
//
//printf("P1_1\n");
//
//while(1)
//{
//	for (int i = 0; i < 4; i++)
//	{
//		last_input[i] = input[i];
//		input[i] = gpio_read() & (input_mask<<i) ;
//
//
//		if (!last_input[i] && input[i]){
//			printf("%d", i);
//			gpio_write( gpio_read() ^ (output_mask << i));
//		}
//	}
//// Get GPIO bits
//
//} // while(1)
//
//return 0;
//}


// -------------------------------------------------------------------------------

//#include "log.h"
//#include "riscv_types.h"
//#include "gpio_drv.h"

void delay(uint64_t ticks);

int main()
{
	uint32_t dir;


	dir = gpio_get_direction();
	dir |= 0x000F0000;
	gpio_set_direction(dir);


	uint32_t btn_previous[4] = {0,0,0,0};
	uint32_t btn_current[4] = {0,0,0,0};
	uint32_t output;
	uint32_t input;

	while(1)
	{
		output = LED_0_MASK;
		input = BTN_0_MASK;

		for(int i = 0; i <= 3; i++)
		{
			btn_previous[i] = btn_current[i];
			btn_current[i] = gpio_read() & input;

			if( !btn_previous[i] && btn_current[i] )
				gpio_write(gpio_read() | output);

			if( btn_previous[i] && !btn_current[i] )
				gpio_write(gpio_read() & ~output);

			output <<= 1;
			input <<= 1;
		}
	}




//    uint32_t mask = LED_0_MASK;
//    uint32_t dir;
//
//	// Enable output on bits 19..16
//	dir = gpio_get_direction();
//	dir |= 0x000F0000;
//	gpio_set_direction( dir );
//
//	printf("P1_1\n");
//
//	printf ( "Dir: %08X\n", gpio_get_direction() );
//
//   while(1)
//   {
//	  gpio_write( mask );
//
//	  printf("INPUT VALUE: %08X\n", gpio_read() );
//
//	  mask <<= 1;
//
//	  if ( mask == 0x00100000 )
//	  {
//		 mask = LED_0_MASK;
//	  }
//
//	  delay( 10000000 );
//   }


//	while(1)
//	{
//		uint32_t output = LED_3_MASK;
//		input = gpio_read();
//
//		for(uint32_t i = SW_0_MASK; i <= SW_3_MASK; i <<= 1)
//		{
//
//			if(input & i){
//				gpio_write(gpio_read() | output);
//			}
//			else{
//				gpio_write(gpio_read() & ~ output);
//			}
//
//			output >>= 1;
//		}
//	}


//	while(1)
//	{
//	   // Get GPIO bits
//	   input = gpio_read();
//
//	   //uint32_t input_mask, output_mask;
//
//	   if ( input & SW_0_MASK )
//	   {
//	      gpio_write( gpio_read() | LED_0_MASK );
//	   }
//	   else
//	   {
//	      gpio_write( gpio_read() & ~LED_0_MASK );
//	   }
//
//	   if ( input & SW_1_MASK )
//	   {
//	      gpio_write( gpio_read() | LED_1_MASK );
//	   }
//	   else
//	   {
//	      gpio_write( gpio_read() & ~LED_1_MASK );
//	   }
//
//	   if ( input & SW_2_MASK )
//	   {
//	      gpio_write( gpio_read() | LED_2_MASK );
//	   }
//	   else
//	   {
//	      gpio_write( gpio_read() & ~LED_2_MASK );
//	   }
//
//	   if ( input & SW_3_MASK )
//	   {
//	      gpio_write( gpio_read() | LED_3_MASK );
//	   }
//	   else
//	   {
//	      gpio_write( gpio_read() & ~LED_3_MASK );
//	   }
//
//	} // while(1)

	return 0;
}

void delay(uint64_t ticks)
{
	uint64_t cnt = 0;

	do{
		cnt++;
	} while(cnt<ticks);
}
