
#include <stdbool.h>
#include <stdint.h>
#include "app_config.h"
#include "nrf_delay.h"
#include "boards.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

/**
 * @brief Function for application main entry.
 */
int i = 0;
int main(void)
{
    APP_ERROR_CHECK(NRF_LOG_INIT(NULL));
    NRF_LOG_DEFAULT_BACKENDS_INIT();

    NRF_LOG_INFO("TWI scanner started.");
    NRF_LOG_FLUSH();
    /* Configure board. */
    bsp_board_init(BSP_INIT_LEDS);

    /* Toggle LEDs. */
    while (true)
    {
        for (i = 0; i < LEDS_NUMBER; i++)
        {
            bsp_board_led_invert(i);
            nrf_delay_ms(500);
            NRF_LOG_INFO("LED number: %d", i);
            NRF_LOG_FLUSH();
        }
    }
}