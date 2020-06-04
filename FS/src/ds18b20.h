


#ifndef __DS18B20_H
#define __DS18B20_H

#define DS18B20_PIN_NO   	PG4
#define DS18B20_PORT 		PORTG
#define DS18B20_PIN  			PING
#define DS18B20_DDR  		DDRG

void bsp_ds18b20_gpio_init(void);
void ds18b20_init(void);
byte ds18b20_readB(void);
void ds18b20_writeB(byte wrd);
u16 read_ds18b20_temperature(void);


#endif

