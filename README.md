# HLS-Project

## HLS-based Up-counter Streaming Module for FPGA Design



In the ever-evolving field of digital electronics, FPGA stands as a beacon of adaptability and speed. Today, I'm excited to introduce a prime example of FPGA's capabilities – an up-counter streaming module designed for real-time interfacing utilizing FIFO generator with a seven-segment display.

 

Design Overview:

The design comprises an integrated system built on an FPGA platform, utilizing High-Level Synthesis (HLS) for rapid development and iteration. The main focus of the design is an up-counter module which is part of a larger system including a pulse generator, FIFO buffer, debouncer, and display drivers – to perform counting operations and display the results in real-time.



Key Submodules:

Pulse Generator: Initiates the counting sequence, providing a regular pulse stream to the up-counter.

FIFO Generator: Manages the queuing of count values, ensuring a smooth and orderly data flow.

Debouncer: Filters out any noise from the input buttons, ensuring accurate count increment triggers.

Up-Counter: Lies at the heart of the design, incrementing the count in response to incoming pulses and managing the modulo operation for wrapping the count value.



Inputs/Outputs:

Inputs:

clk_in: The main system clock that synchronizes the operation of all submodules.

reset: Resets the system to a known state.

4-bit sw: User input switches to specify the modulo value for the counter.

up_count: The signal line carrying the current count value.



Outputs:

8-bit seven segment display (display_data): Drives the display segments to show the count.

4-bit seven segment enable (display_enable): Controls which segments are activated on the display.



Design Function:

At its core, the up-counter module functions to increment a count value with each pulse received from the pulse generator. The count is presented through a seven-segment display, which is controlled by the output lines display_data and display_enable. The FIFO generator ensures that the count values are processed in the order they are received.



Applications:

This module is versatile and can be applied to a variety of scenarios, including but not limited to digital clocks, counters in consumer appliances, and educational tools for digital logic learning. Its real-time processing capability makes it suitable for applications where immediate feedback from user input is necessary.



Conclusion:

The HLS-based up-counter streaming module demonstrates how complex digital systems can be realized with reduced development times, facilitating innovation and creativity in digital design. This project is an enabler for engineers and developers to turn their digital concepts into real-world applications swiftly and effectively.
![Screenshot 2024-04-13 105130](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/c035294b-67d2-4725-aa06-ae65091db4c0)

![Screenshot 2024-04-12 235450](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/7ee0d394-f0c9-4702-83f5-7c4de3850391)
![Screenshot 2024-04-12 235923](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/a8183a41-8196-4c29-8c8d-c070e02f298f)
![Screenshot 2024-04-13 000020](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/f64fdc1b-5efc-4b84-854e-e81726884f1f)

![Screenshot 2024-04-13 001557](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/5ea76b9e-d423-4a85-9683-a6eccf342f91)
![Screenshot 2024-04-13 104043](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/5dcc33a2-18a5-47a0-986c-7fe0fadb19ae)


## FPGA-based HLS PMOD Keyboard IP Design

1. Introduction
   
FPGA-based PMOD keyboards are fundamental interfaces in embedded systems, enabling user input for a variety of applications. In this report, we present the design and implementation of an FPGA-based HLS PMOD Keyboard IP with two sub-modules: PMOD keyboard refresh and PMOD keyboard. This solution facilitates efficient interaction with external keyboards and provides robust functionality for FPGA-based systems.

3. Design Overview
   
The FPGA-based HLS PMOD Keyboard IP comprises two primary sub-modules:

PMOD Keyboard Refresh: Generates refresh signals for scanning the keyboard matrix.

PMOD Keyboard: Interfaces with the PMOD keyboard, scanning rows and detecting key presses.

4. Input and Output Ports
   
The HLS PMOD Keyboard IP exposes the following input and output ports:

Input Ports:

ap_clk: Clock signal for the FPGA fabric.

4-bit input_pmod_row: Input for scanning rows of the PMOD keyboard matrix.

