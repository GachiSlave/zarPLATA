#include "xtimer.h"
#include "timex.h"
#include "periph/gpio.h"


// Обработчик прерывания по нажатию кнопки
void btn_handler(void *arg)
{
  // Прием аргументов, передаваемых из главного потока.
  (void)arg;
  
  // Переключение состояния пина PC8
 
    gpio_toggle(GPIO_PIN(PORT_C, 8));
    xtimer_sleep (0.1);

  
}


int main(void)
{
  // Инициализация пина PA0, к которому подключена кнопка, как источника прерывания.
  // GPIO_RISING - прерывание срабатывает по фронту
  // btn_handler - имя функции обработчика прерывания
  // NULL - ничего не передаем в аргументах

    gpio_init_int(GPIO_PIN(PORT_A, 0), GPIO_IN_PD , GPIO_BOTH, btn_handler, NULL);
  // Инициализация пина PC8 на выход

  gpio_init(GPIO_PIN(PORT_C, 8), GPIO_OUT);

  while(1){

  }
  return 0;
}
/* int main(void)
{
    gpio_init(GPIO_PIN(PORT_C,8), GPIO_OUT);
    gpio_init(GPIO_PIN(PORT_C,9), GPIO_OUT);
    xtimer_ticks32_t last_wakeup = xtimer_now();

    while(1) {
        xtimer_periodic_wakeup(&last_wakeup, INTERVAL);
        printf("slept until %" PRIu32 "\r\n", xtimer_usec_from_ticks(xtimer_now()));
        gpio_toggle(GPIO_PIN(PORT_C,8));
        xtimer_periodic_wakeup(&last_wakeup, INTERVAL);
        gpio_toggle(GPIO_PIN(PORT_C,9));
    }

    return 0;
    }
    */
