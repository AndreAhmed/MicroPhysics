# TFT LCD Module Interface Using SPI with STM32F103C8

## Pin Connections

| Pin        | Connection                                  | Description                                                                                   |
|------------|---------------------------------------------|-----------------------------------------------------------------------------------------------|
| SPI_MISO   | STM32F103C8 MOSI (Master Out Slave In)      | Data line from the display to the microcontroller for sending data.                           |
| SPI_MOSI   | STM32F103C8 MISO (Master In Slave Out)      | Data line from the microcontroller to the display for sending data.                           |
| SPI_CLK    | STM32F103C8 SPI Clock (SCK)                 | Clock signal for synchronizing data transmission.                                             |
| LCD_CS     | Digital Output on STM32F103C8               | Chip select signal for the display. Drive low to select the display for communication.        |
| LCD_RS     | Digital Output on STM32F103C8               | Control signal for Data/Command (DC/RS) on the display. Indicates command or display data.    |
| LCD_WR     | Digital Output on STM32F103C8               | Controls the write operation for the display.                                                 |
| LCD_RST    | Digital Output on STM32F103C8               | Reset control signal for the display.                                                         |
| GND        | Ground (GND) of STM32F103C8                 | Connect both GND pins of the display to the microcontroller's ground.                         |

## Notes

- **SPI_MISO:** Data line from display to microcontroller for sending data.
- **SPI_MOSI:** Data line from microcontroller to display for sending data.
- **SPI_CLK:** Clock signal for synchronizing data transmission.
- **LCD_CS:** Chip select signal for display communication.
- **LCD_RS:** Control signal for Data/Command (DC/RS) on display.
- **LCD_WR:** Controls write operation for display.
- **LCD_RST:** Reset control signal for display.
- **GND:** Ground connection between display and microcontroller.

Please remember to connect the necessary power supply pins (5V) and potentially the backlight control pin (LED), depending on the specific requirements of your TFT LCD module. This will ensure proper functionality and illumination.

Additionally, make sure to correctly configure and initialize the SPI interface and GPIO pins in our STM32F103C8 code. This step is crucial for establishing effective communication between the display and the microcontroller. Refer to the documentation provided for both the display module and the STM32F103C8 microcontroller to ensure accurate pin assignments, communication protocols, and initialization procedures.

By carefully following these steps, we can successfully interface the TFT LCD module using SPI with our STM32F103C8 microcontroller.