ap_rst: Reset signal to initialize the IP.

Output Ports:

4-bit pmod_output_col: Output for detected columns of the PMOD keyboard matrix.

8-bit display_data: Data for driving the seven-segment display.

4-bit display_enable: Enable signals for controlling segments of the seven-segment display.

5. Conclusion
   
The FPGA-based HLS PMOD Keyboard IP offers a versatile and efficient solution for integrating PMOD keyboard functionality into FPGA-based systems. Leveraging HLS methodology enables rapid development and optimization, while the modular design ensures scalability and ease of integration. With its robust features and customizable configurations, the HLS PMOD Keyboard IP can be seamlessly integrated into various embedded systems, enhancing user interaction and expanding application possibilities.
![Screenshot 2024-04-01 223941](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/0b2a7a59-cccd-4081-97cc-33d639c20cf1)

![Screenshot 2024-04-01 223719](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/79df9054-a85f-4dbf-ae07-db871e98dd0d)

![Screenshot 2024-04-01 212623](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/21fa5ef8-e20a-4327-b71d-9bb9b067f4b9)

![Screenshot 2024-04-01 212013](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/f12bba50-9dbc-4fb4-a624-287c4d6d3fe9)
![Screenshot 2024-04-01 204546](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/53e85983-200f-4bc4-8b7d-379cb9a0374e)

## FPGA-based HLS Timer with Initialization IP Block Design

FPGA-based timers are essential components in various embedded systems, facilitating timekeeping functionalities crucial for a wide range of applications. I recently designed and implemented an FPGA-based HLS timer with initialization IP for a complex DSP project developed using High-Level Synthesis (HLS) methodology.

🗝️Design Overview

The HLS timer with initialization IP consists of the following key components:

✨Debouncer: Ensures stable input signals by eliminating noise and bouncing effects.

✨Pulse Generator: Generates pulse signals to trigger timer events such as start, stop, and reset.

✨Seven-Segment Driver: Drives the seven-segment display to visualize timer output.

✨Seven-Segment Signal: Generates refresh signals for the seven-segment display.

✨Timer Signal: Provides timing signals for precise operation of the timer.

✨Timer with Initialization: Implements countdown functionality and initialization of timer values.

🗝️Input and Output Ports

The HLS timer IP exposes the following input and output ports:

✨Input Ports:

ap_clk: Clock signal for the FPGA fabric.

6-bit "minutes" switch: Input for setting timer values or configurations.

start: Start signal to initiate timer operations.

ap_rst: Reset signal to reset the timer and associated submodules.

✨Output Ports:

8-bit seven_segment_data: Data for driving the seven-segment display.

4-bit seven_segment_enable: Enable signals for controlling segments of the seven-segment display.

The FPGA-based HLS timer with initialization IP offers a versatile and efficient solution for implementing timer functionalities in FPGA-based systems. 

Leveraging HLS methodology enables rapid development and optimization, while the modular design ensures scalability and ease of integration. With its robust features and customizable configurations, the HLS timer IP can be seamlessly integrated into various embedded systems, meeting diverse application requirements.
![Screenshot 2024-03-31 204721](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/8ed88c10-88ff-46e9-97fa-baabcdf62556)
![Screenshot 2024-03-31 205313](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/e9afc0bc-363c-4d10-9ae4-22d2db19c6c1)
![Screenshot 2024-03-31 203223](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/f27e0050-3e83-4cdd-a72c-3edd01734b16)
![Screenshot 2024-03-31 194553](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/56de009d-2b09-44ae-a430-884e41aea885)
![Screenshot 2024-03-31 194245](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/0ebe0f2f-f6b9-4374-a9e0-60c56ecdf479)
![Screenshot 2024-03-31 193646](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/12f80666-463a-46a8-a7ea-a8450e419c38)
![Screenshot 2024-03-31 114933](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/fa87e8ea-bbca-4818-b6e9-44119216d63e)
![Screenshot 2024-03-31 115231](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/3afca4c9-01c0-49fb-acf4-6a98ad4de346)



