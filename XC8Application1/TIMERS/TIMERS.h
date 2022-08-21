/*
 * TIMER0.h
 *
 * Created: 8/4/2022 6:26:02 PM
 *  Author: Diefco
 */ 

void Timer0_initaialize_CTC_mode_interrupt(void);
void Timer0_wave_NON_PWM(void);
void Timer0_wave_Fast_PWM(void);
void Timer0_wave_Phase_Correct_PWM(void);
/*---------------------------------------timer2--------------*/
void Timer2_initaialize_OVF_mode_interrupt(void);
void Timer2_initaialize_CTC_mode_interrupt(void);
void Timer2_wave_NON_PWM(void);
void Timer2_wave_Fast_PWM(void);
void Timer2_wave_Phase_Correct_PWM(void);

/*-------------------------------timer1------------------*/
void Timer1_wave_fast_PWM(double value);