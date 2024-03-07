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