## High-Level Synthesis (HLS) Based Median Filter for FPGA Applications
Median filtering is a powerful technique in digital signal processing used for noise reduction and image enhancement. In this report, we delve into the implementation of a median filter using High-Level Synthesis (HLS) targeting FPGA platforms. HLS offers a high-level abstraction for designing complex algorithms and accelerates development by automatically generating hardware descriptions from C/C++ code.

How the Median Filter Works:


The med function computes the median of three input values.

The median_filter function applies the median filter to input data in_data.

The filter maintains a sliding window of size 3 to compute the median.

The output out_data is the median value, and out_data_vld indicates valid output.

Key Applications:


Image Processing: Median filtering removes salt-and-pepper noise from images while preserving edges.

Signal Processing: Used in audio and biomedical signal processing to remove impulsive noise without blurring the signal.

Digital Communications: Employed for channel equalization in wireless communication systems to mitigate multipath interference effects.

Real-Time Systems: Finds applications in robotics and automotive safety systems due to its simplicity and effectiveness.

![Screenshot 2024-03-19 001828](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/bc38bacb-a87d-4584-b25f-70924f4eb9eb)

![Screenshot 2024-03-19 001547](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/2d1ed7a2-b5cb-4865-a2ef-fec84e0533e2)

![Screenshot 2024-03-19 001351](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/79731a78-c09f-4331-afd0-db5b820bd112)

![Screenshot 2024-03-19 001049](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/d03a0dc1-b722-484a-805b-831ca8d39341)

![Screenshot 2024-03-19 025843](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/7667cc7e-abf8-494d-9cd7-09d8635a218b)

![Screenshot 2024-03-19 002321](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/30b1b497-f196-4918-b210-823130383f47)



## HLS-based IIR Filter

In the realm of FPGA (Field-Programmable Gate Array) design, the efficient implementation of digital signal processing (DSP) algorithms is a critical aspect. Among these algorithms, IIR (Infinite Impulse Response) filters stand out for their versatility and effectiveness in a wide range of applications. 

The code represents a second-order IIR filter implementation. Here's a breakdown of the key components:

Interface Definition: The iir function takes an input x and produces an output y. Both x and y are of type DATA_TYPE, and they are passed by reference (&) to allow modifications.

Interface Directives: The #pragma HLS INTERFACE directives specify the interface properties of the function. In this case, ap_ctrl_hs denotes a high-speed control interface, while ap_none indicates that x and y do not have streaming interfaces.

Pipeline Directive: The #pragma HLS PIPELINE II=2 directive enables pipeline optimization with a pipeline initiation interval (II) of 2, enhancing throughput by allowing two computations to occur concurrently.

The core of the function performs the IIR filtering operation using the provided coefficients (b0, b1, b2, a1, and a2). It maintains internal state variables (xn1, xn2, yn1, and yn2) to store past input and output samples, ensuring correct filter behavior.

![Screenshot 2024-03-18 230544](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/f487523d-2075-4767-81ae-b493268f811c)
![Screenshot 2024-03-18 232209](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/4eedd797-1640-4d45-8109-6bffe78423f4)
![Screenshot 2024-03-18 232329](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/3102135c-ab2e-42c1-882b-6924dba1eb0c)
![Screenshot 2024-03-18 232738](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/59584658-cd72-4729-9054-76607c170def)
![Screenshot 2024-03-18 234404](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/73ba0539-af2f-435b-9623-f363d779722e)


## HLS-based QAM Module for Wireless Communication Application (Corresponding RTL Verilog HDL files are included)

lms_equalizer: Implements the LMS equalizer module that updates the filter coefficients based on the error signal (difference between desired output and actual output) using the LMS algorithm. It also updates the input sample delay line to prepare for the next iteration.

qam_modulation: Implements QAM modulation by mapping input data bits onto a QAM constellation in the I-Q plane. The design provided is for QAM-4 modulation, but the constellation points can be adjusted for other QAM schemes.

