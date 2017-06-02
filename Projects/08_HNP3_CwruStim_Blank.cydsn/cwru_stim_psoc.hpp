/*
  CwruStim.h - Library for muscle stim board for HNPv2 Project.
  Created by Lu Li (lxl361@case), Aug, 2015.
  Version 1.1
  Online Doc: https://goo.gl/s20iH4
  Repo: https://github.com/lilulab/CwruStim_beta
*/

#ifndef cwru_stim_psoc_h
#define cwru_stim_psoc_h

#include "cwru_stim_const_psoc.h"
#include "Gait_VCK5_misc.h"

#include <stdint.h>
#include<inttypes.h>
#include<math.h>
#include<project.h>

//#include "StimPattern/Gait_VCK5_misc.h" // VCK5's walking pattern

/*
  HNPv2 NTREK Embedded Controller Board(ECB) 
  Support two channels for muscle stimulation board UART communication.
  UART1 (TX1 and RX1) for stim board 1
  UART3 (TX3 and RX3) for stim board 3
 */ 

class Stim
{
  public:

    Stim(int uart_channel_id); // Stim constructor and UART selector

    // Stim board setup function
    int init(int mode); // Initialize Stim Board "\']/;
    int config(int setting); // Configure Stim Board via UART
    int update(int type, int pattern, uint16_t cycle_percentage); // Update Stim pattern via UART

    uint16_t _Gait_LUT_VCK5[NUM_GAIT_VCK5_BOARD][NUM_PATTERN][NUM_PATTERN_PARAM];//[board][pattern][PP/PW/AMP/IPI]
    int gait_LUT_builder(void); 

    int start(uint8_t sync_signal); // Start Stim board using sync signal command
    int start_multi_schedule(void); // Start multiple scheduler
    // UART lower level stuff
    int serial_write_array(uint8_t buf[],int length);

    int debug_print_states(int id); // Use Serial0 to print debug messages.

    // UECU command sets

    //UECU Halt and reset
    int cmd_halt_rset(uint8_t halt_flag);

    // UECU Delete Schedule
    int cmd_del_sched(uint8_t sched_id);

    // UECU Create Schedule
    int cmd_crt_sched(uint8_t sync_signal, uint16_t duration);

    // UECU Channel Setup 
    int cmd_chan_set( uint8_t port_chn_id, 
                      uint8_t amp_limit,
                      uint8_t pw_limit,
                      uint16_t ip_delay, 
                      uint8_t asp_ratio, 
                      uint8_t anode_cathode);

    // UECU Create Event
    int cmd_crt_evnt( uint8_t sched_id, 
                        uint16_t delay, 
                        uint8_t priority, 
                        uint8_t event_type, 
                        uint8_t port_chn_id,
                        uint8_t pulse_width,
                        uint8_t amplitude,
                        uint8_t zone);

    // UECU Change Event Parameter Command
    int cmd_set_evnt( uint8_t event_id,
                      uint8_t pulse_width,
                      uint8_t amplitude,
                      uint8_t zone);

    // UECU Change Event Schedule Message
    int cmd_chg_evnt_sched(
                      uint8_t event_id,
                      uint8_t sched_id,
                      uint16_t delay,
                      uint8_t priority);

    // UECU Change Schedule Message
    int cmd_set_sched( uint8_t sched_id,
                      uint8_t sync_signal,
                      uint16_t duration); 

    // UECU Sync Message
    int cmd_sync_msg( uint8_t sync_signal); 

    // channel pw gains for dynamic gait control
    // related var: float _current_pw_gains[STIM_CHANNEL_MAX_PERC];
    int set_chan_pw_gain(uint8_t channel, float gain);
    float get_chan_pw_gain(uint8_t channel);

    // channel amp gains for dynamic gait control
    // related var: float _current_amp_gains[STIM_CHANNEL_MAX_PERC];
    int set_chan_amp_gain(uint8_t channel, float gain);
    float get_chan_amp_gain(uint8_t channel);
  
  private:
    // Stim board setup
    int _uart_channel_id;
    int _mode;
    int _setting;
    int _stim_error;

    // Multi scheduler sync
    uint8_t _PERC_8CH_SYNC_MSG[STIM_CHANNEL_MAX_PERC];

    // Pulse width
    uint8_t _current_pulse_width[STIM_CHANNEL_MAX_PERC];

    // Amplitude
    uint8_t _current_amplitude[STIM_CHANNEL_MAX_PERC];

    // Inter phase interval
    uint8_t _current_ipi[STIM_CHANNEL_MAX_PERC];

    // for fixed scheduler
    uint16_t _group_event_count[FIXED_SCHED];//count num of events in one schedule
    uint8_t _schedule_id; //schedule_id 

    // channel pw gains for dynamic gait control
    float _current_pw_gains[STIM_CHANNEL_MAX_PERC];

    // channel amp gains for dynamic gait control
    float _current_amp_gains[STIM_CHANNEL_MAX_PERC];

    // cal check sum byte
    uint8_t checksum(uint8_t vals[], int length);

    // gen pw ranping
    uint8_t get_PW_ramping( int channel_i,
                            const uint16_t (*LUT_PP_t)[12][8],
                            const uint8_t (*LUT_PW_t)[12][8],
                            uint16_t cycle_pp_t);

    // execute command, apply the gain to _current_pulse_width[];
    uint8_t exe_chan_pw_gain(uint8_t channel);

    // execute command, apply the gain to _current_amplitude[];
    uint8_t exe_chan_amp_gain(uint8_t channel);

};

#endif



