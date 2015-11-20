/*
    Project 1 of "Network Analysis & Modeling"
    Date : 2015/12/24
*/ 

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "lcgrand.h"    // the random generator

#define BUSY    1   // the server status
#define IDLE    0
#define Q_LIMIT                 100
#define interarrival_exp_para   59.94       // the parameter of field inter-
                                            // arrival exp. distribution
#define complex_exp_para        262.5       // the parameter of field comple-
                                            // xity exp. distribution
#define alpha                   0.1         // the const. to calculate framing
                                            // time
#define capacity_enc            15800       // encoder capacity
#define capacity_stor           1600        // storage capacity
#define end_time                28800.0     // total simulation time
#define num_events              8          

int next_field_type, num_custs_delayed, next_event_type,
    num_in_enc_q, num_in_stor_q, enc_server_status,
    stor_server_status;
float area_num_in_q, area_server_status, mean_interarrival, 
    mean_complex, time_arrival[Q_LIMIT+1], total_of_delays, 
    time_last_event, time_next_event[event_num+1], sim_time;  
FILE *output;

void initialize(void);

/*
    event type:
    0: initialize
    1: field arrival
    2: drop
    3: start encoding
    4: encoding end and enter storage queue
    5: start framing
    6: end framing
    7: end simulation
*/

int main() {
    output = fopen("report.txt", "w");
    
    mean_interarrival   = 1/interarrival_exp_para;
    mean_complex        = 1/complex_exp_para;
   
    fprintf(output, "Project 1 Report\n");
    fprintf(output, "Mean Interarrival Time : %7.5f (sec)\n", mean_interarrival);
    fprintf(output, "Mean Complexity Time : %7.5f (sec)\n", mean_complex);
    fprintf(output, "Total Simulation Time : %7.5f (sec)\n", sim_time);

    fclose(output);

    return 0;
}

void initialize(void)  /* Initialization function. */
{
    /* Initialize the simulation clock. */

    sim_time = 0.0;

    /* Initialize the state variables. */

    enc_server_status   = IDLE;
    stor_server_status  = IDLE;
    num_in_enc_q        = 0;
    num_in_stor_q       = 0;
    time_last_event     = 0.0;

    /* Initialize the statistical counters. */

    num_custs_delayed  = 0;
    total_of_delays    = 0.0;
    area_num_in_q      = 0.0;
    area_server_status = 0.0;

    /* Initialize event list.  Since no customers are present, the departure
       (service completion) event is eliminated from consideration.  The end-
       simulation event (type 3) is scheduled for time time_end. */
    time_next_event[0] = time_end+1;
    time_next_event[1] = sim_time + expon(mean_interarrival);
    time_next_event[2] = sim_time + encode_time;
    time_next_event[3] = 
    time_next_event[7] = time_end;
}

float encode_time(){
    return capacity_enc/(expon(mean_complex));
}