qam_demodulation: Implements QAM demodulation by computing the Euclidean distance between the received symbol and each constellation point and detecting the closest point as the demodulated data.

transmit_filter: Implements the transmit filter module that applies the FIR filter to the input sample to shape the transmitted signal spectrum. The FIR filter coefficients can be optimized based on the desired spectral characteristics.

lms_adaptive_filter: Implements the LMS adaptive filtering function that updates the filter coefficients based on the error signal (difference between desired output and filtered output) using the LMS algorithm.

fir_filter: Implements a simple FIR filter module that computes the output of the equalizer filter using the current input sample and filter coefficients.

dfe_equalizer: Implements the Decision Feedback Equalization (DFE) function that computes the equalized sample by subtracting decision feedback from the filtered output. 

Here's an overview of the design process:

System Specification:

The requirements of the QAM system are reviewed including the modulation scheme (e.g., QAM-16, QAM-64), bandwidth, data rate, signal-to-noise ratio (SNR) requirements, and any specific application constraints.

Modulation and Demodulation:


For QAM modulation, I mapped the input data bits onto a complex constellation, such as symbols in the I-Q plane.
For demodulation, I implemented algorithms to estimate the transmitted symbols based on received signals and perform symbol detection.

Transmit Filter:

Design and implement a transmit filter to shape the transmitted signal spectrum and meet regulatory requirements.
Finite Impulse Response (FIR) is used to design the transmit filter.
Filter coefficients are optimized to achieve desired spectral characteristics while minimizing implementation complexity.

Receive Filter:

A receive filter is designed and implemented to mitigate noise and interference and improve signal-to-noise ratio (SNR) at the receiver.
Adaptive filtering techniques such as Least Mean Squares (LMS) or Decision Feedback Equalization (DFE) is used for adaptive equalization in the receive filter.

Equalization:

An equalizer is implemented to compensate for channel distortion and improve signal quality.
Adaptive equalization techniques such as Decision Feedback Equalization (DFE) or Maximum Likelihood Sequence Estimation (MLSE) can be employed.
Channel effects such as multipath propagation, phase distortion, and frequency-selective fading are estimated and compensated for.

![Screenshot 2024-03-16 102102](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/5b690f66-c979-4c3d-aab3-806ccd312eae)

![Screenshot 2024-03-15 165557](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/2296d916-c60f-422d-87e0-6b9a2fedbbd8)

![Screenshot 2024-03-15 170955](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/1166ed96-4f78-4300-81a7-74f52b3b95ac)


## HLS D Flip-Flop:
The code defines a function HLS_dff that models a series of digital flip-flops (DFFs) in a High-Level Synthesis (HLS) environment for FPGAs. A flip-flop is a basic digital memory element that stores one bit of information. The function takes a single input data, which represents the input bit to be stored, and outputs three bits, n1, n2, and n3, each representing the state of one flip-flop in the series.


The #pragma HLS INTERFACE directives specify that the ports for data, n1, n2, and n3 have no specific interface protocol (ap_none), which means they are treated as simple wires with no handshaking or protocol overhead. The ap_ctrl_none on the return port indicates that there is no control interface, and the function should not expect any start or done signals.


The #pragma HLS PIPELINE directive with II=1 specifies that the design should be pipelined with an initiation interval of 1. This means that on every clock cycle, a new set of inputs can be processed by the function, leading to a continuous flow of data and a potentially higher throughput.


Inside the function, there are four static boolean variables (dff_0, dff_1, dff_2, dff_3) declared to hold the state of each flip-flop. The volatile keyword on dff_0 indicates that this variable's value can change at any time and should not be optimized away by the compiler. On each function call, the flip-flops are updated in a chain, where dff_3 takes the value of dff_2, dff_2 takes the value of dff_1, and so on, with dff_0 taking the new input data. The outputs n1, n2, and n3 are then assigned the values of dff_1, dff_2, and dff_3, respectively.

