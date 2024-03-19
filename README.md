# HLS-Project
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

# HLS-based QAM Module for Wireless Communication Application

lms_equalizer: Implements the LMS equalizer module that updates the filter coefficients based on the error signal (difference between desired output and actual output) using the LMS algorithm. It also updates the input sample delay line to prepare for the next iteration.

qam_modulation: Implements QAM modulation by mapping input data bits onto a QAM constellation in the I-Q plane. The design provided is for QAM-4 modulation, but the constellation points can be adjusted for other QAM schemes.

qam_demodulation: Implements QAM demodulation by computing the Euclidean distance between the received symbol and each constellation point and detecting the closest point as the demodulated data.

transmit_filter: Implements the transmit filter module that applies the FIR filter to the input sample to shape the transmitted signal spectrum. The FIR filter coefficients can be optimized based on the desired spectral characteristics.

lms_adaptive_filter: Implements the LMS adaptive filtering function that updates the filter coefficients based on the error signal (difference between desired output and filtered output) using the LMS algorithm.

fir_filter: Implements a simple FIR filter module that computes the output of the equalizer filter using the current input sample and filter coefficients.

dfe_equalizer: Implements the Decision Feedback Equalization (DFE) function that computes the equalized sample by subtracting decision feedback from the filtered output. 

Here's an overview of the design process:

System Specification:

The requirements of the QAM system including the modulation scheme (e.g., QAM-16, QAM-64), bandwidth, data rate, signal-to-noise ratio (SNR) requirements, and any specific application constraints.
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
