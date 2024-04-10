typedef unsigned int u32;
typedef unsigned char u8;
typedef signed int s32;
typedef signed char s8;

extern void uart0_init(unsigned int);
extern void uart0_tx (unsigned char);
extern void uart0_tx_string (s8*);
extern u8 uart0_rx (void);

void config_vic (void);
void en_uart0_intr (void);