The screenshots provide additional context:


The csim.log shows that the C simulation of the design (csim.exe) has run with zero errors, suggesting that the function behaves correctly in simulation.

The timing estimate indicates a target of 10 ns with an uncertainty of 2.70 ns. However, as there are no latency or violation issues, the design is meeting timing requirements.

The Vitis HLS console logs indicate successful generation of RTL and co-simulation passes, further confirming functional correctness.

The waveform shows the clock, data, and the output signals (n1, n2, n3). We can infer the behavior of the flip-flops from the transitions of these signals: each output n changes to the value of data from one clock cycle before it, demonstrating the shift-register behavior created by the series of flip-flops.

This design is typically used in digital circuits where a sequence of bits needs to be captured and transferred on each clock cycle, effectively creating a delay line or a shift register. In an FPGA, this would translate to a series of flip-flop components connected in sequence, each storing the bit value of the previous stage.

![Screenshot 2024-03-06 214337](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/428fa943-e791-4617-97c1-e303657b5dc5)

![Screenshot 2024-03-06 215533](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/81de6a94-c4d1-4342-a239-f9764f19e9c4)

![Screenshot 2024-03-06 220103](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/6ed8456f-4341-42c1-8592-331b6ca7ecf0)

![Screenshot 2024-03-06 220653](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/6940fa01-9168-4512-8f3a-1fa4f6d18009)

## HLS Register

The HLS function HLS_reg is defined with two parameters: a single bit data input and a 5-bit unsigned integer n output passed by reference. The design uses the ap_uint<5> data type to define a 5-bit wide register. In HLS, ap_uint is a datatype provided by Xilinx libraries for arbitrary precision arithmetic, which in this case, allows us to define the width of our integer at 5 bits specifically.


The #pragma HLS INTERFACE directives are used to specify the interface configuration for the ports. Setting ap_ctrl_none for the return port indicates that the block does not use the default control signals (start, done, idle). This means that the function will continuously run and process data without needing to be explicitly started or stopped. The ports data and n are configured with ap_none, suggesting they are simple connections without any sideband signals or protocol.


The #pragma HLS PIPELINE directive with an initiation interval (II) of 1 tells the HLS tool to attempt to pipeline this function such that it can accept new input data every clock cycle, effectively allowing for parallel processing and increasing throughput.


Inside the function, there's a static 5-bit register reg which initially holds the value 0b00000. Each time the function is invoked, the register contents are shifted right by one bit, and the data input is placed into the most significant bit (reg[4]). The updated value of reg is then assigned to the output n.


From the attached screenshots, we can observe that:


The csim.log file indicates that the C simulation has been run successfully with no errors, implying functional correctness of the design at the C level.

The timing estimate does not show any issues, with a target and estimated timing of 10 ns and an uncertainty of 2.70 ns.

The synthesis report indicates that the design meets the timing requirements with no latency or iterations, and it is set up for pipelining.

The co-simulation report confirms that the RTL simulation passes, ensuring that the synthesized design behaves as expected when compared to the C model.

The waveform depicts the behavior of the data input and the n output over time, confirming the shift register operation where each bit in n is shifted in each clock cycle, and the input data is placed into the most significant bit position.

This design would typically be used in scenarios where a sequence of bits needs to be captured and shifted in time, such as in serial communication interfaces or for temporary storage and manipulation of bits within a larger digital system. The shift register's ability to operate every clock cycle maximizes the data handling efficiency, which is essential for high-performance FPGA applications.

![Screenshot 2024-03-07 143859](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/2dafc91a-19c3-45d6-a0b5-ccb228ea9e2f)

![Screenshot 2024-03-07 144217](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/4e9542b9-8f51-4e93-bfb8-b0065a0b2a4f)

![Screenshot 2024-03-07 152145](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/7d8334cb-a2aa-4200-bbec-80732a2a95f4)

