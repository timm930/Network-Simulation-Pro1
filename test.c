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
#define queue_size              100
#define interarrival_exp_para   59.94       // the parameter of field inter-
                                            // arrival exp. distribution
#define complex_exp_para        262.5       // the parameter of field comple-
                                            // xity exp. distribution
#define alpha                   0.1         // the const. to calculate framing
                                            // time
#define capacity_enc            15800       // encoder capacity
#define capacity_storage        1600        // storage capacity
#define sim_time                28800.0     // total simulation time
#define event_num               8          

int next_field_type, next_event_type, num_events, 
    num_in_q, server_status;
float mean_interarrival, mean_complex, time_arrival[queue_size+1], 
    time_last_event, time_next_event[event_num+1];  

int main() {
    FILE *output;
    output = fopen("report.txt", "w");
    
    mean_interarrival   = 1/interarrival_exp_para;
    mean_complex        = 1/complex_exp_para;
   
    fprintf(output, "Project 1 Report\n");
    fprintf(output, "Mean Interarrival Time %7.5f (sec)\n", mean_interarrival);
    fprintf(output, "Mean Complexity Time %7.5f (sec)\n", mean_complex);
    fprintf(output, "Total Simulation Time %7.5f (sec)\n", sim_time);

    fclose(output);

    return 0;
}
