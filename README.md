# IMAX-LLM: Efficient Kernel Mapping and System Evaluation on CGLA

This repository contains the official implementation for the paper *“Efficient Kernel Mapping and Comprehensive System Evaluation of LLM Acceleration on a CGLA”* (IEEE Access).

We present a system for accelerating state-of-the-art LLMs (specifically the Qwen3 family) using a general-purpose CGLA (Coarse-Grained Linear Array) architecture called IMAX. This implementation is built upon the llama.cpp framework and utilizes a hybrid execution model that offloads computationally intensive dot-product operations to the IMAX accelerator.

## Key Features

- **CGLA acceleration**: Optimized kernel mapping for the 1D PE array architecture (IMAX).
- **Qwen3 support**: Validated on Qwen3-0.6B, 1.7B, and 8B models.
- **Diverse quantization kernels**:
  - FP16: Baseline and high-precision layers.
  - Q8_0: Standard 8-bit integer quantization.
  - Q3_K: Highly compressed mixed-precision (uses custom CVT53 instruction).
  - Q6_K: 6-bit quantization (uses custom CVT86 instruction).
- **High energy efficiency**: Achieves up to 44.4× improvement in PDP (Power-Delay Product) compared to NVIDIA RTX 4090.

## Hardware Setup

The system evaluation was conducted on the following FPGA platform:

- Device: AMD Versal Premium VPK180 Evaluation Kit
- Host CPU: ARM Cortex-A72 (Dual-core)
- OS: PetaLinux (aarch64)
- IMAX configuration: 2-lane configuration (running at 145 MHz)
- Tools: Vivado 2024.1

## Installation & Build

### Prerequisites

- Xilinx Vitis / Vivado 2024.1
- CMake 3.14 or higher
- C++17 compiler

### Build Instructions

```bash
# Clone the repository
git clone https://github.com/naist-arch-lab/imax-llm.git
cd imax-llm

# Load the IMAX bitstream to the FPGA
./scripts/load_bitstream.sh imax_2lane.xclbin

# Build the llama.cpp-based engine
mkdir build
cd build
cmake .. -DLLAMA_IMAX=ON -DCMAKE_BUILD_TYPE=Release
make -j4
```

## Usage

Prepare the Qwen3 model files (GGUF format) and run inference as follows:

```bash
# Example: Running Qwen3-0.6B with Q8_0 quantization
./llama-cli-acap-emax7+dma -m models/qwen3-0.6b-q8_0.gguf \
  -p "Tell me about the future of AI." \
  -n 128
```

## Architecture Overview

The system hooks into the matrix multiplication operations (`GGML_OP_MUL_MAT`) of llama.cpp and offloads them to the IMAX accelerator.

- **Host (ARM CPU)**: Handles complex control flow, tokenization, embedding layers, KV cache management, Softmax, and RMS Norm.
- **Accelerator (IMAX)**: Handles computationally intensive Linear Projections (Q, K, V, Output) and Feed Forward SwiGLU layers.

For detailed dataflow and kernel mapping strategies (e.g., SML8, CVT53), please refer to the paper and the source code in `src/kernels/`.