![Screenshot 2024-03-07 152629](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/767f9caf-a8fb-4666-bf2e-4d1cf9749efd)

# HLS FPGA Design Rotate-With-Load Module:
A common function in cryptographic algorithms and data manipulation tasks. The project encompasses the full HLS design flow including C simulation, synthesis, schedule viewing, co-simulation, and RTL waveform simulation.


Design Specification

The provided HLS code implements a rotate-with-load function. The function takes a data_in input, which is conditionally loaded into a register rotate_reg when the load signal is high. Upon a high rotate signal, the rotate_reg is right-rotated by one position, with the output provided in data_out. The use of the ap_uint<W> data type suggests a templated width, providing flexibility for different data widths.


HLS Pragmas and Interface Configuration

Several HLS interface pragmas are declared for the function arguments, optimizing the design's control and data flow:


ap_ctrl_none: Disables automatic control signals, providing full control over the execution.

ap_none: Specifies that the ports will have no handshaking signals, simplifying the interface.

PIPELINE II=1: Enables full pipelining with an initiation interval of 1, maximizing throughput.

Design Flow

1. C Simulation (csimulation): The initial stage involves verifying the functional correctness of the HLS code. The console output indicates that the C simulation was successfully completed with no errors, demonstrating functional correctness of the HLS code under testbench conditions.


2. Synthesis: The synthesis summary shows that the design targets a 5 ns clock period, achieving an estimated 2.637 ns timing, which is well within the target. The synthesis reports no timing violations, suggesting an efficient translation of the HLS code to RTL.


3. Schedule Viewer: The viewer provides a graphical representation of the operation schedule. The data suggests that operations are tightly packed with no evident pipeline stalls or wasted clock cycles, indicative of an efficient HLS scheduling result.


4. Co-Simulation Report: The co-simulation integrates the RTL simulation with the C model, ensuring the RTL implementation functions as intended. The console output indicates all simulation runs passed with no errors, showcasing the RTL's fidelity to the original HLS design.


5. RTL Simulation Waveform: The waveform visualization confirms the expected operation of the design. Signals load and rotate control the behavior of the rotate_reg, as seen by the changes in data_out, which align with the specified behavior.



Performance and Resource Utilization:


The synthesis report highlights the efficient use of FPGA resources, with only 18 flip-flops (FFs) and 53 look-up tables (LUTs) used, and no block RAM (BRAM) or DSP slices consumed.
The design is pipelined, which is reflected in the timing estimate and schedule viewer results, indicating high throughput capability.

Functional Behavior:

The waveforms corroborate the expected functional behavior, with the rotate_reg correctly loading and rotating based on the control signals.

Challenges and Improvements:

The static nature of rotate_reg as a single-bit shift might limit the function's flexibility. Future improvements could include parameterizing the shift amount for varying rotate operations.
No clear error handling or corner-case consideration is present in the code. Robustness could be improved with the addition of error detection and management logic.

The HLS-based FPGA design for a rotate-with-load function exhibits a promising blend of high performance, functional correctness, and efficient resource utilization. The design flow from csimulation to RTL waveform analysis showcases the effectiveness of HLS in streamlining FPGA design, delivering rapid prototyping capabilities while maintaining high-quality synthesis results. With further optimization and robustness features, the design could be well-suited for demanding applications that require dynamic data manipulation with high throughput requirements.

![Screenshot 2024-03-07 170552](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/fab8cf29-a4dc-41b3-820c-69618f1b1041)

![Screenshot 2024-03-07 171620](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/b5757315-4a7c-4910-89a9-d2b543c7d530)

![Screenshot 2024-03-07 171801](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/604539d3-a8c1-44c3-98de-0b005249ca7c)

![Screenshot 2024-03-07 172640](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/61ffa7d3-b536-4172-84d5-da72f2835fc0)

![Screenshot 2024-03-07 173132](https://github.com/JohnBagshaw/HLS-Project/assets/84130776/80245e6d-0e2b-4dae-9882-61e1926fd89c)



