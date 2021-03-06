#if !defined __UI_H__
#define __UI_H__


typedef void (*butthandler_t)(void*);
 
void ui_init(void);
void register_button_handlers(butthandler_t h1, butthandler_t h2);

extern uint16_t blink_length, blink_interval; 
extern bool blink_both;

#define BLINK_GPS_SEARCHING {blink_length=500;blink_interval=500;}
#define BLINK_NORMAL        {blink_length=30;blink_interval=2000;}
#define BLINK_FWUPGRADE     {blink_both=true;blink_length=50;blink_interval=50;}

#define BEEP_FREQ 2900
#define BEEP_ALT_FREQ 3040

#define beep(t) _beep(BEEP_FREQ, (t))
#define hbeep(t) _beep(BEEP_ALT_FREQ, (t))

#define tx_led_on()  gpio_set_level(LED_TX_PIN, 1)
#define tx_led_off() gpio_set_level(LED_TX_PIN, 0)

void _beep(uint16_t freq, uint16_t time);
void blipUp();
void blipDown();
void beeps(char* s);

#endif
