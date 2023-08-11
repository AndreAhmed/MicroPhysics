# TFT LCD Module Interface Using SPI with STM32F103C8

## TFT LCD Module SPI Interface Pin Connections

- **SPI_MISO (Display Data In - from Display to Microcontroller):**
  Connect this pin from the TFT LCD module to the MOSI (Master Out Slave In) pin of the STM32F103C8. This connection allows data to flow from the display to the microcontroller, such as touch input data or display status information.

- **SPI_MOSI (Display Data Out - from Microcontroller to Display):**
  Connect this pin from the TFT LCD module to the MISO (Master In Slave Out) pin of the STM32F103C8. This connection allows data to flow from the microcontroller to the display, such as display commands and pixel data.

- **SPI_CLK (Clock Signal):**
  Connect this pin from the TFT LCD module to the SPI clock (SCK) pin of the STM32F103C8. The SPI clock signal synchronizes the data transmission between the microcontroller and the display.

- **LCD_CS (Chip Select - Active Low):**
  Connect this pin from the TFT LCD module to a digital output pin on the STM32F103C8 that you will use as the chip select (CS) signal. This signal is used to enable communication with the display. When this pin is low, the display is selected for communication.

- **LCD_RS (Data/Command - Register Select):**
  Connect this pin from the TFT LCD module to a digital output pin on the STM32F103C8 that you will use to control the Data/Command (DC/RS) signal. This signal indicates whether the data being sent is a command (configuration data) or display data.

- **LCD_WR (Write Control - Active Low):**
  Connect this pin from the TFT LCD module to a digital output pin on the STM32F103C8. This pin controls the write operation for the display. When this pin is low, the microcontroller is writing data to the display.

- **LCD_RST (Reset - Active Low):**
  Connect this pin from the TFT LCD module to a digital output pin on the STM32F103C8. This pin is used to reset the display.

- **GND (Ground):**
  Connect both GND pins from the TFT LCD module to the ground (GND) of the STM32F103C8 to provide a common ground reference.

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
