/*
*****************************************************************
corticolumn.h

Copyright (C) 2021 Luka Micheletti
*****************************************************************
*/

#ifndef __CORTICOLUMN__
#define __CORTICOLUMN__

#include <stdint.h>

// Column values.
#define SYNAPSES_COUNT_MAX 0x00000FFFu

// Neuron values.
#define NEURON_DEFAULT_THRESHOLD 0xCCu
#define NEURON_STARTING_VALUE 0x00u
#define NEURON_DECAY_RATE 0x01u
#define NEURON_RECOVERY_VALUE -0x77
#define NEURON_LIFESPAN 0x1111u
#define NEURON_ACTIVITY_MAX 0xFFFFu
#define NEURON_ACTIVITY_STEP 0x0033u

// Synapse values.
#define SYNAPSE_DEFAULT_VALUE 0x22
#define SYNAPSE_MIN_PROPAGATION_TIME 0x11u
#define SYNAPSE_DEFAULT_PROPAGATION_TIME 0x32u
#define SYNAPSE_STARTING_PROGRESS 0x00u
#define SYNAPSE_DEL_THRESHOLD 0x00FFu
#define SYNAPSE_GEN_THRESHOLD 0x1100u

// Spike values.
#define SPIKE_DELIVERED -1
#define SPIKE_IDLE -2

#ifdef __cplusplus
extern "C" {
#endif

// Neuron data types.
typedef uint8_t neuron_threshold_t;
typedef int16_t neuron_value_t;
typedef uint16_t neuron_activity_t;

// Synapse data types.
typedef uint8_t synapse_propagation_time_t;
typedef int8_t synapse_value_t;

// Spike data types.
typedef int16_t spike_progress_t;

// Corticolumn data types.
typedef uint32_t neurons_count_t;
typedef uint32_t synapses_count_t;
typedef uint32_t spikes_count_t;

// Defines the building block of the brain intelligence: the minimum sensory-motor learning model.
typedef struct {
    /* NEURON DATA */
    // The number of neuron in the corticolumn (also defines the number of synapses).
    neurons_count_t neurons_count;
    
    // Threshold value. The neuron fires if value goes above it.
    neuron_threshold_t* neuron_thresholds;

    // Actual value of the neuron. If it goes above threshold, then the neuron fires.
    neuron_value_t* neuron_values;

    // The activity level of the neuron (direct match for the firing rate);
    neuron_activity_t* neuron_activities;


    /* SYNAPSE DATA */
    // Amount of synapses in the corticolumn.
    synapses_count_t synapses_count;

    // Propagation time of spikes along the synapse.
    synapse_propagation_time_t* synapse_propagation_times;

    // Value of the synapse. This is what influences the output neuron.
    synapse_value_t* synapse_values;

    // Index of the input neuron.
    neurons_count_t* synapse_input_neurons;

    // Index of the output neuron.
    neurons_count_t* synapse_output_neurons;


    /* SPIKES DATA */
    spikes_count_t spikes_count;

    // Progress of the current spike along the synapse.
    spike_progress_t* spike_progresses;

    // Reference synapse.
    synapses_count_t* spike_synapses;

    spikes_count_t traveling_spikes_count;

    // Progress of the current spike along the synapse.
    spike_progress_t* traveling_spike_progresses;

    // Reference synapse.
    synapses_count_t* traveling_spike_synapses;
} corticolumn;

#ifdef __cplusplus
}
#endif

#endif
