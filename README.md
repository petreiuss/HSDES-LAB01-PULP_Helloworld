# HSDES-LAB1: PULP Virtual Platform Setup and C programming
The target device for the lab sessions is the multi-core [PULP](https://github.com/pulp-platform/pulp) platform. 
The PULP Virtual Platform simulator GVSOC, which is included within the [PULP SDK](https://github.com/pulp-platform/pulp-sdk), will be used during the class. 
To install the GVSOC Simulator and setup your environment, you can 


## GVSOC Simulator Install Guide

### Download the PULP Virtual Machine
The Virtual Machine including a pre-installed PULP Virtual Platform simulator can be found here [Link]() (5GB).
The machine can be used in VirtualBox (instructions below) or other hosts (not tested -- you are on your own...).

Instructions for using this in VirtualBox:
1. Download **pulp-box.ova** from this Google Drive link (5.11 GB)
2. Install and open **VirtualBox** (https://www.virtualbox.org/)
3. Go to **File > Import Appliance...**
4. Select pulp-box.ova as the Appliance to import
5. If needed, change the destination folder, then click on Import
6. In the main VirtualBox window, click on the new virtual machine, then on Start

The username in the virtual machine is _pulp-user_, while the password is _pulp_. Check the README file.

### Install the PULP-SDK on your Linux machine
You can follow the instructions [here](https://github.com/pulp-platform/pulp-sdk#getting-started), which has been tested on a fresh Ubuntu 18.04 Bionic Beaver 64-Bit machine. 
The main step concern:
1. Install the compiler. A precompiled version can be taken from [here](https://github.com/pulp-platform/pulp-riscv-gnu-toolchain/releases/tag/v1.0.16).

2. Export the RISC-V compiler path.
~~~~~shell
export PULP_RISCV_GCC_TOOLCHAIN=<INSTALL_DIR>
~~~~~

3. Clone and build the PULP SDK
~~~~~shell
git clone git@github.com:pulp-platform/pulp-sdk.git
cd pulp-sdk
source configs/pulp-open.sh
make build
~~~~~



## Test your GVSOC Installation
After completing the GVSOC setup, you can run helloworld on PULP. 
First you can download some example programs in your preferred working directory.
~~~~~shell
cd <your_work_directory>
git clone git@github.com:GreenWaves-Technologies/pmsis_tests.git
cd pmsis_tests/quick/hello/
make clean all run
~~~~~
If you see an *Helloworld* from PULP, your setup is fine! ;)

## Additional Information
### Source the PULP SDK eveytime you open a new shell
To run example code on the PULP Virtual Plaform, you must source the platorm configurafion file and export the RISC-V Compiler path.
~~~~~shell
export PULP_RISCV_GCC_TOOLCHAIN=<INSTALL_DIR>
source configs/pulp-open.sh
~~~~~
You can consider to prepare a bash script to run this command.
If you are using the PULP Virtual Machine, you should run the command:
~~~~~shell
source /pulp/pulp-open.sh
~~~~~



