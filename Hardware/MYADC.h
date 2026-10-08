#ifndef __MYADC_H_
#define __MYADC_H_

extern uint16_t AD_Value;
void MYADC_Init(void);
uint16_t MYADC_Getvalue(void);
void MYADCDMA_Getvalue(void);

#endif