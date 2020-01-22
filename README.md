# TMC5160_init_code_with_STEP_DIR
Part of my master's degree. Used to initialize stepper motor Motion king 23HS6430 driver TMC5160 for use in STEP/DIR mode with the use of Arduino Nano. 
After this initialization motor's axis should be hard to rotate with the hand as current now passes though motor's coils.

Check the tables below on instructrucions how to connect the boards. (They are in written in Croation language)

Opis	                        TMC5160	    Arduino Nano
3V3 ili 5V	                   VCC_IO	        5 V
GND	                            GND	          GND
Chip select	                    CSN          	D10
SPI clock	                      SCK	          D13
MOSI	                          SDI          	D11
MISO	                          SDO	          D12
Enable – aktivno nisko	        DRV_ENN	       D8
Korak u STEP/DIR načinu rada	  REFL	         D2
Smjer u STEP/DIR načinu rada	  REFR	         D5

Opis	                        TMC5160           Ostali sklopovi
9V – 36 V	                      VS	            + stezaljka izvora od 12 V
GND	                           GND	            - stezaljka izvora od 12 V
Faza motora B	                  B2	            Prvi izvod druge zavojnice motora (Crvena žica)
Faza motora B	                  B1	            Drugi izvod druge zavojnice motora (Zelena žica)
Faza motora A	                  A2	            Prvi izvod prve zavojnice motora (Plava žica)
Faza motora A	                  A1	            Drugi izvod prve zavojnice motora (Žuta žica)
